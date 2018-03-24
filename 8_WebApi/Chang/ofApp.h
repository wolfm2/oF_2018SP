#pragma once

#include "ofMain.h"

#include "ofxJSON.h"

class ofApp : public ofBaseApp{
    
public:
    
    
public:
    
    string tempResult;
    string summaryText;
    string highTemperature;
    string day;
    int num;
    float x;
    float xMax= 1024.;
    
    int sunRiseMin;
    int sunSetMin;
    int currentMin;
    int currentTime;
    int sunRise;
    int sunSet;
    
    ofxJSONElement json;
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxJSONElement json;
    
};
