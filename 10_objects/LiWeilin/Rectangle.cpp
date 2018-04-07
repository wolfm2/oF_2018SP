//
//  Rectangle.cpp
//  objects
//
//  Created by Weilin on 4/6/18.
//
//

#include "Rectangle.hpp"

void Rectangle::setup(){
    rect_pos.x = ofRandom(0, ofGetWidth());
    rect_pos.y = ofRandom(0, ofGetHeight());
    CatchUpSpeed = ofRandom(0, 0.05f);
    color.set(ofRandom(255), ofRandom(255),ofRandom(255),ofRandom(200,255));
    radius = ofRandom(10, 20);
    
};

void Rectangle::update(){
    rect_pos.x += CatchUpSpeed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += CatchUpSpeed * (ofGetMouseY() - rect_pos.y);
};

void Rectangle::draw(){
    ofSetColor(color);
    ofDrawRectangle(rect_pos.x, rect_pos.y, radius, radius);
    
};
