#pragma once

#include "ofMain.h"

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
    
    ofVec2f mode1, mode2;
    
    ofSerial serial;
    
    ofFbo fbo;
    
    ofColor pink;
    ofColor violet;
    ofColor rblue;
    ofColor sblue;
    ofColor kgreen;
    ofColor lgreen;
    ofColor yellow;
    ofColor orange;
    ofColor oranger;
    ofColor red;
    ofColor rRed;
    
    
    ofColor grey;
    ofColor dRed;
    
    
    ofSoundPlayer bgm;
    
    int pulsetime;
    float sTime;
    int value;
    int R;
    
    bool boom = true;

		
};
