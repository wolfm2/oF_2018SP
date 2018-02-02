#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(155,200,100);
    ofDrawCircle(300,200,100);
    ofSetColor(205,200,60);
    ofDrawBezier(100, 200, 400, 500, 300, 200, 450, 600);
    ofSetColor(105,100,80);
    ofDrawLine(15, 25, 35, 45, 60, 80);
    ofSetColor(135,80,80);
    ofDrawBitmapString("hi oF",700,350);
    ofSetColor(85,80,80);
    ofDrawCurve(40,420,100,500,480,680,400,300);
    ofSetColor(205,100,100);
    ofDrawEllipse(800,200,80,100);
    ofSetColor(105,70,120);
    ofDrawLine(500,400,600,700);
    ofSetColor(105,200,250);
    ofDrawRectangle(700,500,100,100);
    ofSetColor(105,150,120);
    ofDrawTriangle(500,150,550,300,600,350);
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
