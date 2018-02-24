#include "dog.h"

dog::dog()
{
}

void dog::setup(int xIn, int yIn, float rotIn)
{
    animal::setup(xIn, yIn, rotIn);
    color = ofColor(135, 75, 0);
    earColor = ofColor(180, 100, 0);
}

void dog::update(ofPoint posIn, float rotIn)
{
    pos = posIn;
    animal::update(rotIn);
}

void dog::update(ofPoint posIn)
{
    pos = posIn;
    animal::update(rot);
}