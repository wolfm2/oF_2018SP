//
//  Rectangle.hpp
//  wk09
//
//  Created by Zhong Yuxin on 4/5/18.
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
    int a;
    
};



#endif /* Rectangle_hpp */
