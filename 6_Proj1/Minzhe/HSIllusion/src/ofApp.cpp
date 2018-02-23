#include "ofApp.h"
#include <iostream>
using namespace std;

ofImage beehouse, person, bee, bee2;
ofFbo fbo; // framebuffer object
ofColor honey(190,114,41); // yellow
ofColor white(255,255,255);
ofSoundPlayer wen;
ofPoint b_pos;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    fbo.allocate(ofGetWidth(),ofGetHeight(),GL_RGB32F);
    beehouse.load("beehouse2.png");
    person.load("person.png");
    bee.load("bee.png");
    bee2.load("bee2.png");
    wen.loadSound("bee.wav");
    wen.setMultiPlay(true);
    fbo.begin();
    ofClear(255, 255, 255,0);
    fbo.end();
    ofBackground(white);
}
float tX=0;
float tY=0;
float rX=0;
float rY=0;
bool x,X,y,Y;
float mouseX=0;
float mouseY=0;
float bee_catchUpSpeed=0.01f;

//--------------------------------------------------------------
void ofApp::update(){
    if(x == true){
        rX++;
        wen.setSpeed(ofRandom(0.8,1.2));
        wen.play();
    }
    if(X == true){
        rX--;
    }
    if(y == true){
        rY++;
    }
    if(Y == true){
        rY--;
    }
    b_pos.x += bee_catchUpSpeed*(mouseX-b_pos.x);
    b_pos.y += bee_catchUpSpeed*(mouseY-b_pos.y);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofSetColor(white,10);//background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(honey);
    ofFill();
    ofDrawCircle(mouseX, mouseY, 5);
    ofSetLineWidth(2);
    ofDrawLine(mouseX, mouseY, mouseX+10, mouseY+10);
    fbo.end();

    ofSetColor(ofRandom(200, 255),255,255);
    fbo.draw(0,0);
//    how does this draw function work? if it draws everyframe,
//    why it can't cover the picture I draw at the first frame??
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(0.6, 0.6);
    beehouse.draw(0-beehouse.getWidth()/2, 0-beehouse.getHeight()/2);
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(ofGetWidth()/4, ofGetHeight()/2);
    ofScale(0.3, 0.3);
    person.draw(0-person.getWidth()/2, 0-person.getHeight()/2);
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(ofGetWidth()*3/4, ofGetHeight()/2);
    ofTranslate(tX, tY);
    ofRotateX(rX);
    ofRotateY(rY);
    ofScale(0.3, 0.3);
    bee.draw(0-bee.getWidth()/2, 0-bee.getHeight()/2);
    ofPopMatrix();
    
//    ofPushMatrix();
//    ofScale(0.3, 0.3);
//    ofTranslate(ofGetWidth(), ofGetHeight());
//    bee.draw(0-bee.getWidth()/2, 0-bee.getHeight()/2);
//    ofPopMatrix();
    //why the coordinate is different from the previous one if I use the same photo??
    
    ofPushMatrix();
    ofScale(0.03, 0.03);
    ofTranslate(ofGetWidth()/4, ofGetHeight()/4);
    bee2.draw(b_pos.x, b_pos.y);
    ofPopMatrix();
    
    ofSetColor(honey);
    ofDrawBox(b_pos.x, b_pos.y, 0, 20);
//    ofDrawRectRounded(b_pos.x, b_pos.y, 10, 10, 2);
    
    //how to draw hexagon??
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case 'x':
            x= true;
        case 'X':
            x= true;
        case 'y':
            y= true;
        case 'Y':
            Y= true;
        case 'w':
            tY -= 10;
        case 's':
            tY += 10;
        case 'a':
            tX -= 10;
        case 'd':
            tX += 10;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key){
        case 'x':
            x= false;
        case 'X':
            x= false;
        case 'y':
            y= false;
        case 'Y':
            Y= false;
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouseX= x;
    mouseY= y;

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
