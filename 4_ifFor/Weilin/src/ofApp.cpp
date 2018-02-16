#include "ofApp.h"
ofFbo fbo;
//--------------------------------------------------------------
void ofApp::setup(){
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo.begin();
    ofClear(249, 137, 62, 0);
    fbo.end();
    
    ofSetBackgroundColor(249, 137, 62,100);

}

//--------------------------------------------------------------
void ofApp::update(){
    int mouseX = 0;
    int mouseY = 0;

}

//--------------------------------------------------------------

void ofApp::draw(){
   
    fbo.begin();

    
    int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50); // scale position of mouse
    int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    for (int y = 0; y < ofGetHeight(); y += 20 + deltaY) {  // don't get closer than 20
        for (int x = 0; x < ofGetWidth(); x += 20 + deltaX) {
            int mouseDistX = abs(x - mouseX);
            if (mouseDistX < 100) {  // if mouseX is < 100 px away from a circle
                ofNoFill();
            } else {
                ofFill();
            }
            
            fbo.end();
            
            ofSetColor(175, 210, 247,80);
            ofDrawCircle(x, y, 30);  // Get y value from for statement.
            
            fbo.draw(0,0);
        }
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
    mouseX = x;
    // x and y are "locals" or Òlocal variablesÓ
    mouseY = y;
    // locals override globals of the same name!!


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
