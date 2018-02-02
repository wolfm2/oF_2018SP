#include "ofApp.h"
int x = 100;
int y = 100;

//--------------------------------------------------------------
void ofApp::setup(){
    

}

//--------------------------------------------------------------
void ofApp::update(){
    x += 1;
//    x ++;
//    x = x+1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, x%255, 200);
    ofDrawCircle(x, y, 50);
    
    ofPopStyle();
    

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
