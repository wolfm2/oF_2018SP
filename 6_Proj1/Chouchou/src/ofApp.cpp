#include "ofApp.h"
//system
int frameNumber;


//10rects
int rectWt = 130;
int rectHt = 200;
int mark = 0;
//--0--start
float draw0Start = 0;
float draw0Frame = 300;
int start_distance = 0;
//--1--moving rects
float movingNum = 0;
float draw1Frame = 300;
float draw1Start = 300;
//--2-- 
float draw2Start = 600;
ofImage questionMark;
//--3--
float draw3Start = 900;
int draw3Num = 0;
//--4--
float draw4Start = 1600;
ofImage excMark;
int draw4Num = 0;
//--5--
float draw5Start = 1800;
int draw5Num = 0;
ofImage fire;
//--6--
float draw6Start = 2200;
ofImage sun;
int draw6Num = 0;
//--7--
float draw7Start = 2500;



//animation
float speed = 0;
float acc = -4;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(1500, 1500);
	questionMark.load("questionmark.png");
	excMark.load("excmark.png");
	fire.load("fire.png");
	sun.load("sun.png");
}
//--------------------------------------------------------------
void ofApp::update(){
	frameNumber = ofGetFrameNum();
	//--0--
	if (movingNum < draw1Frame) {
		movingNum = frameNumber- draw1Frame;
	}else {
		movingNum = draw1Frame;
	}	
	draw3Num = frameNumber - draw3Start;
	draw4Num = frameNumber - draw4Start;
	draw5Num = frameNumber - draw5Start;
	draw6Num = frameNumber - draw6Start;

}






void drawContinuousRects() {
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2-200);
	//translate(width / 2, height / 2);
	int num = 10;
	float intervalX = ofMap(ofGetMouseX(), 0, ofGetWidth(), 40, -40);
	float intervalY = ofMap(abs(ofGetMouseX() - ofGetWidth() / 2), 0, ofGetWidth() / 2, 0, -20);
	float rectX = 100;
	float rectY = 200;
	float tilt = ofMap(ofGetMouseX(), 0, ofGetWidth(), -20, 20);

	if (mark == 1) { num += 1; }
	//----draw 10 rectangles at one draw() function----
	for (int i = num - 1; i > 0; i--) {
		ofPushMatrix();

		//-----rhytm or not-----
		//-----using rhytm-----
		//float rhytm = ofMap(pow(abs(sin(ofGetFrameNum()* 0.03 - i * 0.3)), 50), 0, 1, 0, -50)* ofMap(abs(ofGetMouseX() - ofGetWidth() / 2), 0, ofGetWidth() / 2, 0, 1);
		//ofTranslate(intervalX * (i - num / 2.0), intervalY * (i - num / 2.0) + rhytm);
		//-----not using rhytm----
		ofTranslate(intervalX * (i - num / 2.0), intervalY * (i - num / 2.0));

		//----draw rectangles with stroke----
		ofFill();
		ofSetColor(20); // fill color  
		ofDrawRectangle(-rectX / 2.0, -rectY / 2.0 + tilt, rectWt, rectHt);
		ofNoFill();
		ofSetColor(255, 251, 249); // contour (stroke) color  
		ofSetLineWidth(4.0f);
		ofDrawRectangle(-rectX / 2.0, -rectY / 2.0 + tilt, rectWt, rectHt);

		ofPopMatrix();
	}
	ofPopMatrix();
	
}
void drawJumpingRects(float rate) {
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2 - 200);
	//translate(width / 2, height / 2);
	int num = 10;
	float intervalX = ofMap(ofGetMouseX(), 0, ofGetWidth(), 40, -40);
	float intervalY = ofMap(abs(ofGetMouseX() - ofGetWidth() / 2), 0, ofGetWidth() / 2, 0, -20);
	float rectX = 100;
	float rectY = 200;
	float tilt = ofMap(ofGetMouseX(), 0, ofGetWidth(), -20, 20);

	if (mark == 1) { num += 1; }
	//----draw 10/11 rectangles at one draw() function----
	for (int i = num - 1; i > 0; i--) {
		ofPushMatrix();

		//-----rhytm or not-----
		//-----using rhytm-----
		float rhytm = ofMap(pow(abs(sin(ofGetFrameNum()*rate- i * 0.3)), 50), 0, 1, 0, -50)* ofMap(abs(ofGetMouseX() - ofGetWidth() / 2), 0, ofGetWidth() / 2, 0, 1);
		ofTranslate(intervalX * (i - num / 2.0), intervalY * (i - num / 2.0) + rhytm);
	
		//----draw rectangles with stroke----
		ofFill();
		ofSetColor(20); // fill color  
		ofDrawRectangle(-rectX / 2.0, -rectY / 2.0 + tilt, rectWt, rectHt);
		ofNoFill();
		ofSetColor(255, 251, 249); // contour (stroke) color  
		ofSetLineWidth(4.0f);
		ofDrawRectangle(-rectX / 2.0, -rectY / 2.0 + tilt, rectWt, rectHt);

		ofPopMatrix();
	}
	ofPopMatrix();

}


