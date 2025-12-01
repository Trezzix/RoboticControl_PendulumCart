clc; clear; close all;
% Thomas Lønne Stiansen - FHV Winter Semester 2025

% Constants
markSize = 10;
sign = -1; % for negative feedback
ylims = 15;

%% Root Locus

% Loaded from cart_Model.m
    % With Weight
        K = 0.131346246942449;
        tau = 0.081642070282424;
    % Without Weight
        % K = 0.143342010172210;
        % tau = 0.058378523227571;
s = tf('s');
G_cartVel = K / (tau*s + 1);   % G  =  V_c(s) / V_m(s)  =  [m/s] / [V]
    % Integrate to get position control
G_cartPos = G_cartVel * (1/s); % G  =  X_c(s) / V_m(s)  =  [m]   / [V]

G_OL = G_cartPos;

% IT_1 Block
figure
step(G_OL)
title('Step Response: Open Loop')

% Root Locus: only 1 pole, thus goes off to -∞
figure
rlocus(G_OL)
title('Root Locus: Open Loop')
ylim([-ylims ylims])

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

% Instead of sgrid
sgrid(zeta,omega_n);

%% Controller

% Proportional
% sysP = 5; % cartVel
% sysP = 40; % cartPos - no weight
sysP = 64; % cartPos - with weight
G_CL = feedback( sysP*G_OL , 1, sign);

figure
rlocus(G_CL)
title('Root Locus: Closed Loop')
ylim([-ylims ylims])
    % pzmap(G_CL)
    % title('Pole-Zero Map: Closed Loop')
sgrid(zeta, omega_n)

% Plot time response
figure
step(G_CL)
stepinfo(G_CL)
title('Step Response: Closed Loop')