#include "ofApp.h"
#include <iostream>
#include <string>
//--------------------------------------------------------------
void ofApp::setup(){
    
    //load font
    myFont.load("Montserrat-Regular.ttf",18);
    
    //load json url
    std::string url = "https://api.darksky.net/forecast/3ff901c8a03450814bbf0ecb7d29b55f/40.7128,-74.0059";
    json.open(url);
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    //set background lerp colour
    
    //ofColor black = ofColor ( 0 , 0 , 0 ) ;
    //ofColor yellow = ofColor ( 255 , 255 , 0 ) ;
    
    //ofColor background = black.lerp(yellow, 0.2f);
    //ofSetColor(background);
    //ofBackground(background);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw background
    backgroundLerp = ofMap(currentTime, sunriseTime, sunsetTime, 0, 1);
    ofColor black = ofColor ( 0 , 0 , 0 ) ;
    ofColor yellow = ofColor ( 255 , 255 , 0 ) ;
    
    ofColor background = black.lerp(yellow, backgroundLerp);
    ofSetColor(background);
    ofBackground(background);
    
    //draw "hello world"
    ofSetColor(255);
    myFont.drawString("Hello World!", 100, 100);
    
    //Draw the summary text and high temperature for tomorrow on the canvas
    summaryText  = json["daily"]["data"][day]["summary"].asString();
    highTemperature  = json["daily"]["data"][day]["temperatureHigh"].asString();
    
    myFont.drawString("Summary: " + summaryText, 100, 200);
    myFont.drawString("High temperature: " + highTemperature, 100, 300);
    
    //Draw an orange circle on the screen at y=100 r=50.  Its X should be a map() using our current time, sunrise/sunset, and the width of the canvas
    
    //ofSetColor(255,140,0); //orange
    
    sunriseTime = json["daily"]["data"][day]["sunriseTime"].asInt();
    sunsetTime = json["daily"]["data"][day]["sunsetTime"].asInt();
    currentTime = json["currently"]["time"].asInt();
    
    circlePosX = ofMap(currentTime, sunriseTime, sunsetTime, 0, ofGetWidth());
    ofSetColor(255,140,0); //orange
    ofDrawCircle(circlePosX, 100, 50);
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //Use key presses 0-7 to print the above for each day in the forecast
    if(key == '0'){
        day = 0;
        cout<<"0";
    }
    if(key == '1'){
        day = 1;
        cout<<"1";
    }
    if(key == '2'){
        day = 2;
        cout<<"2";
    }
    if(key == '3'){
        day = 3;
        cout<<"3";
    }
    if(key == '4'){
        day = 4;
        cout<<"4";
    }
    if(key == '5'){
        day = 5;
        cout<<"5";
    }
    if(key == '6'){
        day = 6;
        cout<<"6";
    }
    if(key == '7'){
        day = 7;
        cout<<"7";
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
