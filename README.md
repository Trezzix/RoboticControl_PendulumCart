# Project: Linear Pendulum Gantry
Thomas Lønne Stiansen

<img src="Figures/Stefan_labPreparation.jpeg" alt="drawing" width="450"/>

Project for the following courses at Fachhochschule Vorarlberg (FHV):
- Applied Robotics - only graded for this course
- Control Engineering

*Supervised by Stefan Bonerz and Robert Amann, and help by Markus Seeberger*

## Project Division

The project is organized into the following sub-goals:

- **Guide:** Operation guide for later students, including test with reading and writing signals
- **Cart Position:** Position control of cart with simple controller designed through root-locus
- **State-Space Control:** Design state-space controller with LQR

## Directories/Files

*(that are not self explanatory)*

- **Archiv** : Project folder given by Stefan Bonerz, Quanser workbooks and templates
- **Supplements** = Files given throughout the project. Most important ones:
    - QUARC_Setup_English.pdf : Given by Markus Seeberger & expanded during R&D
    - Lösung_11.pdf : Presentation from BSc course provided by Stefan Bonerz
- **Matlab** : Scripts
    - cart_Model.m : Calculation of model's transfer function
    - cart_RootLocus_P.m : Root-Locus design of P-controller
    - cart_RootLocus_PI.m : Root-Locus design of PI-controller
    - LQR_modeling.m : All calculations for State-Space Control w/LQR
        - config_ip02.m : Function used for LQR, calc/load parameters from Quanser
- **Simulink** : Models run on the lab computer, <u>*must use MATLAB R2022b or older!*</u>

## Demo
A small demo video is given in the root folder under: ***"SIP.mov"***