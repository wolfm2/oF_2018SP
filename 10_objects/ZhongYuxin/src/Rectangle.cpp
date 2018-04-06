//
//  Rectangle.cpp
//  wk09
//
//  Created by Zhong Yuxin on 4/5/18.
//

#include "Rectangle.hpp"

void Rectangle::setup(){
    rect_pos.x = ofRandom(0,ofGetWidth());
    rect_pos.y = ofRandom(0, ofGetHeight());
    CatchUpSpeed = ofRandom(0,0.05f);
    color.set(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
    a = ofRandom(10,20);
};

void Rectangle::update(){
    rect_pos.x += CatchUpSpeed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += CatchUpSpeed * (ofGetMouseY() - rect_pos.y);
};

void Rectangle::draw(){
    ofSetColor(color);
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(rect_pos.x, rect_pos.y, a, a);
}
