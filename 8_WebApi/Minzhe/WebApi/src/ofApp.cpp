#include "ofApp.h"
#include <iostream>
#include <string>

//--------------------------------------------------------------

ofTrueTypeFont font;
string h="Hello World";

float lerp;
float circlePos_x;
int day;

void ofApp::setup(){
    ofSetWindowShape(1600, 1200);
    ofSetCircleResolution(200);
    //why I can't initiate a string and use cout to print it
    std:: string url="https://api.darksky.net/forecast/79c3ea8fb41f4b050f2b063d350e1e40/40.7128,-74.0059";
    font.load("Batang.ttf", 30);
    //now parse the JSON
    bool parsingSuccessful = json.open(url);
    
    if(parsingSuccessful){
        ofLogNotice("ofApp::setup")<<json.getRawString(true);
    }else{
        ofLogNotice("ofApp::setup")<<"Failed to parson JSON.";
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //lerp background from yellow to black
    lerp=ofMap(json["currently"]["time"].asInt(), json["daily"]["data"][0]["sunriseTime"].asInt(), json["daily"]["data"][0]["sunsetTime"].asInt(), 0, 1);
    ofColor yellow=ofColor:: yellow;
    ofColor black=ofColor:: black;
    ofSetColor(yellow.lerp(black, lerp));
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //draw an orange circle mapping current time
    circlePos_x=ofMap(json["currently"]["time"].asInt(), json["daily"]["data"][0]["sunriseTime"].asInt(), json["daily"]["data"][0]["sunsetTime"].asInt(),0,ofGetWidth(),true);
    ofSetColor(ofColor::orange);
    ofFill();
    ofDrawCircle(circlePos_x, 100, 50);
    
    //draw string on canvas
    ofSetColor(ofColor::aqua);
    float fontWidth = font.stringWidth(h);
    font.drawString(h, ofGetWidth()/2-fontWidth/2, 300);

    //draw time on canvas
    std::time_t epoch;
    struct tm*timeinfo; //*points to a structure
    bool currentTime=true;// print current time or covert an epoch
    if(currentTime){
        std::time(&epoch); //&gets the variable address
    }else{
        epoch=json["daily"]["data"][day]["summary"].asInt();
    }
    timeinfo=localtime(&epoch);
    font.drawString(asctime(timeinfo), 100, 600);

    //summary
    std:: string summary=json["daily"]["data"][day]["summary"].asString();
    font.drawString("Summary:", 100, 700);
    font.drawString(summary, 100, 770);

    //TemperatureHigh
    std:: string temH=json["daily"]["data"][day]["temperatureHigh"].asString();
    font.drawString("Tomorrow's Temperature High: ", 100, 900);
    font.drawString(temH, 100, 970);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case '0':
            day=0;
            break;
        case '1':
            day=1;
            break;
        case '2':
            day=2;
            break;
        case '3':
            day=3;
            break;
        case '4':
            day=4;
            break;
        case '5':
            day=5;
            break;
        case '6':
            day=6;
            break;
        case '7':
            day=7;
            break;
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
