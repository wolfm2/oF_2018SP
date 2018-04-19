#pragma once

#include "ofMain.h"
#include "ofxLiquidFun.h"

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

    
    ofImage bottle01;
    ofImage bottle02;
    ofImage bottles;
    ofImage table;
    ofImage fire;

	ofTrueTypeFont myfont;
    
    ofSoundPlayer fireSound;
    ofSoundPlayer waterSound;
    ofSoundPlayer beakerSound;
    ofSoundPlayer glassSound;

	ofxBox2d box2d;
	ofxBox2dParticleSystem particles;

	ofPolyline beakerLine;
	ofPolyline roundFlaskLine;
	ofPolyline burnerLine;
	ofPolyline erlenmeyerFlaskLine;

	ofxBox2dEdge beaker;
	ofxBox2dEdge roundFlask;
	ofxBox2dEdge burner;
	ofxBox2dEdge erlenmeyerFlask;
};
