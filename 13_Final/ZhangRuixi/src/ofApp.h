#pragma once

#include "ofMain.h"
#include "star.hpp"

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
    
    
    
    vector<star> stars;
    ofSoundPlayer   soundPlayer;
    int nBandsToGet;
    

    ofImage clock01;
    ofImage clock02;
    ofImage clock03;
    ofImage clock04;
    //rotate
    float rX = 0;
    float rY = 0;
    float rZ = 0;
		
};
