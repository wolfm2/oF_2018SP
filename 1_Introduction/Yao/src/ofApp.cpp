#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    r= 50;
    x= 500;
    y= 500;
    R= 130;
    G= 70;
    B= 100;
    x1= 100;
    y1= 157;
    x2= 90;
    y2= 80;
    x3= 207;
    y3= 267;
    x4= 300;
    y4= 200;
    w= 150;
    h= 200;
    x5= 500;
    y5= 300;
    r1= 90;
    r2= 50;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(R,G,B);
    ofDrawCircle(x,y,r);
    ofSetColor(50,70,150);
    ofDrawTriangle(x1,y1,x2,y2,x3,y3);
    ofSetColor(60,10,170);
    ofDrawRectangle(x4,y4,w,h);
    ofSetColor(0,0,10);
    ofDrawEllipse(x5,y5,r1,r2);
    ofSetColor(100,0,10);
    ofDrawRectangle(250,300,70,70);
    ofSetColor(10, 100, 500);
    ofDrawTriangle(570, 300, 510, 400, 630, 400);
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
