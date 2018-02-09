#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255, 255, 255);
//    red
    ofSetColor(246,100,81);
    ofDrawTriangle(600,251,730,251,592,277);
    ofDrawTriangle(440,338,560,338,396,554);
//    green
    ofSetColor(183,196,155);
    ofDrawTriangle(512,251,588,251,568,315);
    ofDrawTriangle(550,363,415,546,504,507);
    ofDrawTriangle(266,566,380,566,379,723);
//    grey
    ofSetColor(237,239,236);
    ofDrawTriangle(498,259,442,326,561,326);
    ofDrawTriangle(426,351,267,555,382,555);
//    yellow
    ofSetColor(255,189,41);
    ofDrawTriangle(281,259,292,300,426,326);
    ofDrawTriangle(95,284,423,337,344,439);
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
