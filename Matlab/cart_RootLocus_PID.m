clc; clear; close all;
% Thomas Lønne Stiansen - FHV Winter Semester 2025
    % For PID control with Root Locus on cart

% Constants
markSize = 10;
sign = -1; % for negative feedback
ylims = 15;

%% Root Locus

% Loaded from cart_Model.m
    % With Weight
        K_PID = 0.131346246942449;
        tau = 0.081642070282424;
    % Without Weight
        % K = 0.143342010172210;
        % tau = 0.058378523227571;
s = tf('s');
G_cartVel = K_PID / (tau*s + 1);   % G  =  V_c(s) / V_m(s)  =  [m/s] / [V]
    % Integrate to get position control
G_cartPos = G_cartVel * (1/s); % G  =  X_c(s) / V_m(s)  =  [m]   / [V]

G_OL = G_cartPos;

% IT_1 Block
figure
step(G_OL)
title('Step Response: Open Loop')

% % Root Locus
% figure
% rlocus(G_OL)
% title('Root Locus: Open Loop')
% ylim([-ylims ylims])

%% Requirements

% Requirements
OS_percent = 1; % [percent]
ts = 0.5; % [sec]

% Mp = OS   ,   D = zeta    ,   wn = omega_n
OS = OS_percent / 100;
    % Damping Ratio
zeta = -log(OS) / sqrt( pi^2 + log(OS)^2 ); % MATLAB: log = ln
    % Natural Frequency
omega_n = 4/(ts*zeta);

% Damped Frequency of Oscillation
omega_d = omega_n * sqrt(1 - zeta^2);
% Exponential Damping Frequency
sigma_d = zeta*omega_n;

%% PD Design - Inspired by Lösung_11.pdf

% Desired Poles
p_w = - sigma_d + j*omega_d;

% Poles of Plant
p_i = pole(G_OL);

% Angles of System Poles
for i = 1 : length(p_i)
    phi(i) = rad2deg( atan2( (imag(p_w) - imag(p_i(i)) ), ... % Δy
                             (real(p_w) - real(p_i(i)) ) ) ); % Δx
end
% Required Angle
phi_zD = 180 + sum(phi);

% PD Zero
z_D = omega_d / tand(phi_zD) + sigma_d;

% PD Controller
G_PD = (s + z_D);

% Root Locus
figure
rlocus(G_OL * G_PD)
title('Root Locus: PD Design')
% ylim([-ylims ylims])

% Instead of sgrid
sgrid(zeta,omega_n);

%%% Selected from Root-Locus %%%
K_PD = 2.5;

%% PI Design - Inspired by Lösung_11.pdf

% Zero Selection
z_I = [0.1 0.3 0.6 0.9];
for i=1:length(z_I)
    G_PI(i) = ( s + z_I(i) ) / s;
end

% Step response of PI zeros
figure;
Legend = cell(length(z_I),1);
for i = 1 : length(z_I)
    step( feedback(G_PD*G_PI(i)*G_OL, 1, -1) );
    axis([0 10 0 1.25]);
    Legend{i} = strcat('z_c = ', num2str(z_I(i)));
    hold on;
end
legend(Legend, 'Location','southeast');
title('Step Response: PI Design')
yline(1.05, '--k')
yline(0.95, '--k')

%%% Selected from Response %%%
z_I_idx = 2;

%% Combined

G_c = ( K_PD*G_PD * G_PI(z_I_idx) );

% Root Locus
figure
rlocus(G_OL * G_c)
title('Root Locus: PID Design')
% ylim([-ylims ylims])
sgrid(zeta, omega_n)

%%% Selected from Root-Locus %%%
K_PID = 1.3;

%% Controller

G_C = K_PID * G_c;

% Proportional
G_CL = feedback( G_C*G_OL , 1, sign);

figure
% rlocus(G_CL)
% title('Root Locus: Closed Loop')
% ylim([-ylims ylims])
pzmap(G_CL)
title('Pole-Zero Map: Closed Loop')
sgrid(zeta, omega_n)

% Plot time response
figure
step(G_CL)
stepinfo(G_CL)
title('Step Response: Closed Loop')