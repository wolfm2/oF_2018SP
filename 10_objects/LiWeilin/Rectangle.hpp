//
//  Rectangle.hpp
//  objects
//
//  Created by Weilin on 4/6/18.
//
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <ofMain.h>

class Rectangle{
    
    public:
    void setup();
    void update();
    void draw();
    
    private:
    
    ofPoint rect_pos;
    ofColor color;
    
    float mouseX;
    float mouseY;
    float CatchUpSpeed;
    int radius;
};

#endif /* Rectangle_hpp */