void draw0_Start() {
	ofPushMatrix();
	//cout << "YYY";
	ofFill();
	ofSetColor(0, 0, 0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	//draw method 1
	ofDrawRectangle(ofGetWidth()-300, ofGetHeight()- 120+ (sin(ofGetFrameNum()*0.1) + abs(sin(ofGetFrameNum()*0.1)))*-80, 7, 200);
	ofDrawRectangle(100 + start_distance, ofGetHeight() - 10, 50, 10);
	for (int i = 0; i<15; i++) {
		ofDrawRectangle((100 * i + start_distance) % 1500, ofGetHeight() - 10, 50, 10);
	}
	start_distance += 5;
	ofPopMatrix();	
}
void draw1_MovingRects() {
	ofPushMatrix();
	ofTranslate( ofGetWidth() / 2 * movingNum / draw1Frame, ofGetWidth()/2-200);
	
	int num = 10;
	float intervalX = ofMap(ofGetMouseX(), 0, ofGetWidth(), 40, -40);
	float intervalY = ofMap(abs(ofGetMouseX() - ofGetWidth() / 2), 0, ofGetWidth() / 2, 0, -20);
	float rectX = 100;
	float rectY = 150;
	float tilt = ofMap(ofGetMouseX(), 0, ofGetWidth(), -20, 20);


	//----draw 10 rectangles at one draw() function----
	for (int i = num - 1; i > 0; i--) {
		ofPushMatrix();

		//-----rhytm or not-----
		//-----using rhytm-----
		//float rhytm = ofMap(pow(abs(sin(ofGetFrameNum()* 0.03 - i * 0.3)), 50), 0, 1, 0, -50)* ofMap(abs(ofGetMouseX() - ofGetWidth() / 2), 0, ofGetWidth() / 2, 0, 1);
		//ofTranslate(intervalX * (i - num / 2.0), intervalY * (i - num / 2.0) + rhytm);
		//-----not using rhytm----
		ofTranslate(intervalX * (i - num / 2.0), intervalY * (i - num / 2.0));

		//----draw rectangles with stroke----
		ofFill();
		ofSetColor(20); // fill color  
		ofDrawRectangle(-rectX / 2.0, -rectY / 2.0 + tilt, rectWt, rectHt);
		ofNoFill();
		ofSetColor(255, 251, 249); // contour (stroke) color  
		ofSetLineWidth(4.0f);
		ofDrawRectangle(-rectX / 2.0, -rectY / 2.0 + tilt, rectWt, rectHt);

		ofPopMatrix();
	}
	ofPopMatrix();

}
void draw2_Question() {	
	drawContinuousRects();
	ofFill();
	ofSetColor(0, 0, 0);
	ofDrawRectangle(ofGetWidth() - 300, ofGetHeight() - 120, 7, 200);

	if ((frameNumber - draw2Start) >=50) {
		questionMark.draw(1100,1200,50,80);
	}
	if ((frameNumber - draw2Start) >= 100) {
		questionMark.draw(1200, 1100,50, 80);
	}
	if ((frameNumber - draw2Start) >= 200) {
		questionMark.draw(1300, 1200, 50, 80);
	}
}
void draw3_NewOne() {
	cout << draw3Num<<"//";
	if (draw3Num <= 300) {
		drawContinuousRects();
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetWidth() - 300, ofGetHeight() - 120, 7, 200);
		ofDrawRectangle(ofGetWidth() - 2*draw3Num, draw3Num+ (sin(ofGetFrameNum()*0.1) + abs(sin(ofGetFrameNum()*0.1)))*-80, 130, 200);
	}
	else if (draw3Num <= 360) {
		drawContinuousRects();
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetWidth() - 300, ofGetHeight() - 120, 7, 200);
		ofDrawRectangle(ofGetWidth() - 600, 300 + (sin(ofGetFrameNum()*0.3) + abs(sin(ofGetFrameNum()*0.3)))*-80, 130, 200);
	}
	else if (draw3Num <= 420) {
		drawJumpingRects(0.3);
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetWidth() - 300, ofGetHeight() - 120, 7, 200);
		ofDrawRectangle(ofGetWidth() - 600, 300 , 130, 200);

	}
	else if (draw3Num <= 480) {
		drawContinuousRects();
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetWidth() - 300, ofGetHeight() - 120, 7, 200);
		ofDrawRectangle(ofGetWidth() - 600, 300 + (sin(ofGetFrameNum() * 0.6) + abs(sin(ofGetFrameNum() * 0.6)))*-80, 130, 200);

	}
	else if (draw3Num <= 540) {
		drawJumpingRects(0.6);
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetWidth() - 300, ofGetHeight() - 120, 7, 200);
		ofDrawRectangle(ofGetWidth() - 600, 300, 130, 200);
	}
	else if (draw3Num <= 700) {

		drawContinuousRects();
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetWidth() - 300, ofGetHeight() - 120, 7, 200);
		ofDrawRectangle(ofGetWidth() - 600, 300+(320/160)*(draw3Num-540) + (sin(ofGetFrameNum() * 0.2) + abs(sin(ofGetFrameNum() * 0.2)))*-80, 130, 200);
		ofNoFill();
		ofSetColor(255, 251, 249); // contour (stroke) color  
		ofSetLineWidth(4.0f);
		ofDrawRectangle(ofGetWidth() - 600, 300 + (320 / 160)*(draw3Num - 540) + (sin(ofGetFrameNum() * 0.2) + abs(sin(ofGetFrameNum() * 0.2)))*-80, 130, 200);

		mark = 1;
	}


}
void draw4_Oh() {
	drawContinuousRects();
	ofFill();
	ofSetColor(0, 0, 0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawRectangle(ofGetWidth() - 300, ofGetHeight() - 120, 7, 200);
	if (draw4Num >= 100) { excMark.draw(ofGetWidth() - 100, ofGetHeight() - 250, 80, 80); }
}
void draw5_Try() {
	drawContinuousRects();
	if (draw5Num <= 100) {
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetWidth() - 900, ofGetHeight() -750 + (sin(ofGetFrameNum()*0.2) + abs(sin(ofGetFrameNum()*0.2)))*-80, 7, 200);
	}
	else if (draw5Num <= 150) {
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetWidth() - 900, ofGetHeight() - 750 , 7, 200);

	}
	else if (draw5Num<=250){
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetWidth() - 600, ofGetHeight() - 600 + (sin(ofGetFrameNum()*0.5) + abs(sin(ofGetFrameNum()*0.5)))*-80, 7, 200);
	}
	else if (draw5Num <= 300) {
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofDrawRectangle(ofGetWidth() - 600, ofGetHeight() - 600 , 7, 200);
	}
	
	else {
		ofFill();
		ofSetColor(0, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		ofPushMatrix();
		ofTranslate(250, 300);
		ofDrawRectangle(ofGetWidth() - 550, ofGetHeight() - 900 + (sin(ofGetFrameNum()*0.8) + abs(sin(ofGetFrameNum()*0.8)))*-80, 7, 200);
		fire.draw( ofGetWidth() - 450, ofGetHeight() - 850 + (sin(ofGetFrameNum()*0.7) + abs(sin(ofGetFrameNum()*0.8)))*-80,100,100);
		fire.draw(ofGetWidth() - 660, ofGetHeight() - 850 + (sin(ofGetFrameNum()*0.9) + abs(sin(ofGetFrameNum()*0.8)))*-80,100,100);
		ofPopMatrix();
	}

}
void draw6_Sun() {
	drawContinuousRects();
	if (draw6Num <= 100) {
		
		sun.draw(150, 150, draw6Num * 2, draw6Num*2);
		

		ofFill();
		ofSetColor(0, 0, 0);
		ofDrawRectangle(ofGetWidth() - 550, ofGetHeight() - 900, 7, 200);
		ofDrawRectangle(ofGetWidth() - 500, ofGetHeight() - 925,100*draw6Num/100,50 * draw6Num / 100);
		
		
	}
	else if (draw6Num<=200) {
		sun.draw(150, 150, 200, 200);
	}

}



