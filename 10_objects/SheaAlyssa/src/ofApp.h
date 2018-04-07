#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

class ofApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();
};

class rectangle {
    ofPoint rect_pos;
    float rect_cUSpeed;

    public:
    
        rectangle();
        void setCUSpeed();
        void setColor();
    
        void update();
        void draw();
 };

#endif
