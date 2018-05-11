#pragma once

#include "ofMain.h"
#include "ofxSliderGroup.h"
#include "ofxGui.h"

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
    
    ofTrueTypeFont font;
    ofPolyline line1;
    ofPolyline line2;
    
    ofxPanel gui;
    ofxGuiGroup guiGroup;
    
    ofxIntSlider Red;
    ofxIntSlider Green;
    ofxIntSlider Blue;


    ofxFloatSlider floatSlider;
    ofxToggle toggle;
    
};
