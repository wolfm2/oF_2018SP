#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;
ofPoint rect_pos;

float minDist = 0.0f;
float maxDist = 500.0f;

float minSpeed = 50.0f;
float maxSpeed = 1000.0f;

//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);
    ofSetFrameRate(60);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);

}

//--------------------------------------------------------------
void ofApp::update(){

    float xMod;
    float yMod;

    float xDiff = mouseX - rect_pos.x;
    float yDiff = mouseY - rect_pos.y;

    if (xDiff > 0) {
        xMod = ofMap(xDiff, minDist, maxDist, maxSpeed, minSpeed, 1);
    }
    else {
        xMod = ofMap(xDiff, -minDist, -maxDist, -maxSpeed, -minSpeed, 1);
    }

    if (yDiff > 0) {
        yMod = ofMap(yDiff, minDist, maxDist, maxSpeed, minSpeed, 1);
    }
    else {
        yMod = ofMap(yDiff, -minDist, -maxDist, -maxSpeed, -minSpeed, 1);
    }
     
    rect_pos.x += rect_catchUpSpeed * xMod;
    rect_pos.y += rect_catchUpSpeed * yMod;

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
}