//--------------------------------------------------------------
void ofApp::draw(){
	//----draw background----
	ofFill();
	ofSetColor(255, 251, 249);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawRectangle(ofGetWidth() / 2, ofGetHeight() / 2, ofGetWidth(), ofGetHeight());
	//-0---0,600----
	if (frameNumber < draw2Start&& frameNumber>draw0Start)		{draw0_Start();}
	//-1---300-600----
	if (frameNumber < draw2Start && frameNumber>draw1Start)		{draw1_MovingRects();}
	//-2---600-900----
	if (frameNumber < draw3Start && frameNumber>draw2Start)		{draw2_Question(); }
	//-3---900-1600---
	if (frameNumber < draw4Start && frameNumber>draw3Start)		{draw3_NewOne(); }
	//-4---1600-1800---
	if (frameNumber < draw5Start && frameNumber>draw4Start)		{draw4_Oh(); }
	//-5---1800-2200---
	if (frameNumber < draw6Start && frameNumber>draw5Start)		{ draw5_Try(); }
	//-6---2200-2500---
	if (frameNumber < draw7Start && frameNumber>draw6Start)		{ draw6_Sun(); }






	//--line background from 600
	if (frameNumber > draw2Start) {
		for (int i = 0; i < 15; i++) {
			ofDrawRectangle((100 * i) % 1500, ofGetHeight() - 10, 50, 10);
		}
	}
	
	
	//
	


}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//jump--------------------------------------------------------------------
	if (frameNumber < 500) {
		ofPushMatrix();
		//cout << "YYY";
		ofFill();
		ofSetColor(255, 0, 0);
		ofSetRectMode(OF_RECTMODE_CENTER);
		//draw method 1
		ofDrawRectangle(ofGetWidth() / 4, ofGetHeight() / 2 - 100 + (sin(ofGetFrameNum()*0.3) + abs(sin(ofGetFrameNum()*0.3)))*-50, 30, 200);
		ofPopMatrix();

		//draw method 2
		speed += acc;
		ofDrawRectangle(ofGetWidth() / 2, ofGetHeight() - 100 + speed, 7, 200);
		speed -= 0.5;
		acc += 0.1;
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
