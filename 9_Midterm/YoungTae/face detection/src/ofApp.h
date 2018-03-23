#pragma once
#include "ofMain.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
		void drawFacePoints();
		void drawFacePolygons();
	
		ofxOscReceiver receiver;
	
		bool found = false;
		vector<ofVec2f> points;
	
		int dots = 0;
    
    
    ofSoundPlayer Sound;
    ofSoundPlayer Sound1;
    ofSoundPlayer Sound2;
    ofSoundPlayer Sound3;
    ofImage piano;
};
