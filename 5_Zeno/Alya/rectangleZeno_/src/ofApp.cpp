#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = .01f ;
ofPoint rect_catchUpSpeed2;// speed with which we pursue the mouse
ofPoint rect_pos;


//--------------------------------------------------------------
void ofApp::setup(){
    // macs by default run on non vertical sync, which can make animation very, very fast
    // this fixes that:
    ofSetVerticalSync(true);
    
    // set background:
    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
    rect_pos.set(mouseX,mouseY);
//    rect_catchUpSpeed.set(ofRandom(-1.2, 1.2), ofRandom(-1, 1));
//
//    rect_catchUpSpeed2.set(0, ofRandom(0, 0.01));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //please notice that here it started slow and then accelerated, I didnt know how to make it stop when meeting the mouse
    
    rect_pos.x = rect_catchUpSpeed * mouseX + (1+rect_catchUpSpeed) * rect_pos.x;
    rect_pos.y = rect_catchUpSpeed * mouseY + (1+rect_catchUpSpeed) * rect_pos.y;

    
//
//        rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x);
//        rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);
    
//    ofPoint rect_pos;
//
//
//easing in
    
    
    // here the further the mouse go the closer the rect get to her.
//        rect_pos.x = (mouseX + rect_pos.x ) * rect_catchUpSpeed+1;
//        rect_pos.y = (mouseY + rect_pos.y ) * rect_catchUpSpeed+1;
    
    
    // here it's going so fast and skipping the mouse
//    rect_pos.x += rect_catchUpSpeed * (mouseX + rect_pos.x) + (1+rect_catchUpSpeed) * rect_pos.x;
//    rect_pos.y += rect_catchUpSpeed * (mouseY+ rect_pos.y) + (1+rect_catchUpSpeed) * rect_pos.y;
    
    
      // here also it's going so fast and skipping the mouse
//    rect_pos.x = rect_pos.x + (rect_catchUpSpeed+.1)* mouseX;
//    rect_pos.y = rect_pos.y + (rect_catchUpSpeed+.1)* mouseY;
    
//    rect_catchUpSpeed += rect_catchUpSpeed2;
//    rect_pos += rect_catchUpSpeed;
//

   
//            rect_pos.x = (rect_catchUpSpeed * mouseX ) + rect_pos.x;
//            rect_pos.x+1;
//
//            rect_pos.y = (rect_catchUpSpeed * mouseY )+ rect_pos.y;
//            rect_pos.y+1;
   
    
    //this goes to fast you cant even see iy
//    rect_pos.x += (rect_catchUpSpeed + rect_pos.x)* mouseX ;
//    rect_pos.y += (rect_catchUpSpeed + rect_pos.y) * mouseY;
    
    
//    rect_pos.x -=  rect_catchUpSpeed * mouseX + (rect_catchUpSpeed+1) * rect_pos.x;
//    rect_pos.y -=  rect_catchUpSpeed * mouseY + (rect_catchUpSpeed+1) * rect_pos.y;

    
//    rect_pos.x =  (rect_catchUpSpeed+1) * mouseX  * rect_pos.x;
//    rect_pos.y =  (rect_catchUpSpeed+1) * mouseY  * rect_pos.y;

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position حط الانكر بوينت في السنتر
    ofSetColor(255,255,255);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
    
    
  
    
    
}
