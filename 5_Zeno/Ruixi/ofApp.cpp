#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;
ofPoint rect_pos;

float maxSpeed = 0;
//float X_speed ;
//float Y_speed ;
float maxX_speed = 0;
float maxY_speed = 0;

//--------------------------------------------------------------
void ofApp::setup(){
   
    ofSetVerticalSync(true);
    
   
    ofEnableAlphaBlending();
    ofBackground(30,30,30);
    
    //load sound effect here
    birdCall.load("sounds/bird.mp3");
    
    if(mouseX - rect_pos.x <= 100 && mouseY - rect_pos.y <=100 ){
        birdCall.play();
        cout<<"sound is play"<<endl;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
      //here is ease out
//        rect_pos.x +=  rect_catchUpSpeed * (mouseX - rect_pos.x);
//        rect_pos.y +=  rect_catchUpSpeed * (mouseY - rect_pos.y);


//    rect_pos.x +=   maxSpeed * (mouseX - rect_pos.x);
//    rect_pos.y +=   maxSpeed * (mouseY - rect_pos.y);
    
    //给定义
    
    float x_speed = rect_catchUpSpeed * (mouseX - rect_pos.x);
    float y_speed = rect_catchUpSpeed * (mouseY - rect_pos.y);
    
    //绝对正
    if (abs(x_speed) > maxX_speed) {
        maxX_speed = abs(x_speed);  // If bigger. Save it.
        cout << "X Max:" << maxX_speed << endl; // Print when changed.
    }

    if (abs(y_speed) > maxY_speed) {
        maxY_speed = abs(y_speed);  // If bigger. Save it.
        cout << "Y Max:" << maxY_speed << endl; // Print when changed.
    }
    
    
    if (x_speed > 0) { // if positive
        rect_pos.x += maxX_speed - abs(x_speed);
    }
    
    if (x_speed < 0) { // if negative
        rect_pos.x -= maxX_speed - abs(x_speed);
    }
    
    if (y_speed > 0) { // if positive
        rect_pos.y += maxY_speed - abs(y_speed);
    }
    
    if (y_speed < 0) { // if negative
        rect_pos.y -= maxY_speed - abs(y_speed);
    }
    
    
    
    
    if (false) { // BONUS: Change the boolean to fix jitter.
        // If we will/would overshoot, make x or y the same as the mouse.
        if (abs(mouseX - rect_pos.x) < maxX_speed) {
            rect_pos.x = mouseX;
        }
        
        if (abs(mouseY - rect_pos.y) < maxY_speed) {
            rect_pos.y = mouseY;
        }
    }
 
    //play the sound
    
 
    
}


//--------------------------------------------------------------
void ofApp::draw(){
    
    
    float colorB = 50;
    
    // draw green rectangle
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246, colorB);
    ofDrawRectangle(rect_pos.x,rect_pos.y, 20,20);
    
    
//    ofSetColor(200,150, 80);
//    ofRect(rect_pos.x+ofRandom(20), rect_pos.y+ofRandom(20), 20, 20);
 
    

   

}
