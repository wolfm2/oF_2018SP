#include "ofApp.h"

#include <iostream>
#include <string>

string myString;
//ofTrueTypeFont font;

int num = 0;
float sunX = 0;
float lerp = 0;
int sunTime = 0;

//--------------------------------------------------------------
void ofApp::setup(){
//    font.loadFont("Borgen.ttf", 12);
    std::string url = "https://api.darksky.net/forecast/11986ae43a4ea3ae397cbd7bcce041d5/37.8267,-122.4233";
    
    
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
    
    ofBackground(0);
    ofSetColor(255);
    
    //lerp background
    lerp = ofMap(json["currently"]["time"].asInt(),
                 json["daily"]["data"][0]["sunriseTime"].asInt(),
                 json["daily"]["data"][0]["sunsetTime"].asInt(),
                 0,
                 1);
    
    ofSetColor(yellow.lerp(black, lerp));
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    
    //Draw the summary text and high temperature for tomorrow on the canvas.
    summaryText  = json["daily"]["data"][num]["summary"].asString();
    highTemperature  = json["daily"]["data"][num]["temperatureHigh"].asString();
    
    //print the information we get in JSON to canvas
    ofDrawBitmapString(summaryText, 120,140);
    ofDrawBitmapString(highTemperature, 120,200);
    ofDrawLine(10,230,1000,230);
    
    
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
    
    //Use key presses 0-7 to print the above for each day in the forecast.
    
    if (key == '0'){
        num =0;
        //      std::string highTemperature  = json["daily"]["data"][0]["temperatureHigh"].asString();
        //      std::string summaryText  = json["daily"]["data"][0]["summary"].asString();
        
        cout<<"low";    }
    
    if (key == '1'){
        num =1;
        
        cout<<"1";    }
    
    if (key == '2'){
        num =2;
        
        cout<<"2";    }
    
    if (key == '3'){
        num =3;
        
        cout<<"3";    }
    
    if (key == '4'){
        num =4;
        cout<<"4";    }
    
    if (key == '5'){
        num =5;
        
        cout<<"5";    }
    
    if (key == '6'){
        num =6;
        
        cout<<"6";    }
    
    if (key == '7'){
        num =7;
        
        cout<<"7";    }
    
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
