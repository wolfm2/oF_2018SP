#ifndef wave_hpp
#define wave_hpp


#include <stdio.h>
#include "ofMain.h"

class wave{
private:
    float time;
    float rx, ry, rz;
    float tx, ty, tz;
    float x, y, z;

    
    ofColor color;
    ofFbo fbo;
    
public:
    wave(float a, float b);
    void setup();
    void update();
    void draw();
    ofPoint vec;
    
};

#endif /* wave_hpp */
