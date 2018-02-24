#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;  // speed with which we pursue the mouse
ofPoint rect_pos;
ofPoint updateDistance;
ofPoint initialDistance;
ofPoint unit;
float speed;
int maxspeed = 1;
int maxspeed2 = 0.1;
//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);

	rect_pos.x = 0;
	rect_pos.y = 0;

	
}

void getInitialDistance() {
	initialDistance.x = updateDistance.x;
	initialDistance.y = updateDistance.y;
}
void easeInVersionOne() {

	if (updateDistance.x <= 10 && updateDistance.y <= 10) {
		rect_pos.x += unit.x*maxspeed * 10;
		rect_pos.y += unit.y*maxspeed * 10;
		if (updateDistance.x <= 1 && updateDistance.y <= 1) {
			rect_pos.x = 0;
			rect_pos.y = 0;
		}


	}
	else {

		unit.x = updateDistance.x/abs(updateDistance.x)*sqrt((updateDistance.x)*(updateDistance.x) / ((updateDistance.x)*(updateDistance.x) + (updateDistance.y)*(updateDistance.y)));
		unit.y = updateDistance.y / abs(updateDistance.y)*sqrt((updateDistance.y)*(updateDistance.y) / ((updateDistance.x)*(updateDistance.x) + (updateDistance.y)*(updateDistance.y)));

		speed = ofGetWidth() / abs(updateDistance.x);

		rect_pos.x += unit.x*maxspeed*speed;
		rect_pos.y += unit.y*maxspeed*speed;

	}

}
void easeInVersionTwo() {
	if (updateDistance.x <= 1 && updateDistance.y <= 1) {
		rect_pos.x = 0;
		rect_pos.y = 0;
		getInitialDistance();

	}
	else {
		rect_pos.x += maxspeed2*(initialDistance.x - updateDistance.x+0.1)*updateDistance.x/abs(updateDistance.x);
		rect_pos.y += maxspeed2*(initialDistance.y - updateDistance.y+0.1)*updateDistance.y / abs(updateDistance.y);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	
	//***************ease in
	updateDistance.x = mouseX - rect_pos.x;
	updateDistance.y = mouseY - rect_pos.y;

	cout << updateDistance.x;
	easeInVersionOne();
	//easeInVersionTwo();


	// **************ease out
	//rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x); 
	//rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);
}






//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
}
