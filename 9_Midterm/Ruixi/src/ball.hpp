//
//  ball.hpp
//  midterm
//
//  Created by ruixi zhang on 14/03/2018.
//

//#ifndef ball_hpp
//#define ball_hpp
//
//#include <stdio.h>

#pragma once
#include "ofMain.h"
#include "ofxLeapMotion2.h"


class Ball {
public:
    
//    Ball6(){}
//    ~Ball(){}
    
    //leapmotion here
    void exit();
    
    ofxLeapMotion leap;
    vector <ofxLeapMotionSimpleHand> simpleHands;
    
    vector <int> fingersFound;
    ofEasyCam cam;
    
    ofVec2f pos;
    float radius;
    ofColor color;
    float pct;

  
    
    Ball();
    void setup();
    void update(); 
    void draw();
    
    
    // variables
    float x;        // position
    float y;
    float speedY;   // speed and direction
    float speedX;
    int dim;        // size
    float rRandom;
    float bRandom;
//    ofColor color;
    
    vector<Ball> balls;
  
    ofPoint ball_pos;
    
    

    

    
//    #define NBALLS 10
//    Ball groupOfBalls[NBALLS];
//
};

//#endif /* ball_hpp */

