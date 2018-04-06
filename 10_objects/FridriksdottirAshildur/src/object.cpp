//
//  object.cpp
//  homework_10
//
//  Created by Áshildur Friðriksdóttir on 05/04/2018.
//

#include "object.hpp"

void Object::setup(){
    rect_pos.x = ofRandom(0, ofGetWidth());
    rect_pos.y = ofRandom(0, ofGetHeight());
    speed = ofRandom(0, 0.1f);
    color.set(ofRandom(255), ofRandom(255),ofRandom(255));
    radius = 20;
    
};

void Object::update(){
    rect_pos.x += speed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += speed * (ofGetMouseY() - rect_pos.y);
};

void Object::draw(){
    ofSetColor(color);
    ofRect(rect_pos.x, rect_pos.y, radius, radius);
    
};
