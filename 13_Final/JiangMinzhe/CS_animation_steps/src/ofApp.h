#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
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
    
    int wWidth, wHeight;
    int hue, sat, val;
    
    ofVideoGrabber wCam;
    
    ofxCvColorImage origOutput;
    ofxCvColorImage origOutputHSV;
    
    ofxCvGrayscaleImage hueOutput;
    ofxCvGrayscaleImage satOutput;
    ofxCvGrayscaleImage briOutput;
    
    ofxCvGrayscaleImage lockedOutput;
    ofxCvContourFinder lockedContours;
    
    unsigned char * lockedOnPixels;
    ofTexture lockedOnTexture;
    
    ofImage foam, gelatin, glycerin, light, mould, pigment, pot, soap, spoon, table, water, stove, drop, spoon2, mould2, wave, spoon3;
    
    ofTrueTypeFont font, font2;
    
    ofSerial myBluetooth;
    
    ofxBox2d box2d;
    vector <ofPtr<ofxBox2dRect>> boxes;
    ofxBox2dParticleSystem particles; // liquidFun particle system
    
    ofPolyline potLine;
    
    ofxBox2dEdge potEdge;
    
    ofSoundPlayer boiling, vibration, liquid;
};
