#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 0, 0);
    ofDrawCircle(700, 700, 50);
    
    ofSetColor(0, 0, 255);
    ofDrawRectangle(180, 180, 180, 180);
    
    ofSetColor(0, 255, 0);
    ofDrawEllipse(400, 150, 150, 10);
    
    ofSetColor(0, 100, 180);
    ofDrawLine(800, 800, 800, 200);
    
    ofSetColor(255, 100, 40);
    ofDrawTriangle(50, 500, 10, 40, 90, 40);
    
    ofSetColor(250, 200, 100);
    ofDrawBezier(100, 50, 110, 50, 190, 110, 200, 60);
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
