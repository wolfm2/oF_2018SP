#include "ofApp.h"
#include <iostream>
#include <string>

string myString;
ofTrueTypeFont font;

int day = 1;
float sunX = 0;
float lerp = 0;
int sunTime = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    font.loadFont("Borgen.ttf", 12);
    std::string url = "https://api.darksky.net/forecast/1cb351bfb101f005b483023d1ccc0a34/40.7128,-74.0059";

    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful) {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //lerp background
    lerp = ofMap(json["currently"]["time"].asInt(),
                 json["daily"]["data"][0]["sunriseTime"].asInt(),
                 json["daily"]["data"][0]["sunsetTime"].asInt(),
                 0,
                 1);
    ofColor yellow = ofColor::yellow;
    ofColor black = ofColor::black;
    ofSetColor(yellow.lerp(black, lerp));
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //hello
    ofSetColor(255);
    font.drawString("Hello World!", 50, 50);
    
    //tomorrow summary
    ofSetColor(255);
    font.drawString("Summary: ", 50, 100);
    std::string summary  = json["daily"]["data"][day]["summary"].asString();
    font.drawString(summary, 180, 100);
    
    //tomorrow high temp
    ofSetColor(255);
    font.drawString("High: ", 50, 150);
    std:: string high = json["daily"]["data"][day]["temperatureHigh"].asString();
    font.drawString(high, 180, 150);
    
    
    //sun drawing
    sunX = ofMap(json["currently"]["time"].asInt(),
                        json["daily"]["data"][0]["sunriseTime"].asInt(),
                        json["daily"]["data"][0]["sunsetTime"].asInt(),
                        0,
                        ofGetWidth());
    ofSetColor(255,140,0);
    ofDrawCircle(sunX, 100, 50);
    
    

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
