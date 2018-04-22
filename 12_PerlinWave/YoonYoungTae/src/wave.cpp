#include "wave.hpp"

wave::wave(float x, float y){
    
};

void wave::setup(){

    time = ofRandom(10);
    ofSetBackgroundColor(0,0,0);

    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight(),GL_RGBA32F);

    fbo.begin();
    ofClear(255, 255, 255,0);
    fbo.end();
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));

}

void wave::update(){
    float t = time*ofGetElapsedTimef();
    
    rx=ofSignedNoise(t*0.5)*200;
    ry=ofSignedNoise(t*0.6)*200;
    rz=ofSignedNoise(t*0.7)*200;
    
    
    tx=sin(t*0.3)*10+ofSignedNoise(time*0.01)*2;
    ty=cos(t*0.5)*10+ofSignedNoise(time*0.02)*2;
    
    vec +=ofPoint(tx, ty);
    
   

}

void wave::draw(){
    fbo.begin();
    ofSetColor(0,3);
    ofDrawRectangle(0,0, ofGetWidth(), ofGetHeight());
    ofSetColor(color);
    ofFill();
    ofPushMatrix();
    ofTranslate(vec.x, vec.y, vec.z);
    ofRotateX(rx);
    ofRotateY(ry);
    ofRotateZ(rz);
    
    ofDrawLine(-20,0,20,0);
    ofPopMatrix();
    
    fbo.end();
    
    ofSetColor(255);
    fbo.draw(0,0);
}
