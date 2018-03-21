#include "ofApp.h"
#include "ofxJSON.h"
#include <iostream>
#include <string>

ofTrueTypeFont font;
string enterString;
ofxJSONElement json;
int sun = 1;
int day = 0;
int circleX = 0;
float value = 0;


void ofApp::setup(){
    
    font.load("Neue-Regular.otf", 20);
    
    string url = "https://api.darksky.net/forecast/b2f3df8e0c99cdbcb97ccf437e9676f3/37.8267,-122.4233";
    json.open(url);
    
    
	ofSetVerticalSync(true);
    
    image.load("bg.jpg");
    rain.load("rain.png");
    bg.load("hahaha.mp3");
    
    
    int sunrise = json["daily"]["data"][day]["sunriseTime"].asInt();
    int sunset = json["daily"]["data"][day]["sunsetTime"].asInt();
    int currenttime = json["currently"]["time"].asInt();
    
    
    value = ofMap(currenttime, sunrise, sunset, 0,1);
    
    if (value<0.5){
        
        bg.setVolume(0.3);
        bg.play();
    }


    bg.setLoop(true);
	
	int num = 3000;
	p.assign(num, demoParticle());
	currentMode = PARTICLE_MODE_ATTRACT;
	resetParticles();
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    leap.open();
}

void ofApp::resetParticles(){

	attractPoints.clear();
	for(int i = 0; i < 1; i++){
		attractPoints.push_back( ofPoint( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) ) );
	}
	
	attractPointsWithMovement = attractPoints;
	
	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);		
		p[i].setAttractPoints(&attractPointsWithMovement);;
		p[i].reset();
	}	
}


