#pragma once

#include "ofMain.h"
#include "animal.h"

class cat : public animal
{
  public:
    bool isHiss = false;
    float hissCount = 5;
    int minSpeed = 25;
    int maxSpeed = 50;
    int newRadius;

    ofColor newColor;
    ofColor newEarColor;
    ofColor newTailColor;

    cat();
    void setup(int xIn, int yIn, float rotIn);
    void update();
    void easing();
    void hiss(bool state);
    void setDst(ofPoint vecIn);
};