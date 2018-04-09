#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "square.hpp"
#define  squareNum 5

class ofApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();
    
    
    Square mySquare[squareNum];
    
    
};

#endif
