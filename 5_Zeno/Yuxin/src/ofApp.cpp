#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;  // speed with which we pursue the mouse
ofPoint rect_pos;
//ofPoint rect1_pos;
float maxSpeed = 0.1f;

//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);

}

//--------------------------------------------------------------
void ofApp::update(){


    
    rect_pos.x +=   maxSpeed * (mouseX - rect_pos.x);
    rect_pos.y +=   maxSpeed * (mouseY - rect_pos.y);
    
    
//    rect_pos.x += maxSpeed - rect_catchUpSpeed * (mouseX - rect_pos.x);
//    rect_pos.y += maxSpeed - rect_catchUpSpeed * (mouseY - rect_pos.y);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
//    ofSetColor(255,0,0);
//    ofRect(rect1_pos.x, rect1_pos.y, 20, 20);
}
