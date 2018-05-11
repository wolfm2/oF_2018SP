#pragma once

#include "ofMain.h"
#include "sentence.hpp"
#include "ofxLeapMotion2.h"

class ofApp : public ofBaseApp{
    
public:
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
    void exit();
    

    string source[22]{
        "You are so fucking ugly",
        "I thought you couldn’t get more ugly",
        "We don’t want losers at the party",
        "a picture of ur tits is going viral, slut",
        "why don't you go and play with electricity",
        "when you were born i bet ur mum cried first",
        "Saying smart stuff makes you look stupid",
        "Smells like shit here since you came around",
        "jump out the window",
        "I wish you all the best ways to die",
        "But you came out the wrong hole",
        "Aren’t u missing a chromosome or2",
        "even a pig would call you fat",
        "We will get you, wait and see",
        "fuck off ugly bitch",
        "you look like Shrek",
        "how are we gonna get rid of you",
        "you are the ugliest in class",
        "You look like a retard",
        "who would want a girl like you",
        "your IQ must be negative",
        "Futuristic lesbian",
    };
    
    sentence sentences[22];
    
    ofxLeapMotion leap;
    vector <ofxLeapMotionSimpleHand> simpleHands;
    vector <int> fingersFound;
    
    ofPoint handPos;
    bool build=false;
    ofPoint a;
    ofPoint b;
    int state=0;
    int frame=0;
    ofSoundPlayer mySound;
  

};

