#include "ofApp.h"
#include "ofMath.h"


//--------------------------------------------------------------
void ofApp::setup(){

}



//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    

    //first pattern
    ofPushMatrix();
    ofTranslate(300, 400);
    ofSetColor(0, 0 ,0);
    ofNoFill();
    ofDrawCircle(0, 0, 50);//ceter circle
    
    
    //draw 11 black circles that rotates z-axis
    int r = 80;
    ofFill();
    for(int i=0; i<12; i++){
        ofDrawCircle(r*cos(10), r*sin(10), (i*4));
        ofRotateZ(10+(i*4)); //rotate degrees increase
        r=r+4; //rotates radius increase
    }
    ofPopMatrix();
    
    
    
    //second pattern
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(700, 400);
    ofSetColor(0, 0 ,0);
    ofNoFill();
    ofDrawCircle(0, 0, 200);
    
    ofFill();
    // (360/24) = 15
    //rotate 15 degrees every time and do it 24 times
    for (int i=0; i<24; i++){
        ofDrawRectangle(0,160,10,40);
        ofRotateZ(15);
    }
    ofPopMatrix();

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
