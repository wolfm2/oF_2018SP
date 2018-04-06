//
//  object.hpp
//  homework_10
//
//  Created by Áshildur Friðriksdóttir on 05/04/2018.
//

#ifndef object_hpp
#define object_hpp

#include <ofMain.h>

class Object{
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


#endif /* object_hpp */
