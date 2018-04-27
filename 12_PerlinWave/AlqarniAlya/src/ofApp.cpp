#include "ofApp.h"

//thanks Levone for helping me : )

ofFbo fbo;
//vector
vector<line> myline;

line::line(){
}

void line::setup(){
    
    position = ofPoint(0,300,100);
    size = ofRandom(0.5,2);
    n = ofRandom(0.1,2);
    
    a= ofRandom(0.2,0.3);
    b = ofRandom(0.3,0.4);
    c =ofRandom(0.4,0.5);
    
    color.set(ofRandom(255),ofRandom(100),ofRandom(100));
    
    
}


void line::update(){
    time = ofGetElapsedTimef()*n;
    
    
    rX = ofSignedNoise(time*0.3)*100;
    rY = ofSignedNoise(time*0.3)*100;
    rZ = ofSignedNoise(time*0.13)*100;
    
    scale=(1-ofNoise(time*0.4))*size;
    
    
    X = ofSignedNoise(time*a)*ofRandom(10,20);
    Y = ofSignedNoise(time*b)*ofRandom(10,20);
    Z = ofSignedNoise(time*c)*ofRandom(10,20);
    
    position+= ofPoint(X, Y, Z);
    
    
    
}


void line :: draw(){
    ofPushMatrix();
    ofTranslate(position.x, position.y, position.z);
    ofScale(scale,scale, scale);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    ofSetColor(color);
    ofDrawLine(-40,0,40,0);
    ofPopMatrix();
    
}



//--------------------------------------------------------------
void ofApp::setup(){

    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    fbo.begin();
    ofClear(255,255,255,3);
    
    fbo.end();
    
    myFont.loadFont("Neue-Black.otf",30);
    
    
    for(int i = 0; i<=5 ;i++){
        line newline;
        newline.setup();


        myline.push_back(newline);
        
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    
    
    for(int i=0; i< myline.size();i++){
        myline[i].update();
        cout << "test test"<<endl;
        
                if(myline[i].position.y < 0 || myline[i].position.y > ofGetWindowWidth() || myline[i].position.x<0 ||myline[i].position.x >ofGetWindowWidth()){
            myline.erase(myline.begin()+i);
            line newline;
            newline.setup();
            myline.push_back(newline);
            
        }
        
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    
    fbo.begin();
    ofSetColor(255,255,255,3);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    for(int i = 0; i<myline.size(); i++){
        
        myline[i].draw();
        
    }
    

    fbo.end();
    ofSetColor(255);
    fbo.draw(0,0);
    
    ofSetColor(255, 255, 255 );
    myFont.drawString("let the fun begin!", 350, 400);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == 'e'){
        myline.clear();
    }
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
