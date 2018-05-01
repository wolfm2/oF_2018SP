#pragma once

#include "ofMain.h"

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
		
};

class line{
public:
    line();
    void setup();
    void update();
    void draw();
    ofPoint location;
    
private:
    ofFbo fbo;
    ofColor color;
    
    float rotateX;
    float rotateY;
    float rotateZ;
    
    float moveX;
    float moveY;
    float moveZ;
    
    float a,b,c;
    
    float weight;
    float scale;
    float time;
    
};
