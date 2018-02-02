#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
 
    ofSetColor(30, 30, 30);
    ofDrawLine(200,0,900,900);
    
    ofSetColor(30, 30, 30);
    ofDrawLine(150,0,900,900);
    
    ofSetColor(30, 30, 30);
    ofDrawLine(100,0,900,900);
    
    ofSetColor(30, 30, 30);
    ofDrawLine(50,0,900,900);
    
    ofSetColor(30, 30, 30);
    ofDrawLine(0,10,900,900);
    
    ofSetColor(30, 30, 30);
    ofDrawLine(0,60,900,900);
    
    ofSetColor(255, 0, 0);
    ofDrawCircle(300, 300, 100);
    
    ofSetColor(60, 220, 100);
    ofDrawBezier(350, 525, 400, 55, 600, 90, 450, 350);
    
    ofSetColor(255, 255, 0);
    ofDrawBitmapString("Dire Straits on Repeat", 600, 60);
    
    ofSetColor(120, 75, 250);
    ofDrawCurve(30, 100, 250, 300, 400, 200, 550, 720);
    
    ofSetColor(255, 255, 0);
    ofDrawEllipse(600, 500, 400, 100);
    
    ofSetColor(92, 33, 85);
    ofDrawRectangle(45, 60, 100, 300);
    
    ofSetColor(136, 200, 90);
    ofDrawTriangle(95, 270, 175, 320, 300, 100);
    
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
