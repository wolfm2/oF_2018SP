#pragma once

#include "place.h"
#include "ofxJSON.h"
#include "ofMain.h"
#include <algorithm>


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

		ofTrueTypeFont font;
		ofxJSONElement json;
		vector<place> placeList;
		bool changed = false;
		ofSoundPlayer sound;
		bool soundState = false;
    
    ofImage map;
    ofImage car;
    
    ofPolyline line;
    
};
