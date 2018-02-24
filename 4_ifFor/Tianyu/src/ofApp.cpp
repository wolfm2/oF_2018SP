#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(100, 100, 100);
}

//--------------------------------------------------------------
void ofApp::update(){
    int mouseX = 0;  // these are globals
    int mouseY = 0;
}

//--------------------------------------------------------------
void ofApp::draw(){
   
int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50); // scale position of mouse
int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
for (int y = 0; y < ofGetHeight(); y += 30 + deltaY) {  // don't get closer than 20
    for (int x = 0; x < ofGetWidth(); x += 30 + deltaX) {
        int mouseDistX = abs(x - mouseX);
        if (mouseDistX < 200) {  // if mouseX is < 100 px away from a circle
            ofNoFill();
        } else {
            ofFill();
        }
        ofSetColor(100, 150, 200);
        ofDrawCircle(x, y, 10);  // Get y value from for statement.
    }
}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
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
