//
//  Rectangle.hpp
//  class
//
//  Created by yuemei on 4/5/18.
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
    ofColor color;
    
    ofPoint rect_pos;
 
    int radius;
    float mouseX;
    float mouseY;
    float speed;
  
};

#endif /* Rectangle_hpp */
