#include "ofApp.h"
#include <iostream>
#include <string>
//setup
ofTrueTypeFont myFont;
ofImage sea1, sea2, seaTrans,
		island,
		coal,gas,oil,
		plant,
		Dutch,Irish;
ofSoundPlayer water;

//sea level matrix
int addSeaLevel = 0;
float mapSeaLevel = 0;
//carbon scale
float smokeRadius1 = 40;
float smokeRadius2 = 60;
float smokeRadius3 = 100;
float smokeScale = 1;
float mapSmokeScale = 1;
//plant mark
int plantMark = 0;
//-----carbon

ofPoint position_coal;
float catchupSpeed = 0.01;

std::string url_car = "https://api.carbonintensity.org.uk/intensity";
std::string url_fac = "https://api.carbonintensity.org.uk/intensity/factors";

//2017-08-25T12:35Z
int half_month=1;
int half_day=1;
int half_hour=0;
int half_minute=0;
// url_half_total = url_half + url_half_time;
// url_half_time = "2018-" + url_half_month + "-" + url_half_day + "T" + url_half_hour + ":" + url_half_minute + "Z";
std::string url_half_month;
std::string url_half_day;
std::string url_half_hour;
std::string url_half_minute;
std::string url_half_time;
std::string url_half = "https://api.carbonintensity.org.uk/intensity/";
std::string url_half_total;
std::string show_time;

char *intStr;

int countMin = 0;
int countFrame = 0;
int CbIntes;
int signal = 0;


