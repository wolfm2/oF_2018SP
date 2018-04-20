//
//  wave.cpp
//  perlinnoise_hw3
//
//  Created by 江旻哲 on 4/19/18.
//

#include "wave.hpp"

wave::wave(float a, float b){
    x=a;
    y=b;
};

void wave::setup(){
    
    time = ofRandom(5);
    ofColor rColor=ofColor::cyan;
    ofColor lColor=ofColor::magenta;
    color=rColor.lerp(lColor, ofRandom(1));
    
    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    fbo.begin();
    ofClear(255, 255, 255,0);
    fbo.end();
    
    ofSetBackgroundColor(0, 0, 0);
}

void wave::update(){
    float t=time*ofGetElapsedTimef();
    
    rx=ofSignedNoise(t*0.01)*180;
    ry=ofSignedNoise(t*0.02)*180;
    rz=ofSignedNoise(t*0.03)*180;
    
    tx=sin(t*0.5)*15+ofSignedNoise(time*0.05)*3;
    ty=cos(t*0.6)*15+ofSignedNoise(time*0.06)*3;
    
    vec +=ofPoint(tx, ty);
}

void wave::draw(){
    fbo.begin();
    
    ofSetColor(0,1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofPushMatrix();
    ofTranslate(vec.x, vec.y);
    
    ofRotateX(rx);
    ofRotateY(ry);
    ofRotateZ(rz);
    
    ofSetColor(color);
    ofFill();
    
    ofDrawLine(x-20, y, x+20, y);
    ofPopMatrix();
    
    fbo.end();
    ofSetColor(255);
    fbo.draw(0,0);
}
