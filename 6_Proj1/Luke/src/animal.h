#pragma once

#include "ofMain.h"

class animal : public ofBaseApp
{
  public:
	ofPoint pos;
	ofPoint orig;
	ofPoint dst;
	int drawRadius = 25;
	int moveRadius = 50;
	float rot;

	ofColor color;
	ofColor earColor;
	ofColor tailColor;

	ofPath leftEar;
	ofPath rightEar;
	ofPath tail;

	animal();
	void setup(int xIn, int yIn, float rotIn);
	void update(float rotIn);
	void draw();
	ofPoint getPos();
};