#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
int mouseX = 0;  // these are globals
int mouseY = 0;
float R,G,B;

void ofApp::draw(){
    int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50); // scale position of mouse
     int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    int y = 100;
     for (int y = 0; y < ofGetHeight(); y += 40 + deltaY) {  // don't get closer than 20
    for (int x = 0; x < ofGetWidth(); x += 20 + deltaX) {
        int mouseDistX = abs(x - mouseX);
        int mouseDistY = abs(y - mouseY);
        if (mouseDistX < 80 && mouseDistY < 100) {  // if mouseX is < 100 px away from a circle
            R = ofRandom(0,200);
            G = ofRandom(30,100);
            B = ofRandom(90,200);
            ofSetColor(R, G, B,30);
//            float randomColor = ofRandom(161,66);
//            ofSetColor(randomColor, 50);
            ofNoFill();
        } else {//true or false
//            ofSetColor(34,80,2);
        ofFill();
        }
//        ofSetColor(0, 0, 255);
        ofDrawCircle(x, y, 80);  // Make sure Y is declared!  Ex: int y=100;
        }
    } //is will draw the circle in the screen, because the x's position is less than the width it wikk keep drawing

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
