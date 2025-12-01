clear all; close all;
% From Lösung 11 - Example slide 13/14

%%

s=tf('s');

% Nullstelle
z_c=[0.1, 0.2, 0.4, 0.6];
for i=1:length(z_c)
    sys_c(i)=(s+z_c(i))/s;
end

% Systemdefinition
sys_oL=3/((s+1)*(s+3));
for k=1:4
    subplot(2,2,k);
    rlocus(sys_oL*sys_c(k));
    legend(num2str(z_c(k)));
    axis([-6 1 -8 8]);
    % Genzwerte
    Mp = 0.08; % 8% Überschwingweite
    D = -log(Mp)/sqrt(pi()^2+log(Mp)^2); % Dämpfung
    wn = 0; % Normierte Eigenfrequenz
    sgrid(D, wn);
end

% Step
figure;
for k=1:4
    step( feedback( 2.4*sys_c(k)*sys_oL, 1, -1) );
    hold on;
end
legend(num2str(z_c(1)),num2str(z_c(2)),num2str(z_c(3)),num2str(z_c(4)));
axis([0 60 0 1.1]);
