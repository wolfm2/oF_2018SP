#include "ofApp.h"
#include<iostream>
#include<string>
#include <map>
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    std::string url = "https://api.darksky.net/forecast/6fe14d54b1e54ae20510e97047a49e6d/40.7128,-74.0059";
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);//
    
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
    //ofBackground(0);
    ofSetColor(255);
    
    ofDrawBitmapString("Hello World", 50, 50);

    std::string sum   = json["daily"]["data"][1]["summary"].asString();
    std::string tem   = json["daily"]["data"][1]["temperatureHigh"].asString();
    std::string text   =  "Weather: " + sum + "   High temperture: " + tem;
    ofDrawBitmapString(text, 50, 70);
    
    std::string sunrise   = json["daily"]["data"][0]["sunriseTime"].asString();
    std::string sunset   = json["daily"]["data"][0]["sunsetTime"].asString();
    std::string time = json["currently"]["time"].asString();
    
    
    //Draw an orange circle on the screen at y=100 r=50.  Its X should be a map() using our current time, sunrise/sunset, and the width of the canvas.
    //Using this, make the background a lerp between yellow (255,255,0) and black.

    int sunr = std::stof(sunrise);
    int suns = std::stof(sunset);
    int tm = std::stof(time);
    //cout << "sunr:" << sunr << endl;
    //cout << "suns:" << suns << endl;
    //cout << "tm:" << tm << endl;
    
    int x = ofMap(tm, sunr, suns, 0, ofGetWidth());
    //cout << "x: " << x << endl;
    ofSetColor(234, 78, 0);
    ofDrawCircle(x, 100, 50);
    ofFill;
    
    //Use this                                                                     with the current time, sunrise, sunset to map a value between 0 - 1.
    float newx = ofMap(tm, sunr, suns, 0, 1);
    cout << "newx: " << newx << endl;

    
    //Using this, make the background a lerp between yellow (255,255,0) and black.
    
    ofColor y = ofColor(255, 255, 0);
    ofColor b = ofColor::black;
    ofSetBackgroundColor(y.lerp(b, newx));


   
    for (Json::ArrayIndex i = 0; i < json["daily"]["data"].size(); i++) {
    std::string Sum  = json["daily"]["data"][i]["summary"].asString();
    std::string Tem = json["daily"]["data"][i]["temperatureHigh"].asString();
    std::string Text   = "Weather: " + Sum + "   High temperture: " + Tem;
    ofDrawBitmapString(Text, 50, i * 24 + 90);
    }
    
    



}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '0'){
        cout << "summary: " << json["daily"]["data"][0]["summary"].asString() << endl;
        cout << "high temperature: " << json["daily"]["data"][0]["temperatureHigh"].asString() << endl;
    }
    
    if (key == '1'){
        cout << "summary: " << json["daily"]["data"][1]["summary"].asString() << endl;
        cout << "high temperature: " << json["daily"]["data"][1]["temperatureHigh"].asString() << endl;
    }
    
    if (key == '2'){
        cout << "summary: " << json["daily"]["data"][2]["summary"].asString() << endl;
        cout << "high temperature: " << json["daily"]["data"][2]["temperatureHigh"].asString() << endl;
    }
    
    if (key == '3'){
        cout << "summary: " << json["daily"]["data"][3]["summary"].asString() << endl;
        cout << "high temperature: " << json["daily"]["data"][3]["temperatureHigh"].asString() << endl;
    }
    
    if (key == '4'){
        cout << "summary: " << json["daily"]["data"][4]["summary"].asString() << endl;
        cout << "high temperature: " << json["daily"]["data"][4]["temperatureHigh"].asString() << endl;
    }
    
    if (key == '5'){
        cout << "summary: " << json["daily"]["data"][5]["summary"].asString() << endl;
        cout << "high temperature: " << json["daily"]["data"][5]["temperatureHigh"].asString() << endl;
    }
    
    if (key == '6'){
        cout << "summary: " << json["daily"]["data"][6]["summary"].asString() << endl;
        cout << "high temperature: " << json["daily"]["data"][6]["temperatureHigh"].asString() << endl;
    }
    
    if (key == '7'){
        cout << "summary: " << json["daily"]["data"][7]["summary"].asString() << endl;
        cout << "high temperature: " << json["daily"]["data"][7]["temperatureHigh"].asString() << endl;
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
