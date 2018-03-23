#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofImage feather;
    ofTrueTypeFont font;
    
    //float rX = 0;     //leaf
    //float rY = 0;
    //float rZ = 0;
    
    float featherX = 0;
    float featherY = 0;
    float featherZ = 0;
    
    
    float featherScaleH = 0;
    float featherScaleW = 0;
    
    float featherTranslateX = 0;
    float featherTranslateY = 0;
    

};
