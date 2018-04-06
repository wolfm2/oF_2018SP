#pragma once

#include "ofMain.h"
#include "rectZeno.hpp"
#define NRECTS 5
/*
 Identify all the variables and functions required to make the square move.
 Write a class that encapsulates all the above variables, with an update and draw method in a class declaration.
 The class should include two other methods: setCUSpeed, and setColor.  Both should be called only once from the constructor.
 Make 5 objects of this class each initialized with a different catchUpSpeed and color.
 Each should start at a random x,y within the canvas.
 The ONLY globals should be your 5 objects.
 */

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
    rectZeno groupOfRects[NRECTS];
};
