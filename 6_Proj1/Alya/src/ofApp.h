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
		
    ofSoundPlayer   mySound;
    
    ofImage a;
    ofImage b;
    ofImage c;
    ofImage d;
    ofImage e;
    ofImage f;
    ofImage g;
    ofImage h;
    ofImage i;
    ofImage j;
    ofImage k;
    ofImage l;
    ofImage m;
    ofImage n;
    ofImage o;
    ofImage p;
    
    ofFbo fbo;
    ofColor mousy;
    
      int imageflag= 0;

    
};
