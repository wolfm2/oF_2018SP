#include "ofApp.h"
#include "ofMain.h"

float rect_catchupspeed = 0.00001f;

float rect_maxspeed = 1;

ofPoint rect_pos;



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    ofSetFrameRate(10);
    
    ofEnableAlphaBlending();
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    rect_pos.x += rect_catchupspeed * (mouseX - rect_pos.x);
    rect_pos.y += rect_catchupspeed * (mouseY - rect_pos.y);
    
    if((rect_pos.x!=mouseX)&&(rect_pos.y!=mouseY)){
        if(rect_catchupspeed <= rect_maxspeed){
            rect_catchupspeed = rect_catchupspeed * 2;
        }else{
            rect_catchupspeed = 0.00001;
            
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(255);
    ofRect(rect_pos.x, rect_pos.y, 30, 30);

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
