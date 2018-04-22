//
//  Line.cpp
//  waveLines
//
//  Created by yuemei on 4/19/18.
//

#include "Line.hpp"

void Line::setup(){
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo.begin();
    ofClear(255, 255, 255, 0);
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    fbo.end();
    
    ofSetFrameRate(10);
    
};

void  Line::update(){
    
    time = ofGetElapsedTimef();
    rotateX = - ofSignedNoise(time*ofRandom(0.01,0.03))*180;
    rotateY = -ofSignedNoise(time*0.02, time*0.07)*180;
    rotateZ = -ofSignedNoise(time*0.03, time*0.05, time*0.04)*180;
    
    
    transX += sin(waveX)*20 + ofNoise(time * 0.05)*5;
    transY += cos(waveY)*20 + ofNoise(time * 0.08, time)*3;
    
    waveX += 0.03;
    waveY += 0.05;
    
    cout<<transX<<", "<<transY<<endl;
    
};

void Line::draw(){
    
    fbo.begin();
    ofSetColor(0,1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    
    ofPushMatrix();
    ofSetColor(color,1);
    ofRotateX(rotateX);
    ofRotateY(rotateY);
    ofRotateZ(rotateZ);
    ofTranslate(transX, transY);
    ofDrawLine(-20, 0, 20, 0);
    ofPopMatrix();
    fbo.end();
    
    ofSetColor(255, 255, 255);
    fbo.draw(0,0);
    
};

