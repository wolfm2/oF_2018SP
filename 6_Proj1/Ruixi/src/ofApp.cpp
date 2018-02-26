#include "ofApp.h"

//float handPosX;
ofFbo fbo;
ofColor black(0,0,0);
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1920, 1080);
    

    
    image1.load("images/bg.jpg");
    boat.load("images/boat.png");
    myfont.load("front/theFirst.ttf", 32);
    
//    ofBackground(0);
//    image1.draw(0,0,ofGetWidth(),ofGetHeight());
//    boat.draw(ofGetMouseX()-100, ofGetHeight() - 80 ,200,100);
//
    
    
    posX = ofGetWidth()/2;
    posY = ofGetHeight()/2;
    
    speedX = ofRandom(-5.0, 5.0);
    speedY = ofRandom(-5.0, 5.0);
    
    posX2 = ofGetWidth()/2;
    posY2 = ofGetHeight()/2;
    
    speedX2 = ofRandom(-5.0, 5.0);
    speedY2 = ofRandom(-5.0, 5.0);
    
    
//    boatY1 = ofGetMouseY()+5;
//    boatY2 = ofGetMouseY()-5;
    
    
    
    posX3 = ofGetWidth()/2;
    posY3 = ofGetHeight()/2;
    
    
    speedX3 = ofRandom(-5.0, 5.0);
    speedY3 = ofRandom(-5.0, 5.0);
    
    curScore = 10;
    
    myfont.load("front/theFirst.ttf", 32);
    
    
    //here is fbo of the boad effect
    fbo.allocate(ofGetWidth(), ofGetHeight(),GL_RGBA32F);
    
    fbo.begin();
      ofClear(255,255,255,0);
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    posX += speedX;
    posY += speedY;
    
 

    
    if (posX <= 40 || posX >= ofGetWidth() - 40){
        speedX *= - 1;
    }
    
    if (posY <= 40 ){
        speedY *= - 1;
    }

    
    
    if (posY >= ofGetHeight() - 90 && posX <= ofGetMouseX() + 100 && posX >= ofGetMouseX() - 100){
        speedY *= - 1;
//        curScore = curScore + 10;
      
    }
  
    
    
    //  ball 2
    
    if (curScore >= 20){
    posX2 += speedX2;
    posY2 += speedY2;
    }
    
   
    
    if (posX2 <= 40 || posX2 >= ofGetWidth() - 40){
        speedX2 *= - 1;
    }
    
    if (posY2 <= 40 ){
        speedY2 *= - 1;
    }
    
    if (posY2 >= ofGetHeight() - 90 && posX2 <= ofGetMouseX() + 100 && posX2 >= ofGetMouseX() - 100){
        speedY2 *= - 1;
//        curScore = curScore + 10;
//
    }
    
    
    //  ball 3
    
    if (curScore >= 30){
    posX3 += speedX3;
    posY3 += speedY3;
    }
    
    
    if (posX3 <= 40 || posX3 >= ofGetWidth() - 40){
        speedX3 *= - 1;
    }
    
    if (posY3 <= 40 ){
        speedY3 *= - 1;
    }
    
    if (posY3 >= ofGetHeight() - 90 && posX3 <= ofGetMouseX() + 100 && posX3 >= ofGetMouseX() - 100){
        speedY3 *= - 1;
//        curScore = curScore + 10;
        
    }
    
    
  
}

//--------------------------------------------------------------
void ofApp::draw(){

  
    image1.draw(0,0,ofGetWidth(),ofGetHeight());
    boat.draw(ofGetMouseX()-100, ofGetHeight() - 80 ,200,100);

    
    
    
//    ofColor colorOne(250, 235, 215);
//    ofColor colorTwo(255,182,193);
//    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
//
    
    ofDrawBitmapString(curScore, 5, 15);

   
    ofSetCircleResolution(100);
    ofSetColor(255,250,205);
    ofFill();
//    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 30);
    ofDrawCircle(posX, posY, 40);
    
    



//    ofSetColor(255,228,225);
//    ofDrawRectangle(200, ofGetHeight() - 10, 200, 10);
    
//
//    if ofMousePressed() {
//        ofDrawCircle(x+1, y+1, 20);
//    }
    
    if (posY >= ofGetHeight() - 90 && posX <= ofGetMouseX() + 100 && posX >= ofGetMouseX() - 100){
       
        curScore = curScore + 10;
        
    }
    
    
    if (posY > ofGetHeight() + 40 || posY2 > ofGetHeight() + 40 || posY3 > ofGetHeight() + 40){

//        ofFill();
        ofClear(255);
        ofSetColor(0);
//      ofDrawBitmapString("GAME OVER!!!", ofGetWidth()/2, ofGetHeight()/2);
        myfont.drawString("GAME OVER", ofGetWidth()/2-10, ofGetHeight()/2);
}
    
    
    //BALL2
    
    if (curScore >= 20){
       
        ofDrawCircle(posX2, posY2 , 40);
    }
    
    
    
    if (posY2 >= ofGetHeight() - 90 && posX2 <= ofGetMouseX() + 100 && posX2 >= ofGetMouseX() - 100){
     
        curScore = curScore + 10;
        
    }
    
    
    
    //BALL3
    if (curScore >= 30){
        
       
        ofDrawRectangle(posX3, posY3, 40, 40);
    }
   
    
    
    if (posY3 >= ofGetHeight() - 90 && posX3 <= ofGetMouseX() + 100 && posX3 >= ofGetMouseX() - 100){
      
        curScore = curScore + 10;
        
    }
    
    
    
    
    //  here is add fbo effect on the boat
    
    fbo.begin();
    ofSetColor(255, 255, 255,0);
        image1.load("images/bg.jpg");
    
    //    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    boat.load("images/boat.png");
    
    ofDrawCircle(mouseX, mouseY, 50);
    ofFill();
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(0,0);

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//    if (x-1){
//        ofDrawCircle(20, 20, 50);
//    }

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
