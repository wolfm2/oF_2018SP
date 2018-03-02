#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    faceear.load("faceear.png");
    ear.load("ear.png");
    facehair.load("facehair.png");
    hair.load("hair.png");
    facehorn.load("facehorn.png");
    horn.load("horn.png");
    font.load("baskvl.ttf",20);
    
}
float rotateX, rotateY, rotateZ = 0;
float transX, transY = 0;
float scaleH = 1;
float scaleW = 1;

//--------------------------------------------------------------
void ofApp::update(){


}
//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofSetColor(255);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateX(rotateX);
    ofRotateY(rotateY);
    ofRotateZ(rotateZ);
    ofTranslate(transX, transY);
    ofScale(scaleH,scaleW);
    ear.draw(ofGetWindowPositionX()/2, 250);
    hair.draw(-300, 200);
    horn.draw(-100, 220);
    ofPopMatrix();


    faceear.draw(250, 300, 200);
    facehair.draw(450, 300, 200);
    facehorn.draw(650, 300, 200);
    
    ofFill();
    ofSetColor(0, 0, 255);
    font.drawString("match the item with its face",20,50);
    font.drawString("transX +/- = q/w",20,80);
    font.drawString("transY +/- = a/s",20, 110);
    font.drawString("rotateX +/- = e/r",20,140);
    font.drawString("rotateY +/- = d/f",20, 170);
    font.drawString("rotateZ +/- = t/y",300,80);
    font.drawString("scaleW +/- = g/h",300,110);
    font.drawString("scaleH +/- = i/u",300,140);
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


    if(key == 'q'){
        transX --;
    }

    if(key == 'w'){
        transX ++;
    }

    if(key == 'a'){
        transY --;
    }

    if(key == 's'){
        transY ++;
    }

    if(key == 'e') {
        rotateX ++;
    }

    if(key == 'r') {
        rotateX --;
    }

    if(key == 'd') {
        rotateY ++;
    }

    if(key == 'f') {
        rotateY --;
    }

    if(key == 't') {
        rotateZ ++;
    }

    if(key == 'y') {
        rotateZ --;
    }

    if(key == 'g') {
        scaleW ++;
    }

    if(key == 'h') {
        scaleW --;
    }
    
    if(key == 'u') {
        scaleH --;
    }
    
    if(key == 'i') {
        scaleH ++;
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

