% Damped Frequency of Oscillation
omega_d = zeta*omega_n;
% Exponential Damping Frequency
sigma_d = omega_n * sqrt(1 - zeta^2);

phi_1 = 180 - atand(omega_d / (sigma_d - 1/tau) ); % degrees
z_PD = omega_d / tand(phi_1);