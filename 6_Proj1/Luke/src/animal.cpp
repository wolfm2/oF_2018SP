#include "animal.h"

animal::animal()
{
}

void animal::setup(int xIn, int yIn, float rotIn)
{
    pos.set(xIn, yIn);
    orig.set(xIn, yIn);
    dst.set(xIn, yIn);
    rot = rotIn;

    ofSetCircleResolution(1000);

    leftEar.setColor(color);
    leftEar.setCircleResolution(1000);
    rightEar.setColor(color);
    rightEar.setCircleResolution(1000);
}

void animal::update(float rotIn)
{
    rot = rotIn;

    leftEar.setColor(earColor);
    leftEar.clear();
    leftEar.triangle(ofPoint(drawRadius + 10, 0), ofPoint(drawRadius * cos(30 * DEG_TO_RAD), drawRadius * sin(30 * DEG_TO_RAD)), ofPoint(drawRadius * cos(-30 * DEG_TO_RAD), drawRadius * sin(-30 * DEG_TO_RAD)));
    leftEar.close();
    leftEar.rotate(rot + 90 - 30, ofVec3f(0, 0, 1));
    leftEar.translate(pos);

    rightEar.setColor(earColor);
    rightEar.clear();
    rightEar.triangle(ofPoint(drawRadius + 10, 0), ofPoint(drawRadius * cos(30 * DEG_TO_RAD), drawRadius * sin(30 * DEG_TO_RAD)), ofPoint(drawRadius * cos(-30 * DEG_TO_RAD), drawRadius * sin(-30 * DEG_TO_RAD)));
    rightEar.close();
    rightEar.rotate(rot + 90 + 30, ofVec3f(0, 0, 1));
    rightEar.translate(pos);
}

void animal::draw()
{
    leftEar.draw();
    rightEar.draw();

    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, drawRadius);
}

ofPoint animal::getPos()
{
    return pos;
}