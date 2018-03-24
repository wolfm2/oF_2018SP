#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    std::string url = "https://api.darksky.net/forecast/5a6b68c5dc45389b85857cd120471d1b/40.7128,-74.0059";
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    myfont.load("PenguinAttack.ttf", 20);
    myfont1.load("PenguinAttack.ttf", 20);
    myfont2.load("PenguinAttack.ttf", 20);
    myfont3.load("PenguinAttack.ttf", 20);
    myfont4.load("PenguinAttack.ttf", 20);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(50);
    ofSetColor(255);
    
    //    for (Json::ArrayIndex i = 0; i < json["response"]["docs"].size(); ++i)
    //    {
    //        std::string title  = json["response"]["docs"][i]["headline"]["main"].asString();
    //        std::string author = json["response"]["docs"][i]["byline"]["original"].asString();
    //        std::string date   = json["response"]["docs"][i]["pub_date"].asString();
    //        std::string text   = title + " - " + author + " (" + date + ")";
    //        ofDrawBitmapString(text, 20, i * 24 + 40);
    //    }
    std::string time= json["currently"]["time"].asString();
    std::string sunrise= json["daily"]["data"][1]["sunriseTime"].asString();
    std::string sunset= json["daily"]["data"][1]["sunsetTime"].asString();
    std::string summary= json["daily"]["summary"].asString();
    std::string high= json["daily"]["data"][2]["temperatureHigh"].asString();
    
    myfont.drawString("Time: "+ time, 300, 200);
    myfont1.drawString("Sunrise: "+ sunrise, 300, 240);
    myfont2.drawString("Sunset: "+ sunset, 300, 280);
    myfont3.drawString("Summary: "+ summary, 300, 320);
    myfont4.drawString("Temperature High: "+ high, 300, 360);
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
