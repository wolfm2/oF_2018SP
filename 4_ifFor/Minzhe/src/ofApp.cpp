#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 163, 174);
}

//--------------------------------------------------------------
void ofApp::update(){

}
int mouseX = 0;  // these are globals
int mouseY = 0;

//--------------------------------------------------------------
void ofApp::draw(){
    /*
     Modify the ifForExample.
     Push your src folder of ifForExample with an explanatory text file and screenshot.
     Check x and y distance to change the color, alpha, and size of each circle.
     Requirements:
     Basic:
     Modify the if statement for an on/off effect
     Intermediate:
     Use ofMap() to change the values gradually relative to the distance of the mouse
     Advanced:
     Apply the fbo trails technique on ifForExample

     */
    int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50); // scale position of mouse
    int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    for (int y = 0; y < ofGetHeight(); y += 20 + deltaY) {  // don't get closer than 20
        for (int x = 0; x < ofGetWidth(); x += 20 + deltaX) {
            int mouseDistX = abs(x - mouseX);
            int mouseDistY=abs(y-mouseY);
            int alphaX=ofMap(mouseDistX, 0, ofGetWidth(), 0, 255);
            int sizeY=ofMap(mouseDistY, 0, ofGetHeight(), 0, 50);
            
            ofSetColor(247, 168, 0, alphaX);
            ofDrawCircle(x, y, sizeY);  // Get y value from for statement.
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
    // x and y are "locals" or Òlocal variablesÓ
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
