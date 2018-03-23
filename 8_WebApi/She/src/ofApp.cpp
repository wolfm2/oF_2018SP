#include "ofApp.h"

#include<string>

ofTrueTypeFont myFont;

string Hi = "Hello World";

std::string url = "https://api.darksky.net/forecast/bbe1a2d07a0c0875dc67ae522244bad3/40.7128,-74.0059";
// weather data

int dayMark;

float circle_xPos;

float lerpValue;

//--------------------------------------------------------------
void ofApp::setup(){
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful){
        
        ofLogNotice("ofAPP::setup") << json.getRawString(true);
        
    }else{
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    lerpValue = ofMap(json["currently"]["time"].asInt(),
                      json["daily"]["data"][0]["sunriseTime"].asInt(),
                      json["daily"]["data"][0]["sunsetTime"].asInt(),
                      0,
                      1);
    
    ofColor yellow = ofColor::yellow;
    ofColor black = ofColor::black;
    
    ofSetColor(yellow.lerp(black, lerpValue));
    ofDrawRectangle(0, 0, ofGetWidth(),ofGetHeight());
    
    ofSetColor(255);
    
    float fontWidth = myFont.stringWidth(Hi);
    myFont.drawString(Hi, ofGetWidth()/2 - fontWidth/2, 400);
    
    ofSetColor(255);
    
    std::time_t epoch;
    struct tm * day;
    epoch = json["daily"]["data"][dayMark]["time"].asInt();
    day = localtime(&epoch);
    
    float dayStringWidth = myFont.stringWidth(asctime(day));
    myFont.drawString(asctime(day),100, 600);
    
    
    //summary
    std::string fore_summary = json["daily"]["data"][dayMark]["summary"].asInt();
    myFont.drawString("summary: ", 100, 700);
    myFont.drawString(fore_summary,100,770);
    
    std::string fore_temHigh = json["daily"]["data"]["dayMark"]["temperatureHigh"].asString();
    myFont.drawString("tommrrow's temperature High: ", 100, 900);
    myFont.drawString(fore_temHigh, 100,970);
    
    
    circle_xPos = ofMap(json["daily"]["data"][0]["sunriseTime"].asInt();
                        json["daily"]["data"][0]["sunsetTime"].asInt();
                        0,
                        ofGetWidth());
    
    ofSetColor(ofColor::orange);
    ofDrawCircle(circle_xPos, 100, 50, 50);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case'0':
            dayMark = 0;
            cout << 0;
            
            break;
        case'1':
            dayMark = 1;
            cout << 1;
            
            break;
        case'2':
            dayMark = 2;
            cout << 2;
            
            break;
            
        case'3':
            dayMark = 3;
            cout << 3;
            
            break;
        case'4':
            dayMark = 4;
            cout << 4;
            
            break;
        case'5':
            dayMark = 5;
            cout << 5;
            
            break;
        case'6':
            dayMark = 6;
            cout << 6;
            
            break;
        case'7':
            dayMark = 7;
            cout << 7;
            
            break;

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
