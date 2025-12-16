clc; clear; close all;

%% Selection
weight = true;
ALPHA_MINMAX = 20; % [deg]
XC_MINMAX = 0.3; % [m]

% Calc from them
ALPHA_MIN = -ALPHA_MINMAX;
ALPHA_MAX = +ALPHA_MINMAX;
XC_MIN = -XC_MINMAX;
XC_MAX = +XC_MINMAX;

%% Constants

global ALPHA_MAX ALPHA_MIN K_EC K_EP 
%%%%%%%%%%%%%%%%%%%% Load parameters - Quanser %%%%%%%%%%%%%%%%%%%%%%
M_c2 = 0.57; % [kg] IP02 Cart mass w/3 cable connectors
M_w = 0.37; % [kg] Cart weight
M_p = 0.23; % [kg] Pendulum: Mass
l_p = 0.3302; % [m] Pendulum: from pivot to COM
J_p = 7.88*10^-3; % [kg*m^2] Moment of Inertia about COM
B_p = 0.0024; % [Nm*s/rad] Pendulum: Viscous Damping Coefficient
g = 9.81; % [m/s^2] gravitational constant
if weight
    IP02_LOAD_TYPE = 'WEIGHT';
else
    IP02_LOAD_TYPE = 'NO_LOAD';
end
[ R_m, J_m, k_t, eta_m, k_m, K_g, eta_g, M_c, r_mp, B_c ] = config_ip02( IP02_LOAD_TYPE );
%%%%%%%%%%%%%%%%%%%% Load parameters - Quanser %%%%%%%%%%%%%%%%%%%%%%

% Calculated
B_eq = (k_m * eta_g * K_g^2 * eta_m * k_t) / (R_m * r_mp^2) + B_c; % Equivalent Damping
J_eq = M_c + ( eta_g * K_g^2 * J_m ) / (r_mp^2 );                  % Equivalent Inertia
J_T = J_eq*M_p*l_p^2 + J_eq*J_p + J_p*M_p;                         % Total Inertia
    % For F_c substitution
C_x = (eta_g * K_g^2 * k_t * k_m) / (R_m * r_mp);
C_V = (eta_g * eta_m * K_g * k_t) / (R_m * r_mp);

%% State-Space

    A_32 = (M_p^2 * l_p^2 * g) / J_T ;              % α     \
    A_33 = -(J_p + M_p*l_p^2)*(B_eq + C_x) / J_T ;  % ẋ_c   | eq: x¨_c
    A_34 = - (M_p * l_p * B_p) / J_T ;              % ̇α     /__________
    A_42 = M_p * l_p * g * (J_eq + M_p) / J_T ;     % α     \
    A_43 = - (M_p * l_p)*(B_eq + C_x) / J_T ;       % ẋ_c   | eq: α¨
    A_44 = - B_p * (J_eq + M_p) / J_T ;             % ̇α     /
% State-Space from Lagrangian Mechanics - See report!
A = [ 0   0     1     0 ;
      0   0     0     1 ;
      0  A_32  A_33  A_34 ;  % x¨_c
      0  A_42  A_43  A_44 ]  % α¨
B = [                  0    ;
                       0    ;
      (J_p + M_p*l_p^2)*C_V/J_T ;
              (M_p*l_p)*C_V/J_T ]
C = [ 1 0 0 0 ;
      0 1 0 0 ]
D = [ 0 ;
      0 ]

%% Verify controllability

C_AB = [ B , A*B , A^2*B , A^3*B ]; % UiA formula
if rank(C_AB) ~= size(A,1)
    error('[ERROR] System is not controllable!')
end

%% LQR Design

% Constants for Bryson's Rule
u_max = 10; % [V]
x1_max = 0.1; % [m]
x2_max = deg2rad(3); % [rad]
x3_max = 3.16; % [m/s]
x4_max = deg2rad(180); % [rad/s]
    q1 = 1 / (x1_max^2); % [m]
    q2 = 1 / (x2_max^2); % [deg]
    q3 = 1 / (x3_max^2); % [m/s]
    q4 = 1 / (x4_max^2); % [deg/s]
Q = [ q1  0  0  0 ;  % x_c   = Cart     Position
       0 q2  0  0 ;  % α     = Pendulum Position
       0  0 q3  0 ;  % ẋ_c   = Cart     Velocity
       0  0  0 q4 ]; % ̇α     = Pendulum Velocity
R = 1 / (u_max^2);

% Tuning
Q(1,1) = Q(1,1) * 1;
Q(2,2) = Q(2,2) * 1;
Q(3,3) = Q(3,3) * 1;
Q(4,4) = Q(4,4) * 1;
R = R * 1;

% Linear Quadratic Regulator
[ K, ~, ~] = lqr(A,B, Q,R) % [ K, sol_Riccati, p_CL ]

%{
    UiA Lecture:
        - Increased Q --> Larger control gain
        - Increased R --> Lower control gain
%}

%% Specifications of a second-order low-pass filter
wcf = 2 * pi * 10.0;  % filter cutting frequency
zetaf = 0.9;        % filter damping ratio