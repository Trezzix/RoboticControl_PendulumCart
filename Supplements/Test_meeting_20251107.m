close all; clear all; clc;
% Sent from Stefan Bonerz over Teams

%%
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

%%
% Paraemter definition of control system
Mp=0.1; % 10% overshoot
ts=1;   % 1s settling time
D=-log(Mp)/sqrt(pi()^2+log(Mp)^2);
wn=4/(ts*D);
sgrid(D,wn);

%%
% P-controller
sysP=150;

% Feedback control system
sys=feedback(sysP*sysM,1,-1);

step(sys);

% D-controler
z_c=10;
sysD=(s+z_c);
rlocus(sysM*sysD);
sysP=10;

% Feedback control system with PD controller
sys=feedback(sysD*sysP*sysM,1,-1);