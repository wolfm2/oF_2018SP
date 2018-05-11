//
//  star.hpp
//  of_final
//
//  Created by ruixi zhang on 5/11/18.
//

#ifndef star_hpp
#define star_hpp

#include <stdio.h>
#include "ofMain.h"

class star{
    float time;
    float rx, ry, rz;
    float tx, ty;
    float x, y;
    
    ofColor color;
    ofFbo StarFbo;
    
public:
    star(float a, float b);
    void setup();
    void update();
    void draw();
    ofPoint vec;
    
 
    
    
};

#endif /* wave_hpp */

