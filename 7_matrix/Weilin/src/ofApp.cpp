#include "ofApp.h"
ofImage rec;

//--------------------------------------------------------------
void ofApp::setup(){
    rec.load("01.jpg");
}
float rotateX = 0;
float rotateY = 0;
float rotateZ = 0;

float transX = 0;
float transY = 0;

float scaleH = 1;
float scaleW = 1;

//--------------------------------------------------------------
void ofApp::update(){
    //rotateX++;
    //if (ofGetFrameNum() % 3 == 0)
    //rotateY++;
    //if (ofGetFrameNum() % 7 == 0)
    //rotateZ++;

}
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(0.8, 0.8, 0.8);  // can be 3 dimensional
    ofRotateX(rotateX);
    ofRotateY(rotateY);
    ofRotateZ(rotateZ);
    ofTranslate(transX, transY);
    ofScale(scaleW,scaleH);
    rec.draw(0 - rec.getWidth()/2, 0 - rec.getHeight()/2);  // draw at new 0,0
    ofPopMatrix();
    
    


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
      if(key=='x'){
        cout << "low";
          
    }
    

    if(key == 'x' ){
        rotateX ++;
    }
    
    if(key =='y'){
        rotateY ++;
    }
    
    if(key == 'z' ){
        rotateZ ++;
    }
    
    if (key =='X'){
        rotateX --;
    }

    if (key =='Y'){
        rotateY --;
    }
    
    if(key == 'Z' ){
        rotateZ ++;
    }
    
    if(key == 'q' ){
        transX ++;
    }
    
    if(key =='a'){
        transY ++;
    }
    
    if(key == 's' ){
        transX --;
    }
    
    if(key =='d'){
        transY --;
    }
    
    
    if(key == 'h' ){
        scaleH +=0.3;
    }
    
    if(key =='w'){
        scaleW +=0.3;
    }
    
    if(key == 'H' ){
        scaleH -=0.3;
    }
    
    if(key =='W'){
        scaleW -=0.3;
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
