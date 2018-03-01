#include "ofApp.h"
ofImage soldier;
ofTrueTypeFont font;
string enterString;


//--------------------------------------------------------------
void ofApp::setup(){
    soldier.load("soldier.png");
    font.load("SketchGothicSchool.ttf",50);
    
}

float rX = 0;
float rY = 0;
float rZ = 0;
float tV = 0;
float tH = 0;
float sH = 0;
float sW = 0;


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    


    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(0.2+sW, 0.2+sH,0.2);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    soldier.draw(0-ofGetWidth()/2+tH,0-ofGetHeight()/2+tV);
    ofPopMatrix();
    
//    ofFill();
//    ofSetColor(0, 0, 0);
    font.load("SketchGothicSchool.ttf",30);
    font.drawString(enterString, ofGetWidth() / 2-150, ofGetHeight()-100);
    font.load("SketchGothicSchool.ttf",25);
    font.drawString("Width: w/W", 30, 50);
    font.drawString("Height: h/H", 30, 100);
    font.drawString("Rotate by X axis: x/X", 30, 150);
    font.drawString("Rotate by Y axis: y/Y", 30, 200);
    font.drawString("Rotate by Z axis: z/Z", 30, 250);
    font.drawString("Position: a/d/s/q", 30, 300);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    enterString = "You are entering:  " ;
    
    if (key == 'x'){
        rX--;
        enterString += 'x';
    }
    if (key == 'X'){
        rX++;
        enterString += 'X';
    }
    if (key == 'y'){
        rY--;
        enterString += 'y';
    }
    if (key == 'Y'){
        rY++;
        enterString += 'Y';
    }
    if (key == 'z'){
        rZ--;
        enterString += 'z';
    }
    if (key == 'Z'){
        rZ++;
        enterString += 'Z';
    }
    if (key == 'q'){
        tV--;
        enterString += 'q';
    }
    if (key == 's'){
        tV++;
        enterString += 's';
    }
    if (key == 'a'){
        tH--;
        enterString += 'a';
    }
    if (key == 'd'){
        tH++;
        enterString += 'd';
    }
    if (key == 'h'){
        sH-=0.1;
        enterString += 'h';
    }
    if (key == 'H'){
        sH+=0.1;
        enterString += 'H';
    }
    if (key == 'w'){
        sW-=0.1;
        enterString += 'w';
    }
    if (key == 'W'){
        sW+=0.1;
        enterString += 'W';
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