void ofApp::update(){
    
    simpleHands = leap.getSimpleHands();

    if( leap.isFrameNew() && simpleHands.size() ){

        leap.setMappingX(-30, 30, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(20, 550, -ofGetHeight(), ofGetHeight());
        leap.setMappingZ(-50, 50, -ofGetHeight()/2, ofGetHeight()/2);

        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};

        for(int i = 0; i < simpleHands.size(); i++){
            for (int f=0; f<5; f++) {
                int id = simpleHands[i].fingers[ fingerTypes[f] ].id;
                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp; // metacarpal
                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip; // proximal
                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip; // distal
                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip; // fingertip
                fingersFound.push_back(id);
    
                for(unsigned int i = 0; i < p.size(); i++){
                    
                    float handposx = mcp.x;
                    float handposy = -mcp.y;
                    
                    p[i].update(handposx,handposy);

                }
                
                for(unsigned int i = 0; i < attractPointsWithMovement.size(); i++){
                    attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 10.0;
                    attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 10.0;
                }
            }
        }

    }
    
    
//    fingersFound.clear();
//
//    //here is a simple example of getting the hands and drawing each finger and joint
//    //the leap data is delivered in a threaded callback - so it can be easier to work with this copied hand data
//
//    //if instead you want to get the data as it comes in then you can inherit ofxLeapMotion and implement the onFrame method.
//    //there you can work with the frame data directly.
//
//
//
//    //Option 1: Use the simple ofxLeapMotionSimpleHand - this gives you quick access to fingers and palms.
//
//
//    simpleHands = leap.getSimpleHands();
//
//    if( leap.isFrameNew() && simpleHands.size() ){
//
//        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
//        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
//        leap.setMappingZ(-150, 150, -200, 200);
//
//        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
//
//        for(int i = 0; i < simpleHands.size(); i++){
//            for (int f=0; f<5; f++) {
//                int id = simpleHands[i].fingers[ fingerTypes[f] ].id;
//                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp; // metacarpal
//                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip; // proximal
//                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip; // distal
//                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip; // fingertip
//                fingersFound.push_back(id);
//            }
//        }
//    }
//
//
//
//    //Option 2: Work with the leap data / sdk directly - gives you access to more properties than the simple approach
//    //uncomment code below and comment the code above to use this approach. You can also inhereit ofxLeapMotion and get the data directly via the onFrame callback.
//    /*
//     vector <Hand> hands = leap.getLeapHands();
//     if( leap.isFrameNew() && hands.size() ){
//
//     //leap returns data in mm - lets set a mapping to our world space.
//     //you can get back a mapped point by using ofxLeapMotion::getMappedofPoint with the Leap::Vector that tipPosition returns
//     leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
//     leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
//     leap.setMappingZ(-150, 150, -200, 200);
//
//     fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
//
//     for(int i = 0; i < hands.size(); i++){
//     for(int j = 0; j < 5; j++){
//     ofPoint pt;
//
//     const Finger & finger = hands[i].fingers()[ fingerTypes[j] ];
//
//     //here we convert the Leap point to an ofPoint - with mapping of coordinates
//     //if you just want the raw point - use ofxLeapMotion::getofPoint
//     pt = leap.getMappedofPoint( finger.tipPosition() );
//     pt = leap.getMappedofPoint( finger.jointPosition(finger.JOINT_DIP) );
//
//     fingersFound.push_back(finger.id());
//     }
//     }
//     }
//     */
//
//    //IMPORTANT! - tell ofxLeapMotion that the frame is no longer new.
//    leap.markFrameAsOld();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if (sun==1){
    
    
    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    
        for(int i = 0; i < simpleHands.size(); i++){
            bool isLeft        = simpleHands[i].isLeft;
            ofPoint handPos    = simpleHands[i].handPos;
            ofPoint handNormal = simpleHands[i].handNormal;
    
//            ofSetColor(0, 0, 255);
//            ofDrawSphere(handPos.x, handPos.y, handPos.z, 20);
//            ofSetColor(255, 255, 0);
//            ofDrawArrow(handPos, handPos + 100*handNormal);
    
            for (int f=0; f<5; f++) {
                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
    
//                ofSetColor(0, 255, 0);
//                ofDrawSphere(mcp.x, mcp.y, mcp.z, 12);
//                ofDrawSphere(pip.x, pip.y, pip.z, 12);
//                ofDrawSphere(dip.x, dip.y, dip.z, 12);
//                ofDrawSphere(tip.x, tip.y, tip.z, 12);
//
//                ofSetColor(255, 0, 0);
//                ofSetLineWidth(20);
//                ofLine(mcp.x, mcp.y, mcp.z, pip.x, pip.y, pip.z);
//                ofLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
//                ofLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
            }
        }
    image.draw(0,0,ofGetWidth(),ofGetHeight());

	for(unsigned int i = 0; i < p.size(); i++){
		p[i].draw();
	}
    
    
	
//    ofSetColor(190);
//
//
//    ofSetColor(230);
//    ofDrawBitmapString(currentModeStr + "\n\nSpacebar to reset. \nKeys 1-4 to change mode.", 10, 20);
//
//    ofBackgroundGradient(ofColor(90, 90, 90), ofColor(30, 30, 30),  OF_GRADIENT_BAR);
//
//    ofSetColor(200);
//    ofDrawBitmapString("ofxLeapMotion - Example App\nLeap Connected? " + ofToString(leap.isConnected()), 20, 20);

    cam.begin();
//
//    ofPushMatrix();
//    ofRotate(90, 0, 0, 1);
//    ofSetColor(20);
//    ofDrawGridPlane(800, 20, false);
//    ofPopMatrix();
////
//
//    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
//
//    for(int i = 0; i < simpleHands.size(); i++){
//        bool isLeft        = simpleHands[i].isLeft;
//        ofPoint handPos    = simpleHands[i].handPos;
//        ofPoint handNormal = simpleHands[i].handNormal;
//
//        ofSetColor(0, 0, 255);
//        ofDrawSphere(handPos.x, handPos.y, handPos.z, 20);
//        ofSetColor(255, 255, 0);
//        ofDrawArrow(handPos, handPos + 100*handNormal);
//
//        for (int f=0; f<5; f++) {
//            ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
//            ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
//            ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
//            ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
//
//            ofSetColor(0, 255, 0);
//            ofDrawSphere(mcp.x, mcp.y, mcp.z, 12);
//            ofDrawSphere(pip.x, pip.y, pip.z, 12);
//            ofDrawSphere(dip.x, dip.y, dip.z, 12);
//            ofDrawSphere(tip.x, tip.y, tip.z, 12);
//
//            ofSetColor(255, 0, 0);
//            ofSetLineWidth(20);
//            ofLine(mcp.x, mcp.y, mcp.z, pip.x, pip.y, pip.z);
//            ofLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
//            ofLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
//        }
//    }
        cam.end();
    
    
    ofColor r = ofColor::yellow;
    ofColor b = ofColor::black;
    ofSetColor(b.lerp(r, value),80);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    
    ofSetColor(255, 255, 255);
    ofFill();
    font.drawString(enterString, ofGetWidth() / 2-110, ofGetHeight()-100);
        enterString = "Fireflies Play";}
    
    if (sun == 0){
        
        image.draw(0,0,ofGetWidth(),ofGetHeight());
        
        rain.draw(80,80,15,25);
        rain.draw(50,130,15,25);
        rain.draw(100,300,15,25);
        rain.draw(120,890,15,25);
        rain.draw(140,470,15,25);
        rain.draw(170,510,15,25);
        rain.draw(210,1000,15,25);
        rain.draw(500,600,15,25);
        rain.draw(1000,800,15,25);
        rain.draw(700,65,15,25);
        rain.draw(320,600,15,25);
        rain.draw(5000,300,15,25);
        rain.draw(ofGetWidth()/2,ofGetHeight()/2,15,25);
        rain.draw(1300,300,15,25);
        rain.draw(200,310,15,25);
        rain.draw(670,260,15,25);
        rain.draw(720,410,15,25);
        
        
        int sunrise = json["daily"]["data"][day]["sunriseTime"].asInt();
        int sunset = json["daily"]["data"][day]["sunsetTime"].asInt();
        int currenttime = json["currently"]["time"].asInt();
        
        
        value = ofMap(currenttime, sunrise, sunset, 0,1);
        
//        if (value<0.5){
//            bg.setVolume(0.3);
//            bg.play();
//        }
        
        ofColor r = ofColor::yellow;
        ofColor b = ofColor::black;
        ofSetColor(b.lerp(r, value),80);
        ofFill();
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        
        ofSetColor(255, 255, 255);
        ofFill();
        font.drawString(enterString, ofGetWidth() / 2-110, ofGetHeight()-100);
        enterString = "Fireflies Play";
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'r'){
        sun = 0;
    }
    
    if (key == 's'){
        sun = 1;
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
