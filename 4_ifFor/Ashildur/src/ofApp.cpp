#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    int mouseX = 0; //these are globals
    int mouseY = 0;
}

//--------------------------------------------------------------
void ofApp::draw(){
    int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50); // scale position of mouse
     int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    int y = 100;
     for (int y = 0; y < ofGetHeight(); y += 20 + deltaY) {  // don't get closer than 20, now we have many lines
    for (int x = 0; x < ofGetWidth(); x += 20 + deltaX) {
        int mouseDistX = abs(x - mouseX);
        if (mouseDistX < 100) {  // if mouseX is < 100 px away from a circle
          ofNoFill();
        } else {
        ofFill();
        }
        ofSetColor(0, 0, 255);
        ofDrawCircle(x, y, 20);  // Make sure Y is declared!  Ex: int y=100;
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
void ofApp::mouseMoved(int x, int y ){
    mouseX = x;
    //x and y are "locals" or "locals variables"
    
    mouseY = y;
    //locals override globals of the same name
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
