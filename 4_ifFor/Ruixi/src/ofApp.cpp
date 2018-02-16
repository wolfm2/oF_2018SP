#include "ofApp.h"


int mouseX = 0;
int mouseY = 0;
ofFbo fbo;
ofColor insideBall(0,0,0);
//--------------------------------------------------------------
void ofApp::setup(){



//    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
//    fbo.begin();
//      ofClear(0, 0, 0, 50);
//    fbo.end();
//
//
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    int moveX = ofMap(mouseX, 0, ofGetWidth(), 0, 50);
    int moveY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
//    int y = 100;
    
    for(int x=0; x < ofGetWidth(); x += moveX + 20){
       
        
        for(int y=0; y < ofGetHeight(); y += moveY + 20){
            int mouseDistY = abs(y-mouseY);
            if(mouseDistY < 100 && mouseDistY > 50 || mouseDistY > ofGetHeight()/2+20){
                ofSetColor(ofRandom(170, 200), 10, x%170);
                ofNoFill();
                ofDrawRectangle(x-10, y-10, 30,30);
               
            }else{
                
                ofSetColor(ofRandom(200),0,255);
                ofFill();
                ofDrawCircle(x, y, 20);
        
            }
            
//            if(y > 100){
//
//                fbo.begin();
//                ofSetColor(0, 0, 0,20);
//                ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 50);
//                ofSetColor(insideBall);
//                ofFill();
//                ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 10);
//                fbo.end();
//
//                fbo.draw(0,0);
//            }
             x += 5;
             y += 5;
        
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
