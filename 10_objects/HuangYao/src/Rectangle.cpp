//
//  Rectangle.cpp
//  zeno advanced
//
//  Created by Yao Huang on 4/8/18.
//

#include "Rectangle.hpp"

void Rectangle::setup(){
    
    rect_pos.x = ofRandom(0,ofGetWidth());
    rect_pos.y = ofRandom(0,ofGetHeight());
    
    catchUpSpeed = ofRandom(0,0.04f);
    
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    
    radius = 30;
};

void Rectangle::update(){
    
    rect_pos.x += catchUpSpeed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += catchUpSpeed * (ofGetMouseY() - rect_pos.y);

};

void Rectangle::draw(){
    
    ofSetColor(color);
    ofDrawRectangle(rect_pos.x, rect_pos.y, radius, radius);
    
};
