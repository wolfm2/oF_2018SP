#include "ofApp.h"
#include <iostream>
#include <string>



ofTrueTypeFont myFont;
string Hi = "Hello World !";

std::string url = "https://api.darksky.net/forecast/603ed809e4a01cef738c4dd8af50d1db/40.7128,-74.0059";

//keyPressed 
int dayMark;
//circle
float circle_xPos;
//background
float lerpValue;

//--------------------------------------------------------------
void ofApp::setup() {
	
	ofSetWindowShape(1600, 1600);
	myFont.loadFont("OpenSans.ttf", 30);

	//JSON PART
	bool parsingSuccessful = json.open(url);

	if (parsingSuccessful) {
		ofLogNotice("ofApp::setup") << "parse successful";
	}else {
		ofLogNotice("ofApp::setup") << "failed to parse JSON";
	}
		

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	//lerp background, the background changes along with the time from yellow to black
	lerpValue = ofMap(json["currently"]["time"].asInt(),
		json["daily"]["data"][0]["sunriseTime"].asInt(),
		json["daily"]["data"][0]["sunsetTime"].asInt(),
		0,
		1);
	ofColor yellow = ofColor::yellow;
	ofColor black = ofColor::black;
	ofSetColor( yellow.lerp(black, lerpValue));
	ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
	//draw big "Hello World !"
	ofSetColor(255);
	myFont.loadFont("OpenSans.ttf", 60);
	float fontWidth = myFont.stringWidth(Hi);
	myFont.drawString(Hi, ofGetWidth() / 2 - fontWidth / 2, 400);

	//draw text
	ofSetColor(255);

	//Forecast day
	std::time_t epoch;
	struct tm * day;
	epoch = json["daily"]["data"][dayMark]["time"].asInt();
	day = localtime(&epoch);

	float dayStringWidth = myFont.stringWidth(asctime(day));
	myFont.loadFont("OpenSans.ttf", 40);
	myFont.drawString(asctime(day), 100, 600);




	//summary
	myFont.loadFont("OpenSans.ttf", 30);
	std::string fore_summary = json["daily"]["data"][dayMark]["summary"].asString();
	myFont.drawString("Summary:   ", 100, 700);
	myFont.drawString(fore_summary, 100, 770);
	//tempHIgh
	std::string fore_tempHigh = json["daily"]["data"][dayMark]["temperatureHigh"].asString();
	myFont.drawString("Tomorrow's Temperature High: ", 100, 900);
	myFont.drawString(fore_tempHigh, 100, 970);

	//draw circle mapping current time
	circle_xPos = ofMap(json["currently"]["time"].asInt(),
		json["daily"]["data"][0]["sunriseTime"].asInt(),
		json["daily"]["data"][0]["sunsetTime"].asInt(),
		0,
		ofGetWidth());
	ofSetColor(ofColor::orange);
	ofDrawCircle(circle_xPos, 100, 50, 50);

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
		switch (key) {
		case '0':
			dayMark = 0;
			cout << 0;

			break;
		case '1':
			dayMark = 1;
			break;
		case '2':
			dayMark = 2;
			break;
		case '3':
			dayMark = 3;
			break;
		case '4':
			dayMark = 4;
			break;
		case '5':
			dayMark = 5;
			break;
		case '6':
			dayMark = 6;
			break;
		case '7':
			dayMark = 7;
			break;

		}
	}
	


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
