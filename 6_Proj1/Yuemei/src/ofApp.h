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
    

    int mouseX = 0;
    int mouseY = 0;
    float catchUpSpeed = 0.001f;
    ofPoint reactPos;
//
//    ofFbo fbo;
    
    bool bShape1Act = false;
    bool bShape2Act = false;
    bool bShape3Act = false;
//    bool fboAct = false;
    float posx,posy;
    
    ofSoundPlayer mySound;
    ofColor normal = ofColor(247, 194, 66);
    ofColor cShape1Act = ofColor(247, 143, 56);
    ofColor cShape3Act = ofColor(255, 255, 255);
    
    ofColor orange = ofColor(247, 92, 47);
    ofColor blue = ofColor(86, 108, 115);
    ofColor green = ofColor(144, 180, 75);
    
    
};
