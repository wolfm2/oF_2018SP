#include "ofApp.h"

ofFbo fbo;  // framebuffer object


//--------------------------------------------------------------
void ofApp::setup(){
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    
    fbo.begin();
    ofClear(221, 255, 253, 0);
    fbo.end();
    
    ofSetBackgroundColor(221, 255, 253);
}

//--------------------------------------------------------------
void ofApp::update(){

}

int mouseX = 0;
int mouseY = 0;

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    
    int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50); // scale position of mouse
    int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    //int y = 100;
    for (int y = 0; y < ofGetHeight(); y += 20 + deltaY) {  // don't get closer than 20
    for (int x = 0; x < ofGetWidth(); x += 20 + deltaX) {
        int mouseDistX = abs(x - mouseX);
        int mouseDistXm = ofMap(mouseDistX, 0, ofGetWidth(), 0, 400);
        if (mouseDistXm < 50) {  // if mouseX is < 50 px away from a circle
          ofNoFill();
        } else {
        ofFill();
        }
        //ofSetColor(0, 0, 255);

        fbo.end();
        
        ofSetColor(255, 0, 80, 30);//change alpha
        ofDrawCircle(x, y, 20);  // Make sure Y is declared!  Ex: int y=100;
        
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
    mouseY = y;
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
