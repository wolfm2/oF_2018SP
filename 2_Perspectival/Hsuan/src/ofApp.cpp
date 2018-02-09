#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int i;
    int j;
    
    
    for(i=500; i<= 700; i+=50){
        for(j=150; j<=350; j+=50){
            ofSetColor(3,j,0);
            ofDrawTriangle(500, 350, i, j, (i+20), (j+20));
        }
    }
    
    for(i=500; i>= 300; i-=50){
        for(j=550; j>=350; j-=50){
            ofSetColor(21,(j-300),0);
            ofDrawTriangle(500, 350, i, j, (i-20), (j-20));
        }
    }
    
    for(i=500; i>= 150; i-=50){
        for(j=50; j<=350; j+=50){
            ofSetColor(46,i,14,i);
            ofDrawTriangle(500, 350, i, j, (i-20), (j+20));
        }
    }
    
    ofSetColor(58,26,12);
    ofDrawTriangle(500, 350, 590, 500, 610, 490);
   
 
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
