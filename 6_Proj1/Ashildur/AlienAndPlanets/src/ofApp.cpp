#include "ofApp.h"
#include "ofxGui.h"


int mouseX;
int mouseY;


ofPoint probe_pos; //this is an object with 2 variables in it (it's a vector)
ofFbo fbo;  // framebuffer object - must first create fbo object first
float tetha,radius, maxRadius, vel, xPos, yPos;
ofSoundPlayer bomb;
    
    



//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
    
    alien.load("alien.wav");
    bomb.load("bomb.wav");
    
    //setting the volume of the sound
    
    alien.setVolume(0.5);
    
    
    alien.play();
    alien.setLoop(true); //This makes the alien music loop
    
    fftSmooth = new float [8192];
    for (int i = 0; i < 8192; i++) {
        fftSmooth [i] = 0;
    }
    
    bands = 64;
    bomb.setVolume(0.5);
    
    yPos=0;
    xPos=0;
    
    
    // bomb.play();
    
    
    //Set up for the planets
    
    ofBackground(0,0,0);
    planet01.setup();
    planet02.setup();
    planet03.setup();
    
    
    planetGroups.add(planet01.planetGroups);
    planetGroups.add(planet02.planetGroups);
    planetGroups.add(planet03.planetGroups);
    
    
    gui.setup(planetGroups);
    
    //----
    
    tetha=180;
    maxRadius=700;
    vel=.5;
    yPos=0;
    xPos=0;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    planet01.update();
    planet02.update();
    planet03.update();
    
    ofSoundUpdate();
    
    float * value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++) {
        fftSmooth[i] *= 0.2f;
        if (fftSmooth [i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(0,255,0);
    ofDrawCircle(mouseX, mouseY, 20); //This makes the green circle (alien) follow the mouse
    
    gui.draw();
    
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    planet01.draw();
    
    ofTranslate(planet01.posX, planet02.posY);
    for (int i = 0; i < bands; i ++) {
//        ofCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i]*150));
        planet02.draw();
    }
    
    ofTranslate(planet02.posX, planet03.posY);
    planet03.draw();
    
    
    
    ofSetColor(255, 128, 0, 150);
    ofCircle(xPos,yPos,radius);
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case '1':
            bomb.play();
            break;
        case '2':
            bomb.stop();
            break;
    }
    
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
   
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    mouseX = x; // x and y are local variables
    mouseY = y; // locals override globals of the same name
    
    
    cout << x << endl;
    cout << y << endl;
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    tetha = 0;
    xPos=x;
    yPos=y;

    
    bomb.play();
    
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
