#include "ofApp.h"
ofImage Google;


//--------------------------------------------------------------
void ofApp::setup(){
    Google.load("Google.png");
   
}

float rX = 0;
float rY = 0;
float rZ = 0;
float sh = 5;
float sw = 5;
//--------------------------------------------------------------
void ofApp::update(){
   
}

int rotateX = 0;
int rotateY = 0;
int rotateZ = 0;
int X = 1024/2;
int Y = 768/2;
int height = 0;
int wideth = 0;

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofBackground(255);
    
    ofPushMatrix();
    ofTranslate(X,Y);
    ofScale(0.1, 0.1, 0.1);  // can be 3 dimensional
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    Google.draw(0 - Google.getWidth()/2, 0 - Google.getHeight()/2);  // draw at new 0,0
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


    if (key== 'a'){
        cout << "a";
        X-=50;
    }
    if (key== 'q'){
        cout << "q";
        Y+=50;
    }
    if (key== 's'){
        cout << "s";
        Y-=50;
    }
    if (key== 'd'){
        cout << "d";
        X+=50;
    }
    if (key== 'x'){
        
        rX--;
        cout << "x";
    }
    if (key== 'X'){
        rX++;
        cout << "X";
    }
    if (key== 'y'){
        rY--;
        cout << "y";
    }
    if (key== 'Y'){
        rY++;
        cout << "Y";
    }
    if (key== 'z'){
        rZ--;
        cout << "z";
    }
    if (key== 'Z'){
        rZ++;
        cout << "Z";    }
    
    if (key == 'h'){
        sh ++;
    }
    
    if (key == 'H'){
        sh --;
    }
    
    if (key == 'w'){
        sw ++;
    }
    
    if (key == 'W'){
        sw --;
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
