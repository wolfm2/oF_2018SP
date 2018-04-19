#include "ofApp.h"

vector<wave> waves;

wave::wave(){

}

void wave::setup(){

    loc += ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    sTime = ofRandom(0.1,2);
    sWeight = ofRandom(1, 1.5);
    
    a=ofRandom(0.2,0.3);
    b=ofRandom(0.3,0.4);
    c=ofRandom(0.4,0.5);
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    
    fbo.allocate(ofGetWindowWidth(),ofGetWindowHeight());
    fbo.begin();
    ofClear(255,255,255,0);
    fbo.end();
    
    ofSetBackgroundColor(0,0,0);

}

void wave::update(){
    float time = sTime*ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.5) * 200.0;  // rotate +- 400deg
    rY = ofSignedNoise(time * 0.6) * 200.0;
    rZ = ofSignedNoise(time * 0.7) * 200.0;
    dScale = (1 - ofNoise(time * 0.2)) * sWeight;

    moveX= ofSignedNoise(time*a)*ofRandom(1,20);
    moveY= ofSignedNoise(time*b)*ofRandom(1,20);
    moveZ= ofSignedNoise(time*c)*ofRandom(1,20);
    
    loc += ofPoint(moveX, moveY, moveZ);
    
}

void wave::draw() {

    fbo.begin();
//    cout<<"hello world!"<<endl;

    ofSetColor(255,255,255, 10);  // alpha fade it
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());

    
    ofPushMatrix();
    ofTranslate(loc.x, loc.y, loc.z);
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofPushStyle();
    ofSetColor(color);
    ofFill();
    
    ofDrawLine(-20,0,20,0);

    ofPopStyle();
    ofPopMatrix();
    fbo.end();
    ofSetColor(255);
    fbo.draw(0,0);
    
}



//--------------------------------------------------------------
void ofApp::setup(){

    
    for(int i=0; i<5; i++){
        wave newwave;
        newwave.setup();
        waves.push_back(newwave);
        
    }

    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    for(int i=0; i<waves.size(); i++){
        waves[i].update();
        cout << "my Point [" << i << "]: " << waves[i].loc <<endl;
        
        
        if(waves[i].loc.y<0||waves[i].loc.y>ofGetWindowHeight()||waves[i].loc.x<0||waves[i].loc.x>ofGetWindowWidth()){
            waves.erase(waves.begin()+i);
            wave newwave;
            newwave.setup();
            waves.push_back(newwave);
        }
    }

    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    for(int i=0; i<waves.size(); i++){
        waves[i].draw();
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
