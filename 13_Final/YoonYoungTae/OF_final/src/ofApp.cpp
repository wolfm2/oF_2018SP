#include "ofApp.h"

float x, y, angle = 0;
ofPoint p0, p1;
ofPoint t, u;
float rX, rY, rZ;
ofFbo fbo;
ofColor black(0,0,0);

//--------------------------------------------------------------
void ofApp::setup(){
    p0 = ofPoint(ofRandom(10), ofRandom(10));
    p1 = ofPoint( 2, 2);
    t = ofPoint(ofGetWidth(), ofGetHeight(), 0);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetBackgroundColor(black);
    

    
    song.load("party.mp3");
    while (! song.isLoaded());
    nBandsToGet = 100;
    
    fftSmoothed = new float[100];
    for (int i= 0; i < 100; i++) {
        fftSmoothed[i] = 10;
    }
    
    val = ofSoundGetSpectrum(nBandsToGet);
    for (int i =0; i < nBandsToGet; i++) {
        if(fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
    }
    song.play();
    

}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    
    rX = ofSignedNoise(time * 0.3) * 30.0;
    rY = ofSignedNoise(time * 0.6) * 30.0;
    rZ = ofSignedNoise(time * 0.9) * 30.0;
    
    
    float x = ofMap(ofSignedNoise(time * 0.2), -1, 1, 0, ofGetWidth());
    float y = ofMap(ofSignedNoise(time * 0.4), -1, 1, 0, ofGetHeight());
    float z = ofMap(ofSignedNoise(time * 0.6), -1, 1, -500, 500);
    
    t = ofPoint(x, y, z);
    
    ofSoundUpdate();
    val = ofSoundGetSpectrum(nBandsToGet);
    for (int i = 0;i < nBandsToGet; i++){
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
    }
    cout << ofToString(fftSmoothed[0]*20) << endl;
    val = ofSoundGetSpectrum(nBandsToGet);
    ofBackground(0x23,fftSmoothed[1]*100,fftSmoothed[0]*100);
    
    for (int i = 0;i < nBandsToGet; i++){
        
       
        fftSmoothed[i] *= 0.96f;
        
        
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo.begin();
    ofPushStyle();
    ofSetColor(0,0,0,1);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPopStyle();
    
    ofPushMatrix();
    ofTranslate(t);
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofPushStyle();
    ofSetColor(80, 100, 120);
    ofDrawLine(p0, p1);
    ofPopStyle();
    ofPopMatrix();
    fbo.end();
    
    fbo.draw(310,180);
    
    
    for (int i = 0; i < nBandsToGet/2; i++) {
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
        ofRotateZ(i);
        ofSetColor(55, 25, 35);
        ofDrawRectangle(0, 0, 400+(1*val[i])*80, 400+(1*val[i])*80);
        ofNoFill();
        ofSetColor(55, 155, 15);
        ofDrawRectangle(0, 0, 100+(val[i])*400, 100+(val[i])*400);
        ofPopMatrix();
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
