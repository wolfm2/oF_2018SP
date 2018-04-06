//
//  rectZeno.cpp
//  rectangleZeno_noobj
//
//  Created by 江旻哲 on 4/5/18.
//

#include "rectZeno.hpp"

rectZeno::rectZeno(){
    rect_pos.x=ofRandom(0, ofGetWidth());
    rect_pos.y=ofRandom(0, ofGetHeight());
    dim=ofRandom(20,50);
    setCUSpeed();
    setColor();
}

void rectZeno::setCUSpeed(){
    catchUpSpeed=ofRandom(0,0.1);
}

void rectZeno::setColor(){
    ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
}

void rectZeno::update(){
    rect_pos.x +=catchUpSpeed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += catchUpSpeed * (ofGetMouseY() - rect_pos.y);
}

void rectZeno::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(rect_pos.x, rect_pos.y, dim, dim);
}
