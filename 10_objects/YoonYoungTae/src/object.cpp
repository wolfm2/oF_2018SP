//
//  object.cpp
//  object
//
//  Created by Young Tae Yoon on 4/6/18.
//

#include "object.hpp"

void Object::setup(){
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    rect_pos.x = ofRandom(0, ofGetWidth());
    rect_pos.y = ofRandom(0, ofGetHeight());
    speed = ofRandom(0.1);
    radius = 50;
    
};

void Object::update(){
    rect_pos.x += speed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += speed * (ofGetMouseY() - rect_pos.y);
};

void Object::draw(){
    ofSetColor(color);
    ofRect(rect_pos.x, rect_pos.y, radius, radius);
    
};
