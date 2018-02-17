#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 200;  // speed with which we pursue the mouse
ofPoint rect_pos;

//--------------------------------------------------------------
void ofApp::setup(){
    // macs by default run on non vertical sync, which can make animation very, very fast
    // this fixes that:
    ofSetVerticalSync(true);
    
    // set background:
    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
    rect_pos.set(0, 0);
    
}

//--------------------------------------------------------------
void ofApp::update(){
//    if((rect_pos.x + rect_catchUpSpeed /((mouseX - rect_pos.x)+1))> mouseX){
//        if((mouseX - rect_pos.x)> 0){
//            rect_pos.x+= 1;
//        }else{
//            rect_pos.x-= 1;
//        }
//
//    }else{
        rect_pos.x += rect_catchUpSpeed /((mouseX - rect_pos.x)+1);
    //}
    
//    if((rect_pos.y + rect_catchUpSpeed /((mouseY - rect_pos.y)+1))> mouseY){
//        if((mouseY - rect_pos.y)> 0){
//            rect_pos.y+= 1;
//        }else{
//            rect_pos.y-= 1;
//        }
//    }else{
        rect_pos.y += rect_catchUpSpeed /((mouseY - rect_pos.y)+1);
    //}
    
    std::cout << "value: " << rect_pos.x << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
}

