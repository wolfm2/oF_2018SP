#pragma once

#include "ofMain.h"
//#include "ofxLeapMotion2.h"



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
    
//
          ofImage image1;
          ofImage boat;
        float posX, posY, posX2, posY2,posX3, posY3;
        float speedX, speedX2, speedY, speedY2, speedX3, speedY3;
    
   
        float boatX1, boatY1, boatX2, boatY2;
        int curScore;
    
         ofTrueTypeFont myfont;
    
    
        
//        ofVec2f V1(100,100);
//
};
