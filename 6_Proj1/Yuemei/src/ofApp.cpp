#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
//    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
//    fbo.begin();
//    ofClear(247, 194, 66);
//    fbo.end();
    
    posx=-40;
    posy=-90;
    
    mySound.load("music.mp3");
    mySound.play();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    reactPos.x += catchUpSpeed * (mouseX - reactPos.x);
    reactPos.y += catchUpSpeed * (mouseY - reactPos.y);

    }


//--------------------------------------------------------------
void ofApp::draw(){
    
// shape 1 mix color
    ofSetColor(orange);
    ofDrawTriangle(70, 300, 310, 250, 200, 90);
    
    if(mouseX > 70 && mouseX < 330 && mouseY > 90 && mouseY < 250){
        bShape1Act = true;
    }else{
        bShape1Act = false;
    }


 //shape 2 change position
    if(mouseX > 340 && mouseX < 590 && mouseY > 500 && mouseY < 638){
        bShape2Act = true;
    }else{
        bShape2Act = false;
    }

    

// shape 3 circle color change
    ofSetColor(green);
    ofDrawCircle(800, 170, 100);
    if(mouseX > 700 && mouseX < 900 && mouseY > 70 && mouseY < 270){
        bShape3Act = true;
//        fboAct = false;
    }else{
        bShape3Act = false;
//        fboAct = true;
    }


    
    
// bool
    if(bShape1Act){
        ofSetColor(cShape1Act);
        posx=0;
        posy=0;
    }else if(bShape2Act){
        posx=-40;
        posy=-90;
        ofSetColor(normal);
    }else if(bShape3Act){
        posx=0;
        posy=0;
        ofSetColor(cShape3Act);
    }else{
        posx=0;
        posy=0;
        ofSetColor(normal);
    }
    
    

    ofPushMatrix();
    ofPushStyle();
    ofTranslate(400, 500);
    ofSetColor(blue);
    ofDrawRectangle(posx, posy, 250, 138);
    ofPopStyle();
    ofPopMatrix();
    
//    fbo.begin();
//    ofSetColor(normal, 90);
    ofDrawCircle(mouseX, mouseY, 20);
//    fbo.end();
//
////    ofSetColor(normal);
//    fbo.draw(0, 0);
    
    
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
