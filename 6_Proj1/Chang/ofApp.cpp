#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;  // speed with which we pursue the mouse
ofPoint rect_pos;    // verticls
ofFbo fbo;
ofColor black(0,0,0);

//--------------------------------------------------------------
void ofApp::setup(){
    // macs by default run on non vertical sync, which can make animation very, very fast
    // this fixes that:
//    ofSetVerticalSync(true);  // 有些时候mac update太快所以调节一下
//    
//    // set background:
//  //  ofEnableAlphaBlending();
//    ofBackground(30,30,30);

    
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts) full color full alpha
    //最精细的
    
    fbo.begin();
    ofClear(255,255,255, 0);  //这边的意思是说清除之前framebuffer剪贴板的内容
    fbo.end();
    
    ofSetBackgroundColor(black);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x);
    rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,255,0);
    ofDrawRectangle(700, 0, ofGetWidth()-700, 1000);
    
    
    fbo.begin();  //
    ofSetColor(black,10); // background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
 
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 60,60);
     ofFill();
    if(rect_pos.x >700){
      rect_pos.x =650;
        //rect_pos.x = ofGetWidth()-760;
    }
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    
    
    fbo.draw(0,0); // t
    
    
    ofSetColor(255,0,0);
    ofDrawCircle(mouseX,mouseY,30);
    
    
   
    
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
