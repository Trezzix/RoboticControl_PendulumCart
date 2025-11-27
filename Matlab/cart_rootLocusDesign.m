clc; clear; close all;

%% Chosen parameters

weight = false;

%% Load constant conversion parameters

% from radians to degrees
K_R2D = 180 / pi;
% from degrees to radians
K_D2R = 1 / K_R2D;
% from Inch to Meter
K_IN2M = 0.0254;
% from Meter to Inch
K_M2IN = 1 / K_IN2M;
% from rad/s to RPM
K_RDPS2RPM = 60 / ( 2 * pi );
% from RPM to rad/s
K_RPM2RDPS = 1 / K_RDPS2RPM;
% from oz-force to N
K_OZ2N = 0.2780139;
% from N to oz-force
K_N2OZ = 1 / K_OZ2N;

%% Load parameters
R_m = 2.6; % [ohm] Motor armature resistance
L_m = 180e-6; % [H] Motor armature Inductance
k_t = 1.088 * K_OZ2N * K_IN2M; % [Nm/A] Motor torque constant
eta_m = 1; % [ (Tm*w) / (Vm * Im) ] Motor electro-mechanical efficiency
k_m = 0.804e-3 * K_RDPS2RPM; % [Vs/rad] Motor back-EMF constant
J_m = 5.523e-5 * K_OZ2N * K_IN2M; % [kg*m^2] Rotor inertia
M_c2 = 0.57; % [kg] IP02 Cart mass w/3 cable connectors
M_w = 0.37; % [kg] Cart weight
K_g = 3.71; % [-] Internal gear ratio (planetary gearbox)
eta_g = 1; % [-] Internal gear ratio efficiency (planetary gearbox)
N_mp = 24; % [-] Number of teeth: cart motor pinion
r_mp = 0.5 / 2 * K_IN2M; % [m] Motor pinion radius
N_pp = 56; % [-] Number of teeth: cart position pinion
r_pp = 1.167 /2 * K_IN2M; % [m] Position pinion radius
P_r = 1e-2 / 6.01; % [m/teeth] Rack pitch
T_c = 0.814; % [m] Cart travel

%% Constants

% Mass of cart
if weight % with weight
    M = M_w + M_c2;
    B_c = 5.4; % [Nm*s/rad]
else % without weight
    M = M_c2;
    B_c = 4.3; % [Nm*s/rad]
end
% Actuator Gain
Am = ( eta_g * K_g * eta_m * k_t ) / ...
            ( r_mp * R_m );
% Equivalent Damping
B_eq = ( (eta_g * K_g^2 * eta_m * k_t * k_m) + (B_c * r_mp^2 * R_m) ) / ...
            ( r_mp^2 * R_m );
% Equivalent Inertia
J_eq = M + ( eta_g * K_g^2 * J_m ) / (r_mp^2 );

% Transfer Function
K = Am/B_eq;
tau = J_eq/B_eq;
table(K, tau)