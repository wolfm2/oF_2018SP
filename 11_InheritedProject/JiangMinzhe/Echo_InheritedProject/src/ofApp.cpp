#include "ofApp.h"
#include <iostream>
#include <string>
using namespace std;

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
float mapSunScale=1;
float mapFishColor=1;
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

char *intStr;// what for??

int countMin = 0;
int countFrame = 0;
int CbIntes;
string level;
int sig = 0;

int curAgent = 0;
//--------------------------------------------------------------
void ofApp::setup(){
	//--------canvas
	ofSetWindowShape(1200, 1200);
//    ofSetBackgroundColor(95,190,255);
    ofSetCircleResolution(220); //add resolution
	myFont.loadFont("IBM.ttf", 30);
	sea1.load("sea1.png");
	sea2.load("sea2.png");
	seaTrans.load("transSea.png");
	island.load("island.png");
	coal.load("coal.png");
	gas.load("gas.png");
	oil.load("oil.png");
	plant.load("plant.png");
	water.load("water.wav");
    //---------------shader
#ifdef TARGET_OPENGLES
    shader.load("shadersES2/shader");
#else
    if(ofIsGLProgrammableRenderer()){
        shader.load("shadersGL3/shader");
    }else{
        shader.load("shadersGL2/shader");
    }
#endif

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

    ofSetFrameRate(60); // Limit the speed of our program to 60 frames per second
    ofBackground(0);
    
    for (curAgent; curAgent < MAX_AGENTS; curAgent++) {  // only enable if we disable mouse gravity
        Agents[curAgent].start(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
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
            level=json_half["data"][0]["intensity"]["index"].asString();
			mapSmokeScale = ofMap(CbIntes, 150, 400, 2, 5);
			mapSeaLevel = ofMap(CbIntes, 150,400,50, 300);
            mapSunScale=ofMap(CbIntes, 150, 400, 0, ofGetWidth());
            mapFishColor=ofMap(CbIntes, 150, 400, 0, 1);
		}

		//------looping the time
		if (countMin % 2 == 1) {
			half_hour++;
			sig = 1;
		}
		else {
			sig = 0;
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
    
    for (int i=0; i < MAX_AGENTS; i++) {
        Agents[i].update(Agents);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float percentX= mapSunScale/(float)ofGetWidth();
    percentX=ofClamp(percentX, 0, 1);
    ofColor colorLeft=ofColor::gray;
    ofColor colorRight=ofColor::skyBlue;
    ofColor colorMix=colorRight.getLerped(colorLeft, percentX);
    ofSetBackgroundColor(colorMix);
    
    shader.begin();
    ofSetColor(colorMix);
    ofDrawCircle(0,0,250);
    shader.end();
    
	std::string startTime = json_car["data"][0]["from"].asString();

	//draw sea
	ofSetColor(255);
	if (sig) {
		sea1.draw(0, ofGetHeight() / 2+100);
	}
	else {
		sea2.draw(0, ofGetHeight() / 2+100);
	}
	//sea level change
        ofPushMatrix();
		ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2-addSeaLevel+mapSeaLevel+100);
        ofScale(0.6, 0.6);
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
			if (plantMark%4 == 0) {
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
				position_coal.y -= catchupSpeed * (mouseY - position_coal.y); //mouseX, mouseY won't have a value unless you press
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
    
            ofSetColor(255, 255, 255);
			if (plantMark%4 == 1) {
				plant.draw(0, 0);
			}
			if (plantMark%4 == 2) {
				plant.draw(0, 0);
				plant.draw(-100, 10);
			}
			if (plantMark%4 == 3) {
				plant.draw(0, 0);
				plant.draw(-100, 10);
				plant.draw(-160, 30);
			}if (plantMark%4 == 0 && plantMark!=0) {
				plant.draw(70, 20);
            }
	ofPopMatrix();


	seaTrans.draw(0, ofGetHeight() / 2 + 300);
		

	

	//-----------draw the time and carbon intensity on the screen
	float fontWidth = myFont.stringWidth(show_time);//good job!!
	ofSetColor(0);
	myFont.drawString(show_time, ofGetWidth() / 2 - fontWidth / 2,800);
	myFont.drawString("Carbon Intesity :  "+std::to_string(CbIntes), ofGetWidth() / 2-250, 900);

    int alpha = 150;
    
    ofColor gray=ofColor::grey;
    ofColor purple(198, 0, 205, alpha);
    ofColor inbetween = gray.getLerped(purple, mapFishColor);  // linear interpolation between colors color
    
    ofPushMatrix();
    ofTranslate(0, 630);
    for (int i=0; i < MAX_AGENTS; i++) {
        ofSetColor(inbetween);
        Agents[i].draw();
    }
    ofPopMatrix();
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
//    plant.draw(mouseX, mouseY);
//    plant.draw(ofGetWidth()/2, ofGetHeight()/2);
	smokeScale *=0.9;
	addSeaLevel += 30;	
    plantMark++;
	water.play();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//      plant.draw(x, y);

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
