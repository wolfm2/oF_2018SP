#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetWindowShape(1500, 900);

//    ofBackground(255,233,0);  //yellow
//    ofBackground(102, 0, 204);
    
    bottle01.load("images/01.png");                //images
    bottle02.load("images/02.png");
    bottles.load("images/bottles.png");
    table.load("images/table.png");
    
    myfont.load("fonts/TheLightFont.ttf", 20);     //font
   
    fireSound.load("Sounds/fire.mp3");             //load sounds
    water.load("Sounds/water.mp3");
    beaker.load("Sounds/beaker.mp3");
    glass.load("Sounds/glass.mp3");

    
    
    
    myBall.setup();   //class
    
    

    

}

//--------------------------------------------------------------
void ofApp::update(){
    myBall.update();  //class
    
    
   
}

//--------------------------------------------------------------
void ofApp::draw(){

//    //   draw picture without other color effect
//    ofSetColor(255, 255, 255);
//    ofNoFill();
//    bottles.draw(ofGetWidth()/5, ofGetHeight()/5 *3, 1000, 300);
    
//    background color
    ofColor colorOne(77, 77, 255);
    ofColor colorTwo(102, 0, 204);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);

    //   draw picture without other color effect
//    ofSetColor(255, 255, 255);
  
    ofFill();
    myBall.draw();
    

    //number
    myfont.drawString("1", ofGetWidth()/5+150, ofGetHeight()/3*2 - 20);
    myfont.drawString("2", ofGetWidth()/5+380, ofGetHeight()/3*2 - 20);
    myfont.drawString("3", ofGetWidth()/5+620, ofGetHeight()/3*2 - 20);
    myfont.drawString("4", ofGetWidth()/5+820, ofGetHeight()/3*2 - 20);
    
    
//    ofSetColor(255, 255, 255);
//    ofNoFill();
    bottles.draw(ofGetWidth()/5+100, ofGetHeight()/3, 800, 220);
    
    ofSetColor(255, 255, 255);
    ofNoFill();
    table.draw(ofGetWidth()/9, ofGetHeight()/3 +100, 1230, 460);
    
    
    
    

//    bottle01.draw(ofGetWidth()/5, ofGetHeight()/5 * 3, ofGetWidth()/5-100,ofGetWidth()/5 -100);
//    bottles.draw(500,500,500,500);
    

    myfont.drawString("Hello,Chemistry!!", 100,  100);
    
    
    
    
    
   
    
    
   


}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1'){
        beaker.play();
        
    }
    ;
    if(key == '2'){
        water.play();
    }
    
    if(key == '3'){
        fireSound.play();
    }
    
    if(key == '4'){
        glass.play();
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

//--------------------------------------------------------------

