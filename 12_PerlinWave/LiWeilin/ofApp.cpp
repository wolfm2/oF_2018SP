#include "ofApp.h"

vector<line> lines;

line::line(){
}
void line::setup(){
    
    ofSetBackgroundColor(0,0,0);

    color.set(ofRandom(80),ofRandom(80),ofRandom(80));
    location = ofPoint(100,3,50);
    weight = ofRandom(0,1);
    
    rotateX = ofRandom(10);
    rotateY = ofRandom(20);
    rotateZ = ofRandom(30);
    a = ofRandom(0.5,0.6);
    b = ofRandom(0.1,0.2);
    c = ofRandom(0.3,0.4);
    
    fbo.allocate(ofGetWindowWidth(),ofGetWindowHeight());
    fbo.begin();
    ofClear(255,255,255,0);
    fbo.end();
    
    
}

void line::update(){
    time = ofGetElapsedTimef();
    
    scale = ofNoise(time*0.2)*weight;
    rotateX = ofSignedNoise(time*0.1)*150;
    rotateY = ofSignedNoise(time*0.2)*200;
    rotateZ = ofSignedNoise(time*0.3)*250;
    
    moveX= ofSignedNoise(time*a)*ofRandom(1,10);
    moveY= ofSignedNoise(time*b)*ofRandom(1,15);
    moveZ= ofSignedNoise(time*c)*ofRandom(1,20);
    
    location+= ofPoint(moveX, moveY,moveZ);
}

void line::draw(){
    fbo.begin();
    ofSetColor(255,255,255,5);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    ofPushMatrix();
    
    ofRotateX(rotateX);
    ofRotateY(rotateY);
    ofRotateZ(rotateZ);
    
    ofTranslate(location.x, location.y, location.z);
    ofScale(scale,scale,scale);
    ofPushStyle();
    ofSetColor(color);
    ofFill();
    ofDrawLine(300,0,500,0);
    ofPopStyle();
    ofPopMatrix();
    
    fbo.end();
    ofSetColor(255);
    fbo.draw(0,0);
    
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    for(int i=0; i<5; i++){
        line newLine;
        newLine.setup();
        lines.push_back(newLine);
    }
}


//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0; i<lines.size(); i++){
        lines[i].update();

        
        
        if(lines[i].location.y<0||lines[i].location.y>ofGetWindowHeight()||lines[i].location.x<0||lines[i].location.x>ofGetWindowWidth()){
            lines.erase(lines.begin()+i);
            line newLine;
            newLine.setup();
            lines.push_back(newLine);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i=0; i<lines.size(); i++){
        lines[i].draw();
    }

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
