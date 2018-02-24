#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    mySound.load("piano.mp3");
    
    a.load("frame1.jpg");
    b.load("2.jpg");
    c.load("3.jpg");
    d.load("4.jpg");
    e.load("5.jpg");
    f.load("6.jpg");
//    g.load("7.jpg");
//    h.load("8.jpg");
//    i.load("9.jpg");
//    j.load("10.jpg");
//    k.load("11.jpg");
//    l.load("12.jpg");
//    m.load("13.jpg");
//    n.load("14.jpg");
//    o.load("15.jpg");
//    p.load("16.jpg");

    
}

float rX = 0;
float rY = 0;
float rZ = 0;
//--------------------------------------------------------------
void ofApp::update(){
    mySound.play();
    
    rX++;
    if (ofGetFrameNum() % 3 == 0)
        rY++;
    if (ofGetFrameNum() % 7 == 0)
        rZ++;
    
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0,0,0);
    ofSetColor(255, 0, 0);
    ofDrawLine(280, 475, 360, 475);
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(" its all in the little moments.", 90, 470);
    ofSetColor(250, 250, 250);
    ofDrawBitmapString(" - between the a+z you can find that moment -", 90, 490);
 
    
    if(imageflag == 0){
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofScale(0.09, 0.09, 0.09);
        ofRotateX(rX);
        ofRotateY(rY);
        ofRotateZ(rZ);
      a.draw(380,50,200,170);
        a.draw(0 - a.getWidth()/2, 0 - a.getHeight()/2);
        ofPopMatrix();
        
    }else if(imageflag == 1){
        b.draw(0,50,700,500);
        
    }else if(imageflag == 2){
        
        
        c.draw(0,50,700,500);
        
        
    }else if(imageflag == 3){
        d.draw(0,50,700,500);
        
        
    }else if(imageflag == 4){
        
        
        e.draw(0,50,700,500);
        
        
    }else if(imageflag == 5){
        
        
        f.draw(0,50,700,500);
    }
        
//    }else if(imageflag == 6){
//
//
//        g.draw(0,50,700,500);
//
//    }else if(imageflag == 7){
//        h.draw(0,50,700,500);
//
//
//    }else if(imageflag == 8){
//
//        i.draw(0,50,700,500);
//
//    }else if(imageflag == 9){
//
//
//        j.draw(0,50,700,500);
//
//
//    }else if(imageflag == 10){
//
//
//        k.draw(0,50,700,500);
//
//
//    }else if(imageflag == 11){
//        l.draw(0,50,700,500);
//
//
//    }else if(imageflag == 12){
//
//
//        m.draw(0,50,700,500);
//
//
//    }else if(imageflag == 13){
//
//
//        n.draw(0,50,700,500);
//
//
//    }else if(imageflag == 14){
//
//        o.draw(0,50,700,500);
//

    
    

  
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

//    if(key == OF_KEY_PAGE_UP){
//        imageflag++;
//
//    }else{ if(key == OF_KEY_PAGE_DOWN ){
//    imageflag--;
//}
//    }
   
   
    
//    if(key == 'q'){
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); ;
//
//        }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'a'){
        imageflag++;
        
      
        
    }else{ if(key == 'z' ){
        imageflag--;
    }
        
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
