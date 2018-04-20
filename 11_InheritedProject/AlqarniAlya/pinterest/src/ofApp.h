#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "buttons.hpp"

class ofApp : public ofBaseApp{
    

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);


    
    ofxJSONElement json;
    ofTrueTypeFont myFont;
    ofImage image;
    ofImage pinimage;
    ofImage stone;
    ofFbo fbo;
    
    ofImage sunset;
    ofImage cave;
    
    string Location;
    string DominantColor;
    int MostPopular = 0;
    string Address;
    string Description;
    int Num = 0;
    int count = 0;
    int first = 0;
    int second = 0;
    
    
    void onMouseInCircle(ofVec2f & e);
    void onMouseInAnyCircle(ofVec2f & e);
    myButtons mostPopular;
//    MyButton grayCircles [TOTAL_GRAY_CIRCLES];
    ofColor bg;
    ofVec2f clickedPoint;
};
