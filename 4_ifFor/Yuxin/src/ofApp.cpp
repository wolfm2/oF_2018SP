#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255, 255, 255);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
int mouseX = 0;  // these are globals
int mouseY = 0;

void ofApp::draw(){
    int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50); // scale position of mouse
    int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    for (int y = 0; y < ofGetHeight(); y += 20 + deltaY) {  // don't get closer than 20
        for (int x = 0; x < ofGetWidth(); x += 20 + deltaX) {
            int mouseDistX = abs(x - mouseX);
            int mouseDistY = abs(y - mouseY);
//            ofVec2f p1 (x, y);
//            ofVec2f p2 (mouseX,mouseY);
//            int distance = p1.distance(p2);
            if (mouseDistX < 100 && mouseDistY < 100) {  // if mouseX is < 100 px away from a circle
//            if(distance < 50){
                int radius = (mouseDistX, 0, 100, 0, 30);
                int b = (mouseX, 0, ofGetHeight(), 0, 55);
                int r = (mouseY, 0, ofGetHeight(), 50, 255);
                int alpha = (mouseDistY, 0, 100, 50, 100);
                ofFill();
                ofSetColor(r, 0, b, alpha);
                ofDrawCircle(x, y, radius);
            }
            else{
                ofNoFill();
                ofSetColor(255, 0, 0);
                ofDrawCircle(x, y, 30);
            }
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
    // x and y are "locals" or “local variables”
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
