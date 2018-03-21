#include "ofApp.h"

int byteData;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(false);
    verdana.loadFont("Economica-BoldItalic.ttf",30);
    ofImage distortionMap;
    distortionMap.load("distortion.png");
    
    
    mySound.load("sound.mp3");
    mySound.play();
    
//    printer.open("/dev/tty.PL2303-00002014");
    myArduino.connect("/dev/tty.usbmodem14311", 19200);
//    ofLogError();
//    printer.listDevices();
//    OF_EXIT_APP(0);
    
    //set up a slit scan with a maximum capacity of frames
    // in the distortion buffer
    //    slitScan.setup(640, 480, 900);
    slitScan.setup(640, 480, 400);
    
    slitScan.setDelayMap(distortionMap);
    //blending means the edges between the scans are feathered
    slitScan.setBlending(true);
    
    //time delay is the deepest in history the delay can go
    //and width is the number of frames the distortion will encompass
    //note that the delay cannot be more than the total capacity
    slitScan.setTimeDelayAndWidth(0, 120);
    
    //set up the grabber
    grabber.initGrabber(ofGetWidth(),ofGetHeight());
    
     printer.isInitialized();
}

void ofApp::setupArduino(const int & version) {
    // Arduino setup tasks will go here
    ofAddListener(myArduino.EInitialized, this, &ofApp::setupArduino);
    ofRemoveListener(myArduino.EInitialized, this, &ofApp::setupArduino);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    if(grabber.isFrameNew()){
        slitScan.addImage(grabber);
    }
    myArduino.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
   
    //    ofBitmapFont(verdana);
    //    ofDrawBitmapString("capture this by pressing [x] ", 70, 800);
    slitScan.getOutputImage().draw(0, 0);
     verdana.drawString(" capture this by pressing [x] ", 70, 500);
    
    
    
    //     ofSetColor(0, 0, 255);
    //     ofDrawRectangle(15,680,-100, 160, 25);
    //
    //        char tempString[255];
    //        sprintf(tempString," capture this by pressing [x] ");
    //        ofSetColor(0,0, 0, 0);
    //        verdana.drawString(tempString ,70,560);
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'x'){
        img.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
        img.save("screenshot.png");
    }
    
    switch (key) {
        case OF_KEY_UP:
            myArduino.sendDigital(13, ARD_HIGH);  // turn LED on
            break;
        case OF_KEY_DOWN:
            myArduino.sendDigital(13, ARD_LOW); // turn LED off
            break;
        default:
            break;
    }
    
}

void ofApp::exit(){
    printer.close();
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

