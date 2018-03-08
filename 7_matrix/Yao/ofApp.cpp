#include "ofApp.h"
ofImage diamond;
//--------------------------------------------------------------
void ofApp::setup(){
    diamond.load ("diamond.png");
}
float x=0;
float y=0;
bool state=false;
bool state1=false;
bool state2=false;
float scaleX=1;
float scaleY=0.8;

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2+x,ofGetHeight()/2+y);
    if(state==true){
        ofRotateX(60);
    }
    if(state1==true){
        ofRotateY(30);
    }
    if(state2==true){
        ofRotateZ(90);
    }
    ofScale(scaleX, scaleY);
    diamond.draw(0-diamond.getWidth()/2,0-diamond.getHeight()/2);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='x'){
        state= !state;
    }
    if(key=='y'){
        state1= !state1;
    }
    if(key=='z'){
        state2= !state2;
    }
    if (key == 'q','a','s','d'){
        x ++, y ++;
    }
    if(key=='h'){
        scaleX-=0.1, scaleY-=0.1;
    }
    if(key=='H'){
        scaleX+=0.1,scaleY+=0.1;
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
