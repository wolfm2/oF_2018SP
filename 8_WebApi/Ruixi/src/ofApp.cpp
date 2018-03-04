#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetWindowShape(1920, 1080);
    myFont.load("font/pixel.ttf", 15);
   

    //darksky API json load and open
    std::string url = "https://api.darksky.net/forecast/0ad68fed5ce43bd57cf7872badb9068d/37.8267,-122.4233";
    // here is parse the JSON
    jsonSuccessful = json.open(url);
    ofSetBackgroundColor(30);
    
    
    // debug  does json open.
    if (jsonSuccessful)
    {
        ofLogNotice("ofApp::setup") << "JSON now is sucessful";
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }

    
    
    
    
//    background color
//    01
//         set background color lerp   ???    //wrong
//        ofColor Y = ofColor(255,255,0);
//        ofColor B = ofColor(0,0,255);
//        ofColor inBetween = Y.lerp(B, 0.5f);
//
//    02
//    set background color as night
//        ofColor night = (0,0,0);
//        ofColor day = (255,255,0);
//        ofBackground(night);
    
    
   
  
    

    
    
    
//    ofSetFrameRate(60);
//    Tweenzor::init();
//    lerpAmount = 255.f;
//    Tweenzor::add(&lerpAmount, 0.f, 255.f, 0.f, 2.f);
//    Tweenzor::getTween(&lerpAmount)->setRepeat(-1, true);

    
    
    

    

    
}

//--------------------------------------------------------------
void ofApp::update(){
//    Tweenzor::update( ofGetElapsedTimeMillis() ) ;
//    for (int i=0; i<1; i++){
//        ofColor r = ofColor::red;
//        ofColor b = ofColor::blue;
//        b.lerp(r, 0.5); // now purple!
//        ofSetBackgroundColor(b.lerp(r, i));
//    }
    
    
    
    //change the color of the sun
    sunColor ++;
    
    //change x location of "Hello world"
    fontX ++;
 

}

//--------------------------------------------------------------
void ofApp::draw(){
   
    

    
  //  here is print the local time
    std::time_t epoch;
    struct tm * timeinfo;  // * points to a structure. We'll get to this later.
    bool currentTime = true;  // print current time or convert an epoch

    if (currentTime) {
        std::time ( &epoch ); // & gets the variable address. We'll get to this later.
    } else {
        epoch = json["current"]["time"].asInt();;  // or whatever epoch you have from json.
    }

    

    timeinfo = localtime ( &epoch );
    std::cout << std::asctime(timeinfo);  // prints: Sat Feb 24 19:53:20 2018

    
    
    
    
    //here is get the data from API
    
    summaryText = json["daily"]["data"][dayNum]["summary"].asString();
    highTemperature = json["daily"]["data"][dayNum]["temperatureHigh"].asString();
    sunRise = json["daily"]["data"][dayNum]["sunriseTime"].asInt();
    sunSet = json["daily"]["data"][dayNum]["sunsetTime"].asInt();
    //    currentTime  = json["current"]["time"].asInt();
    
    //    currentMin = toMinute(currentTime);
    //    sunRiseMin = toMinute(sunRise);
    //    sunSetMin = toMinute(sunSet);
    
    cout << "sunRise: "<<sunRise<<endl;
    cout << "sunSet: "<<sunSet<<endl;
//    cout << "currentTime: "<<currentTime <<endl;
    cout << "day: "<<dayNum<<endl;
    
    
    
    
    
    
    //lerp background color
    ofColor y = ofColor::yellow;
    ofColor b = ofColor::black;
    skyColorMix = ofMap(currentTime, sunRise,sunSet,0, 1);
    //    skyColorMix = 0.5;
    //    y.lerp(b, lerpBB);
    ofSetBackgroundColor(y.lerp(b, skyColorMix));
    
    
    
    // sun
        sunLocationX = ofMap(currentTime,
                             json["daily"]["data"][0]["sunriseTime"].asInt(),
                             json["daily"]["data"][0]["sunsetTime"].asInt(),

                             0 + 50, ofGetWidth() - 150);
    
    
        ofSetCircleResolution(100);
        ofSetColor(ofColor::orange);     //change the color from update
        ofFill();
    
        ofDrawCircle(sunLocationX, 200, 50);
    
    cout<< "sunLocationX:"<<sunLocationX<<endl;

    
    
    
//        ofPopStyle();
    
//        sunLocationX = ofMap(dayNum, sunRise,sunSet, 0, ofGetWidth());
//    for (int x = 0; x < ofGetWidth(); x += deltaX) {
//        //    for(sunLocationX = 0; sunLocationX < ofGetWidth(); sunLocationX += deltaSunLocation +10){
//        ofSetColor(255, sunColor%255, 51);     //change the color from update
//        ofFill();
//        ofSetCircleResolution(100);
//        ofDrawCircle(sunLocationX, 100, 50);
    
//    }

    
    
    
    // draw text
    ofSetColor(255);
    myFont.drawString("HELLO WORLD!",  fontX, ofGetHeight()/2);
    
//    if (fontX >= ofGetWidth()){
//        fontX --;
//    }
//
//    if(fontX <= 0){
//        fontX ++;
//    }
//
   
    

    
    
    
  
//    cout << "currentMin: "<<currentMin<<endl;
//    cout << "sunRiseMin: "<<sunRiseMin<<endl;
//    cout << "sunSetMin: "<<sunSetMin<<endl;
    
    
    
    
    //Text from API
    ofSetColor(255);
    ofFill();
    myFont.drawString(summaryText, 100,500);
    myFont.drawString("Today's hight temperature:"+ highTemperature, 100, 530);
    
    ofNoFill();
    ofDrawTriangle(80, 485, 70, 503, 90, 503);
  
    ofDrawLine(0, 470, ofGetWidth(), 470);
 
    

   

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //0-7
    if(key == '0'){
        dayNum = 0;
      
    }
    
    if(key == '1'){
        dayNum = 1;
    }
    
    if(key == '2'){
        dayNum = 2;
    }
    
    if(key == '3'){
        dayNum = 3;
    }
    
    if(key == '4'){
        dayNum = 4;
    }
    
    if(key == '5'){
        dayNum = 5;
    }
    
    if(key == '6'){
        dayNum = 6;
    }
    
    if(key == '7'){
        dayNum = 7;
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
