#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 220, 0);
    ofNoFill();
     ofDrawTriangle(ofGetWidth()/2-120, ofGetHeight()/2-120, ofGetWidth()/2+120, ofGetHeight()/2-120, ofGetWidth()/2+120, ofGetHeight()/2+120);
    
    ofSetCircleResolution(100);
    ofSetColor(255, 200, 0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 120);
    ofFill();
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
    ofSetColor(255, 180, 0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 80);
    ofSetColor(255, 128, 0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 60);
    
    ofSetColor(255, 230, 230);
    ofFill();
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2-220, 120, 140);
    ofSetColor(255, 204, 204);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2-210, 100, 120);
    ofSetColor(255, 179, 179);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2-200, 80, 100);
    ofSetColor(255, 153, 153);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2-190, 60, 80);
    
    
    ofSetColor(255, 220, 0);
    ofNoFill();
    ofDrawTriangle(ofGetWidth()/2, ofGetHeight()/2-220, ofGetWidth()/2-220, ofGetHeight()/2+120, ofGetWidth()/2+220, ofGetHeight()/2 + 120);
   
    ofSetColor(255, 80, 0);
    ofFill();
    ofDrawTriangle(ofGetWidth()/2-45, ofGetHeight()/2-30, ofGetWidth()/2 + 45, ofGetHeight()/2-30, ofGetWidth()/2, ofGetHeight()/2 + 60);
    
    ofNoFill();
    ofDrawRectangle(ofGetWidth()/2-120, ofGetHeight()/2, 120, 120);
    
    
    ofDrawLine(ofGetWidth()/2-120, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2+120);
    
  

    
//    ofDrawBezier(20, 20, 40, 30, 30, 30, 30, 30);
    ofNoFill();
    ofDrawBezier(20, 20, 80, 40, 120, 30, 200, 60);
    
    ofSetColor(0);
    ofDrawBitmapString("-0.2", ofGetWidth()/2-50, ofGetHeight()/2 );
    
    ofSetColor(255, 204, 204);
    ofDrawCurve(30, 60, 70, 30, 110, 60, 150, 30);
    
   
   
    
    
    //how to use spacing here:
    
//    int spacing = 50;
//    ofBeginShape();
//    for(int x=0; x<ofGetWidth(); x+= spacing) {
//        ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * 0.3f * sin(x*0.01f + ofGetFrameNum() * 0.02f));
//    }
//    ofEndShape(false);
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
