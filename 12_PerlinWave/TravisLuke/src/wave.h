#pragma once

#include "ofMain.h"

class wave : public ofBaseApp
{
  public:
    wave();

    void setup();
    void update();
    void draw();

    ofVec3f pos;
    ofVec3f dir;
    ofVec3f axis;
    float rot;
    ofColor color;
    ofFbo fbo;
    int offset;
    float speed;
};