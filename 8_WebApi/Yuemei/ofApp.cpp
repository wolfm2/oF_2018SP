#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.load("font.otf", 30);
    std::string url = "https://api.darksky.net/forecast/9cfafc3a4acf5bceaf8fd34079970871/37.8267,-122.4233";
    json.open(url);  // stores the JSON response data internally.  Returns T/F
//    string myString = json["root"]["daily"][1]["summary"].asString();
//    string myFloat = json["root"]["daily"]["data"][1]["temperatureHigh"].asString();
//


    


}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor y = ofColor::red;
    ofColor b = ofColor::black;
    b.lerp(b, 0.5);
    ofSetBackgroundColor(b.lerp(y, 0.5));
    
    ofSetColor(215, 196, 187);
    myFont.drawString("Hello World !", 500, 300);
    
    //Draw the summary text and high temperature for tomorrow on the canvas.
    summaryText  = json["daily"]["data"][day]["summary"].asString();
    highTemperature  = json["daily"]["data"][day]["temperatureHigh"].asString();
//    ofDrawBitmapString(summaryText, 100, 100);  non tpyeface
    
    myFont.drawString(summaryText, 100, 100);
    myFont.drawString(highTemperature, 100, 150);
    
    
//Draw an orange circle on the screen at y=100 r=50.  Its X should be a map() using our current time, sunrise/sunset, and the width of the canvas.
    ofSetColor(240, 94, 28);
    
    sunriseTime = json["daily"]["data"][day]["sunriseTime"].asInt();
    sunsetTime = json["daily"]["data"][day]["sunsetTime"].asInt();
    currentTime = json["currently"]["time"].asInt();

//    sunriseTime = toSecond(sunriseTime);
//    sunsetTime = toSecond(sunsetTime);
//    currentTime = toSecond(currentTime);
    
    sunriseTime = (sunriseTime - 1519800000)/60;
    sunsetTime = (sunsetTime - 1519800000)/60;
    currentTime = (currentTime - 1519800000)/60;
    
    cout<<"sunriseTime: "<<sunriseTime<<endl;
    cout<<"sunsetTime: "<<sunsetTime<<endl;
    cout<<"currentTime: "<<currentTime<<endl;
    
    
    circleX = ofMap(currentTime, sunriseTime, sunsetTime, day, ofGetWidth(), ofGetHeight());
    cout<<"circle x: "<<circleX<<endl;
    ofDrawCircle(circleX, 100, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //Use key presses 0-7 to print the above for each day in the forecast.
    if(key == '0'){
        day = 0;
    }
    if(key == '1'){
        day = 1;
    }
    if(key == '2'){
        day = 2;
    }
    if(key == '3'){
        day = 3;
    }
    if(key == '4'){
        day = 4;
    }
    if(key == '5'){
        day = 5;
    }
    if(key == '6'){
        day = 6;
    }
    if(key == '7'){
        day = 7;
        cout<<"7";
    }
}
//--------------------------------------------------------------
int ofApp::toSecond(int _time){
//
//    std::time_t time;
//    struct tm * timeinfo;  // * points to a structure. We'll get to this later.
//    time = _time;
//
//    cout<<"<<<<<<<<time: "<<time<<endl;
//
//    std::time ( &time ); // & gets the variable address. We'll get to this later.
//    timeinfo = localtime ( &time );
//    std::cout << asctime(timeinfo)<<endl;  // prints: Sat Feb 24 19:53:20 2018
//
//    int seconds = timeinfo->tm_hour * 60 * 60 + timeinfo->tm_min * 60 + timeinfo->tm_sec;
//
//    return seconds;
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
