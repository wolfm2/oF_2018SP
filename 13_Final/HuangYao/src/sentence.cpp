//
//  sentence.cpp
//  Yao
//
//  Created by Yao Huang on 5/10/18.
//

#include "sentence.hpp"

sentence::sentence(){
    object.loadFont("AdobeHeitiStd-Regular.otf", ofRandom(10, 30), true, true, true);
    posX= ofRandom(200, ofGetWindowWidth());
    posY= ofRandom(100, ofGetWindowHeight()- 100);
}

void sentence::setup(string input){
    text= input;
    strncpy(character, text.c_str(), 100);
    
    for(int i=0; i< text.length(); i++){
        pos[i].x= posX;
        pos[i].y= posY;
        drop[i].x= ofRandom(-0.5, 0.5);
        drop[i].y= ofRandom(2,3);
        move.x= ofRandom(-1, 1);
        move.y= ofRandom(-1, 1);
    }
    
}

void sentence::update(){
    if(split== true){
        for(int i= 0; i< text.length(); i++){
            if(pos[i].y< ofGetWindowHeight()-5){
                pos[i].x+= drop[i].x;
                pos[i].y+= drop[i].y;
            }
        }
    }else{
        for(int i= 0; i< text.length(); i++){
            pos[i].x+= move.x;
            pos[i].y+= move.y;
            if(pos[i].x> ofGetWindowWidth()-30 || pos[i].x< 5){
                move.x*= -1;
            }
            if(pos[i].y> ofGetWindowHeight()-5 || pos[i].y< 5){
                move.y*= -1;
            }
        }
    }
}

void sentence::draw(){
    if(split== true){
        for(int i=0; i< text.length(); i++){
            object.drawString(ofToString(character[i]), pos[i].x+ i* 10, pos[i].y);
        }
    }else{
        object.drawString(text, pos[0].x, pos[0].y);
    }
}
