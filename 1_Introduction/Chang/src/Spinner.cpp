//
//  Spinner.cpp
//  flow
//
//  Created by Jeffrey Crouse on 11/10/17.
//

#include "Spinner.hpp"

// -------------------------------------------------------
void Spinner::setup() {
    size.x = ofRandom(10, 50);
    size.y = ofRandom(20, 100);
    pos.x = ofRandom(640);
    pos.y = ofRandom(480);
    //color.setHsb(ofRandom(0, 255),(0,255),(0,255));
    ofColor(ofRandom(0, 255));
}

// -------------------------------------------------------
void Spinner::update() {
    rot += rotVel;
    rot *= 0.9;
}

// -------------------------------------------------------
void Spinner::draw() {
    
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateY(rot.x);
    //ofRotateX(rot.y);
    //ofTranslate(-size.x/2.0, -size.y/2.0);
    ofTranslate(-size.x, -size.y);
    
    ofSetColor(color,100);
    ofDrawRectangle(0, 0, size.x*1.5, size.y*1.5);
    ofPopMatrix();
}
