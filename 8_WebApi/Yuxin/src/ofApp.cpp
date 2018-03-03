#include "ofApp.h"
#include "ofxJSON.h"
#include <iostream>
#include <string>



ofTrueTypeFont font;
string enterString;
ofxJSONElement json;
int day = 0;
int circleX = 0;
float value = 0;


//--------------------------------------------------------------
void ofApp::setup(){
    font.load("AmaticSC-Bold.ttf", 30);

    string url = "https://api.darksky.net/forecast/b2f3df8e0c99cdbcb97ccf437e9676f3/37.8267,-122.4233";
    json.open(url);  // stores the JSON response data internally.  Returns T/F


}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    int sunrise = json["daily"]["data"][day]["sunriseTime"].asInt();
    int sunset = json["daily"]["data"][day]["sunsetTime"].asInt();
    int currenttime = json["currently"]["time"].asInt();
    
    
    value = ofMap(currenttime, sunrise, sunset, 0,1);
    
    ofColor r = ofColor::yellow;
    ofColor b = ofColor::black;
    ofSetColor(b.lerp(r, value));
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    
    ofSetColor(0, 0, 0);
    ofFill();
    font.drawString(enterString, ofGetWidth() / 2-80, ofGetHeight()-100);
    enterString = "Hello world!";
    
    string summary = json["daily"]["data"][day]["summary"].asString();
    string hightemp = json["daily"]["data"][day]["temperatureHigh"].asString();
 
    font.drawString(summary, 100, 100);
    font.drawString(hightemp, 100, 200);
    
    
    circleX = ofMap(currenttime, sunrise, sunset, 0, ofGetWidth());
    

    ofSetColor(240, 94, 28);
    ofFill();
    ofDrawCircle(circleX, 100, 50);

    

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '0'){
        day = 0;
    }
    if (key == '1'){
        day = 1;
    }
    if (key == '2'){
        day = 2;
    }
    if (key == '3'){
        day = 3;
    }
    if (key == '4'){
        day = 4;
    }
    if (key == '5'){
        day = 5;
    }
    if (key == '6'){
        day = 6;
    }
    if (key == '7'){
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
