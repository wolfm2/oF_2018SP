#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(231,239,246);
    ofDrawCircle(200, 200, 100);
    
    ofSetColor(173,203,227);
    ofDrawLine(400, 200, 500, 200);
    
    ofSetColor(99,172,229);
    ofDrawTriangle(700, 150, 600, 300, 800, 300);

    ofSetColor(75,134,180);
    ofDrawRectangle(100, 400, 200, 100);
    
    ofSetColor(30, 60, 90);
    ofDrawEllipse(450, 450, 100, 200);
  
    ofSetColor(60, 60, 90);
    ofDrawCurve(30, 40, 600, 400, 750, 550, 40, 70);
    
//    ofSetColor(90, 160, 190);
//    ofDrawBitmapString("hi!!", 500,300);
//
//    ofSetColor(90,80,200);
//    ofDrawBezier(40, 400, 50, 500, 450, 390, 235, 876);
    

   
    
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
