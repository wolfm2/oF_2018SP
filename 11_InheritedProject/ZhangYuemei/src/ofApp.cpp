#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//load images and music
    backImage.load("background.jpg");
    sun.load("sun.png");
    moon.load("moon.png");
    
    music.load("music.mp3");
//Arduino
    serial.listDevices();
    vector<ofSerialDeviceInfo>deviceList = serial.getDeviceList();
    serial.setup(1, 9600);
    
    
//API
    std::string url = "https://api.darksky.net/forecast/9cfafc3a4acf5bceaf8fd34079970871/37.8267,-122.4233";
    json.open(url);

//load stars
for(int i = 0; i < 60; i++){
    ofVec2f temp;
    temp.set(ofRandom(700), ofRandom(700));
    Star[i] = temp;
    ofImage temp1;
    temp1.load("star.png");
    star[i] = temp1;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
//play music
    if (!music.isPlaying()) {
        music.play();
    }
    

    if (serial.available()) {
    float value = serial.readByte();
    if (value >= 10 && value <= 20) {
        sizeW = 50;
        sizeH = 50;
    }
        if (value > 20) {
            sizeW = 30;
            sizeH = 30;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    backImage.draw(0, 0);
    
//connect the API
    currentTime = json["currently"]["time"].asInt();
    dayTime = json["daily"]["data"][day]["sunriseTime"].asInt();
    nightTime = json["daily"]["data"][day]["sunsetTime"].asInt();
    
//    cout<<"datTime: "<<dayTime<<endl;
    
    if (currentTime > dayTime && currentTime < nightTime) {
        sun.draw(50,30);
    }else{
        moon.draw(600, 100);
    }
    for (int i = 0; i < 60; i ++) {
        star[i].draw(Star[i],sizeH, sizeW);
    }
    
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
