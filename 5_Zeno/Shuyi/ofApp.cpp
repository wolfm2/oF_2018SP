#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;  // speed with which we pursue the mouse
float rect_catchUpspeed_1 = 0.1f;
ofPoint rect_pos;
ofPoint rect_pos_1;


//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
    


}

//--------------------------------------------------------------
void ofApp::update(){

    
    //rect_pos.x += rect_catchUpSpeed * (500 - ofDist(mouseX, rect_pos.x, mouseY, rect_pos.y));
   // rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);

    //rect_pos.x += 1000 - rect_catchUpSpeed * (mouseX - rect_pos.x);
    //rect_pos.y += 1000 - rect_catchUpSpeed * (mouseY - rect_pos.y);
    
    rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x);
    rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);
    
    rect_pos_1.x += rect_catchUpspeed_1 * (mouseX - rect_pos_1.x);
    rect_pos_1.y += rect_catchUpspeed_1 * (mouseY - rect_pos_1.y);
    
    cout << "rectX: " << rect_pos.x << endl;
    cout << "rectY: " << rect_pos.y << endl;
    cout << "mouseX: " << mouseX << endl;
    cout << "mouseY: " << mouseY << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
    ofSetColor(15,205,95);
    ofRect(rect_pos_1.x,rect_pos_1.y, 30,30);
    
}
