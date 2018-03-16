#pragma once

#include "ofMain.h"
#include "ofxJson.h"
#include <string>




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
    int sentence_id = 0;
    int posX = 0;
    float value = 0;

    string joys;
    bool joyful;
    int score = 0;
    bool small;
    
    string eventString;
    
    ofColor change;
    
        ofxJSONElement result;
//        ofxJSONElement json;
    
   
    
    


};

