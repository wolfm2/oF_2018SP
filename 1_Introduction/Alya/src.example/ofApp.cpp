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
    ofSetColor(20, 23, 124);
    ofDrawCircle(100, 100, 60);
    
    ofSetColor(123, 0, 200);
    ofDrawBezier(10, 50, 342, 324, 234, 312, 231, 323);
    
    ofSetColor(34, 345, 23);
    ofDrawRectangle(10, 10, 100, 100);
    
    ofSetColor(20, 123, 200);
    ofDrawTriangle(200, 200, 200, 123, 12, 21);
    
    ofSetColor(200, 23, 124);
    ofDrawCircle(300, 240, 78);
    
    
    ofSetColor(255, 255, 255);
    ofDrawCurve(120, 100, 90, 90, 700, 720, 740, 100);
    
    ofSetColor(234, 23, 124);
    ofDrawLine(7, 40, 260, 40);
    

    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 60);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 80);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 100);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 110);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 115);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 135);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 155);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 175);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 195);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 215);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 225);
    
    ofSetColor(209, 100, 123);
    ofDrawBitmapString("where is the rest of the shapes?", 50, 245);
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
