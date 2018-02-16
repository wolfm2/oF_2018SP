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

    // float xMod = min((mouseX - rect_pos.x), maxSpeed) / maxSpeed;
    // float yMod = min((mouseY - rect_pos.y), maxSpeed) / maxSpeed;

    // float xMod = min(maxSpeed / (maxSpeed * (mouseX - rect_pos.x)), maxSpeed);
    // float yMod = min(maxSpeed / (maxSpeed * (mouseY - rect_pos.y)), maxSpeed);

    // float xMod = (mouseX - rect_pos.x) > 0 ? min(maxSpeed / (maxSpeed * (mouseX - rect_pos.x)), maxSpeed) : max(maxSpeed / (maxSpeed * (mouseX - rect_pos.x)), -maxSpeed);
    // float yMod = (mouseY - rect_pos.y) > 0 ? min(maxSpeed / (maxSpeed * (mouseY - rect_pos.y)), maxSpeed) : max(maxSpeed / (maxSpeed * (mouseY - rect_pos.y)), -maxSpeed);

    // if(!isinf(abs(xMod))) {
    //     if(xMod > (mouseX - rect_pos.x)) {
    //         rect_pos.x += (mouseX - rect_pos.x);
    //     }
    //     else {
    //         rect_pos.x += xMod;
    //     }
    // }

    // if(!isinf(abs(yMod))) {
    //     if(yMod > (mouseY - rect_pos.y)) {
    //         rect_pos.y += (mouseY - rect_pos.y);
    //     }
    //     else {
    //         rect_pos.y += yMod;
    //     }
    // }

    // rect_pos.x += !isinf(abs(xMod)) ? xMod : 0;
    // rect_pos.y += !isinf(abs(yMod)) ? yMod : 0;

    // rect_pos.x += rect_catchUpSpeed * xMod;
    // rect_pos.y += rect_catchUpSpeed * yMod;

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
