#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

class ofApp : public ofSimpleApp{

	public:

		void setup();//
		void update();//
    void draw();//自带，不能删
    
    float maxspeed = 1000 ;
};

#endif
