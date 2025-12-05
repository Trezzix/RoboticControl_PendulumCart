clc; clear; close all;
% Thomas Lønne Stiansen - FHV Winter Semester 2025
    % For PI control with Root Locus on cart

% Constants
markSize = 10;
sign = -1; % for negative feedback
yLims = 10;
xMin = -10;
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
sgrid(zeta, omega_n)

%% PI Design - Inspired by Lösung_11.pdf

% Zero Selection
z_I = [0.1 0.3 0.5 1];
for i = 1 : length(z_I)
    G_PI(i) = ( s + z_I(i) ) / s;
end

% Step response of PI zeros
figure;
Legend = cell(length(z_I),1);
for i = 1 : length(z_I)
    step( feedback(G_PI(i)*G_OL, 1, -1) );
    axis([0 100 0 1.8]);
    Legend{i} = strcat('z_c = ', num2str(z_I(i)));
    hold on;
end
legend(Legend, 'Location','northeast');
title('Step Response: PI Design')
% yline(1.05, '--k')
% yline(0.95, '--k')

%%% Selected from Response %%%
z_I_idx = 2;

%% PI Design - Root Locus

% Root Locus
figure
rlocus(G_OL * G_PI(z_I_idx))
hold on
title('Root Locus: PI Design')
sgrid(zeta, omega_n)
    plot(x, y1, '--k',  x, y2, '--k');
ylim([-yLims yLims])
xlim([xMin xMax])

%%% Selected from Root-Locus %%%
K_PI = 49;

%% Step response of PI zeros
figure;
Legend = cell(length(z_I),1);
for i = 1 : length(z_I)
    step( feedback(K_PI*G_PI(i)*G_OL, 1, -1) );
    axis([0 9 0.95 1.25]);
    Legend{i} = strcat('z_c = ', num2str(z_I(i)));
    hold on;
end
legend(Legend, 'Location','northeast');
title('Step Response: PI Design - with K_{PI}')

%% Controller

G_C = K_PI * G_PI(z_I_idx);
% G_C = pidtune(G_OL, 'PID');

% Proportional
G_CL = feedback( G_C*G_OL , 1, sign);

% Pole Zero Map of PI Control
figure
pzmap(G_CL)
title('Pole-Zero Map: PI Control')
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

%% Convert to discrete with Tustin transform

t_sample = 0.01;
G_C_discrete = c2d(G_C, t_sample, 'tustin');