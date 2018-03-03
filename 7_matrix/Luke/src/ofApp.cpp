#include "ofApp.h"

ofImage leaf;

int x = 0;
int y = 0;

float scaleW = 1.0f;
float scaleH = 1.0f;

float rotateX = 0;
float rotateY = 0;
float rotateZ = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    leaf.load("leaf.png");
    ofSetFrameRate(60);
    x = ofGetWindowWidth()/2;
    y = ofGetWindowHeight()/2;
}



//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(255);

    ofPushMatrix();
    ofTranslate(x, y);
    ofScale(scaleW, scaleH);  // can be 3 dimensional
    ofRotateX(rotateX);
    ofRotateY(rotateY);
    ofRotateZ(rotateZ);
    leaf.draw(0 - leaf.getWidth()/2, 0 - leaf.getHeight()/2);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'x') {
        rotateX -= 1;
    }
    
    if(key == 'X') {
        rotateX += 1;
    }

    if(key == 'y') {
        rotateY -= 1;
    }

    if(key == 'Y') {
        rotateY += 1;
    }

    if(key == 'z') {
        rotateZ -= 1;
    }

    if(key == 'Z') {
        rotateZ += 1;
    }

    if(key == 'e') {
        y -= 1;
    }

    if(key == 's') {
        x -= 1;
    }

    if(key == 'd') {
        y += 1;
    }

    if(key == 'f') {
        x += 1;
    }

    if(key == 'w') {
        scaleW -= 0.1;
    }

    if(key == 'W') {
        scaleW += 0.1;
    }

    if(key == 'h') {
        scaleH -= 0.1;
    }

    if(key == 'H') {
        scaleH += 0.1;
    }

    if(key == 'r') {
        x = ofGetWindowWidth()/2;
        y = ofGetWindowHeight()/2;
        
        scaleW = 1.0f;
        scaleH = 1.0f;

        rotateX = 0;
        rotateY = 0;
        rotateZ = 0;
    }


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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