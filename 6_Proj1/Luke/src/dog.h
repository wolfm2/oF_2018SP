#pragma once

#include "ofMain.h"
#include "animal.h"

class dog : public animal
{
  public:
    dog();
    void setup(int xIn, int yIn, float rotIn);
    void update(ofPoint posIn, float rotIn);
    void update(ofPoint posIn);
};