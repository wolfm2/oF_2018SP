#include "ofApp.h"
#include "ofMain.h"

rectangle r1;
rectangle r2;
rectangle r3;
rectangle r4;
rectangle r5;

rectangle::rectangle(){
    rect_pos.x=ofRandom(10, 800);
    rect_pos.y=ofRandom(10, 800);
}

void rectangle::setCUSpeed(){
//    rect_cUSpeed = ofRandom(0,1);
    rect_cUSpeed = 0.01f;
}

void rectangle::setColor(){
    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void rectangle::update(){
    setCUSpeed();
    rect_pos.x += rect_cUSpeed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += rect_cUSpeed * (ofGetMouseY() - rect_pos.y);
}

void rectangle::draw(){
//    ofFill();
    setColor();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofRect(rect_pos.x,rect_pos.y, 20,20);
}
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1200,1200);
    // macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);

}

//--------------------------------------------------------------
void ofApp::update(){
r1.update();
r2.update();
r3.update();
r4.update();
r5.update();
   
}

//--------------------------------------------------------------
void ofApp::draw(){
r1.draw();
r2.draw();
r3.draw();
r4.draw();
r5.draw();
}
