#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "Rectangle.hpp"

class ofApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();
    
    Rectangle rectangle;
};

#endif
