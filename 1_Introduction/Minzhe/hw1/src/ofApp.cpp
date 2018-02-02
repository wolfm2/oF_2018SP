#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCurveResolution(220);
    ofSetCircleResolution(220);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 255, 255);
    ofDrawCircle(80, 80, 20);
    
    ofSetColor(255, 0, 0, 80);
    ofNoFill();
    ofDrawBezier(200, 300, 200, 500, 300, 700, 300, 200);

    ofSetColor(0, 0, 255);
    ofNoFill();
    ofDrawCurve(200, 300, 200, 500, 300, 700, 300, 200);
    
    ofSetColor(40, 150, 200);
    ofDrawEllipse(300, 300, 100, 80);
    
    ofSetColor(100, 50, 200, 70);
    ofDrawLine(150, 200, 80, 300);
    
    ofSetColor(80, 100, 60);
    ofDrawRectangle(150, 150, 100, 200);
    
    ofSetColor(60, 200, 180);
    ofDrawTriangle(100, 200, 150, 70, 300, 150);
    
    ofSetColor(30, 20, 225);
    ofDrawBitmapString("Hi I'm Echo", 300, 300);
    

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
