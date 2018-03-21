#include "ofApp.h"
ofImage leaf;

//--------------------------------------------------------------
void ofApp::setup(){
    leaf.load("leaf.png");
        cout << ofGetHeight();
}

float rX = 0;
float rY = 0;
float rZ = 0;

float height=0.25;
float width=0.25;

float x=512;
float y=384;

//--------------------------------------------------------------
void ofApp::update(){
//    rX++;
//    if (ofGetFrameNum() % 3 == 0)
//        rY++;
//    if (ofGetFrameNum() % 7 == 0)
//        rZ++;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    

    ofPushMatrix();
   // ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
   ofTranslate(x,y);
    //ofScale(0.3, 0.3, 0.3);  // can be 3 dimensional
    // SCALE HAS TO BE 0 AND 1;
    ofScale(width, height,0.3 );
    cout<< width;
    
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    
    leaf.draw(0,0);
   // leaf.draw(0 - leaf.getWidth()/2, 0 - leaf.getHeight()/2);  // draw at new 0,0
    
    //leaf.draw(leaf.getWidth()/2 +  x, leaf.getHeight()/2+y);
    
    ofPopMatrix();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'x'){
        rX--;
        cout<<"low";
    }

    if(key == 'X'){
        rX++;
        cout<<"low";
    }
    if(key == 'y'){
        rY--;
        cout<<"low";
    }

    if(key == 'Y'){
        rY++;
        cout<<"low";
    }
    if(key == 'z'){
        rZ--;
        cout<<"low";
    }

    if(key == 'Z'){
        rZ++;
        cout<<"low";
    }

    if(key == 'q'){
        y++;
    }
    if(key == 'a'){
        x--;
    }
    if(key == 's'){
        y--;
    }
    if(key == 'd'){
        x++;
    }


    if(key == 'h'){
        //height-=0.1;
        height *= -1;
    }
    if(key == 'H'){
        //height+=0.1;
        height *= -1;
    }
    if(key == 'w'){
        width-=0.1;

    }
    if(key == 'W'){
        width +=0.1;
    }









}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    
    if(key == 'x'){
        ofRotateX(1);
        cout<< "low";
    }
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
