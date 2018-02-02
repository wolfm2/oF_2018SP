#include "ofApp.h"

float mouseCY;
float mouseCX;
float rectWi;
float rectHei;
float mouseX;
float mouseY;






//--------------------------------------------------------------
void ofApp::setup(){
	

	ofBackground(255,255,255);
	ofSetWindowShape(1500, 1500);

	
}

//--------------------------------------------------------------
void ofApp::update(){
	rectWi = abs(mouseCX - ofGetWidth()/2);
	rectHei = abs(mouseCY - ofGetHeight()/2);
	ofLog() << mouseCX;
	ofLog() << rectWi;
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//ofDrawBitmapString("Homage to Josef Albers", 500, 300);
	ofDrawRectangle(ofGetWidth() / 2 - rectWi, ofGetHeight() / 2 - rectHei, 2* rectWi, 2*rectHei);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	mouseCX = ofGetMouseX();
	mouseCY = ofGetMouseY();
	ofSetColor(ofRandom(100),ofRandom(100),ofRandom(255));

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	mouseX = ofGetMouseX();
	mouseY = ofGetMouseY();


}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
