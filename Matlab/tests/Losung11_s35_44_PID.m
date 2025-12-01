clc; clear all; close all;
% Lösung_11: PID Compensator (slides 35-44)

%% s38

clear all;
close all;
s=tf('s');
% Systemdefinition
sys_oL=15/((s+1)*(s+3)*(s+6));
rlocus(sys_oL);
axis([-6 1 -10 10]);
% Genzwerte
Mp=0.2; % 20% Überschwingweite
D=-log(Mp)/sqrt(pi()^2+log(Mp)^2); % Dämpfung
ts=1; % Einschwingzeit
wn=4/(ts*D); % Normierte Eigenfrequenz
sgrid(D, wn);
% Graphische Suche nach Wunsch-Polstelle
rlocfind(sys_oL);
% Wunschpolstelle ergit sich damit zu:
p_w=-4+7.8*1i;

%% s39

clear all;
close all;
s=tf('s');
% Wunschpolstelle (hier nur die positive)
p_w=-4+7.8*1i;
% Systemdefinition
sys_oL=15/((s+1)*(s+3)*(s+6));
p_i=pole(sys_oL);
% Bestimmung der Winkel der Streckenpole
for i=1:length(p_i)
phi(i)=rad2deg(atan2((imag(p_w)-imag(p_i(i))),(real(p_w)-real(p_i(i)))));
end
% Bestimmung des erforderlichen Winkels
theta_z=180+sum(phi);
% Zugehörige Nullstelle für Winkel theta
z_c=abs(imag(p_w))/tan(deg2rad(theta_z))+abs(real(p_w));
sys_c=s+z_c;
rlocus(sys_oL*sys_c);
hold on;
plot(real(p_w),imag(p_w),'kx','Markersize',10);
plot(real(p_w),-imag(p_w),'kx','Markersize',10);
axis([-15 1 -8 8]);
% Genzwerte
Mp=0.2; % 20% Überschwingweite
D=-log(Mp)/sqrt(pi()^2+log(Mp)^2); % Dämpfung
ts=1; % Einschwingzeit
wn=4/(ts*D); % Normierte Eigenfrequenz
sgrid(D, wn);

%% s40

clear all;
close all;
s=tf('s');
% Systemdefinition
sys_oL=15/((s+1)*(s+3)*(s+6));
sys_c=s+2.06;
% Step
figure;
step(feedback(4.41*sys_c*sys_oL,1,-1));

%% s42

clear all;
close all;
s=tf('s');
% Systemdefinition
sys_oL=15/((s+1)*(s+3)*(s+6));
sys_cPD=4.41*(s+2.06);
% Wahl der Nullstelle
z_c=[0.1 0.3 0.6 0.9];
for i=1:length(z_c)
sys_cPI(i)=(s+z_c(i))/s;
end
% Step
figure;
Legend=cell(length(z_c),1);
for i=1:length(z_c)
step(feedback(sys_cPD*sys_cPI(i)*sys_oL,1,-1));
axis([0 10 0 1.25]);
Legend{i}=strcat('z_c = ',num2str(z_c(i)));
hold on;
end
legend(Legend);

%% s43

clear all;
close all;
s=tf('s');
% Systemdefinition
sys_oL=15/((s+1)*(s+3)*(s+6));
sys_cPD=4.41*(s+1.5);
sys_cPI=(s+1.2)/s;
rlocus(1.2*sys_oL*sys_cPD*sys_cPI); % 1.2 just from probing in RootLocus? - TLS
axis([-6 1 -10 10]);
% Genzwerte
Mp=0.2; % 20% Überschwingweite
D=-log(Mp)/sqrt(pi()^2+log(Mp)^2); % Dämpfung
ts=1; % Einschwingzeit
wn=4/(ts*D); % Normierte Eigenfrequenz
sgrid(D, wn);
figure;
step(feedback(1.2*sys_cPD*sys_cPI*sys_oL,1,-1));
axis([0 5 0 1.2]);

%% s44

clear all;
close all;
s=tf('s');
% Systemdefinition
sys_oL=15/((s+1)*(s+3)*(s+6));
% PIDTune
sys_c=pidtune(sys_oL,'PID');
% Wurzelortskurve
rlocus(sys_c*sys_oL);
axis([-6 1 -10 10]);
Mp=0.2; % 20% Überschwingweite
D=-log(Mp)/sqrt(pi()^2+log(Mp)^2); % Dämpfung
ts=1; % Einschwingzeit
wn=4/(ts*D); % Normierte Eigenfrequenz
sgrid(D, wn);
% Plot
figure;
step(feedback(sys_c*sys_oL,1,-1));
axis([0 5 0 1.2]);