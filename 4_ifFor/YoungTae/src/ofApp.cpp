#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
        ofBackground(0.160,190);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
int mouseX = 0;
int mouseY = 0;

void ofApp::draw(){
    
    int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50);
    int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    for (int y = 0; y < ofGetHeight(); y += 20 + deltaY) {
        for (int x = 0; x < ofGetWidth(); x += 20 + deltaX) {
            int mouseDistX = abs(x - mouseX);
            int mouseDistY = abs(y - mouseY);
            int alphaX = ofMap(mouseDistX, ofGetHeight(), 0, 0, 100);
            int valueY = ofMap(mouseDistY, ofGetWidth(), 0, 100, 0);
            
            if (mouseDistX < 60 != mouseDistY > 60) {
                ofNoFill();
            } else {
                int sizeY = ofMap(mouseX, 0, ofGetHeight(), 0, 50);
                ofFill();
            }
            ofSetColor(170, 100, 0, alphaX);
            ofDrawCircle(x, y, 10);
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
