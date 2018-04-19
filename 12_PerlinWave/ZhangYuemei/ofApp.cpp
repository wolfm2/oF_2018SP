#include "ofApp.h"

Line num[6];

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetVerticalSync(true);
//    ofEnableAlphaBlending();
    ofBackground(0,0,0);
    line.setup();
    for (int i = 0; i < 6; i++) {
        num[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    line.update();
    for (int i = 0; i < 6; i++) {
        num[i].update();
    }
    
   
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetRectMode(OF_RECTMODE_CENTER);
    line.draw();
    for (int i = 0; i < 6; i++) {
        num[i].draw();
        
    }
    
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
