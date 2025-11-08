
%% 1st msg
close all
clear all
clc
s=tf('s');
% Parameter
kM=1.2;
LA=0.035;
RA=2.4;
JA=0.22;
r=0.1;
% Phi/U_R
sysM=1/(s^3*LA*JA/kM+s^2*JA*RA/kM+kM*s);
% IT_1-block
step(sysM);
% Root Locus
rlocus(sysM);
% Paraemter definition of control system
Mp=0.1; % 10% overshoot
ts=1;   % 1s settling time
D=-log(Mp)/sqrt(pi()^2+log(Mp)^2);
wn=4/(ts*D);
sgrid(D,wn);
% P-controller
sysP=150;
% Feedback control system
sys=feedback(sysP*sysM,1,-1);
step(sys);
% D-controler
z_c=10;
sysD=(s+z_c);
rlocus(sysM*sysD);
sysP=7.8;
% Feedback control system with PD controller
sys=feedback(sysD*sysP*sysM,1,-1);


%% 2nd msg

% Wunschpolstelle (hier nur die positive)
p_w=-4+7.8*1i;
% Systemdefinition
sys_oL=15/((s+1)*(s+3)*(s+6)); p_i=pole(sys_oL);
% Bestimmung der Winkel der Streckenpole
for i=1:length(p_i) phi(i)=rad2deg(atan2((imag(p_w)-imag(p_i(i))),(real(p_w)-real(p_i(i)))));
end
% Bestimmung des erforderlichen Winkels
theta_z=180+sum(phi);
% Zugehörige Nullstelle für Winkel theta
z_c=abs(imag(p_w))/tan(deg2rad(theta_z))+abs(real(p_w));
sys_c=s+z_c;
rlocus(sys_oL*sys_c);