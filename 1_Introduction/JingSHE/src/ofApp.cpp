#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
   

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255, 23, 0); // set background color is red
  
    ofSetColor(0, 0, 255);
    
    ofFill();
    
    ofDrawLine(80, 80, 80, 120); // draw the line filled in blue
    
    ofSetColor(254, 139, 155);
    
    ofFill();
    
    ofDrawBezier(255, 68, 79, 65, 78, 89, 100, 120); // draw bezier filled in pink
    
    ofSetColor(2, 135, 2);
    
    ofFill();
    
    ofDrawCircle(100, 200, 20); // draw a circle filled in green
    
    ofSetColor(2, 5, 4);
    
    ofFill();
    
    ofDrawEllipse(100, 300, 30, 80); // draw a ellipse filled in black
    
    ofSetColor(250, 251, 4);
    
    ofFill();
    
    ofDrawRectangle(80, 400, 50, 50); // draw a rectangle filled in yellow
    
    ofSetColor(255, 255, 255);
    
    ofFill();
    
    ofDrawTriangle(80, 500, 80, 580, 100, 530); // draw a triangle filled in white
  


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
