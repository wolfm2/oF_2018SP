#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.00001f;

//make a new variable
float rect_maxSpeed = 1;

// speed with which we pursue the mouse
ofPoint rect_pos; //vector: x and y is in this vector

//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);
    
    ofSetFrameRate(10);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x);
    rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);
    
    
    //when rect position is not equal to mouse position
    //then rect's speed increases exponentially until its speed equal to maxspeed
    if((rect_pos.x!=mouseX)&&(rect_pos.y!=mouseY)){
        if(rect_catchUpSpeed <= rect_maxSpeed){
            //power of two
            rect_catchUpSpeed  = rect_catchUpSpeed* 2;
            //cout <<rect_catchUpSpeed;
        
        }else{
            //when rect position is equal to mouse position
            //reset the rect's speed to the origin value
            rect_catchUpSpeed = 0.00001;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
}
