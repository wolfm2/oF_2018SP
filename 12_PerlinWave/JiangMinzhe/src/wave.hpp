//
//  wave.hpp
//  perlinnoise_hw3
//
//  Created by 江旻哲 on 4/19/18.
//

#ifndef wave_hpp
#define wave_hpp


#include <stdio.h>
#include "ofMain.h"

class wave{
    float time;
    float rx, ry, rz;
    float tx, ty;
    float x, y;
    
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
