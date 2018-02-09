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
    
    int r;
    int x;
    int y;
    int R;
    int G;
    int B;
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    float x4;
    float y4;
    float w;
    float h;
    float x5;
    float y5;
    float r1;
    float r2;
};
