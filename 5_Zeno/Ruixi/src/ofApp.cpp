#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;
ofPoint rect_pos;

float maxSpeed = 0.04f;

//--------------------------------------------------------------
void ofApp::setup(){
   
    ofSetVerticalSync(true);
    
   
    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //    rect_pos.x += maxSpeed - rect_catchUpSpeed * (mouseX - rect_pos.x);
    //    rect_pos.y += maxSpeed - rect_catchUpSpeed * (mouseY - rect_pos.y);
    
    
    rect_pos.x +=   maxSpeed * (mouseX - rect_pos.x);
    rect_pos.y +=   maxSpeed * (mouseY - rect_pos.y);
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofDrawRectangle(rect_pos.x,rect_pos.y, 20,20);
    
    
    ofSetColor(200,150, 80);
    ofRect(rect_pos.x+ofRandom(20), rect_pos.y+ofRandom(20), 20, 20);
}
