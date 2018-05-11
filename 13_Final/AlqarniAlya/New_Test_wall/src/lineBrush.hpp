//
//  lineBrush.hpp
//  New_Test_wall
//
//  Created by a on 5/10/18.
//

#ifndef lineBrush_hpp
#define lineBrush_hpp

#pragma once
#include "ofMain.h"

#include <stdio.h>
// TYLER - simple Brush1 class:

class Brush1
{
public:
    
    void draw(ofVec3f pos);    // draw the brush shapes at a position
    
    ofEasyCam cam1;
    
};

#endif /* lineBrush_hpp */
