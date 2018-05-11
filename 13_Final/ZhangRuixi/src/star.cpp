//
//  star.cpp
//  of_final
//
//  Created by ruixi zhang on 5/11/18.
//

#include "star.hpp"



star::star(float a, float b){
    x=a;
    y=b;
};

void star::setup(){
    

    
    time = ofRandom(100);
    ofColor rColor=ofColor::cyan;
    ofColor lColor=ofColor::magenta;
    color=rColor.lerp(lColor, ofRandom(1));
    
    StarFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    StarFbo.begin();
    ofClear(255, 255, 255,0);
    StarFbo.end();
    
    ofSetBackgroundColor(0, 0, 0);
}

void star::update(){
    float t=time*ofGetElapsedTimef();
    
    rx=ofSignedNoise(t*0.02)*180;
    ry=ofSignedNoise(t*0.01)*180;
    rz=ofSignedNoise(t*0.03)*180;
    
    tx=sin(t*0.5)*15+ofSignedNoise(time*0.05)*3;
    ty=cos(t*0.6)*15+ofSignedNoise(time*0.06)*3;
    
    vec +=ofPoint(tx, ty);
    
    

    
    
    

}

void star::draw(){
    StarFbo.begin();
    
    ofSetColor(0,1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    ofPushMatrix();
    ofTranslate(vec.x, vec.y);
    
    ofRotateX(rx);
    ofRotateY(ry);
    ofRotateZ(rz);
    
    ofSetColor(color);
    ofNoFill();
        
    ofDrawCircle(x, y, 20);
    ofPopMatrix();
    
    StarFbo.end();
    ofSetColor(255);
    StarFbo.draw(0,0);
    
    // draw the fft resutls:
    ofSetColor(0,197,144,255);
    

}
