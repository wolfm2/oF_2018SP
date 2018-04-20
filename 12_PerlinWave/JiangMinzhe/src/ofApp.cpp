#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    for(int i=0; i<5; i++){
        wave newwave(0,0);
        newwave.setup();
        waves.push_back(newwave);
    }
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0; i<waves.size(); i++){
        waves[i].update();
        
        if(waves[i].vec.y<0 || waves[i].vec.y>ofGetWindowHeight()||waves[i].vec.x<0||waves[i].vec.x>ofGetWindowWidth()){
            waves.erase(waves.begin()+i);
            wave newwave(mouseX, mouseY);
            newwave.setup();
            waves.push_back(newwave);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<waves.size(); i++){
        waves[i].draw();
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
