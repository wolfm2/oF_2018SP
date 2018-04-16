//
//  Rectangle.hpp
//  zeno advanced
//
//  Created by Yao Huang on 4/8/18.
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
    
    float mousex;
    float mousey;
    float catchUpSpeed;
    int radius;
};

#endif /* Rectangle_hpp */
