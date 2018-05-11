#include "ofApp.h"


int mouseX;
int mouseY;
ofFbo fbo;
ofPoint eyes_pos;
float eyes_catchUpSpeed = 0.15f;
float eyes_maxSpeed = 1.0f;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    chinatown.load("chinatown.jpg");
    eyes.load("eyes.png");
    shoes.load("shoes.png");



    city.load("chinatown.mp3");
    city.setLoop(true);
    city.play();
    city.setVolume(0.1f);
    
    
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    mesh.enableIndices();
    
    float connectionDistance = 100;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
    
    float intensityThreshold = 20;
    int w = chinatown.getWidth();
    int h = chinatown.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = chinatown.getColor(x, y);
            float intensity = c.getLightness();
            
            
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
                ofVec3f pos(x*4, y*4, z);
                
                mesh.addVertex(pos);
                mesh.addColor(c);
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    eyes_pos.x += eyes_catchUpSpeed * (mouseX - eyes_pos.x);
    eyes_pos.y += eyes_catchUpSpeed * (mouseY - eyes_pos.y);
}
//--------------------------------------------------------------
void ofApp::draw(){

    mesh.draw();
    
    chinatown.load("chinatown.jpg");
    
    ofColor centerColor = ofColor(255,255, 255);
    ofColor edgeColor(255, 255, 255);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

    
    easyCam.begin();
    ofPushMatrix();
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
        mesh.draw();
    ofPopMatrix();
    easyCam.end();
    cout << mesh.getNumVertices() << endl;
 
    shoes.draw(ofGetMouseX(),ofGetMouseY());
    
    
    fbo.begin();
    ofSetColor(30,30,30, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255,0,0);
    ofNoFill();
    eyes.draw(eyes_pos.x,eyes_pos.y);
    fbo.end();
    ofSetColor(255,255,255);
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
    mouseX = x;
    mouseY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    city.setVolume(0.5f);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    city.setVolume(1.0f);

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
