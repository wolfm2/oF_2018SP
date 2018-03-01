#include "ofApp.h"
#include "ofxJSON.h"
#include <iostream>
#include <string>



ofxJSONElement json; // JSON reader
string enterString;
ofTrueTypeFont font;

using namespace std;
int main();

int day = 0;
int circleX = 0;
float value = 0;



//--------------------------------------------------------------
void ofApp::setup(){

    
    string url = "https://api.darksky.net/forecast/b26addef80e8df9aa1e2ff19ab05f23d/37.8267,-122.4233";
    json.open(url);
    
    font.load("vag.ttf", 15);


}



//--------------------------------------------------------------
void ofApp::update(){
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int sunrise = json["daily"]["data"][day]["sunriseTime"].asInt();
    int sunset = json["daily"]["data"][day]["sunsetTime"].asInt();
    int currenttime = json["currently"]["time"].asInt();
    
    
    value = ofMap(currenttime, sunrise, sunset, 0, 1);
    
    ofColor y = ofColor::yellow;
    ofColor b = ofColor::black;
    ofColor(b.lerp(y, value));
    
    value = ofMap(currenttime, sunrise, sunset, 0 , 1);
    
    
//    ofColor inbetween = yellow.lerp(black, value);
    
    ofSetColor(b.lerp(y, value));
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()); //This is the Lerp Color ffor the yellow/black-ish background, instead of setting it in the background I will draw a circle
    
    
//    ofSetColor (0,0,0);
//    font.drawString(enterString, ofGetWidth() / 2 - 90, ofGetHeight () / 2 - 90);
//    enterString = "Hello World!";

    string summary = json["daily"]["data"][day]["summary"].asString();
    string hightemp = json["daily"]["data"][day]["temperatureHigh"].asString();

    ofSetColor (0,0,0);
    font.drawString(summary, 20, 250);
    font.drawString(hightemp, ofGetWidth() / 2, 350);



    circleX = ofMap(currenttime, sunrise, sunset, day, ofGetWidth(), ofGetHeight());
    ofSetColor(255,165,0);
    ofDrawCircle(circleX, 100,50);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == '0') {
        day = 0;
    }
    
    if (key == '1') {
        day = 1;
    }
    
    if (key == '2') {
        day = 2;
    }
    
    if (key == '3') {
        day = 3;
    }
    
    if (key == '4') {
        day = 4;
    }
    
    if (key == '5') {
        day = 5;
    }

    if (key == '6') {
        day = 6;
    }
    
    if (key == '7') {
        day = 7;
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
