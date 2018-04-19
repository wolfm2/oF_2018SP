//
//  Line.hpp
//  waveLines
//
//  Created by yuemei on 4/19/18.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include <ofMain.h>

class Line{
public:
    void setup();
    void update();
    void draw();
    
private:
    ofFbo fbo;
    ofColor color;
    
    float rotateX;
    float rotateY;
    float rotateZ;
    
    float transX;
    float transY;
    
    float waveX;
    float waveY;
    
    float time;
    
};


#endif /* Line_hpp */
