#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;  // speed with which we pursue the mouse
ofPoint rect_pos; //ofPoint is a vector
ofPoint rect2_pos;
float rect2_catchUpSpeed = 0.015f;

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

  //  rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x);
   // rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);
    
    rect_pos.x = rect_catchUpSpeed * mouseX + (1-rect_catchUpSpeed) * rect_pos.x;
    rect_pos.y = rect_catchUpSpeed * mouseY + (1-rect_catchUpSpeed) * rect_pos.y;
    
    rect2_pos.x += rect2_catchUpSpeed * (mouseX - rect2_pos.x);
    rect2_pos.y += rect2_catchUpSpeed * (mouseY - rect2_pos.y);
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(100, 100, 160);
    
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
   
    
    
    ofSetColor(234, 124, 144);
    ofDrawCircle(mouseX, mouseY, 20); //This makes the circle follow the mouse
    

}


