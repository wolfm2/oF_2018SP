 #include "ofApp.h"
ofImage baby;
string enterString;

float rX = 0;
float rY = 0;
float rZ = 0;


float Tx = 0;
float Ty = 0;


float Sx = 1;
float Sy = 1;

//--------------------------------------------------------------
void ofApp::setup(){
  baby.load("baby.jpg");
}


//--------------------------------------------------------------
void ofApp::update(){
    rX;
    rY;
    rZ;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
ofBackground(255);
  
ofPushMatrix();
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  ofScale(Sx, Sy);  // can be 3 dimensional
  ofRotateX(rX);
  ofRotateY(rY);
  ofRotateZ(rZ);
  baby.draw(0 - baby.getWidth()/2, 0 - baby.getHeight()/2);  // draw at new 0,0
ofPopMatrix();
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("are you eating healthy? if yes press Y, if no press N", 300, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == 'Y'){
        
        rX++;
        if (ofGetFrameNum() % 7 == 0)
            rY++;
        if (ofGetFrameNum() % 3 == 0)
            rZ++;
        Tx++;
        
        cout << "yes?" ;
    }
    
    if (key == 'N'){
        cout << "NO?!!!" ;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
