#include "ofApp.h"
#include<iostream>
#include<string>
#include <map>

using namespace std;
int lerppp = 0;


//--------------------------------------------------------------
void ofApp::setup(){
    
    //第一步写出url：
    std::string url = "https://api.darksky.net/forecast/11986ae43a4ea3ae397cbd7bcce041d5/37.8267,-122.4233";

    //第二步判断JSON URL是否可以读取：
    bool parsingSuccessful = json.open(url);

    if (parsingSuccessful)    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
}

//--------------------------------------------------------------
void ofApp::update(){
  

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofSetColor(255);
    
    //Draw the summary text and high temperature for tomorrow on the canvas.
    summaryText  = json["daily"]["data"][num]["summary"].asString();
    highTemperature  = json["daily"]["data"][num]["temperatureHigh"].asString();
    
    //print the information we get in JSON to canvas
    ofDrawBitmapString(summaryText, 120,140);
    ofDrawBitmapString(highTemperature, 120,200);
    ofDrawLine(10,230,1000,230);
    
    currentTime  = json["daily"]["data"][num]["time"].asInt();
    currentMin = toMinute(currentTime);
    sunRise  = json["daily"]["data"][num]["sunriseTime"].asInt();
    sunRiseMin = toMinute(sunRise);
    sunSet  = json["daily"]["data"][num]["sunsetTime"].asInt();
    sunSetMin = toMinute(sunSet);
    
    cout << "currentTime: "<<currentTime <<endl;
    cout << "currentMin: "<<currentMin<<endl;
    cout << "sunRise: "<<sunRise<<endl;
    cout << "sunRiseMin: "<<sunRiseMin<<endl;
    cout << "sunSet: "<<sunSet<<endl;
    cout << "sunSetMin: "<<sunSetMin<<endl;
      
    
   // x= ofMap(float(currentTime), float(sunRise), float(sunSet), 0, 1024);
//        x= ofMap(currentTime, sunRise, sunSet, 0, 1024);
        x= ofMap(currentMin, sunRiseMin, sunSetMin, 0, 1024);

         std::cout << "value: " << x << endl;                //value: -613.754??????????

   // ofPopMatrix();
//    ofTranslate(1000, 20);
    //ofTranslate(500, 300);

    //Draw an orange circle on the screen at y=100 r=50.  Its X should be a map() using our current time, sunrise/sunset, and the width of the canvas.
    ofSetColor(255,0,0);
    ofDrawCircle(x, 100, 50);
    //ofPushMatrix();
    
    lerppp = ofMap(json["currently"]["time"].asInt(), json["daily"]["data"][day]["sunriseTime"].asInt(), json["daily"]["data"][day]["sunsetTime"].asInt(), 0, 1);
ofColor black = ofColor(0, 0, 0);
    ofColor yellow = ofColor(255, 255, 0);
      ofBackground(yellow.lerp(black, lerppp));
    


}
//------------------------------------------------------------

int ofApp::toMinute(int timeStruct){
    std::time_t epoch;
    struct tm * timeinfo; // points to a structure. We'll get to this later.
    std::time ( &epoch ); // & gets the variable address. We'll get to this later.

    timeinfo = localtime ( &epoch );
    
    int min = timeinfo->tm_min;
    int hr = timeinfo->tm_hour;
    int value = hr*60 + min;
    cout << value<<endl; // prints: Sat Feb 24 19:53:20 2018
    
   return value;
      std::cout <<"hello"<< std::asctime(timeinfo);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //Use key presses 0-7 to print the above for each day in the forecast.
    
    if (key == '0'){
        num =0;
//      std::string highTemperature  = json["daily"]["data"][0]["temperatureHigh"].asString();
//      std::string summaryText  = json["daily"]["data"][0]["summary"].asString();

 cout<<"low";    }
    
    if (key == '1'){
        num =1;
        
        cout<<"1";    }
    
    if (key == '2'){
        num =2;
        
        cout<<"2";    }
    
    if (key == '3'){
        num =3;
        
        cout<<"3";    }
    
    if (key == '4'){
        num =4;
        cout<<"4";    }
    
    if (key == '5'){
        num =5;
        
        cout<<"5";    }
    
    if (key == '6'){
        num =6;
        
        cout<<"6";    }
    
    if (key == '7'){
        num =7;
        
        cout<<"7";    }

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
