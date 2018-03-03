#include "ofApp.h"


void ofApp::setup()
{
    std::string url = "https://api.darksky.net/forecast/5a6b68c5dc45389b85857cd120471d1b/40.7128,-74.0059";
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
}


void ofApp::draw()
{
    ofBackground(0);
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
    std::string sunrise= json["daily"]["data"]["sunriseTime"].asString();
    std::string sunset= json["daily"]["data"]["sunsetTime"].asString();
    std::string summary= json["daily"]["summary"].asString();
    std::string high= json["daily"]["data"]["temperatureHigh"].asString();
    
    ofDrawBitmapString("Time "+ time, 200, 200);
    ofDrawBitmapString("Sunrise"+ sunrise, 200, 220);
    ofDrawBitmapString("Sunset"+ sunset, 200, 240);
    ofDrawBitmapString("Summary"+ summary, 200, 260);
    ofDrawBitmapString("TemHigh"+ high, 200, 280);
}
