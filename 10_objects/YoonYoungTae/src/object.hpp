//
//  object.hpp
//  object
//
//  Created by Young Tae Yoon on 4/6/18.
//

#ifndef object_hpp
#define object_hpp

#include <ofMain.h>

class Object {
public:
    void setup();
    void update();
    void draw();
    
    
private:
    ofColor color;
    ofPoint rect_pos;
    
    float mouseX;
    float mouseY;
    float speed;
    int radius;
    
};


#endif /* object_hpp */
