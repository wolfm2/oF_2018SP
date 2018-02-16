#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;  // speed with which we pursue the mouse
ofPoint rect_pos;//square's x and y

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

     rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x);//速度0.01f*方向
     rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);//速度0.01f*方向
    
    if (rect_pos.x > ofGetWidth()){
    rect_pos.x = -rect_pos.x;
    rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);
    }
    if (rect_pos.y>ofGetHeight()){
        rect_pos.y=-rect_pos.y;
//        I tried but I don't know how to write the ease-in...
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
}
