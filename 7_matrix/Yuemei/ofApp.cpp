#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("image.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2 - 100, ofGetHeight()/2 - 100);
    ofScale(1, 1, 1);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    image.draw(pX, pY, wX, hY);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'x'){
        rX ++;
    }
    if(key == 'X'){
        rX --;
    }
    if(key == 'y'){
        rY ++;
    }
    if(key == 'Y'){
        rY --;
    }
    if(key == 'z'){
        rZ ++;
    }
    if(key == 'Z'){
        rZ --;
    }
    if(key == 'q'){
        pY --;
    }
    if(key == 'a'){
        pX --;
    }
    if(key == 's'){
        pY ++;
    }
    if(key == 'd'){
        pX ++;
    }
    if(key == 'w'){
        wX ++;
    }
    if(key == 'W'){
        wX --;
    }
    if(key == 'h'){
        hY ++;
    }
    if(key == 'H'){
        hY --;
    }
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
