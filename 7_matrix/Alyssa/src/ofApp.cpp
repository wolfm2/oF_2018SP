#include "ofApp.h"
ofImage cat;
ofTrueTypeFont font;
string fontString;

float rotateX = 0;
float rotateY = 0;
float rotateZ = 0;

float translateX = 0;
float translateY = 0;

float scaleH = 0.8;
float scaleW = 0.8;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(400, 400);
    cat.load("cat8bit.png");
    font.load("Borgen.ttf", 10);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
   
    
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofScale(scaleW, scaleH);
        ofTranslate(translateX, translateY);
        ofRotateX(rotateX);
        ofRotateY(rotateY);
        ofRotateZ(rotateZ);
        cat.draw(0 - cat.getWidth()/2, 0 - cat.getHeight()/2);
    ofPopMatrix();
    
    font.drawString("Stretch/smush kitty by the whiskers : W/w", 10, 10);
    font.drawString("Stretch/smush kitty by the ears : H/h", 10, 30);
    font.drawString("Tumble kitty upside down: X / x", 10, 50);
    font.drawString("Twirl kitty in circles: Y / y", 10, 70);
    font.drawString("Tilt kitty to and fro: Z / z", 10, 90);
    font.drawString("Left: s  Right: d  Up q  Down: a", 10, 110);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'x') {
        rotateX--;
        cout << "x";
    }
    if(key == 'X')  {
        rotateX++;
        cout << "X";
    }
    if(key == 'y') {
        rotateY--;
        cout << "y";
    }
    if(key == 'Y') {
        rotateY++;
        cout << "Y";
    }
    if(key == 'z') {
        rotateZ--;
        cout << "z";
    }
    if(key == 'Z') {
        rotateZ++;
        cout << "Z";
    }
    if(key == 'q') {
        translateY--;
        cout << "q";
    }
    if(key == 'a') {
        translateY++;
        cout << "a";
    }
    if(key == 's') {
        translateX--;
        cout << "s";
    }
    if(key == 'd') {
        translateX++;
        cout << "d";
    }
    if(key == 'h') {
        scaleH-=0.1;
        cout << "h";
    }
    if(key == 'H') {
        scaleH+=0.1;
        cout << "H";
    }
    if(key == 'w') {
        scaleW-=0.1;
        cout << "w";
    }
    if(key == 'W') {
        scaleW+=0.1;
        cout << "W";
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
