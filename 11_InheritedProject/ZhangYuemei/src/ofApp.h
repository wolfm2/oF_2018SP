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
		
    ofxJSONElement json;
    ofSerial serial;
    
    int dayTime;
    int nightTime;
    int currentTime;
    
    int day = 0;
    
    int sizeW;
    int sizeH;

    
    ofImage backImage;
    ofImage sun;
    ofImage moon;
    
    ofSoundPlayer music;
    
    ofVec2f Star[60];
    ofImage star[60];
};
