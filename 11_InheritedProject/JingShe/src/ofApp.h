#pragma once

#include "ofMain.h"
#include "demoParticle.h"
#include "ofxLeapMotion2.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void resetParticles();

		void keyPressed  (int key);
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
    
        ofPoint pos;
        ofPoint vel;
        ofPoint frc;
    
        float drag;
        float uniqueVal;
        float scale;
        float alpha;
    
        int num;
        int clickCount;
    
        ofImage image;
        ofImage rain;
        ofSoundPlayer bg;
		
		particleMode currentMode;
		string currentModeStr; 

		vector <demoParticle> p;
		vector <ofPoint> attractPoints;
		vector <ofPoint> attractPointsWithMovement;
    
        ofxLeapMotion leap;
        vector <ofxLeapMotionSimpleHand> simpleHands;
    
        vector <int> fingersFound;
        ofEasyCam cam;
		
};
