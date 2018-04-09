//
//  square.hpp
//  classwork_0330
//
//  Created by ruixi zhang on 2018/4/8.
//

#ifndef square_hpp
#define square_hpp

#include "ofMain.h" 

class Square {
    
private:
    float sizeOfSquare;
    ofPoint rect_pos;
    ofColor rect_color;
    //    float mouseX;
    //    float mouseY;
    float rect_catchUpSpeed; // speed with which we pursue the mouse
    ofColor color;
    
public:
    void setup();
    void update();
    void draw();
    
    
    Square(){
        cout<<"Hi! sqare class"<<endl;
    }
    
};



#endif /* square_hpp */
