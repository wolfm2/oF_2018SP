#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(800, 700);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	receiver.setup(8338);
	
	for(int i = 0; i < 66; ++i) {
		points.push_back(ofVec2f());
	}

	ofBackground(255);
    Sound.load("1.mp3");
    Sound1.load("2.mp3");
    Sound2.load("3.mp3");
    Sound3.load("4.mp3");
    piano.load("piano.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

	while(receiver.hasWaitingMessages()) {
	
		ofxOscMessage m;
		receiver.getNextMessage(m);
		
		if(m.getAddress() == "/found") {
			found = (bool) m.getArgAsInt32(0);
		}
		
		else if(m.getAddress() == "/raw" && m.getNumArgs() == 132) {
			int p = 0;
			for(int i = 0; i < 132; i = i+2) {
				points[p].x = m.getArgAsFloat(i);
				points[p].y = m.getArgAsFloat(i+1);
				p++;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	if(found) {
		drawFacePoints();
		drawFacePolygons();
	}

	ofFill();
	ofSetColor(0);
    ofDrawBitmapString("Please press arrow key which are up, down, left, or right along with your face movement", 12, 20);
    ofFill();
    ofSetColor(255,255, 255);
    piano.draw(0, 570);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_RIGHT) {
        Sound.play();
    }
    
    if(key == OF_KEY_DOWN) {
        Sound1.play();
    }
    
    if(key == OF_KEY_LEFT) {
        Sound2.play();
    }
    
    if(key == OF_KEY_UP) {
        Sound3.play();
    }
    
    if(key == 's') { // count points = 65
        dots++;
        if(dots >= points.size()) {
            dots = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::drawFacePoints() {
	ofFill();
	for(int i = 0; i < points.size(); i++) {
		if(i == dots) {
			ofSetColor(255, 0, 0);
			ofDrawCircle(points[i], 11);
		} else {
			ofSetColor(100);
			ofDrawCircle(points[i], 8);
		}
	}
}

//--------------------------------------------------------------
void ofApp::drawFacePolygons() {
	ofNoFill();
	ofSetColor(100);

	ofBeginShape();
	for(int i = 0; i < 17; i++) {
		ofVertex(points[i].x, points[i].y);
	}
	for(int i = 26; i > 16; i--) {
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape(OF_CLOSE);


	ofBeginShape();
	for(int i = 36; i < 42; i++) {
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape(OF_CLOSE);
	ofBeginShape();
	for(int i = 42; i < 48; i++) {
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape(OF_CLOSE);

	ofBeginShape();
	for(int i = 48; i < 55; i++) {
		ofVertex(points[i].x, points[i].y);
	}
	for(int i = 62; i > 59; i--) {
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape(OF_CLOSE);

	ofBeginShape();
	for(int i = 54; i < 60; i+=2) {
		ofVertex(points[i].x, points[i].y);
	}
		ofVertex(points[48].x, points[48].y);
	for(int i = 65; i > 62; i--) {
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape(OF_CLOSE);

	ofBeginShape();
	for(int i = 27; i < 31; i++) {
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();

	ofBeginShape();
	for(int i = 31; i < 36; i++) {
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape();
}

//
