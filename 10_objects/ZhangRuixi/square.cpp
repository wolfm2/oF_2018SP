//
//  square.cpp
//  classwork_0330
//
//  Created by ruixi zhang on 2018/4/1.
//

#include "square.hpp"

void Square::setup(){
    ofSetBackgroundColor(0);
    
    rect_catchUpSpeed = ofRandom(0.001f, 0.1f);
    sizeOfSquare = ofRandom(0,40);

    rect_pos.x = ofRandom(0, ofGetWidth());
    rect_pos.y = ofRandom(0, ofGetHeight());
    
    color.set(ofRandom(100,255),40,ofRandom(100,255));
    
}


//-------------------------------------------------------------------
void Square::update(){
    
    
    rect_pos.x += rect_catchUpSpeed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += rect_catchUpSpeed * (ofGetMouseY() - rect_pos.y);
    
}

//-------------------------------------------------------------------
void Square::draw(){
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);                                         // center around the position
    ofSetColor(color);                     // set random color      Red and Blue
    ofRect(rect_pos.x,rect_pos.y,sizeOfSquare,sizeOfSquare);                   //set random size of the square
    
}

