#include "ofApp.h"
ofFbo fbo;

    vector<line> projectline;

line::line(){
}
void line::setup(){
    
    color.set(ofRandom(70),ofRandom(80),ofRandom(90));
    location = ofPoint(100,3,50);
    weight = ofRandom(0,1);
    n = ofRandom(0.1,2);
    
    RX = ofRandom(10);
    RY = ofRandom(20);
    RZ = ofRandom(30);
    a1 = ofRandom(0.5,0.6);
    a2 = ofRandom(0.1,0.2);
    a3 = ofRandom(0.3,0.4);
    
}

void line::update(){
    time = ofGetElapsedTimef()*n;
    
    scale = ofNoise(time*0.2)*weight;
    RX = ofSignedNoise(time*0.1)*100;
    RY = ofSignedNoise(time*0.1)*100;
    RZ = ofSignedNoise(time*0.1)*100;
    
    moveX= ofSignedNoise(time*a1)*ofRandom(5,10);
    moveY= ofSignedNoise(time*a2)*ofRandom(6,10);
    moveZ= ofSignedNoise(time*a3)*ofRandom(7,10);
    
    location+= ofPoint(moveX, moveY,moveZ);
}

void line::draw(){
    
ofPushMatrix();
    
    ofRotateX(RX);
    ofRotateY(RY);
    ofRotateZ(RZ);
    
    ofTranslate(location.x, location.y, location.z);
    ofScale(scale,scale,scale);
    
    ofSetColor(color);
    ofDrawLine(50,0,-100,0);
    
ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::setup(){
   
    fbo.allocate(ofGetWindowWidth(),ofGetWindowHeight());
    
 fbo.begin();
    
    ofClear(0);
    
fbo.end();
    
    for(int i=0; i<5; i++){
        line lineN;
        lineN.setup();
        projectline.push_back(lineN);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0; i<projectline.size(); i++){
        projectline[i].update();
        cout << "my Point [" << i << "]: " << projectline[i].location <<endl;
        
        
        if(projectline[i].location.y<0||projectline[i].location.y>ofGetWindowHeight()||projectline[i].location.x<0||projectline[i].location.x>ofGetWindowWidth()){
            projectline.erase(projectline.begin()+i);
            line lineN;
            lineN.setup();
            projectline.push_back(lineN);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    fbo.begin();
    ofSetColor(255,255,255,0);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    for(int i=0; i<projectline.size(); i++){
        projectline[i].draw();
   
    }
    fbo.end();
    ofSetColor(255);
    fbo.draw(0,0);
   
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
