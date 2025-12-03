clc; clear; close all;
% Thomas Lønne Stiansen - FHV Winter Semester 2025
    % For PID control with Root Locus on cart

% Constants
markSize = 10;
sign = -1; % for negative feedback
yLims = 30;
xMin = -70;
xMax = 5;
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
tp = 1;

% Mp = OS   ,   D = zeta    ,   wn = omega_n
OS = OS_percent / 100;
    % Damping Ratio
zeta = -log(OS) / sqrt( pi^2 + log(OS)^2 ); % MATLAB: log = ln
    % Natural Frequency
% omega_n = 4/(ts*zeta);
omega_n = pi / (tp * sqrt(1 - zeta^2) );

% Damped Frequency of Oscillation
omega_d = omega_n * sqrt(1 - zeta^2);
% Exponential Damping Frequency
sigma_d = zeta*omega_n;

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
    z_D = 25;

% PD Controller
% G_PD = (s + z_D);
    tau_f = 0.001;
    G_PD = (s + z_D) * 1/(tau_f*s + 1);

% Root Locus
figure
rlocus(G_OL * G_PD)
hold on
title('Root Locus: PD Design')
sgrid(zeta,omega_n);
    plot(x, y1, '--k',  x, y2, '--k');
ylim([-yLims yLims])
xlim([xMin xMax])

%%% Selected from Root-Locus %%%
% K_PD = 20;
K_PD = 1.4;

    % Pole Zero Map of PD Control
    G_CL = feedback( K_PD*G_PD * G_OL , 1, sign);
    figure
    pzmap(G_CL)
    title('Pole-Zero Map: PD Control')
    hold on
    sgrid(zeta, omega_n)
        plot(x, y1, '--k',  x, y2, '--k');
    ylim([-yLims yLims])
    xlim([xMin xMax])

%% PI Design - Inspired by Lösung_11.pdf

% Zero Selection
z_I = [0.3 1 2 4];
for i = 1 : length(z_I)
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
z_I_idx = 4;

%% Combined

G_c = ( K_PD*G_PD * G_PI(z_I_idx) );

% Root Locus
figure
rlocus(G_OL * G_c)
hold on
title('Root Locus: PID Design')
sgrid(zeta, omega_n)
    plot(x, y1, '--k',  x, y2, '--k');
ylim([-yLims yLims])
xlim([xMin xMax])

%%% Selected from Root-Locus %%%
K_PID = 42.5;

%% Controller

G_C = K_PID * G_c;
% G_C = pidtune(G_OL, 'PID');

% Proportional
G_CL = feedback( G_C*G_OL , 1, sign);

% Pole Zero Map of PID Control
figure
pzmap(G_CL)
title('Pole-Zero Map: PID Control')
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