//--------------------------------------------------------------
void ofApp::setup(){
	//--------canvas
	ofSetWindowShape(1600, 1600);
	ofSetBackgroundColor(95,190,255);
	myFont.loadFont("IBM.ttf", 30);
	sea1.load("sea1.png");
	sea2.load("sea2.png");
	seaTrans.load("transSea.png");
	island.load("island.png");
	coal.load("coal.png");
	gas.load("gas.png");
	oil.load("oil.png");
	plant.load("plant.png");
	//Dutch.load("dutch.png");
	//Irish.load("irish.png");

	water.load("water.wav");



	//----------------------------------------------------------------------------------------JSON
	bool parsingSuccessful_car = json_car.open(url_car);

	if (parsingSuccessful_car) {
		ofLogNotice("ofApp::setup") << "parse Carbon Intensity successful";
	}
	else {
		ofLogNotice("ofApp::setup") << "failed to parse JSON_CAR";
	}
	//------json_factor
	bool parsingSuccessful_fac = json_fac.open(url_fac);

	if (parsingSuccessful_fac) {
		ofLogNotice("ofApp::setup") << "parse carbon facrtors successful";
	}
	else {
		ofLogNotice("ofApp::setup") << "failed to parse JSON_FAC";
	}
	
	

}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetFrameNum() % 5 == 0)
	{
		//------------correcting the time format API need
		if (half_month < 10) {
			url_half_month = "0" + std::to_string(half_month);
		}
		else {
			url_half_month = std::to_string(half_month);
		}
		if (half_day < 10) {
			url_half_day = "0" + std::to_string(half_day);
		}
		else {
			url_half_day = std::to_string(half_day);
		}
		if (half_hour < 10) {
			url_half_hour = "0" + std::to_string(half_hour);
		}
		else {
			url_half_hour = std::to_string(half_hour);
		}
		if (countMin % 2 == 0) {
			url_half_minute = "00";
		}
		else {
			url_half_minute = "30";
		}


		//-----------creating the url API need
		url_half_time = "2018-" + url_half_month + "-" + url_half_day + "T" + url_half_hour + ":" + url_half_minute + "Z";
		url_half_total = url_half + url_half_time;
		show_time = "2018 - " + url_half_month + " - " + url_half_day + " - " + url_half_hour + " : " + url_half_minute;
		//cout << url_half_time<<"@@@";
		//-----------getting info: carbon intensityfrom API
		if (json_half.open(url_half_total)) {
			CbIntes = json_half["data"][0]["intensity"]["actual"].asInt();
			mapSmokeScale = ofMap(CbIntes, 150, 400, 2, 5);
			mapSeaLevel = ofMap(CbIntes, 150,400,50, 300);
		}

		//------looping the time
		if (countMin % 2 == 1) {
			half_hour++;
			signal = 1;
		}
		else {
			signal = 0;
		}
		if (half_hour == 24) {
			half_hour = 0;
			half_day++;
		}
		if (half_day == 29) {
			half_day = 1;
			half_month++;
		}

		countMin++;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	std::string startTime = json_car["data"][0]["from"].asString();


	// a stupid try of looping time, which has too many for loop in one frame so that is hard to draw something on the screen
	{

		//for (half_month = 1; half_month < 5; half_month++) {
		//	//ss << half_month;
		//	if (half_month < 10) {
		//		url_half_month = "0" + std::to_string(half_month);
		//	}
		//	else {
		//		url_half_month = std::to_string(half_month);
		//	}

		//	for (half_day = 1; half_day < 29; half_day++) {
		//		if (half_day < 10) {
		//			url_half_day = "0" + std::to_string(half_day);
		//		}
		//		else {
		//			url_half_day = std::to_string(half_day);
		//		}

		//		for (half_hour = 0; half_hour < 24; half_hour++) {

		//			if (half_hour < 10) {
		//				url_half_hour = "0" + std::to_string(half_hour);
		//			}
		//			else {
		//				url_half_hour = std::to_string(half_hour);
		//			}
		//			for (half_minute = 0; half_minute < 2; half_minute++) {
		//				if (half_minute == 0) {
		//					url_half_minute = "00";
		//				}
		//				else {
		//					url_half_minute = "30";
		//				}

		//				//format-------    2017 - 08 - 25T12:35Z

		//				url_half_time = "2018-" + url_half_month + "-" + url_half_day + "T" + url_half_hour + ":" + url_half_minute + "Z";
		//				url_half_total = url_half + url_half_time;
		//				show_time = "2018 - " + url_half_month + " - " + url_half_day + " - " + url_half_hour + " : " + url_half_minute;
		//				bool parsingSuccessful_half = json_half.open(url_half_total);
		//				CbIntes = json_half["data"][0]["intensity"]["actual"].asInt();
		//				
		//				float fontWidth = myFont.stringWidth(show_time);
		//				//ofSetColor(0);
		//				myFont.drawString(show_time, ofGetWidth() / 2 - fontWidth / 2, 400);
		//				myFont.drawString(std::to_string(CbIntes), ofGetWidth() / 2, 500);

		//			}

		//		}

		//	}
		//}

	}
	
	//draw sea
	ofSetColor(255);
	if (signal) {
		sea1.draw(0, ofGetHeight() / 2+100);
	}
	else {
		sea2.draw(0, ofGetHeight() / 2+100);
	}
	//sea level change
	ofPushMatrix();
		ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2-addSeaLevel+mapSeaLevel);
			island.draw(-320, -230,740,810);
			gas.draw(-180, -400);
			coal.draw(- 400, -500);
			oil.draw(100, -330);
			ofPushMatrix();
			//gas smoke

			ofTranslate(-100, -500);
			ofSetColor(201, 225, 245, 90);
			ofDrawCircle(0, 0, smokeRadius1*smokeScale*mapSmokeScale);
			ofDrawCircle(-40, -20, smokeRadius2*smokeScale*mapSmokeScale);
			ofDrawCircle(-60, -50, smokeRadius2*smokeScale*mapSmokeScale);
			ofDrawCircle(-80, -40, smokeRadius2*smokeScale*mapSmokeScale);
			ofDrawCircle(-110, -100, smokeRadius2*smokeScale*mapSmokeScale);
			ofPopMatrix();
			ofPushMatrix();
			//coal smoke
			if (plantMark == 0) {
				ofTranslate(-420, -520);
				ofSetColor(70, 70, 70, 50);
				ofDrawCircle(0, 0, smokeRadius1*smokeScale*mapSmokeScale);
				ofDrawCircle(-40, -20, smokeRadius2*smokeScale*mapSmokeScale);
				ofDrawCircle(-60, -50, smokeRadius2*smokeScale*mapSmokeScale);
				ofDrawCircle(-80, -40, smokeRadius2*smokeScale*mapSmokeScale);
				ofDrawCircle(-130, -50, smokeRadius2*smokeScale*mapSmokeScale);
				ofPopMatrix();
				
			}
			else {
			
				ofPushMatrix();
				//coal smoke
				position_coal.x -= catchupSpeed * (mouseX - position_coal.x);
				position_coal.y -= catchupSpeed * (mouseY - position_coal.y);
				ofTranslate(-420 + position_coal.x, -520 + position_coal.y);
				ofSetColor(70, 70, 70, 50);
				ofDrawCircle(0, 0, smokeRadius1*smokeScale*mapSmokeScale);
				ofDrawCircle(-40, -20, smokeRadius2*smokeScale*mapSmokeScale);
				ofDrawCircle(-60, -50, smokeRadius2*smokeScale*mapSmokeScale);
				ofDrawCircle(-80, -40, smokeRadius2*smokeScale*mapSmokeScale);
				ofDrawCircle(-130, -50, smokeRadius2*smokeScale*mapSmokeScale);
				ofPopMatrix();
			}
			
				//smog&CO2 scale --- controlled by CbIntesity
			
			
			ofPushMatrix();
			//oil smoke
				ofTranslate(300, -300);
				ofSetColor(114, 109, 87, 70);
				ofDrawCircle(0, 0, smokeRadius1*smokeScale*mapSmokeScale);
				ofDrawCircle(-40, -20, smokeRadius2*smokeScale*mapSmokeScale);
				ofDrawCircle(-60, -50, smokeRadius2*smokeScale*mapSmokeScale);
				ofDrawCircle(-80, -40, smokeRadius2*smokeScale*mapSmokeScale);
				ofDrawCircle(-60, -80, smokeRadius2*smokeScale*mapSmokeScale);
			ofPopMatrix();
			if (plantMark == 1) {
				plant.draw(0, 0);
			}
			if (plantMark == 2) {
				plant.draw(0, 0);
				plant.draw(-100, 10);
			}
			if (plantMark == 3) {
				plant.draw(0, 0);
				plant.draw(-100, 10);
				plant.draw(-160, 30);
			}if (plantMark == 4) {
				plant.draw(70, 20);
			}
	ofPopMatrix();


	seaTrans.draw(0, ofGetHeight() / 2 + 200);
		

	

	//-----------draw the time and carbon intensity on the screen
	float fontWidth = myFont.stringWidth(show_time);
	ofSetColor(0);
	myFont.drawString(show_time, ofGetWidth() / 2 - fontWidth / 2,1200);
	myFont.drawString("Carbon Intesity :  "+std::to_string(CbIntes), ofGetWidth() / 2-250, 1300);

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
	smokeScale *=0.9;
	addSeaLevel += 30;	
	plantMark++;
	water.play();
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
