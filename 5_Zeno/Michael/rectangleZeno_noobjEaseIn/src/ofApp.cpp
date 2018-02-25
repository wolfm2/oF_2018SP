#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;  // speed with which we pursue the mouse
ofPoint rect_pos;

//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);

}

// "learn" the max speeds
float maxX_speed = 0;
float maxY_speed = 0;

//--------------------------------------------------------------
void ofApp::update(){

    // change in our position (easeout).
    float x_speed = rect_catchUpSpeed * (mouseX - rect_pos.x);
    float y_speed = rect_catchUpSpeed * (mouseY - rect_pos.y);
    
    // save the absolute value of the max speeds we see
    if (abs(x_speed) > maxX_speed) {
      maxX_speed = abs(x_speed);  // If bigger. Save it.
      cout << "X Max:" << maxX_speed << endl; // Print when changed.
    }
    
    if (abs(y_speed) > maxY_speed) {
      maxY_speed = abs(y_speed);  // If bigger. Save it.
      cout << "Y Max:" << maxY_speed << endl; // Print when changed.
    }
  
    // two versions of the solution below
    // first uses 4 if statements
    // second uses 2 compact, less readable c++ TERNARY OPERATORS
    // http://www.cplusplus.com/articles/1AUq5Di1/
    // change the boolean to use one or the other
    // NOTE: Such jitter! We keep overshooting the mouse.
   
    if (false) {  // version 1
      // change by the INVERSE of x|y_speed (always yields positive EASEIN number)
      // +|- based on the sign of x|y_speed
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
    } else {  // version 2
      float absX = maxX_speed - abs(x_speed);
      rect_pos.x += x_speed>0 ? absX : absX*-1;
    
      float absY = maxY_speed - abs(y_speed);
      rect_pos.y += y_speed>0 ? absY : absY*-1;
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
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
}
