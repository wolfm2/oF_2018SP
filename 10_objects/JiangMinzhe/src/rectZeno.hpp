//
//  rectZeno.hpp
//  rectangleZeno_noobj
//
//  Created by 江旻哲 on 4/5/18.
//

#ifndef rectZeno_hpp
#define rectZeno_hpp

#include <stdio.h>
#include "ofMain.h"

class rectZeno {
    ofPoint rect_pos;
    float dim;
    float catchUpSpeed;
    void setCUSpeed();
    void setColor();
public:
    rectZeno();
    void update();
    void draw();
};

#endif /* rectZeno_hpp */
