#include "ofApp.h"


movingRect rect1;
movingRect rect2;

movingRect::movingRect() {
	setCUSpeed();
	setColor();
	rect_pos.x = ofRandom(0, 1200);
	rect_pos.y = ofRandom(0, 1200);
}

void movingRect::setCUSpeed() {
	rect_CUSpeed = ofRandom(0, 1);
}

void movingRect::setColor() {
	ofSetColor(int(ofRandom(0, 255)), int(ofRandom(0, 255)), int(ofRandom(0, 255)));
}
void movingRect::update() {
	rect_pos.x += rect_CUSpeed * (ofGetMouseX() - rect_pos.x);
	rect_pos.y += rect_CUSpeed * (ofGetMouseY() - rect_pos.y);
}

void movingRect::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
	ofRect(rect_pos.x, rect_pos.y, 20, 20);
}
//--------------------------------------------------------------
void ofApp::setup() {
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	//ofSetVerticalSync(true);

	// set background: 
	ofSetWindowShape(1200, 1200);

	ofEnableAlphaBlending();
	ofBackground(30, 30, 30);

}

//--------------------------------------------------------------
void ofApp::update() {
	rect1.update();
	rect2.update();

}

//--------------------------------------------------------------
void ofApp::draw() {
	rect1.draw();
	rect2.draw();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
