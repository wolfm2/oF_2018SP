#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    int mouseX = 0; // these are globals
    int mouseY = 0;

}

//--------------------------------------------------------------
void ofApp::draw(){
    int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50);
    int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    for (int y = 0; y < ofGetHeight(); y += 10 + deltaY){
        for(int x = 0; x < ofGetWidth(); x += 10 + deltaX){
        int mouseDistX = abs(x - mouseX);
        if (mouseDistX < 100){
            ofNoFill();
        }else{
            ofFill();
        }
        ofSetColor(255, 0, 0); // filled with red color
        ofDrawRectangle(x, y, 20, 20); // draw a rectangle with 20 pixs
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
    mouseY = y;

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
