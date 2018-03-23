#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
   
    
    ofBackground(255);
    feather.load("images/feather.jpg");
    font.load("font/font.otf",30);
    
}
//--------------------------------------------------------------
void ofApp::update(){
    
    
    //here is change for leaf
//  rX++;   //each frame changing
//  if (ofGetFrameNum() % 3 == 0)  // 3 frames
//    rY++;
//  if (ofGetFrameNum() % 7 == 0)  //7 frames
//    rZ++;
//
    
    
    
    
//    feather rotation
//
//    featherX ++;
//
//    if (ofGetFrameNum() % 5 == 0)
//        featherY ++;
//
//    if (ofGetFrameNum() % 50 ==0)
//        featherZ ++;
//
//
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    //here is rotate the leaf
//ofPushMatrix();
//  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
//  ofScale(0.3, 0.3, 0.3);  // can be 3 dimensional
//  ofRotateX(rX);
//  ofRotateY(rY);
//  ofRotateZ(rZ);
//  leaf.draw(0 - leaf.getWidth()/2, 0 - leaf.getHeight()/2);  // draw at new 0,0

    
    ofSetColor(0);
    ofFill();
    font.drawString(" please let me fly ", 100, 150);
//    ofSetColor(255, 255, 0);
//    ofFill();
//    font.drawString(" play with me ", 200, 200);
//
    
    //rotate feather.
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(0.25 + featherScaleW ,0.25 + featherScaleH ,0.25);
    
    
    ofRotate(featherX);        //rotate x,y,z
    ofRotate(featherY);
    ofRotate(featherZ);
    
    
    ofSetColor(255);
    ofFill();
    feather.draw(0 - feather.getWidth()/2 + featherTranslateX , 0 - feather.getHeight()/2 + featherTranslateY);
    
    ofPopMatrix();
    
//    char fpsStr[255]; // an array of chars
//    sprintf(fpsStr, "frame rate: %f", ofGetFrameRate());

//    font.drawString(fpsStr, 100,100);

 
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if ( key == 'x'){

        featherX --;
    }
    
    if( key == 'X'){

        featherX ++;
    }
    
    if( key == 'y'){

        featherY --;
    }
    
    if( key == 'Y'){

        featherY ++;
    }
    
    
    if( key == 'z'){

        featherZ --;
    }
    
    if( key == 'Z'){

        featherZ ++;
    }
    
    
    
    if( key == 'w'){

        featherScaleW -= 0.1;
    }
    
    if( key == 'W'){

        featherScaleW += 0.1;
    }
    
    if( key == 'h'){

        featherScaleH -= 0.1;
    }
    
    if( key == 'H'){

        featherScaleH += 0.1;
    }
    
    if( key == 'a'){
        featherTranslateX -= 5;
    }
    
    if( key == 'd'){
        featherTranslateX += 5;
    }
    
    if( key == 'q'){
        featherTranslateY -= 5;
    }
    
    if( key == 's'){
        featherTranslateY += 5;
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
