#include "ofApp.h"
 float *val;    //sound
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,82,165);
    


   
    
//Perlin Wave set up
    for(int i=0; i<3; i++){
        star starWithSound(ofGetMouseX(),ofGetMouseY());
        starWithSound.setup();
        stars.push_back(starWithSound);
    }
    ofSetFrameRate(30);
}


//--------------------------------------------------------------
void ofApp::update(){

    
 
    



    for(int i=0; i<stars.size(); i++){
        stars[i].update();
        
        
        if(stars[i].vec.y<0 || stars[i].vec.y>ofGetWindowHeight()||stars[i].vec.x<0||stars[i].vec.x>ofGetWindowWidth()){
            stars.erase(stars.begin()+i);
            star newwave(mouseX, mouseY);
            newwave.setup();
            stars.push_back(newwave);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
   
  

    
 //perlin wave
    for(int i=0; i<stars.size(); i++){
        stars[i].draw();
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
