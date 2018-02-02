#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(208, 16, 76);
    ofDrawCircle(60, 100, 90);
    
    ofSetColor(255,177,27);
    ofDrawCurve(1000, 800, 1000, 800, 480, 90, 235, 67);
    
    ofSetColor(246, 197, 85);
    ofDrawTriangle(568, 780, 600, 20, 100, 300);
    
    ofSetColor(123, 162, 63);
    ofDrawEllipse(700, 600, 300, 90);
    
    ofSetColor(0,0,0);
    ofDrawLine(180, 80, 300, 40);
    ofDrawLine(200, 120, 500, 120);
    
    ofSetColor(141,116,42);
    ofDrawRectangle(666, 30, 1000, 60);
    
    ofSetColor(90,80,200);
    ofDrawBezier(40, 400, 50, 500, 450, 390, 235, 876);
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
