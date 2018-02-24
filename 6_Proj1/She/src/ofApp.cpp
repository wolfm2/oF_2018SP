#include "ofApp.h"
#include "ofMain.h"



//This is the story uses mouse to move ellipse, uses key"k" to fight with black triangle, and use key"a" and "d" to move the black triangle. After ten times fight, the ellipse will save the pink circle.
// have background music and fight sound


int myCircleX;
int myCircleY;
int myRectX;
int myRectY;
int myRecthighX;
int myRecthighY;
float Ellipse_catchupspeed = 0.08f;


ofPoint Ellipse_pos;
int counter;

ofFbo fbo;

//--------------------------------------------------------------
void ofApp::setup(){
    
    soundPlayer.load("fight.mp3");
    soundPlayer.play();
    //play background music
    
    
    myCircleX = 120;
    myCircleY = 260; //draw a cirlce as princess
    
    myRectX = 300;
    myRectY = 500;   //draw a rectangle as monster
    
    myRecthighX = 100;
    myRecthighY = 200;
    
    
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(0, 51, 204);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
   
    ofBackground(255);
    if(myCircleX < 180){
        myCircleX += 2;
    }else{
        myCircleX = 120;
    }
    // circle princess anxious in the castle
    
    
   if(myRectY > 400){
        myRectY -= 2;
   }else{myRectY = 500;
       
   }
    
    
    
    Ellipse_pos.x += Ellipse_catchupspeed * (mouseX - Ellipse_pos.x );
    Ellipse_pos.y += Ellipse_catchupspeed * (mouseY - Ellipse_pos.y );
    
    
  

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0);
    ofDrawRectangle(40, 500, 200, 200);
    ofDrawRectangle(40, 300, 200, 200);
    ofDrawTriangle(140, 100, 40, 300, 240, 300);
    ofSetColor(255);
    ofDrawTriangle(140, 120, 60 ,280, 220, 280);
    //build a castle
    
    if(counter >= 10){
        myCircleX = 700;
        myCircleY = 600;
        Ellipse_pos.x = 750;
        Ellipse_pos.y = 600;
        myRectX = 300;
        myRectY = 650;
        myRecthighX = 100;
        myRecthighY = 50;
    }// after ten times fight with monster, the monster died and the princess and prince get together
    
    
    ofSetColor(255, 51, 187);
    ofCircle(myCircleX, myCircleY, 20);
    
    
    
    ofSetColor(0);
    ofDrawRectangle(myRectX, myRectY, myRecthighX, myRecthighY);
   
    
    fbo.allocate(200, 200, GL_RGBA);
    fbo.begin();
    ofClear(255,255,255,0);
    fbo.end();
    float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
    ofSetColor(0, 51, 204, alpha);
    ofDrawEllipse(Ellipse_pos.x, Ellipse_pos.y, 50, 80);//create a ellipse as the prince
    fbo.end();
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'k'){
        soundPlayer.load("fight02.mp3");
        soundPlayer.play();
        counter++;
        
    }else if(key == 't'){
        soundPlayer.load("fight.mp3");
        soundPlayer.play();
    }
    if(key == 'a'){
        myRectX -= 4;
    }
    if(key == 'd'){
        myRectX += 4;
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
