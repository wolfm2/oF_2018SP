#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);
    ofSetCircleResolution(1000);

    // lat and lon 40.7370764, -74.0009978, which should be D12
    string url = "https://api.darksky.net/forecast/81bc79dc54f45369dc001ff358c5857f/40.7370764,-74.0009978";

    bool parsingSuccessful = json.open(url);

    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }

    //json.save("data.json");
    //json.open("data.json");
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    lerpPct = ofMap(json["currently"]["time"].asInt(), json["daily"]["data"][day]["sunriseTime"].asInt(), json["daily"]["data"][day]["sunsetTime"].asInt(), 0, 1);
    
    ofColor black = ofColor(0, 0, 0);
    ofColor yellow = ofColor(255, 255, 0);
    
    ofBackground(yellow.lerp(black, lerpPct));

    ofSetColor(255, 150, 0);
    xPos = ofMap(json["currently"]["time"].asInt(), json["daily"]["data"][day]["sunriseTime"].asInt(), json["daily"]["data"][day]["sunsetTime"].asInt(), 0, ofGetWindowWidth(), 1);
    ofDrawCircle(ofPoint(xPos, 100), 50);

    ofSetColor(255, 255, 255);
    ofDrawBitmapString("Hello World", 50, 50);
    ofDrawBitmapString(json["daily"]["data"][day]["summary"], 50, 100);
    ofDrawBitmapString(json["daily"]["data"][day]["temperatureMax"], 50, 150);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if(key == '0') {
        day = 0;
    }

    if(key == '1') {
        day = 1;
    }
    
    if(key == '2') {
        day = 2;
    }

    if(key == '3') {
        day = 3;
    }

    if(key == '4') {
        day = 4;
    }

    if(key == '5') {
        day = 5;
    }

    if(key == '6') {
        day = 6;
    }
    
    if(key == '7') {
        day = 7;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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