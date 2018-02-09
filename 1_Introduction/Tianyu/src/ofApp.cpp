#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(114, 197, 190);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(200, 100, 100);
    ofDrawRectangle(500, 50, 300, 300);
    
    ofSetColor(255, 100, 0);
    ofDrawCircle(500, 500, 100);
    
    ofSetColor(255, 255, 255);
    ofDrawLine(10, 10, 100, 100);
    
    ofSetColor(240, 200, 0);
    ofDrawEllipse(50, 50, 100, 30);
    
    ofSetColor(80, 180, 190);
    ofDrawLine(100, 100, 50, 50);
    
    ofSetColor(240, 200, 0);
    ofDrawEllipse(100, 100, 100, 30);
    
    ofSetColor(255, 255, 255);
    ofDrawLine(200, 200, 100, 100);
    
    ofSetColor(240, 200, 0);
    ofDrawEllipse(300, 300, 100, 30);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("Hi I am an artificial intelligence, but I am not that intelligent", 100, 100);
    
    ofSetColor(122, 255, 100);
    ofDrawCurve(10, 10, 300, 200, 200, 400, 1000, 1000);
    
    ofSetColor(255, 255, 255);
    ofDrawBezier(119, 228, 134, 150, 341, 118, 425, 186);
    
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
