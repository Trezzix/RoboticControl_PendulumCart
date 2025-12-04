clc; clear; close all;
% Thomas Lønne Stiansen - FHV Winter Semester 2025
    % For P control with Root Locus on cart

% Constants
markSize = 10;
sign = -1; % for negative feedback
yLims = 9;
xMin = -14;
xMax = 1;
dk = 0.005;        % Root-Locus: Step size
k = 0 : dk : 46; % Root-Locus: Locus size
x = xMin : 0;

%% Plant

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
plant = zpk(G_OL)

% IT_1 Block
figure
step(G_OL)
title('Step Response: Open Loop')

%% Requirements

% Requirements
OS_percent = 10; % [percent]
% ts = 0.6; % [sec]
tp = 0.5; % [sec]

% Mp = OS   ,   D = zeta    ,   wn = omega_n
OS = OS_percent / 100;
    % Damping Ratio
zeta = -log(OS) / sqrt( pi^2 + log(OS)^2 ); % MATLAB: log = ln
    % Natural Frequency
% omega_n = 4/(ts*zeta);
omega_n = pi / (tp * sqrt(1 - zeta^2) );

% % Damped Frequency of Oscillation
% omega_d = omega_n * sqrt(1 - zeta^2);
% % Exponential Damping Frequency
% sigma_d = zeta*omega_n;

% Stability Lines
theta = acos(zeta);
y1 = +tan(theta)*x;
y2 = -tan(theta)*x;

%% Default System Root Locus

% Root Locus
figure
rlocus(G_OL)
title('Root Locus: Open Loop')
ylim([-yLims yLims])
xlim([xMin xMax])
hold on
sgrid(zeta, omega_n)
    plot(x, y1, '--k',  x, y2, '--k');

K_P = 60;

%% P Control

% Proportional
G_CL = feedback( K_P*G_OL , 1, sign);

% Pole Zero Map of PI Control
figure
pzmap(G_CL)
title('Pole-Zero Map: P Control')
hold on
sgrid(zeta, omega_n)
    plot(x, y1, '--k',  x, y2, '--k');
ylim([-yLims yLims])
xlim([xMin xMax])

% Plot time response
figure
step(G_CL)
stepinfo(G_CL)
title('Step Response: Closed Loop')