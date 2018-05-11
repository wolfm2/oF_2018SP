#include "ofApp.h"
#include "ofxJSON.h"
#include <iostream>
#include <string>

ofImage fish;
ofImage bridge;
ofImage sun;
ofImage earth;
ofImage moon;
ofImage night;
ofImage tidewave;


using namespace std;

float moon_x;
float moon_y;
float angle=0;
//int date;
float wave_y;
float fish_x = 800;
float fish_y;


//ofxJSONElement json;
//string myString;
ofTrueTypeFont font;


//--------------------------------------------------------------
void ofApp::setup(){
    moon.load("moon.png");
    earth.load("earth.png");
    sun.load("sun.png");
    bridge.load("bridge.png");
    night.load("night.png");
    tidewave.load("tidewave.png");
    fish.load("fish.png");
    
    seawaves.loadSound("seawaves.wav");
    fftSmooth = new float[8192];
    
    for(int i=0; i<8192; i++){
        fftSmooth[i] = 0;
    }
    bands = 64;
    
    seawaves.setLoop(true);
    seawaves.setVolume(0.4);
    seawaves.play();
    
    
//    gui.setup();
//    gui.add(date.setup("date", 0, 0, 4)); //0, 7, 15,22
    //WorldTides API
//    string url = "https://www.worldtides.info/api?heights&extremes&lat=40.713&lon=-74.006&length=1209600&maxcalls=5&key=c02b9466-cc3e-4f32-a7b8-8830f608f8ee";
//
//    //Parse url returns true or false
//    bool urlResponse = json.open(url);
//    if(urlResponse){
//        ofLogNotice("ofApp::setup")<<json.getRawString(true);
//    }else{
//        ofLogNotice("ofApp::setup")<<"Parsing Failed.";
//    }
    
    
    font.load("Caviar_Dreams_Bold.ttf", 20);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofFmodSoundUpdate();
    
    float *value = ofSoundGetSpectrum(bands);
    for(int i=0; i< bands; i++){
        fftSmooth[i] *= 0.9f;
        if(fftSmooth[i]<value[i]){
            fftSmooth[i] = value[i];
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //gui.draw();
    
    
    
    int moon_rotate_radius=170;
    int wave_radius = 10;
    moon_x = moon_rotate_radius*cos( ofDegToRad(angle) ) + 500;
    moon_y = moon_rotate_radius*sin( ofDegToRad(angle) ) + 200;
    wave_y = wave_radius*sin(ofDegToRad(angle*2+180));
    fish_y = wave_radius*sin(ofDegToRad(angle*2+180));
    
    ofPushStyle();
    ofSetColor(255,0,0);
    for (int i=0;i<bands; i++){
        ofCircle(500,200,800-(fftSmooth[i]*50));
    }
    ofPopStyle();
    
    
    
    
    angle = angle - 1;
//    date = date + 1;
    if (angle <= -360) {
        angle = 0;
    }
    
    
    
    night.draw(0,0);
    
    ofPushStyle();
    ofSetColor(200);
    bridge.draw(-50,260);
    ofPopStyle();
    //moon.draw(moon_x, moon_y);
    earth.draw(500, 200);
    sun.draw(800,180);
    
    
    fish_x++;
    if(angle >= -90){
        seawaves.setVolume(0.8);
        
        ofPushStyle();
        ofSetColor(255);
        moon.draw(moon_x, moon_y);
        tidewave.draw(-50,620-wave_y);
        
        ofPushMatrix();
        ofScale(0.1,0.1);
        fish.draw(14000-fish_x*6,7000+wave_y*20);
        fish.draw(14000-fish_x*6,7200-wave_y*20);
        fish.draw(14000-fish_x*6,7400+wave_y*20);
        ofPopMatrix();
        ofPopStyle();
        
        
        
    }else if(angle >=-180 & angle < -90){
        seawaves.setVolume(0.4);
        
        ofPushStyle();
        ofSetColor(100);
        moon.draw(moon_x, moon_y);
        tidewave.draw(-50,620-wave_y);
        
        ofPushMatrix();
        ofScale(0.1,0.1);
        fish.draw(14000-fish_x*6,7200-wave_y*20);
        ofPopMatrix();
        ofPopStyle();
        
        
    }else if(angle >=-270 & angle < -180){
        seawaves.setVolume(0.7);
        
        ofPushStyle();
        ofSetColor(255);
        moon.draw(moon_x, moon_y);
        tidewave.draw(-50,620-wave_y);
        ofScale(0.1,0.1);
        fish.draw(14000-fish_x*6,6800+wave_y*20);
        fish.draw(14000-fish_x*6,7000-wave_y*20);
        fish.draw(14000-fish_x*6,7200+wave_y*20);
        ofPopMatrix();
        ofPopStyle();
        
    }else if(angle >=-360 & angle < -270){
        seawaves.setVolume(0.3);
        
        ofPushStyle();
        ofSetColor(100);
        moon.draw(moon_x, moon_y);
        tidewave.draw(-50,620-wave_y);
        ofPushMatrix();
        ofScale(0.1,0.1);
        fish.draw(14000-fish_x*6,7200-wave_y*20);
        ofPopMatrix();
        ofPopStyle();
    }
    
    //font.drawString("brookly tide station", 50, 500);
    font.drawString("brooklyn", 150, 530);
    font.drawString("tide", 150, 560);
    font.drawString("station", 150, 590);
    
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
