#include "ofApp.h"
#include "ofMain.h"

Zeno zeno1;
Zeno zeno2;
Zeno zeno3;
Zeno zeno4;
Zeno zeno5;

Zeno :: Zeno (){
    
    posX=ofRandom(0, 800);
    posY=ofRandom(0, 800);


    cuSpeed = ofRandom(0,0.05);
    
    r= ofRandom(0,255);
    g= ofRandom(0,255);
    b= ofRandom(0,255);
    

}

void Zeno :: update(float mX, float mY){
    //rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x);
    posX+= cuSpeed*(mX-posX);
    posY+= cuSpeed*(mY-posY);
    ofLog(posX);
    ofLog(posY);
}



void Zeno :: draw(){
    
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(r,g,b);
    ofDrawRectangle(posX,posY, 20,20);
}

//float rect_catchUpSpeed = 0.01f;  // speed with which we pursue the mouse
//ofPoint rect_pos;

//--------------------------------------------------------------
void ofApp::setup(){
    // macs by default run on non vertical sync, which can make animation very, very fast
    // this fixes that:
    ofSetVerticalSync(true);
    
    // set background:
    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x);
//    rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);
    
    zeno1.update(mouseX,mouseY);
    zeno2.update(mouseX,mouseY);
    zeno3.update(mouseX,mouseY);
    zeno4.update(mouseX,mouseY);
    zeno5.update(mouseX,mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofFill();
//    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
//    ofSetColor(198,246,55);
//    ofRect(rect_pos.x,rect_pos.y, 20,20);
    zeno1.draw();
    zeno2.draw();
      zeno3.draw();
      zeno4.draw();
      zeno5.draw();
}
