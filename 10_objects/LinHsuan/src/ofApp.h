#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

class ofApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();
};

#endif

class rectZeno {
    
    float rect_catchUpSpeed;
    //ofPoint rect_pos;
    int x_pos, y_pos;
    float red, green, blue;
    
    
public:
    
    rectZeno();
    void update(float, float);
    void draw();
    
};














