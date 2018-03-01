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
    
        ofTrueTypeFont myFont;
        ofxJSONElement json;
    
    int day = 0;
    string summaryText;
    string highTemperature;
    
    float circleX;
    
    int sunriseTime;
    int sunsetTime;
    int currentTime;
    
    ofColor yellow = ofColor(255,255,0);
    ofColor black = ofColor(0,0,0);
    
    int toSecond(int _time);
    
};
