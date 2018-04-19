#include "ofApp.h"
#include "ofMain.h"


// declare objects
rectZeno rect1;
rectZeno rect2;
rectZeno rect3;
rectZeno rect4;
rectZeno rect5;


rectZeno::rectZeno(){
    rect_catchUpSpeed = ofRandom(0, 0.03);
    
    x_pos=ofRandom(200, 500);
    y_pos=ofRandom(200, 500);
    
    red = ofRandom(50, 150);
    green = ofRandom(100, 255);
    blue = ofRandom(0, 150);
}


void rectZeno::update(float rectMouseX, float rectMouseY){
    x_pos += rect_catchUpSpeed * (rectMouseX - x_pos);
    y_pos += rect_catchUpSpeed * (rectMouseY - y_pos);
    ofLog(x_pos);
    ofLog(y_pos);
}

void rectZeno::draw(){
    ofSetColor(red, green, blue);
    ofDrawRectangle(x_pos,y_pos, 20,20);
}


//--------------------------------------------------------------
void ofApp::setup(){
	// macs by default run on non vertical sync,
    // which can make animation very, very fast
	// this fixes that: 
	ofSetVerticalSync(true);

	// set background: 
	ofEnableAlphaBlending();
	ofBackground(30,30,30);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    rect1.update(mouseX,mouseY);
    rect2.update(mouseX,mouseY);
    rect3.update(mouseX,mouseY);
    rect4.update(mouseX,mouseY);
    rect5.update(mouseX,mouseY);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    rect1.draw();
    rect2.draw();
    rect3.draw();
    rect4.draw();
    rect5.draw();
    
}






