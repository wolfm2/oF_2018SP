#include "ofApp.h"
    ofImage leaf;
//--------------------------------------------------------------
void ofApp::setup(){
        leaf.load("leaf.png");
}
float rX = 0;
float rY = 0;
float rZ = 0;
int x = 512;
int y = 377;
float sh = 0.3; //scale height;
float sw = 0.3; //scale width


//--------------------------------------------------------------
void ofApp::update(){
    //rX++;
    //if (ofGetFrameNum() % 3 == 0)//每3次
        //rY++;
    //if (ofGetFrameNum() % 7 == 0)
        //rZ++;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    ofPushMatrix();
    //cout << ofGetWidth()/2; //看图像的位置
    //cout << ofGetHeight()/2;
    ofTranslate(x, y);
    //ofScale(0.3, 0.3, 0.3);  // can be 3 dimensional
    ofScale(sh, sw);

    ofRotate(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    leaf.draw(0 - leaf.getWidth()/2, 0 - leaf.getHeight()/2);  // draw at new 0,0
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'x'){
        cout << "low";
        rX ++;
    }
        
    if (key == 'X'){
        cout << "high";
        rX --;
        }
    
    if (key == 'y'){
        rY ++;
    }
    
    if (key == 'Y'){
        rY --;
    }
    
    if (key == 'z'){
        rZ ++;
    }
    
    if (key == 'Z'){
        rZ --;
    }
    
    if (key == 'q','a','s','d'){
        x ++, y ++;
    }
    
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
