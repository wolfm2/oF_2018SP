#include "ofApp.h"
#include "ofMain.h"

Rectangle rect[5];

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    ofEnableAlphaBlending();
    ofBackground(70,50,75);
    
    ofSeedRandom();
    for(int i=0; i<=5; i++){
        rect[i].setup();
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0;i<=5;i++){
        rect[i].update();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i=0;i<=5;i++){
        rect[i].draw();
        
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
