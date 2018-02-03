#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(120, 125, 70);
    ofDrawBitmapString("Hi", 200, 100);
    ofDrawBitmapString("This is Shuyi", 100, 400);
    
    ofSetColor(150, 20, 80);
    ofDrawCircle(400, 500, 84);
    
    ofSetColor(100, 200, 255);
    ofDrawEllipse(500, 600, 200, 50);
    
    ofSetColor(255, 255, 255);
    ofDrawLine(400, 200, 2000, 3000);
    
    ofSetColor(209, 238, 106);
    ofDrawRectangle(100, 150, 100, 180);
    
    ofSetColor(231, 107, 114);
    ofDrawCurve(0, 0, 100, 600, 600, 400, 700, 700);
    
    ofSetColor(80, 170, 100);
    ofDrawTriangle(500, 400, 500, 300, 350, 350);
    
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
