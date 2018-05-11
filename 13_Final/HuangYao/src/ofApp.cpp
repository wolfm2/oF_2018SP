#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFullscreen(true);
    mySound.load("break.mp3");
    mySound.play();
    
    leap.open();
    
    ofDisableArbTex();
    ofSetVerticalSync(true);
    
    ofBackground(0);
    ofSetFullscreen(true);
    
   // ofSetFrameRate(60);
    //ofSetVerticalSync(true);
    //ofSetLogLevel(OF_LOG_VERBOSE);
    
   
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    
    for(int i=0; i< 22; i++){
        sentences[i].setup(source[i]);
    }
    b.set(ofGetWindowWidth(),ofGetWindowHeight());
    background.load("pm.png");
    cam.setup(600,480,true);
    sphere.setRadius(100);
    ofSetSphereResolution(24);
    myPlayer.load("22222.mov");
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0; i< 22; i++){
        sentences[i].update();
    }
    
    fingersFound.clear();
    
    simpleHands = leap.getSimpleHands();
    
    if( leap.isFrameNew() && simpleHands.size() ){
        
        leap.setMappingX(-200, 200, 0, ofGetWidth());
        leap.setMappingY(300, 600, 0, ofGetHeight());
        leap.setMappingZ(-150, 150, -200, 200);
    }
    
    int count = 0;
    
    for(int i=0; i< simpleHands.size(); i++){
        handPos = simpleHands[i].handPos;
        for(int i=0; i< 22; i++){
            if(handPos.x> sentences[i].pos[0].x- 20 && handPos.x< sentences[i].pos[0].x+ 200 && handPos.y> sentences[i].pos[0].y- 10 && handPos.y< sentences[i].pos[0].y+ 20){
                sentences[i].split= true;
            }
        }
    }
    
    leap.markFrameAsOld();
    cam.update();
    myPlayer.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(state==1){
        myPlayer.draw(0,0,ofGetWindowWidth(),ofGetWindowHeight());
        myPlayer.play();
        if(frame>200){
            myPlayer.setPaused(true);
            
        }
        frame=myPlayer.getCurrentFrame();
    }else{
        background.draw(0,0,ofGetWindowWidth(),ofGetWindowHeight())
    }
    for(int i=0; i<simpleHands.size();i++){
        handPos=simpleHands[i].handPos;
        ofSetColor(255);
        ofDrawCircle(handPos.x,handPos.y,10);
    }
    
    for(int i=0; i< 22; i++){
        sentences[i].draw();
    }
    if(state==0){
        cam.getTexture().bind();
        sphere.setPosition(ofGetWindowWidth()/2,ofGetWindowHeight()/2,0);
        sphere.draw();
        cam.getTexture().unbind();
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(int i=0; i< 22; i++){
        sentences[i].split= true;
    }
    if(key == 'R'){
        mySound.play();
    }
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

void ofApp::exit(){
    // let's close down Leap and kill the controller
    leap.close();
}

