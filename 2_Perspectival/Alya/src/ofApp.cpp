#include "ofApp.h"


ofImage sup;
ofImage Tex;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    sup.load("cool.png");
    Tex.load("tex.jpeg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    
    
    ofSetColor(255, 255, 255);
    ofImage();
    sup.draw(100,100, 500, 500);
    
    ofSetColor(255, 255, 255, 150);
    ofEnableAlphaBlending();
    Tex.draw(200,300, 700, 700);
    ofDisableAlphaBlending();
    
  ofEnableAlphaBlending();
    
        ofSetColor(0, 0, 255, 127);
        ofDrawRectangle(100, 100, 500, 190);
     ofDisableAlphaBlending();
    

    
    
    
     ofSetColor(0, 0, 255);
    ofDrawRectangle(600, 100, 40, 190);
    
//    ofSetColor(0, 0, 255);
//    ofDrawRectangle(210, 400, 500, 90);
    
    ofSetColor(0, 0, 0);
 ofDrawRectangle(20, 20, 1024, 3);
    
    
    ofSetColor(255, 255, 255);
    ofDrawRectangle(370, 380, 600, 20);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 500, 588);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 500, 590);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 500, 605);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 500, 610);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 500, 620);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 500, 630);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 500, 640);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 500, 610);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 234, 34);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 314, 13);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 134, 134);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 213, 314);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 234, 600);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 0, 700);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY HAPPY BIRTHDAY", 678, 134);
    
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
