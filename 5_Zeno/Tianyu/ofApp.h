#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

class ofApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();
    
    float maxSpeed = 1000;
    float targetX, targetY;
};

#endif
