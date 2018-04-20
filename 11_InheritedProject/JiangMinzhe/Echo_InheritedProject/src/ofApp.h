#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "agent.hpp"
#define MAX_AGENTS 100

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

		ofxJSONElement json_uv;
		ofxJSONElement json_car;
		ofxJSONElement json_fac;
		ofxJSONElement json_half;
		bool parsingSuccessful_time;
        ofShader shader;
    
        agent Agents[MAX_AGENTS];
		
};

