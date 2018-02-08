#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(241,124,103);
    ofDrawCircle(100, 100, 50);
    ofSetColor(241, 191, 69);
    ofDrawCurve(12, 34, 156, 278, 190, 120, 213, 560);
    ofSetColor(241, 191, 69);
    ofDrawCurve(100, 100, 245, 89, 650, 90, 630, 201);
    ofSetColor(134, 193, 102);
    ofSetLineWidth(10.0f);
    ofDrawLine(34, 56, 1000, 900);
    ofSetColor(46,169,223);
    ofDrawRectangle(700, 50, 150, 500);
    ofSetColor(250, 252, 242);
    ofDrawEllipse(600, 300, 445, 121);
    ofSetColor(255, 177, 27);
    ofDrawTriangle(45, 191, 213, 389, 105, 651);

    
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
