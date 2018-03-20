#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include <iostream>
#include <string>
#include<iostream>
#include<ctime>
#include<time.h>
#include <stdio.h>
#include <stdlib.h>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
    ofTrueTypeFont overFont;
    ofTrueTypeFont winFont;
    
    ofxJSONElement json;
    string icon;
    
    ofSerial serial;
    
    ofSoundPlayer bgMusic;
    ofSoundPlayer winMusic;
    ofSoundPlayer loseMusic;
    ofSoundPlayer jumpMusic;
    ofSoundPlayer frogMusic;
    
    bool begin = false;
    bool gameOver = false;
    bool win = false;
    
    int offset;
    int value;
    int xPos;//character x position
    int yPos;
    int xCarPos;//carrot x position
    int yCarPos;
    int counter;
    
    ofImage backgroundImage;
    ofImage start;
    ofImage character;
    ofImage iconRain;
    ofImage iconSun;
    ofImage iconCloudy;
    
    ofVec2f Carrot[5];//x and y
    ofImage carrot[5];//images
    ofVec2f Mashroom[8];
    ofImage mashroom[8];
};
