#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;  // speed with which we pursue the mouse
float rect1_catchUpSpeed = 0.02f;
float rect2_catchUpSpeed = 0.03f;
float rect3_catchUpSpeed = 0.04f;
float rect4_catchUpSpeed = 0.05f;
ofPoint rect_pos;
ofPoint rect1_pos;
ofPoint rect2_pos;
ofPoint rect3_pos;
ofPoint rect4_pos;

//--------------------------------------------------------------
void ofApp::setup(){
    // macs by default run on non vertical sync, which can make animation very, very fast
    // this fixes that:
    ofSetVerticalSync(true);

    // set background:
    ofEnableAlphaBlending();
    ofBackground(200,200,100);

}

//--------------------------------------------------------------
void ofApp::update(){

    rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x);
    rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);
    
    rect1_pos.x += rect1_catchUpSpeed * (mouseX - rect1_pos.x);
    rect1_pos.y += rect1_catchUpSpeed * (mouseY - rect1_pos.y);
    
    rect2_pos.x += rect2_catchUpSpeed * (mouseX - rect2_pos.x);
    rect2_pos.y += rect2_catchUpSpeed * (mouseY - rect2_pos.y);
    
    rect3_pos.x += rect3_catchUpSpeed * (mouseX - rect3_pos.x);
    rect3_pos.y += rect3_catchUpSpeed * (mouseY - rect3_pos.y);
    
    rect4_pos.x += rect4_catchUpSpeed * (mouseX - rect4_pos.x);
    rect4_pos.y += rect4_catchUpSpeed * (mouseY - rect4_pos.y);
    



}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 10,10);
    ofSetColor(140,80,40);
    ofRect(rect1_pos.x, rect1_pos.y, 10,10);
    ofSetColor(140,180,40);
    ofRect(rect2_pos.x, rect2_pos.y, 10,10);
    ofSetColor(140,80,140);
    ofRect(rect3_pos.x, rect3_pos.y, 10,10);
    ofSetColor(200,80,40);
    ofRect(rect4_pos.x, rect4_pos.y, 10,10);
}


