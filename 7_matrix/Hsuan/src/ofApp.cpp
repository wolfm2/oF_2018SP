#include "ofApp.h"
ofImage apple;

int rX = 0;
int rY = 0;
int rZ = 0;

int tX = 0;
int tY = 0;

float height = 0.25;
float weight = 0.25;


//--------------------------------------------------------------
void ofApp::setup(){
    apple.load("apple.png");

}



//--------------------------------------------------------------
void ofApp::update(){
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    cout << height;
    cout << weight;

    
    
    
    ofBackground(0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(0.25, 0.25, 0.25);  // can be 3 dimensional
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    ofTranslate(tX, tY);
    
    
    ofScale(height, weight);

    ofPushMatrix();
    apple.draw(0 - apple.getWidth()/2, 0 - apple.getHeight()/2);
    // draw at new 0,0
    
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'x'){
        cout<<"x";
        rX--;
    }else if (key == 'X'){
        cout<<"X";
        rX++;
    }else if (key == 'y'){
        cout<<"y!!";
        rY--;
    }else if (key == 'Y'){
        cout<<"Y";
        rY++;
    }else if (key == 'z'){
        cout<<"z";
        rZ--;
    }else if (key == 'Z'){
        cout<<"Z";
        rZ++;
    }else if (key == 'q'){
        cout<<"q";
        tX++;
    }else if (key == 'a'){
        cout<<"a";
        tY--;
    }else if (key == 's'){
        cout<<"s";
        tX--;
    }else if (key == 'd'){
        cout<<"d";
        tY++;
    }else if (key == 'h'){
        cout<<"h";
        height = height - 0.1;
    }else if (key == 'H'){
        cout<<"H";
        height = height + 0.1;
    }else if (key == 'w'){
        cout<<"w";
        weight = weight - 0.1;
    }else if (key == 'W'){
        cout<<"W";
        weight = weight + 0.1;
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
