#include "ofApp.h"


ofFbo fbo;
float catchUpspeed = 0.01f;
ofPoint pos;

//--------------------------------------------------------------
void ofApp::setup(){
    posX = ofGetWidth()/2;
    posY = ofGetHeight()/2;
    ofSetBackgroundColor(67, 70, 86);
}

//--------------------------------------------------------------
void ofApp::update(){

    pos.x += catchUpspeed * (mouseX - pos.x);
    pos.y += catchUpspeed * (mouseY - pos.y);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    fbo.begin();
    
    //ofSetColor(255, 0, 114, 100);
    ofTranslate(posX, posY);
    ofSetColor(255, 0, 114, 95);
    ofDrawCircle(0, 0, 100);
    ofFill();
    ofSetColor(0, 255, 255, 95);
    ofDrawCircle(0, 0, 80);
    ofNoFill();
    ofSetColor(255, 0, 114, 95);
    ofDrawCircle(0, 0, 60);
    ofFill();
    
    fbo.end();
    ofSetColor(255, 0, 114,90);
    ofFill();
    fbo.draw(0, 0);
    
     r = 5;
    for (int i = 0; i < 12; i++){
        r = r + 5;

        ofRotate(30);
        ofDrawCircle(pos.x, pos.y, r);
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
    posX = mouseX;
    posY = mouseY;

    cout << "test   " << x << " , " << y << endl;
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
