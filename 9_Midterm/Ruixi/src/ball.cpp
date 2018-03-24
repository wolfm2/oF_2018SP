//
//  ball.cpp
//  midterm
//
//  Created by ruixi zhang on 14/03/2018.
//

#include "ball.hpp"


//Ball::Ball(){
//    ofSetCircleResolution(100);
//    
//   
//    
//}
Ball::Ball(){
}

void Ball::setup(){
    

    
//    x = ofRandom(0, ofGetWidth());      // give some random positioning
//    y = ofRandom(0, ofGetHeight());
    
    speedX = ofRandom(-1, 1);           // and random speed and direction
    speedY = ofRandom(-1, 1);
    
    dim = 20;
    
    rRandom = ofRandom(200,225);
    bRandom = ofRandom(200, 225);
    color.set(rRandom,255,bRandom);
    
//    for(int i=0; i<NBALLS; i++){
//        groupOfBalls[i].setup();
//    }
    
    for(int i=0; i<10; i++){
        
    }
   
        //leapmotion set
        ofSetFrameRate(60);
        ofSetVerticalSync(true);
        ofSetLogLevel(OF_LOG_VERBOSE);
    
    
        leap.open();
    
        // keep app receiving data from leap motion even when it's in the background
        leap.setReceiveBackgroundFrames(true);
    
        cam.setOrientation(ofPoint(-20, 0, 0));
    
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_NORMALIZE);
    
    
    ofSetVerticalSync(true);
    
  


    
}

void Ball::update(){
   
    
    
    
    //leapmotion fingers track
    fingersFound.clear();
    
    //here is a simple example of getting the hands and drawing each finger and joint
    //the leap data is delivered in a threaded callback - so it can be easier to work with this copied hand data
    
    //if instead you want to get the data as it comes in then you can inherit ofxLeapMotion and implement the onFrame method.
    //there you can work with the frame data directly.
    
    
    
    //Option 1: Use the simple ofxLeapMotionSimpleHand - this gives you quick access to fingers and palms.
    
    
    simpleHands = leap.getSimpleHands();
    
    if( leap.isFrameNew() && simpleHands.size() ){
        
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200,200);
        
        
        fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
        
        for(int i = 0; i < simpleHands.size(); i++){
            for (int f=0; f<5; f++) {
                int id = simpleHands[i].fingers[ fingerTypes[f] ].id;
                ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp; // metacarpal
                ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip; // proximal
                ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip; // distal
                ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip; // fingertip
                fingersFound.push_back(id);
            }
        }
    }

    
    leap.markFrameAsOld();


 
    
//    x+=speedX;
//    y+=speedY;
    
    
}
//------------------------------------------
void Ball::draw(){
    
    //leaption
    //    ofSetBackgroundAuto(false);
    //    ofBackgroundGradient(ofColor(90, 90, 90), ofColor(30, 30, 30),  OF_GRADIENT_BAR);
    
    cam.begin();
    
    //    ofPushMatrix();
    //    ofRotate(90, 0, 0, 1);
    //    ofSetColor(20);
    //    ofDrawGridPlane(800, 20, false);
    //    ofPopMatrix();
    
    fingerType fingerTypes[] = {THUMB, INDEX, MIDDLE, RING, PINKY};
    
    for(int i = 0; i < simpleHands.size(); i++){
        bool isLeft        = simpleHands[i].isLeft;
        ofPoint handPos    = simpleHands[i].handPos;
        ofPoint handNormal = simpleHands[i].handNormal;


        //                ofSetColor(0, 0, 255);
        //                ofDrawSphere(handPos.x, handPos.y, handPos.z, 20);
        //                ofSetColor(255, 255, 0);
        //                ofDrawArrow(handPos, handPos + 100*handNormal);


        ofSetCircleResolution(6);      //set the circle as hexagon.
        ofSetColor(color);
        ofDrawCircle(handPos.x, handPos.y, dim);



        

        
    
//                for (int f=0; f<5; f++) {
//                    ofPoint mcp = simpleHands[i].fingers[ fingerTypes[f] ].mcp;  // metacarpal
//                    ofPoint pip = simpleHands[i].fingers[ fingerTypes[f] ].pip;  // proximal
//                    ofPoint dip = simpleHands[i].fingers[ fingerTypes[f] ].dip;  // distal
//                    ofPoint tip = simpleHands[i].fingers[ fingerTypes[f] ].tip;  // fingertip
//
//                    ofSetColor(201, 208, 214);
//                    ofDrawSphere(mcp.x, mcp.y, mcp.z, 2);
//                    ofSetColor(144, 163, 170);
//                    ofDrawSphere(pip.x, pip.y, pip.z, 2);
//                    ofSetColor(87, 108, 120);
//                    ofDrawSphere(dip.x, dip.y, dip.z, 2);
//                    ofSetColor(63, 82, 91);
//                    ofDrawSphere(tip.x, tip.y, tip.z, 2);
//
//                    ofSetColor(255, 0, 0);
//                    ofSetLineWidth(20);
//                    ofLine(mcp.x, mcp.y, mcp.z, pip.x, pip.y, pip.z);
//                    ofLine(pip.x, pip.y, pip.z, dip.x, dip.y, dip.z);
//                    ofLine(dip.x, dip.y, dip.z, tip.x, tip.y, tip.z);
        
//                }
        
    
        
        
    }
    
    
    cam.end();
    
  
        
        
    }
    


//----------------------------------------------------

void Ball::exit(){
    // let's close down Leap and kill the controller
    leap.close();
}


