#include "ofApp.h"

float rect_catchUpSpeed = 0.01f;
ofPoint rect_pos;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetWindowShape(792, 612);
    ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
float rX = 0;
float rY = 0;
float rZ = 0;

void ofApp::update(){
    rect_pos.x += rect_catchUpSpeed * (ofGetMouseX() - rect_pos.x);
    rect_pos.y += rect_catchUpSpeed * (ofGetMouseY() - rect_pos.y);
    
    rX++;
//    rY++;
//    rZ++;
}

//--------------------------------------------------------------


void ofApp::draw(){
    ofSetColor(223, 180, 41);
    ofDrawRectangle(0, 0, 388, 60.28);
    ofDrawRectangle(0, 151.02, 108.38, 345.57);
    ofDrawRectangle(124.74, 507.28, 263.26, 104.72);
    ofDrawRectangle(522.53, 151.02, 195.05, 73.53);
    
    ofSetColor(0, 0, 0);
    ofDrawRectangle(0, 60.28, 388, 10.71);
    ofDrawRectangle(388, 0, 134.47, 140.32);
    ofDrawRectangle(0, 140.31, 717.59, 10.71);
    ofDrawRectangle(108.38, 140.31, 16.37, 471.68);
    ofDrawRectangle(124.74, 224.54, 593.15, 10.71);
    ofDrawRectangle(10.71, 496.58, 500.93, 10.71);
    ofDrawRectangle(522.53, 577.91, 195.05, 10.71);
    ofDrawRectangle(0, 496.58, 11.5, 115.42);
    ofDrawRectangle(387.82, 151.02, 12.85, 460.99);
    ofDrawRectangle(509.69, 140.31, 12.85, 471.69);
    ofDrawRectangle(717.59, 0, 12.85, 340.56);
    ofDrawRectangle(717.59, 340.56, 74.41, 271.44);
    
    
    ofSetColor(177,31,35);
    ofDrawRectangle(124.74, 151.02, 263.26, 73.53);
    ofDrawRectangle(124.74, 235.25, 263.26, 261.33);
    
    ofSetColor(27, 42, 83);
    ofDrawRectangle(522.53, 235.25, 195.05, 105.56);
    ofDrawRectangle(400.78, 507.28, 108.91, 104.72);
    
    
    if ( (rect_pos.x<388 && rect_pos.y<60.28) || (0<rect_pos.x && rect_pos.x<108.38 && 151.02 < rect_pos.y && rect_pos.y<496.58) || (387.82 > rect_pos.x && rect_pos.x >124.74 && rect_pos.y>507.28) || (rect_pos.x>522.52 && rect_pos.x<717.59 && rect_pos.y>151.02 && rect_pos.y<224.54))
        
        {
//            ofSetColor(0,0,0);
//            ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 11);
            
            ofPushMatrix();
                ofTranslate(rect_pos.x, rect_pos.y);
                ofRotateX(rX);
                ofRotateY(rY);
                ofRotateZ(rZ);
                ofSetColor(177,31,35);
                ofDrawCircle(rect_pos.x, rect_pos.y, 10);
            ofPopMatrix();
        }
    
    
    
    else if ( (rect_pos.x>388 && rect_pos.x<522.47 && rect_pos.y<140.32) || (717.59<rect_pos.x && 340.56 < rect_pos.y) )
        
    {
//        ofSetColor(255,255,255);
//        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 11);
        ofSetColor(255, 255, 255);
        ofDrawCircle(rect_pos.x, rect_pos.y, 10);
    }
    
    else if ( (rect_pos.x>124.74 && rect_pos.x<388 && rect_pos.y<224.54 && rect_pos.y>151.02) || (rect_pos.x>124.74 && rect_pos.x<388 && rect_pos.y<496.58 && rect_pos.y>235.25) )
        
    {
//        ofSetColor(0,0,0);
//        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 11);
        
        ofSetColor(27, 42, 83);
        ofDrawCircle(rect_pos.x, rect_pos.y, 10);
    }
    
    else if ( (rect_pos.x>522.53 && rect_pos.x<717.59 && rect_pos.y<340.8 && rect_pos.y>235.25) || (rect_pos.x>400.78 && rect_pos.x<509.69 && rect_pos.y>507.28) )
        
    {
//        ofSetColor(0,0,0);
//        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 11);
        ofSetColor(223, 180, 41);
        ofDrawCircle(rect_pos.x, rect_pos.y, 10);
    }
    
    else{
        ofSetColor(0, 0, 0);
        ofDrawCircle(rect_pos.x, rect_pos.y, 10);
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
