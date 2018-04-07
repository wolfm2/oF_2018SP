#include "ofApp.h"
#include "ofMain.h"

float rect_CUSpeed = 0.01f;
ofPoint rect_pos;

Rectangle num[4];


void Rectangle::setup(){
    rect_pos.x = ofRandom(0, ofGetWidth());
    rect_pos.y = ofRandom(0, ofGetHeight());
    rect_CUSpeed = ofRandom(0, 0.1f);
    radius = ofRandom(20, 40);
    color.set(ofRandom(255), ofRandom(255), ofRandom(255), ofRandom(0, 255));
};


void Rectangle::update(){
    rect_pos.x += rect_CUSpeed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += rect_CUSpeed * (ofGetMouseY() - rect_pos.y);
};

void Rectangle::draw(){
    ofSetColor(color);
    ofRect(rect_pos.x , rect_pos.y, radius, radius);
}

void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
    for (int i = 0; i < 6; i++) {
        num[i].setup();
    }
    
    
}




//--------------------------------------------------------------
void ofApp::update(){
    
   
    for (int i = 0; i < 6; i++) {
        num[i].update();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
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
