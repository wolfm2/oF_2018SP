#include "ofApp.h"

ofImage dog;
ofTrueTypeFont myfont;
string enterString;

// These are global variables:

float rotateX = 0;
float rotateY = 0;
float rotateZ = 0;

float transX = 0;
float transY = 0;


float scaleW = 0.2;
float scaleH = 0.2;


//--------------------------------------------------------------
void ofApp::setup(){
    
    dog.load("dog.jpg");
    myfont.load("vag.ttf", 30);
    ofSetWindowShape (1000, 1000); //Changing the size of the canvas
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    

}
//--------------------------------------------------------------




void ofApp::draw(){
    
    
    ofBackground(255); //Make background white
    
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);  //divided by two so it's in the middle
    ofScale(0.9, 0.9, 0.9);  // can be 3 dimensional
    ofTranslate(transX, transY);
    ofScale(scaleW, scaleH);
    ofRotate(rotateX);
    ofRotate(rotateY);
    ofRotate(rotateZ);
    
    ofSetColor(255);
    dog.draw(0 - dog.getWidth()/ 2, 0-dog.getHeight()/2);  // draw at new 0,0
    
    ofPopMatrix();
    ofFill();
    ofSetColor(252, 189, 225);
    myfont.load("vag.ttf", 30); //This is the bigger font in the left
    myfont.drawString(enterString, ofGetWidth() / 2-300, ofGetHeight() -300);
    myfont.load("vag.ttf",20); //This is the font with the directions in the middle
    myfont.drawString("Change width & height : W / w |  H / h", 50, 50);
    myfont.drawString("Rotate X-axis: X / x", 50, 90);
    myfont.drawString("Rotate Y-axis: Y / y", 50, 130);
    myfont.drawString("Rotate Z-azis: Z / z", 50, 170);
    myfont.drawString(" To move image:\n Left: a  Right: s\n Up: e  Down: c", 650, 50);
    

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    enterString = "You pressed: " ;
    switch(key) {
            
    }
    
    


    if(key == 'b') {                    //This is to check if the key pressed works
        cout << "received b";
    } else if(key == 'B') {
        cout << "received B";
    }
    
    //ROTATE:
    
    if(key == 'x') {
        enterString += "x";
        rotateX--;
        
    } else if(key == 'X') {
        enterString += "X";
        rotateX++;
        
    }
    
    
    if(key == 'y') {
        enterString += "y";
        rotateY--;
    } else if(key == 'Y') {
        enterString += "Y";
        rotateY++;
    }
    
    if(key == 'z') {
        enterString += "z";
        rotateZ--;
        
    } else if(key == 'Z') {
        enterString += "Z";
        rotateZ++;
    }
    
    //TRANSLATE / MOVE:
    
    if(key == 'a') {
        enterString += "a";
        transX -=5;
        
    } else if(key == 's') {
        enterString += "s";
        transX +=5;
    }
    
    if(key == 'e') {
        enterString += "e";
        transY -=5;
    } else if(key == 'c') {
        enterString += "c";
        transY +=5;
        
    }
    
    // HEIGHT
    
    switch(key) {
        
    case 'h':
        enterString += "h";
            
        if (scaleH >= 0.1) {
            scaleH -= 0.005;
        }
        else
            scaleH = 0.1;
        break;
            
    case 'H':
        enterString += "H";
            
            if(scaleW <= 1) {
               scaleW += 0.005;
            }
            
            else
                scaleW = 1;
            break;
            
    //WIDTH
            
        case 'w':
            enterString += "w";
            
            if (scaleW >=0.1) {
                scaleW -= 0.005;
            }
            else
                scaleW = 0.1;
            break;
            
        case 'W':
            enterString += "W";
            
            if (scaleW <= 1) {
                scaleW += 0.005;
            }
            
            else
                scaleW = 1;
            break;
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
