% from Emanuel Matt 2025 (copied via WhatsApp message)

clear all
s=tf('s');

% additional zero 
z_c=0.5; 
% continuous-time transfer function with the additional zero
sys_c = (s + z_c) / s;

%system definition
sys_mL = 1/(s+2.071);

ts = 5; % settlingtime in s
Mp= 0.02; % overshoot (0.2 = 20%)
D=-log(Mp)/sqrt(pi()^2+log(Mp)^2);  % damping
w0=4/(D*ts);


figure;
% stability area
theta = acos(D);    
x = linspace(-2.5, 0, 100);
y1 = tan(theta)*x;  
y2 = -tan(theta)*x;
plot(x, y1, '--b', x, y2, '--b', 'LineWidth', 1.5);
text(-2, 0.5, 'stability area', 'Color', 'blue'); 
hold on

%%
% root locus
rlocus(sys_mL*sys_c);
sgrid(D, w0);
[K, poles] = rlocfind(sys_mL*sys_c);
gain = dcgain(feedback(K*sys_c*sys_mL, -1, 1)); 

%%
% Controller coeff
t_step = 0:0.01:20;
hold off
Ti = 1/z_c; 
G_wok = K*(1+1/(Ti*s)); 
[y_wok, t_wok] = step(1/gain*feedback(G_wok*sys_mL, 1), t_step); 

%%
figure; 
hold on; 
plot(t_wok, y_wok);
yline(1, '--');
hold off;