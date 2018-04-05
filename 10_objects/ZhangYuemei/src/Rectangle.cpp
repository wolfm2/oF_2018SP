//
//  Rectangle.cpp
//  class
//
//  Created by yuemei on 4/5/18.
//

#include "Rectangle.hpp"


void Rectangle::setup(){
    rect_pos.x = ofRandom(0, ofGetWidth());
    rect_pos.y = ofRandom(0, ofGetHeight());
    speed = ofRandom(0, 0.1f);
    color.set(ofRandom(255), ofRandom(255),ofRandom(255));
    radius = 20;
    
};

void Rectangle::update(){
    rect_pos.x += speed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += speed * (ofGetMouseY() - rect_pos.y);
};

void Rectangle::draw(){
    ofSetColor(color);
    ofRect(rect_pos.x, rect_pos.y, radius, radius);
    
};
