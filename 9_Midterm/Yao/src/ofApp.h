#pragma once

#include "ofMain.h"
#include "ofxPostGlitch.h"


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
    
    
    ofxPostGlitch postGlitch;
    ofFbo buffer;
    ofEasyCam camera;
    
    ofVideoGrabber video;
    ofVideoPlayer testMovie[4];

    
    ofSoundPlayer soundplayer;
    
    bool pressedKey = false;
    bool pressedKey2 = false;
    bool peessedKeyr = false;
    bool peessedKeyg = false;
    bool peessedKeyb = false;
    
    bool peessedKeyv = false;
    bool bDrawLenna;
    bool bShowHelp;
    
    ofTexture texture;
    ofImage glitch1;
    
    
    ofSerial serial;
    string buffer2;
    int radius;
    
  
    float glitchStart;
    
    //timer
    void reset();
    int startTime;
    int nowTime;
    int preTime;
    
    
    int stage = 0;
    float timer = 0;
    float stageLength = 5;

    ofVec3f p[144][90];
    int count[144][90];

    ofTrueTypeFont myFont;
		
};
