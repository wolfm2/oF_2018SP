#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
//#include "ofxJSONElement.h"
#include <iostream>
#include <string>



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
        bool jsonSuccessful; 
   
    
        float skyColorMix;
        int dayNum;
        int fontSize;
    
    int sun;
    int sunColor;
    float sunLocationX;
    float sunRise;
    float sunSet;
    float currentTime;
    float fontX;
    float lerpBB;
    
    
        string summaryText;
        string highTemperature;

    
  
    

   

		
};
