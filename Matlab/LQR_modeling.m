clc; clear; close all;

%% Non-Inverted Pendulum Equations

syms Jeq Mp lp Jp Bp Beq Fc g
syms xd alphad alpha

A = [ (Jeq+Mp) ,  (-Mp*lp)    ;
       (-Mp*lp)  ,(Jp+Mp*lp^2)  ];
b = [ (Fc - Beq*xd) ;
      (-Bp*alphad + Mp*lp*g*alpha) ];

x = simplify(A\b);
pretty(x(1))
pretty(x(2));