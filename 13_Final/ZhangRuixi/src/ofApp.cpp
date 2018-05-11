#include "ofApp.h"
 float *val;    //sound
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,82,165);
    


    soundPlayer.load("sounds/clock.mp3");
    
    
    clock01.load("images/1.gif");
    clock01.load("images/2.gif");
    clock01.load("images/3.gif");
    clock01.load("images/4.gif");
    

    
    
    //play the sound clock
    while (! soundPlayer.isLoaded());
    soundPlayer.setSpeed(ofRandom(0.8, 1.2));
    soundPlayer.play();
    nBandsToGet = 360;      // up to 512
    
   
    
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
//rotate the clock here
    rX++;
    if (ofGetFrameNum() % 3 == 0)
        rY++;
    if (ofGetFrameNum() % 7 == 0)
        rZ++;
    
    //update the sound playing system:
    ofSoundUpdate();
    
    
    
    val = ofSoundGetSpectrum(nBandsToGet);  //


//star play with sounds
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
    clock01.draw(50,50);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/4-50, ofGetHeight()/4);
    ofScale(0.3, 0.3, 0.3);  // can be 3 dimensional
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    clock01.draw(0 - clock01.getWidth()/2, 0 - clock01.getHeight()/2);  // draw at new 0,0
    ofPopMatrix();

  

    for (int i = 0;i < nBandsToGet; i++){
  //  (we use negative height here, because we want to flip them because the top corner is 0,0)
        
        
      
        ofDrawCircle(ofGetWidth()/4, ofGetHeight()-200, val[i]*800);
       
//        ofScale(val[i], val[i], val[i]);  // can be 3 dimensional
//        ofSetColor(153, 51, 255);
        clock03.draw(0 - clock03.getWidth()/2, 0 - clock03.getHeight()/2);  // draw at new 0,0
       

    }
    
    
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
