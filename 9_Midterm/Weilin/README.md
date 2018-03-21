#Translation/Overview:

This is a audio visualization project with Arduino. The dacing stars are moving around spontaneously with the sound file.

Arduino interaction:
*Potentiometer: turn around the knob to adjust the volume from 0 - 1
*Ultrasonic distance sensor: the size of the dacing stars is changing with the distance. (When you get close, the size will be bigger, and vise versa.)

Key events in this program:
'f' for toggle fullscreen
'z' for showing and hiding gui panel


#Attribution:
I used the code example from book "Mastering openFrameworks" 06-Sound/06-DancingCloud
The link of the example: https://masteringof.wordpress.com/examples/sounds/
All codes are tybed along with the book example.

Other submitted code was written by me.


#Requirements: 

*Sound
I loaded a sound and loop it as background music.
ofApp.h: 26
ofApp.cpp: 38, 39, 40, 140

*4 of (Movement, Easing, Shape changing, Alpha Channels, Matrix, FBO)
1. Movement
This project analyzes music spectrum and use this data for controlling the radius and shuffle of the stars.
I used some noise to control the movement of the stars.
ofApp.h:26
ofApp.cpp:11, 12, 13, 46, 47, 48

2. Alpha Channels
The alpha of dancing clouds is controlled by distance sensor.
ofApp.h: 33, 34
ofApp.cpp: 67, 72, 148
The alpha of title and spectrum are controlled by gui float sliders.
ofApp.h: 44, 45
ofApp.cpp: 120, 128, 130

3. Matrix
I used pushMatrix to move the coordinate system to the center of the screen to draw the dancing stars and popMatrix to restore the coordinate system.
ofApp.cpp: 144, 155

4. FBO
I used fbo to draw the tails of the stars movement.
ofApp.h: 41
ofApp.cpp: 23, 24, 25, 26, 135, 156, 159


*Drawing (images and/or shapes)
Shapes: spectrum rectangle shapes
ofApp.cpp: 132

Images: stars.png
ofApp.h: 25
ofApp.cpp: 34, 151

*Fonts & Writing (a title screen at least)
ofApp.h: 40
ofApp.cpp: 29, 121

*An ofxAddon not covered in class  (Arduino, Graphical effects, Device Drivers)
I used ofxGui to control the alpha channel of title and spectrum
ofApp.h: 43, 44, 45, 47
ofApp.cpp: 18, 19, 20, 21, 161

*A Web API -or- non-superficial Arduino usage 
I used serial communication with Arduino and one potentiometer and two sensors.
Potentiometer: control sound volume
Photocell sensor: control the alpha of dancing stars (it's a night time project only can be seen when in a darker environment)
Ultrasonic distance sensor: control the size of the dancing stars (When you get close, the size will be bigger, and vise versa.)
ofApp.h: 29, 30
ofApp.cpp: 36, 59-77

*Interaction
For controller: two gui float slider
For user: two arduino sensors

*A presentation
https://docs.google.com/presentation/d/17cuSvWOcud_xGfhEJcJcynkcl-pOI5P-XMiRqK_uC6I/edit?usp=sharing



#Extra Work:

I used ofVideoPlayer as background video.
ofApp.h: 24
ofApp.cpp: 31, 32, 56, 117, 118, 137, 138

I used two keys to toggle fullscreen and show/hide gui panel.
ofApp.h: 47
ofApp.cpp: 167 - 175

I used map functions to map the data I received from Arduino to the value I need to use.
ofApp.h: 33 - 38
ofApp.cpp: 72 - 74


#Questions/Comments:

I didn't know which way was better for Arduino and openFrameworks communication when I have multiple inputs, so I solved the problem using ofSerial communication and create an array for multiple incoming data.  Which is better and why?

I used to have problem with the video and I solved it by adding a setColor function before video.draw().

I used ofRamdom function to set the color of dancing stars but I don't know how to change the color of individual star.

For further steps, I want to know how to create a 3D effect of the dancing stars?

How to smooth the edges of texts?

I can't load my data folder to the github because the size exceeds the github limit. Here is the link of my data files https://drive.google.com/open?id=1IUukM9E0jb-RwppBkZCQvq21L_JEZDAy. '
