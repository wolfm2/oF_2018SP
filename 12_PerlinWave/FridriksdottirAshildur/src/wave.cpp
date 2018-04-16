//
//  wave.cpp
//  Perlin_Noise_HW
//
//  Created by Áshildur Friðriksdóttir on 15/04/2018.
//

#include "wave.h"
#include "ofMain.h"



wave::wave(){

}

void wave::setup(){
    
    n = ofRandom(0.1,2);
    a = ofRandom(0.3,0.5);
    b = ofRandom(0.4,0.6);
    c = ofRandom(0.5,0.7);
    
    sWeight= ofRandom(1,1.5);
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    
    p1 = ofPoint(-40,0);
    p2 = ofPoint(40, 0);
    
    t = ofPoint(ofGetWidth()/3, ofGetHeight()/3, 0);
    
    ofSetVerticalSync(true);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
  

}


    


void wave::update(){
    
    
    time = ofGetElapsedTimef()*n;

  
    rX = ofSignedNoise(time * 0.5) * 180.0;  // rotate +- 400deg
    rY = ofSignedNoise(time * 0.3) * 180.0;
    rZ = ofSignedNoise(time * 0.9) * 180.0;


    float x = ofSignedNoise(time * a) * ofRandom(1, 50);
    float y = ofSignedNoise(time * b) * ofRandom(1, 50);
    float z = ofSignedNoise(time * c) * ofRandom(1, 50);

    scaleX= (1-ofNoise(time*0.2)) * sWeight;
    scaleY= (1-ofNoise(time*0.4)) * sWeight;
    scaleZ= (1-ofNoise(time*0.3)) * sWeight;

     t += ofPoint(x, y, z);
    
    
}


void wave::draw(){
    
    fbo.begin();
    ofSetColor(255,255,255,10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(color);
  
    ofPushMatrix();
        ofTranslate(t);
        ofScale(scaleX,scaleY,scaleZ);
        ofRotateX(rX);
        ofRotateY(rY);
        ofRotateZ(rZ);
    
    ofDrawLine(p1, p2);

    ofPopMatrix();
    
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(255,0);
   
    
}
