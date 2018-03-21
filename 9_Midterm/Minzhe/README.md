# Human Microbiome
In this project, I am developing a wearable tech in the domain of data visualization that helps users have a better understanding of their health condition, which can also assist medical diagnosis.

## Overview:
All the instructions are on canvas.
There are key events: ofApp.cpp: 366
You can change the light, the temperature and sound volume to make the visual effect on the canvas change in speed, color and sound pitch. (using variable:sensorRead and ofSerial).

## Attribution:

None.  All submitted code was written by me.


## Technical part
I used the adafruit circuit playground to connect OF with serial port.
The three sensors I used to visualize the data is light, sound and temperature sensor. All of them are analog output.

## The requirements I fulfilled
* Matrix  ofApp.cpp:262
* Adafruit circuit playground: ofApp.cpp:63
![alt text](https://github.com/wolfm2/oF_2018SP/blob/master/9_Midterm/Minzhe/circuit_playground.jpeg)
* Alpha Channels: ofApp.cpp:117
* Shape changing ofApp.cpp:121
* Movement: ofApp.cpp:123
* Drawing (images and/or shapes) ofApp.cpp:73, 121
* Sound ofApp.cpp: 362
* Title ofApp.cpp: 114
* ofx3DFont: ofApp.cpp: 17 ofApp.h: 38
* Interaction ofApp.cpp: 350, 366

## Extra Work:

I change the raw data with noise into the linear data I want. ofApp.cpp: 62
I used some function that we didn't cover in class:
ofNoise: ofApp.cpp: 121
glPushMatrix glPopMatrix ofApp.cpp:83
ofBeginShape ofEndShape ofApp.cpp:180
Particle system ofApp.h: 27

## Questions/Comments:
I set the linewidth so that I  can change the stroke of these organic curves, but I don't know how to get rid of the sharp edge at the curving joints to make my curves smooth.

## Authors

* **Minzhe Jiang** 











