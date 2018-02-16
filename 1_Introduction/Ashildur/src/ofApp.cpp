#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
ofBackground(178, 180, 214);
ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(255,255,255);
    ofDrawEllipse(600, 600, 300, 100);
    
    ofFill();
    ofSetColor(0,0,0);
    ofDrawRectangle(100, 100, 100, 100);
    
    
    ofSetColor(255, 105, 97);
    ofDrawRectRounded(200, 200, 100, 200, 100);
    ofDrawBitmapString("Hello, we are shapes", 500, 300);
    
    ofSetColor(146, 187, 255);
    ofDrawSphere(400, 400, 60);
    
    ofSetColor(255, 255, 255);
    ofDrawCircle(300, 300, 50);
    ofDrawEllipse(600, 600, 300, 100);
    
    ofSetColor(47, 255, 173);
    ofDrawTriangle(400, 400,400, 400, 400, 400);
    
    ofSetColor(90, 200, 200);
    ofDrawSphere(100, 300, 50);
    
    ofSetColor(255, 105, 97);
    ofDrawLine(10, 600, 600, 600);
    ofDrawLine(400, 500, 600, 800);
    ofDrawLine(600, 800, 400, 500);
    


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
