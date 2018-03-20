#include "ofApp.h"
#include "ofxJSON.h"
#include <iostream>
#include <string>

ofxJSONElement json;  //JSON reader
string myString;
ofTrueTypeFont font;

using namespace std;


int day = 1; //tomorrow
float sun_X = 0;
float lerpValue = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    
    string url = "https://api.darksky.net/forecast/b1e1de59c719cc46d2869ccec093b2fc/37.8267,-122.4233";
    
    //Parse url returns true or false
    bool urlResponse = json.open(url);
    if(urlResponse){
        ofLogNotice("ofApp::setup")<<json.getRawString(true);
    }else{
        ofLogNotice("ofApp::setup")<< "Parsing Failed.";
    }
    
    font.load("Caviar_Dreams_Bold.ttf", 20);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //Use this with the current time, sunrise, sunset
    //to map a value between 0 - 1.
    //make the background a lerp between yellow (255,255,0) and black.
    lerpValue = ofMap(json["currently"]["time"].asInt(), json["daily"]["data"][0]["sunriseTime"].asInt(),
                      json["daily"]["data"][0]["sunsetTime"].asInt(), 0, 1);
    
    
    ofColor y = ofColor::yellow;
    ofColor b = ofColor::black;
    ofSetColor(y.lerp(b, lerpValue));
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    
    
    //write Hello World on the canvas
    ofSetColor(253,254,255);
    //font.drawString("Hello World", 100, 100);
    
    
    //draw the summary text and high temperature for tomorrow
    string Summary = json["daily"]["data"][day]["summary"].asString();
    font.drawString("Summary text: ", 100, 100);
    font.drawString(Summary, 100, 150);
    
    string Hightemp = json["daily"]["data"][day]["temperatureHigh"].asString();
    font.drawString("High temperature: ", 100, 250);
    font.drawString(Hightemp, 350, 250);
    
    
    //draw an orange circle on the screen at y=100 r=50
    //its x should be a map() using current time, sunrise/sunset,
    //and the width of the canvas
    sun_X = ofMap(json["currently"]["time"].asInt(), json["daily"]["data"][0]["sunriseTime"].asInt(), json["daily"]["data"][0]["sunsetTime"].asInt(), 0, ofGetWidth());
    
    ofSetColor(254,78,0);
    ofDrawCircle(sun_X, 100, 50);
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //use key presses 0-7 to print summary and high temperature
    //for each day in the forcast
    
    if (key == '0') {
        day = 0;
    }else if (key == '1') {
        day = 1;
    }else if (key == '2') {
        day = 2;
    }else if (key == '3') {
        day = 3;
    }else if (key == '4') {
        day = 4;
    }else if (key == '5') {
        day = 5;
    }else if (key == '6') {
        day = 6;
    }else if (key == '7') {
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
