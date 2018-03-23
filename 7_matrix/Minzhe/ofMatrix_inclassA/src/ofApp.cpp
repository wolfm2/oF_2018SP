#include "ofApp.h"
#include <iostream>
#include <string>
using namespace std;

ofImage camomile;
ofTrueTypeFont font;
string enterKey;
/*
 Translate and scale the image to take approximately .25 of the screen and display it in the middle of the window.
 Enable the following keys to affect the image:
 x,X -  y,Y - z,Z: Rotate negatively or positively in this axis
 w,a,s,d: Translate the object by 1 pixel per update
 h,H - w,W: Scale the height/width negatively or positively
 try array!!
 */

float rX=0;
float rY=0;
float rZ=0;
float tX=0;
float tY=0;
float sH=0;
float sB=0;
Boolean x,X,y,Y,z,Z,h,H,b,B;

//--------------------------------------------------------------
void ofApp::setup(){
    camomile.load("camomile.png");
    font.load("baskvl.ttf", 30);
    ofBackground(0, 163, 174);
}
//--------------------------------------------------------------
void ofApp::update(){
    if (x == true){
        rX++;
    }
    if(X == true){
        rX--;
    }
    if (y == true){
        rY++;
    }
    if(Y == true){
        rY--;
    }
    if(ofGetFrameNum()%3==0 && z == true){
        rZ++;
    }
    if(ofGetFrameNum()%3==0 && Z == true){
        rZ--;
    }
    
    if(h == true){
        sH-= 0.01;
    }
    
    if(H == true){
        sH+= 0.01;
    }
    
    if(b == true){
        sB-= 0.01;
    }
    
    if(B == true){
        sB+= 0.01;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofTranslate(tX, tY);
    ofRotateX(rX);
    ofRotateX(rY);
    ofRotateX(rZ);
    ofScale(0.3,0.3,0.3);// can be 3 dimensional
    ofScale(sH+0.3, sB+0.3);
    camomile.draw(0 - camomile.getWidth()/2, 0 - camomile.getHeight()/2);  // draw at new 0,0
    ofPopMatrix();
    
    //font, string
    font.drawString(enterKey, ofGetWidth()/2-50, ofGetHeight()/2+350);
    font.drawString("Width: w/W", 30, 50);
    font.drawString("Height: b/B", 30, 100);
    font.drawString("Rotate by X axis: x/X", 30, 150);
    font.drawString("Rotate by Y axis: y/Y", 30, 200);
    font.drawString("Rotate by Z axis z/Y", 30, 250);
    font.drawString("Position: a/s/d/w", 30, 300);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
        enterKey="You are entering: ";
    
    //why key is defined as int but we can still make it equal to a char or like a punctuation??
        switch(key){
            case 'x':
                x = true;
                enterKey +='x';
                break;
            case 'X':
                X =true;
                enterKey +='X';
                break;
            case 'y':
                y= true;
                enterKey +='y';
                break;
            case 'Y':
                Y=true;
                enterKey +='Y';
                break;
            case 'z':
                z = true;
                enterKey +='z';
                break;
            case 'Z':
                Z = true;
                enterKey +='Z';
                break;
            case 'd':
                tX++;
                enterKey +='d';
                break;
            case 'a':
                tX--;
                enterKey +='a';
                break;
            case 'w':
                tY--;
                enterKey +='w';
                break;
            case 's':
                tY++;
                enterKey +='s';
                break;
            case 'h':
                h = true;
                enterKey +='h';
                break;
            case 'H':
                H = true;
                enterKey +='H';
                break;
            case 'b':
                b = true;
                enterKey +='b';
                break;
            case 'B':
                B = true;
                enterKey +='B';
                break;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key){
        case 'x':
            x = false;
            break;
        case 'X':
            X =false;
            break;
        case 'y':
            y= false;
            break;
        case 'Y':
            Y=false;
            break;
        case 'z':
            z = false;
            break;
        case 'Z':
            Z = false;
            break;
        case 'h':
            h = false;
            break;
        case 'H':
            H = false;
            break;
        case 'b':
            b = false;
            break;
        case 'B':
            B = false;
            break;
            }

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
