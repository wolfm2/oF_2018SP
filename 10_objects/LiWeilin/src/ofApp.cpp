#include "ofApp.h"
#include "ofMain.h"

Rectangle rects[5];

//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
    ofSeedRandom();
    for(int i = 0; i <= 5; i++){
        rects[i].setup();
    }

}

//--------------------------------------------------------------
void ofApp::update(){

    for(int i = 0; i <= 5; i++){
        rects[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i <= 5; i++){
        rects[i].draw();
    }
}
