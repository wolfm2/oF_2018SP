# Citizen Scientist
In this project, I am developing an interactive user interface in the domain of STEM education that helps users build up their confidence in exploring science at home lab.   

## Overview:
Instruction: Use number key 1-8 to go to each step and use mouse to interact!
You can press keys to see each step of making bio-plastic. I'm using two addons here : openCV, LiquidFun, Easing to create the main interactions.

## Attribution:

None.  All submitted code was written by me.


## Technical part
I used the adafruit circuit playground to control the vibration motor and neopixels, using flora bluefruit module to connect with OF wirelessly.

## The requirements I fulfilled
* Matrix  ofApp.cpp:209, 214
* Nonlinear movement: ofApp.cpp: 224, 232, etc.
* Sound ofApp.cpp:334, 353, etc.
* Perlin: ofApp.cpp:258

## Extra Work:

* I filtered noise of color recognition by using centroid and a if statement. ofApp.cpp: 128-131
* Something new to me
    * OpenCv :  ofApp.cpp:73-83
    * LiquidFun :  ofApp.cpp:16-23, 307-310, etc.
    * Bluetooth :  ofApp.cpp:37, 270, 305, etc.
* Electronics:
    ![alt text](https://github.com/wolfm2/oF_2018SP/blob/master/9_Midterm/Minzhe/circuit_playground.jpeg)

## Questions/Comments:
I used the centroid idea you mentioned to me to get the pixel color of that center point. However, it's still very unstable. I tried different ways to make the color recognition more stable by filtering the noise of the color ofApp.cpp:130. Please let me know if you have a better solution for this.

## Author

 **Minzhe Jiang** 











