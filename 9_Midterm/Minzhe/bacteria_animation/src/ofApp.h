#pragma once

#include "ofMain.h"
#include "particle.hpp"
#include "ofx3DFont.h"
#include "ofxTrueTypeFontUL2.h"

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
		
    vector <particle> particles;
    ofTrueTypeFont font;
    ofSerial mySerial;
    
    wstring show;
    int align;
    string strAlign;
    string strDirection;
    bool renderingMode;
    bool bRotation;
    
    ofx3DFont face;
    ofx3DFont faceNavi3d;
    ofLight light;
    
    ofSoundPlayer flute, triangle;
    ofImage bk;
};
