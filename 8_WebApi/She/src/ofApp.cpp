#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //summary: when you press key 0-7, you will get the weather report, and background color change and orange circle will change
    
    
    //load font
    ofSetFrameRate(60);
    myFont.load("mono.ttf",16);
    ofSetCircleResolution(1000);
    
    string url = "https://api.darksky.net/forecast/81bc79dc54f45369dc001ff358c5857f/40.7370764,-74.0009978";
    
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
   


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    lerpPct = ofMap(json["currently"]["time"].asInt(), json["daily"]["data"][day]["sunriseTime"].asInt(), json["daily"]["data"][day]["sunsetTime"].asInt(), 0, 1);
    
    ofColor black = ofColor(0, 0, 0);
    ofColor yellow = ofColor(255, 255, 0);
    
    ofColor background = black.lerp(yellow, lerpPct);
    ofSetColor(background);
    ofBackground(background);
    
    
    ofSetColor(255, 150, 0);
    xPos = ofMap(json["currently"]["time"].asInt(), json["daily"]["data"][day]["sunriseTime"].asInt(), json["daily"]["data"][day]["sunsetTime"].asInt(), 0, ofGetWindowWidth(), 1);
    ofDrawCircle(ofPoint(xPos, 100), 50);
    
    ofSetColor(0);
    ofDrawBitmapString("Hello World", 50, 50);
    ofDrawBitmapString(json["daily"]["data"][day]["summary"], 130, 100);
    ofDrawBitmapString(json["daily"]["data"][day]["temperatureMax"], 260, 150);
    
    myFont.drawString("Summary:", 20, 100);
    myFont.drawString("High Temperature:", 20, 150);
    myFont.drawString("Day 0", 20, 200);
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '0') {
        day = 0;
        
    }
    
    if(key == '1') {
        day = 1;
        cout<<"1";
    }
    
    if(key == '2') {
        day = 2;
        cout<<"2";
    }
    
    if(key == '3') {
        day = 3;
        cout<<"3";
    }
    
    if(key == '4') {
        day = 4;
        cout<<"4";
    }
    
    if(key == '5') {
        day = 5;
        cout<<"5";
    }
    
    if(key == '6') {
        day = 6;
        cout<<"6";
    }
    
    if(key == '7') {
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
