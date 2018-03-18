#include "ofApp.h"
#include "ofxJSON.h"
#include <iostream>
#include <string>

ofImage fish;
ofImage rod;

using namespace std;

ofxJSONElement json; //JSON reader
string myString;
ofTrueTypeFont font;


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(300);
    
    fish.load("fish.png");
    rod.load("fishingrod.png");
   
    
    bigTide.load("bigTide.wav");
    bigTide.play();
    bigTide.setLoop(true);
    
    
    //using ofxAddon:ofxGui
    gui.setup();
    gui.add(date.setup("date", 0, 0, 13));
    gui.add(time.setup("time", 0, 0, 4));// 00/06/12/18

    
    //WorldTides API
    string url = "https://www.worldtides.info/api?heights&extremes&lat=40.713&lon=-74.006&length=1209600&maxcalls=5&key=c02b9466-cc3e-4f32-a7b8-8830f608f8ee";
    
    //Parse url returns true or false
    bool urlResponse = json.open(url);
    if(urlResponse){
        ofLogNotice("ofApp::setup")<<json.getRawString(true);
    }else{
        ofLogNotice("ofApp::setup")<<"Parsing Failed.";
    }
    
    font.load("Caviar_Dreams_Bold.ttf", 20);
    
    ofBackground(170,215,238);
    
}

//--------------------------------------------------------------



float height;
string tideType;
int rod_posx = 500;
int rod_posy = 500;
int fish_posx = 1000;
float fish_catchUpSpeed = 0.01f;


void ofApp::update(){
    //Easing-out: simulate the fishing
      fish_posx += fish_catchUpSpeed * (rod_posx - fish_posx);
}



//--------------------------------------------------------------
void ofApp::draw(){
    
    //Here change background according to the time
    // 1st/2nd/3rd/4th tide
    //because the api keeps updating
    //so the order will mess up after the presentation day
    if(time==0){
        ofBackground(170,215,238);
    }else if(time == 1){
        ofBackground(229,232,237);
    }else if(time == 2){
        ofBackground(102,156,192);
    }else{
        ofBackground(77,98,129);
    }
    
    //because the api keeps updating
    //so the order will mess up after the presentation day
    gui.draw();

    
    //four times tide in a day
    string DateTime = json["extremes"][date*4+time]["date"].asString();
    font.drawString("Fishing in New York City", 300, 50);
    font.drawString("Date & Time:", 300,100);
    font.drawString(DateTime, 500,100);
    font.drawString("Tide type:", 300,150);
    font.drawString(tideType, 450,150);
    
    
   
    
    height = json["extremes"][date]["height"].asFloat();
    //cout << height;

    tideType = json["extremes"][date]["type"].asString();
    //cout << tideType;
    

    
    
    drawTide(200, 520, 3, 57, 108);
    drawTide(0, 400, 0, 91, 150);
    drawTide(100, 480, 255, 255, 255);
    drawTide(200, 600, 3, 57, 108);
    drawTide(0, 680, 0, 91, 150);
    
   


    ofPushMatrix();
    
    //ofRotateY(100);
    ofScale(0.5,0.5);
    
    if(tideType == "High"){
        
        fish.draw(fish_posx, 600);
        fish.draw(fish_posx, 800);
        fish.draw(fish_posx, 1000);
        bigTide.setVolume(0.6);
        
    }else{
        fish.draw(fish_posx, 800);
        bigTide.setVolume(0.1);
        
    }
    ofPopMatrix();
    
    ofScale(0.5,0.5);
    rod.draw(rod_posx, rod_posy);

//    if(fish_posx>0){
//        fish_posx = fish_posx - 5;
//    }else{
//        fish_posx = 1000;
//    }
    
    

}
//--------------------------------------------------------------
void ofApp::drawTide(int a, int b, int red, int green, int blue){
    ofPushStyle();
    ofSetColor(red,green,blue);
    
    ofBeginShape();
    for(int x=0; x<ofGetWidth()+a; x++) {
        ofCurveVertex(x-a, b + 100*height* sin(x*0.01f + ofGetFrameNum() * 0.02f));
    }
    ofEndShape(false);
    ofPopStyle();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_RIGHT){
        rod_posx = rod_posx + 20;
    }
    if(key == OF_KEY_LEFT){
        rod_posx = rod_posx - 20;
    }
    if(key == OF_KEY_UP){
        rod_posy = rod_posy - 10;
    }
    if(key == OF_KEY_DOWN){
        rod_posy = rod_posy + 10;
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
