#include "ofApp.h"
#include "ofMain.h"

int rainbow[7][3]= {
    {255, 0, 0},     //red
    {255, 127, 0},   //orange
    {255, 255, 0},   //yellow
    {0, 255, 0},     //green
    {0, 0, 255},     //blue
    {75, 0, 130},    //indigo
    {148, 0, 211}    //violet
    
};

ofImage dove;

ofFbo fbo;
ofColor ball(255,255,255);  // white
ofColor black(0,0,0);


float height = 0.01;
float weight = 0.01;


int rZ = 0;
float x = 0;
float y = 0;



//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofSetFrameRate(20);
    
    dove.load("dove1.png");
    
    //fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    // lower precision. leaves artifacts. way faster.
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    // higher precision alpha (no artifacts)
    //GL_RGBA32F memory size for color
    
    fbo.begin();
    ofClear(255,255,255, 0);
    //clear framebuffer first
    fbo.end();
    
    ofSetBackgroundColor(black);//set main screen
}



//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //draw in the framebuffer
    fbo.begin();
    ofSetColor(black, 10); // background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(ball);
    ofNoFill();
    
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(weight, height, 0.3);  // can be 3 dimensional
    ofRotateZ(rZ);
    
    ofPushStyle();  // save the current fill and color state
    
    ofSetColor(rainbow[rZ%7][0], rainbow[rZ%7][1], rainbow[rZ%7][2]);
    
    for(x=0; x<=rZ; x++){
        for(y=0; y<=rZ; y++){
            //ofDrawLine(x, y, x+200, y+200);
            ofCircle((x-50), (y-50), 200);
        }
    }
    
    ofPopStyle();  // return the fill and color state from before
    
    dove.draw(0, 0);  // draw at new 0,0
    
    
    ofFill();
    fbo.end();
    
    //draw on the screen
    // always set the color before drawing the fbo
    ofSetColor(255,255,255);
    fbo.draw(0,0);
    
    
    
     if(rZ>58){
        ofSetBackgroundColor(255, 255, 255);
         
        ofTranslate((ofGetWidth()/2-220), (ofGetHeight()/2-220));
        ofScale(weight, height, 0.3);
         
         int i;
         int j;
         
         for(i=500; i<= 700; i+=50){
             for(j=150; j<=350; j+=50){
                 ofSetColor(3,j,0);
                 ofDrawTriangle(500, 350, i, j, (i+20), (j+20));
             }
         }
         
         for(i=500; i>= 300; i-=50){
             for(j=550; j>=350; j-=50){
                 ofSetColor(21,(j-300),0);
                 ofDrawTriangle(500, 350, i, j, (i-20), (j-20));
             }
         }
         
         for(i=500; i>= 150; i-=50){
             for(j=50; j<=350; j+=50){
                 ofSetColor(46,i,14,i);
                 ofDrawTriangle(500, 350, i, j, (i-20), (j+20));
             }
         }
         
         ofSetColor(58,26,12);
         ofDrawTriangle(500, 350, 590, 500, 610, 490);
     }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c'){
        cout<<"come";
        height = height + 0.01;
        weight = weight + 0.01;
        
        if(rZ<=58){
            x = x + 0.5;
            y = y + 0.5;
            rZ++;
        }
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
