#include "ofApp.h"

int mouseX = 0;  // these are globals
int mouseY = 0;

ofFbo fbo;
//--------------------------------------------------------------
void ofApp::setup(){
	
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
	fbo.begin();
	ofClear(255, 255, 255, 0);
	fbo.end();
	ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50); // scale position of mouse
	int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);

	fbo.begin();
		ofSetColor(0,0,0, 10); // background color with alpha 
		ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		for (int y = 0; y < ofGetHeight(); y += 40 + deltaY) {  // don't get closer than 20
			for (int x = 0; x < ofGetWidth(); x += 20 + deltaX) {
				int mouseDistX = abs(x - mouseX);
				int mouseDistY = abs(y - mouseY);
				if (mouseDistX*mouseDistX+mouseDistY*mouseDistY< 10000) {  // if mouseX is < 100 px away from a circle
					ofNoFill();
				}
				else {
					ofFill();
				}
				ofSetColor(0, 0, 255);
				ofDrawCircle(x, y, 20);  // Get y value from for statement.
			}
		}

	fbo.end();
	ofSetColor(255, 255, 255);
	fbo.draw(0,0);

}





//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	mouseX = x;
	// x and y are "locals" or “local variables”
	mouseY = y;
	// locals override globals of the same name!!

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
