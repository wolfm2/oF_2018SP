#include "ofApp.h"
#include "ofMain.h"

ofPoint rect_pos;
ofPoint mousePos;
ofPoint unitSpeed;
ofPoint speed;
float length;
float initialLength;
float rect_catchUpSpeed = 0.1;
float i = 0;


//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 

	ofSetVerticalSync(true);
	ofSetWindowShape(1500, 1500);
	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);

	rect_pos.x = ofGetWidth()/2;
	rect_pos.y = ofGetHeight()/2;

	mousePos.x = mouseX;
	mousePos.y = mouseY;
	initialLength = mousePos.distance(rect_pos);
}


void easeIn() {

	speed +=unitSpeed/1.8;

	rect_pos.x += speed.x;
	rect_pos.y += speed.y;



	//rect_pos += unitSpeed / length;
}

void easeOut() {
	rect_pos.x += rect_catchUpSpeed * (mousePos - rect_pos).x; 
	rect_pos.y += rect_catchUpSpeed * (mousePos - rect_pos).y;
}

//--------------------------------------------------------------
void ofApp::update() {
	mousePos.x = mouseX;
	mousePos.y = mouseY;
	length = mousePos.distance(rect_pos);
	unitSpeed = (mousePos - rect_pos).getNormalized();


	//***************ease in
	easeIn();
	
	// **************ease out
	//easeOut();
	
}






//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
}
