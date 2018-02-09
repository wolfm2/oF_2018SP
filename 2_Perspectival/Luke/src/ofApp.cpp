#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	width = float(ofGetWindowWidth());
	height = float(ofGetWindowHeight());
	
	cout << width << endl;
	cout << height << endl;

}

//--------------------------------------------------------------
void ofApp::update(){

	face.clear();
	leftEar.clear();
	rightEar.clear();

	face.moveTo(ofPoint(width*2/5, height*1/4));
	face.lineTo(ofPoint(width*1/3, height*7/16));
	face.lineTo(ofPoint(width*2/5, height*3/4));

	face.lineTo(ofPoint(width*3/5, height*3/4));
	face.lineTo(ofPoint(width*2/3, height*7/16));
	face.lineTo(ofPoint(width*3/5, height*1/4));
	
	face.close();
	face.setFilled(true);
	face.setColor(ofColor(100, 40, 0));

	leftEar.moveTo(ofPoint(width*2/5, height*1/4));
	leftEar.lineTo(ofPoint(width*1/5, height*1/2));
	leftEar.lineTo(ofPoint(width*3/10, height*3/4));
	leftEar.lineTo(ofPoint(width*3.5/10, height*3/4));
	
	leftEar.close();
	leftEar.setFilled(true);
	leftEar.setColor(ofColor(70, 25, 0));

	rightEar.moveTo(ofPoint(width*3/5, height*1/4));
	rightEar.lineTo(ofPoint(width*4/5, height*1/2));
	rightEar.lineTo(ofPoint(width*7/10, height*3/4));
	rightEar.lineTo(ofPoint(width*6.5/10, height*3/4));
	
	rightEar.close();
	rightEar.setFilled(true);
	rightEar.setColor(ofColor(70, 25, 0));

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//head
	leftEar.draw();
	rightEar.draw();
	face.draw();

	//eye patches
	ofSetColor(155, 62, 0);
	ofDrawTriangle(ofPoint(width*2/5, height*1/4), ofPoint(width*1/3, height*7/16), ofPoint(width*7/16,height*7/16));
	ofDrawTriangle(ofPoint(width*1/3, height*7/16), ofPoint((width*2/5+width*1/3)/2+1, height*3/5), ofPoint(width*7/16,height*7/16));

	ofDrawTriangle(ofPoint(width*3/5, height*1/4), ofPoint(width*2/3, height*7/16), ofPoint(width*9/16,height*7/16));
	ofDrawTriangle(ofPoint(width*2/3, height*7/16), ofPoint((width*3/5+width*2/3)/2-1, height*3/5), ofPoint(width*9/16,height*7/16));

	//muzzle
	ofSetColor(255, 255, 255);
	ofDrawTriangle(ofPoint(width*9/20, height*1/4), ofPoint(width/2, height*7/20), ofPoint(width*11/20, height*1/4));
	ofDrawLine(ofPoint(width*1/2, height*7/20-50), ofPoint(width*1/2, height*2/3+25));
	ofDrawTriangle(ofPoint(width*1/2, height*2/3-50), ofPoint(width*1/2+50, height*2/3+25), ofPoint(width*1/2-50, height*2/3+25));
	
	//nose
	ofSetColor(0, 0, 0);
	ofDrawTriangle(ofPoint(width*1/2, height*2/3-25), ofPoint(width*1/2-50, height*2/3+25), ofPoint(width*1/2+50, height*2/3+25));

	//mouth
	ofSetColor(0, 0, 0);
	ofSetLineWidth(5);
	ofDrawLine(ofPoint(width*1/2, height*2/3), ofPoint(width*1/2, height*7.25/10));
	ofDrawTriangle(ofPoint(width*1/2, height*7.25/10), ofPoint(width*7/16, height*3/4), ofPoint(width*9/16, height*3/4));
	
	//eyes
	ofSetColor(0, 0, 0);
	ofDrawCircle(ofPoint(ofPoint(width*2/5, height*7/16)), 20);
	ofDrawCircle(ofPoint(ofPoint(width*3/5, height*7/16)), 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

	cout << "(" << x << ", " << y << ")"<< endl;

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

	width = w;
	height = h;

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
