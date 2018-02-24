#include "ofApp.h"
ofTrueTypeFont myfont;
ofImage simpsons;
string enterString;

float xRotate = 0;
float yRotate = 0;
float zRotate = 0;

float xTranslate = 0;
float yTranslate = 0;

float xScale = 0.2;
float yScale = 0.2;
//--------------------------------------------------------------
void ofApp::setup(){
	simpsons.load("Simpsons.png");
	ofSetWindowShape(1200, 1200);
	myfont.load("orangeJuice.ttf",50);

}

//--------------------------------------------------------------
void ofApp::update(){

}


//--------------------------------------------------------------
void ofApp::draw(){
	//background
	ofFill();
	ofSetColor(255, 255, 255);
	ofDrawRectangle(0, 0, 1200, 1200);
	//change the parameters in the keypressed function and change the style in draw
	ofPushMatrix();
		ofTranslate(ofGetWidth()/2, ofGetHeight() / 2);
		ofScale(2, 2);
		ofTranslate(xTranslate, yTranslate);
		ofScale(xScale,yScale);
		ofRotateX(xRotate);
		ofRotateY(yRotate);
		ofRotateZ(zRotate);
		ofSetColor(255, 255, 255);
		simpsons.draw(-simpsons.getWidth() / 2, -simpsons.getHeight() / 2);
		
	ofPopMatrix();	
	ofFill();
	ofSetColor(0, 0, 0);
	myfont.load("orangeJuice.ttf", 50);
	myfont.drawString(enterString, ofGetWidth() / 2-300, ofGetHeight()-300);
	myfont.load("orangeJuice.ttf", 30);
	myfont.drawString("Control width: w/W", 50, 50);
	myfont.drawString("Rotate by X axis: x/X", 50, 90);
	myfont.drawString("Rotate by Y axis: y/Y", 50, 130);
	myfont.drawString("Rotate by Z axis: z/Z", 50, 170);
	myfont.drawString("Control directions: a/d/s/q", 50, 210);
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	enterString = "You are entering:  " ;
	switch (key) {
	//rotate axis detecting
	case 'x':
		enterString += "x";
		xRotate--;
		break;
	case 'X':
		enterString += "X";
		xRotate++;
		break;
	case 'y':
		enterString += "y";
		yRotate--;
		break;
	case 'Y':
		enterString += "Y";
		yRotate++;
		break;
	case 'z':
		enterString += "z";
		zRotate--;
		break;
	case 'Z':
		enterString += "Z";
		zRotate++;
		break;

	//translate control detecting
	case 'q':
		enterString += "q";
		yTranslate-=5;
		break;
	case 'a':
		enterString += "a";
		xTranslate-=5;
		break;
	case 's':
		enterString += "s";
		yTranslate+=5;
		break;
	case 'd':
		enterString += "d";
		xTranslate+=5;
		break;

	//scale control detecting
	case 'h':
		enterString += "h";
		if (yScale >= 0.1) {
			yScale -= 0.005;
		}
		else
			yScale = 0.1;
		break;
	case 'H':
		enterString += "H";
		if (yScale <= 1) {
			yScale += 0.005;
		}
		else
			yScale = 1;
		break;
	case 'w':
		enterString += "w";
		if (xScale >= 0.1) {
			xScale -= 0.005;
		}
		else 
			xScale = 0.1;
		break;
	case 'W':
		enterString += "W";
		if (xScale <= 1) {
			xScale += 0.005;
		}
		else
			xScale = 1;
		break;
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
