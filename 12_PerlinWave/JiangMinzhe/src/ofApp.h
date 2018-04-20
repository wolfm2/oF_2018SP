#pragma once

#include "ofMain.h"
#include "wave.hpp"
/*
 Phase 1
 You can not change the line endpoint values.
 You will use ofRotateXYZ and ofTranslate.
 Phase 2
 Reorganize your code to create a wave object.
 Use ofFbo for a fading effect.
 Adjust the Perlin noise ofMap so it allows a wave to move off the screen in every direction.  (by a healthy margin)
 Create a vector object of type wave object.
 Keep 5 waves of different colors on the screen at the same time.
 When one goes off screen, restart it under the mouse.
 Give each of the 5 different "personalities" expressed through color, shape and/or movement.
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
    
    vector<wave> waves;
};
