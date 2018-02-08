#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetBackgroundColor(255, 255, 255);

	ofSetColor(0, 0, 0);
	ofDrawBezier(0, 0, ofGetWindowWidth() / 12, 0, ofGetWindowWidth() / 12, ofGetWindowHeight() / 12, 0, ofGetWindowHeight() / 12);

	ofSetColor(255, 0, 0);
	ofDrawBitmapString("TEST", ofGetWindowWidth() / 6, ofGetWindowHeight() / 12);

	ofSetColor(0, 255, 0);
	ofDrawCircle(ofGetWindowWidth() / 2, ofGetWindowHeight() / 6, 100);

	ofSetColor(0, 0, 255);
	ofDrawCurve(0, ofGetWindowHeight() / 2, ofGetWindowWidth() / 3, ofGetWindowHeight() / 2, ofGetWindowWidth() / 3, ofGetWindowHeight(), 0, ofGetWindowHeight());

	ofSetColor(255, 255, 0);
	ofDrawEllipse(ofGetWindowWidth() / 2, ofGetWindowHeight() / 1.5, 100, 50);

	ofSetColor(0, 255, 255);
	ofDrawLine(ofGetWindowWidth() / 1.5, ofGetWindowHeight() / 1.5, ofGetWindowWidth(), ofGetWindowHeight());
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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
