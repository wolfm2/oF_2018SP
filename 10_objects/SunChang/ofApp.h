#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

class ofApp : public ofSimpleApp{
    
public:
    
    void setup();
    void update();
    void draw();
};

class Zeno{
    float posX;
    float posY;
    float cuSpeed;
    float r;
    float g;
    float b;
    
//    int mX;
//    int mY;
    
public:
    
    Zeno();
    
    void update(float, float);
    void draw();
    
};











#endif         // endif是什么！？？




