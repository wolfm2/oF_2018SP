#include "ofApp.h"
#include "ofxJSON.h"
#include <iostream>
#include <string>

ofxJSONElement json;
ofTrueTypeFont font;
string enterString;

int day = 0;
float lerpValue = 0;
float circleX = 0;
float value = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    string url = "https://api.darksky.net/forecast/ec5ceb450a6a12771498381a307a0255/40.7612,-73.9988";
    json.open(url);

    font.load("mono.ttf", 20);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){


    int sunriseTime = json["daily"]["data"][day]["sunriseTime"].asInt();
    int sunsetTime = json["daily"]["data"][day]["sunSetTime"].asInt();
    int current = json["currently"]["time"].asInt();

    //value = ofMap(<#float value#>, <#float inputMin#>, <#float inputMax#>, <#float outputMin#>, <#float outputMax#>)

    value = ofMap(current, sunriseTime, sunsetTime, 0, 1);

    ofColor r = ofColor::yellow;
    ofColor b = ofColor::black;
    ofSetColor(b.lerp(r, value));

    ofFill();
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());

    ofSetColor(255);
    font.drawString("Summary tomorrow: ", 25, 220);
    string summary = json["daily"]["data"][day]["summary"].asString();

    ofSetColor(255);
    font.drawString("High temprature for tomorrow: ", 25, 350);
    string higtemp = json["daily"]["data"][day]["temperatureHigh"].asString();

    font.drawString(summary, 20, 250);
    font.drawString(higtemp, 20, 380);

    circleX = ofMap(current,sunriseTime,sunsetTime,day,ofGetWidth(),ofGetHeight());
    ofSetColor(255,100,0);
    ofDrawCircle(circleX, 100, 50);


    std::time_t epoch;
    struct tm * day;
    bool currentTime = true;
    if(currentTime) {
        std::time (&epoch);
    }else{
        epoch = 1519981496;
    }
//    epoch = json["daily"]["data"][0]["time"].asInt();
    day = localtime (&epoch);
    font.drawString(asctime(day),300,100);
    
//    std::cout<<std::asctime(day), 300, 100;

//    ofSetColor(255);
//    font.drawString("HI Hello world!!", ofGetWidth()/2, ofGetHeight()/2);
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


