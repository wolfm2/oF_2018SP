#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(204, 255, 255);
    ofDrawTriangle(512, 0, 192, 576, 832, 576);
    
    ofSetColor(255, 255, 102);
    ofDrawCircle(512, 384, 300);

    ofSetColor(0, 255, 255);
    ofDrawEllipse(512, 384, 600, 100);

    ofSetColor(255);
    ofDrawLine(0,384, 1024, 384);
    ofSetColor(255);
    ofDrawLine(512,0, 512, 768);
    
    

    ofSetColor(255, 153, 0);
    ofDrawRectangle(0, 0, 100, 100);
    ofSetColor(255, 153, 0);
    ofDrawRectangle(924, 0, 100, 100);
    ofSetColor(255, 153, 0);
    ofDrawRectangle(0, 668, 100, 100);
    ofSetColor(255, 153, 0);
    ofDrawRectangle(924, 668, 100, 100);
    
    
    

    ofSetColor(0, 255, 0);
    ofDrawCurve(0, 384,256, 192,  768, 576,1024, 384 );
    ofSetColor(0, 255, 0);
    ofDrawCurve(1024, 384,256,576, 768, 192, 0, 384);

   
    
    
    ofSetColor(255);
    ofDrawBitmapString("Lavonne's Geometry World", 676, 676);

    
    
    
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
