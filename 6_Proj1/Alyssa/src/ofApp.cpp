#include "ofApp.h"
//click cloud effect courtesy of xumo:
//https://forum.openframeworks.cc/t/expanding-circle-with-mouse-click/4622


int mouseX;
int mouseY;
float probe_catchUpSpeed = 0.15f;  // speed with which we pursue the mouse. the closer to 1, the faster.
float probe_maxSpeed = 1.0f;
ofPoint probe_pos; //this is an object with 2 variables in it (it's a vector)
ofFbo fbo;  // framebuffer object - must first create fbo object first
float tetha,radius, maxRadius, vel, xPos, yPos;
ofSoundPlayer lies;
ofSoundPlayer boom;
ofSoundPlayer nyt;
//--------------------------------------------------------------
void ofApp::setup(){
    lies.load("lies.mp3");
    lies.play();
    boom.load("boom.mp3");
    nyt.load("nyt.mp3");

    
    // macs by default run on non vertical sync, which can make animation very, very fast
    // this fixes that:
    ofSetVerticalSync(true);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    fbo.begin();
    ofClear(255,255,255, 0); //clear it of artifacts
    fbo.end();
    
    // set background:
    ofSetWindowShape(800, 800);
    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
    tetha=180;
    maxRadius=700;
    vel=.5;
    yPos=0;
    xPos=0;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    

    probe_pos.x += probe_catchUpSpeed * (mouseX - probe_pos.x);
    probe_pos.y += probe_catchUpSpeed * (mouseY - probe_pos.y);
    
    if(tetha<180)
    {
        tetha+=vel;
        lies.play();
       
    }
    radius=maxRadius*sin(PI*tetha/180);
    
    
}






//--------------------------------------------------------------
void ofApp::draw(){
    
    ///////Nuclear Symbol////////////
    ////////////////////////////////
    
    //black outline of yellow circle
    ofSetColor(0, 0, 0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 105);
    
    //yellow circle
    ofFill();
    ofSetColor(255,255,0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
    
    //top right triangle
    ofFill();
    ofSetColor(0,0,0);
    ofDrawTriangle(ofGetWidth()/2, ofGetHeight()/2, 445, 321, 487, 412);
    
    //top left triangle
    ofFill();
    ofSetColor(0,0,0);
    ofDrawTriangle(ofGetWidth()/2, ofGetHeight()/2, 351, 323, 311, 412);
    
    //bottom triangle
    ofFill();
    ofSetColor(0,0,0);
    ofDrawTriangle(ofGetWidth()/2, ofGetHeight()/2, 350, 478, 448, 478);
    
    //small central yellow circle
    ofFill();
    ofSetColor(255, 255, 0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 30);
    
    //small black center circle
    ofFill();
    ofSetColor(0,0,0);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 25);
    ///////End Nuclear Symbol///////
    ///////////////////////////////


    ///////Orange Circle////
    ////////////////////////
    if(abs(ofDist(mouseX,mouseY, ofGetWidth()/2, ofGetHeight()/2)) < 50){
        ofSetColor(255, 128, 0, 150);
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 105);
        } else{
            ofSetColor(255, 128, 0);
            ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 105);
            ofFill();
            ofSetColor(0,0,0);
            ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 25);
            }
    ///////End Orange Circle//////////
    //////////////////////////////////
    
    
    ///////Probe////////
    ///////////////////
    ofFill();
    ofSetColor(255,255,255);
    ofPath();
    ofDrawCircle(probe_pos.x,probe_pos.y, 25);
    ///////End Probe////////
    ///////////////////
    
    
    ////Red FBO//////////
    //////////////////////
    fbo.begin();
    ofSetColor(30,30,30, 10); // background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()); //draws this window for the buffer offscreen
    ofSetColor(255,0,0);
    ofNoFill();
    ofDrawCircle(mouseX, mouseY, 50);
    ofFill();
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(0,0);
    ////Red FBO//////////
    //////////////////////
    
    
    ////Blue FBO//////////
    //////////////////////
    fbo.begin();
    ofSetColor(30,30,30, 10); // background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight()); //draws this window for the buffer offscreen
    ofSetColor(0,0,255);
    ofNoFill();
    ofDrawCircle(mouseX, mouseY, 33);
    ofFill();
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(0,0);
    ////End Blue FBO//////////
    //////////////////////
    
    ////Orange Click Cloud///
    ////////////////////////
    ofSetColor(255, 128, 0, 150);
    ofCircle(xPos,yPos,radius);
    ////End Orange Click Cloud///
    ////////////////////////

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouseX = x;
    // x and y are "locals" or “local variables”
    mouseY = y;
    // locals override globals of the same name!!

    
    cout << x << endl;
    cout << y << endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    tetha=0;
    xPos=x;
    yPos=y;

    
    boom.play();
    lies.stop();
    nyt.play();
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
