#include "ofApp.h"

float z=30;
float width =20.;
float height = 100.;
ofPoint cirPos(0,350);
float radius = 50;
float speed = 10.;
ofPoint recPos(400,350);
ofPoint recPos1(440,350);
ofPoint recPos2(480,350);
ofPoint recPos3(520,350);
ofPoint recPos4(560,350);
ofPoint recPos5(600,350);
ofPoint recPos6(640,350);
ofPoint recPos7(680,350);
ofPoint recPos8(720,350);
ofPoint recPos9(760,350);
ofPoint recPos10(800,350);
ofPoint recPos11(840,350);
ofPoint recPos12(880,350);
ofPoint recPos13(920,350);
ofPoint recPos14(960,350);
ofPoint recPos15(1000,350);
ofPoint recPos16(1040,350);

bool trangleRotate = false;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(200, 200, 200);

}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//
//    ofSetColor(200, 0, 0);
//    ofDrawCircle(cirPos.x, cirPos.y, radius);
//    ofSetColor(0, 0, 0);
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    ofDrawRectangle(recPos.x, recPos.y, width, height);
//
//
        //when clash
        if((cirPos.x + radius) >= (recPos.x - width/2)){
            //tip the rec
            ofSetColor(200, 0, 0);
            ofDrawCircle(cirPos.x, cirPos.y, radius);
            ofSetColor(0, 0, 0);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofPushMatrix();
            ofTranslate(recPos.x, recPos.y);
            ofRotate(45);
            ofDrawRectangle(0, 0, width, height);
            ofPopMatrix();
                   if ((cirPos.x + radius) >= (recPos1.x - width/2)){
                ofPushMatrix();
                ofTranslate(recPos1.x, recPos1.y);
                ofRotate(45);
                ofDrawRectangle(0, 0, width, height);
                ofPopMatrix();

            }
        }
        else{//no contact
            
            ofSetColor(200, 0, 0);
            ofDrawCircle(cirPos.x, cirPos.y, radius);
            ofSetColor(0, 0, 0);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofDrawRectangle(recPos.x, recPos.y, width, height);
            ofDrawRectangle(recPos1.x, recPos1.y, width, height);
            
        }
    
    
    if ((cirPos.x + radius) >= (recPos1.x - width/2)){
                        ofPushMatrix();
                        ofTranslate(recPos1.x, recPos1.y);
                        ofRotate(45);
                        ofDrawRectangle(0, 0, width, height);
                        ofPopMatrix();
        
        
    }
  
    else{//no contact

          ofSetColor(200, 0, 0);
          ofDrawCircle(cirPos.x, cirPos.y, radius);
          ofSetColor(0, 0, 0);
          ofSetRectMode(OF_RECTMODE_CENTER);
          ofDrawRectangle(recPos1.x, recPos1.y, width, height);

     }

    
//        ofTranslate(400,300);
//        ofRotateZ(ofGetElapsedTimef()*10);
//        ofRotateZ(z);
////        ofRect(400,350,20,100);
////        ofPopMatrix();
//
    if((cirPos.x + radius) >= (recPos2.x - width/2)){
                 ofPushMatrix();
                 ofTranslate(recPos2.x, recPos2.y);
                 ofRotate(45);
                 ofDrawRectangle(0, 0, width, height);
                 ofPopMatrix();
        

   }
    else{//no contact

       ofSetColor(200, 0, 0);
       ofDrawCircle(cirPos.x, cirPos.y, radius);
       ofSetColor(0, 0, 0);
       ofSetRectMode(OF_RECTMODE_CENTER);
       ofDrawRectangle(recPos2.x, recPos2.y, width, height);

    }
//    if(trangleRotate){
//        ofPushMatrix();
//        ofRotate(45);
//        ofTranslate(recPos1.x, recPos1.y);
//        ofDrawRectangle(0, 0, width, height);
//        ofPopMatrix();
//
//    }
    if((cirPos.x + radius) >= (recPos3.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos3.x, recPos3.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
        
        
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos3.x, recPos3.y, width, height);
        
    }
    
    if((cirPos.x + radius) >= (recPos4.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos4.x, recPos4.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
        
        
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos4.x, recPos4.y, width, height);
        
    }
    if((cirPos.x + radius) >= (recPos5.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos5.x, recPos5.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        //ofDrawRectangle(recPos.x, recPos.y, width, height);
        ofDrawRectangle(recPos5.x, recPos5.y, width, height);
    }
    if((cirPos.x + radius) >= (recPos6.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos6.x, recPos6.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos6.x, recPos6.y, width, height);
    }
    if((cirPos.x + radius) >= (recPos7.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos7.x, recPos7.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos7.x, recPos7.y, width, height);
    }
    if((cirPos.x + radius) >= (recPos8.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos8.x, recPos8.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos8.x, recPos8.y, width, height);
    }
    if((cirPos.x + radius) >= (recPos9.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos9.x, recPos9.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos9.x, recPos9.y, width, height);
    }
    if((cirPos.x + radius) >= (recPos10.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos10.x, recPos10.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos10.x, recPos10.y, width, height);
    }
    
    if((cirPos.x + radius) >= (recPos11.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos11.x, recPos11.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos11.x, recPos11.y, width, height);
    }
    if((cirPos.x + radius) >= (recPos12.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos12.x, recPos12.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos12.x, recPos12.y, width, height);
    }
    if((cirPos.x + radius) >= (recPos13.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos13.x, recPos13.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos13.x, recPos13.y, width, height);
    }
    if((cirPos.x + radius) >= (recPos14.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos14.x, recPos14.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos14.x, recPos14.y, width, height);
    }
    if((cirPos.x + radius) >= (recPos15.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos15.x, recPos15.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos15.x, recPos15.y, width, height);
    }
    if((cirPos.x + radius) >= (recPos16.x - width/2)){
        ofPushMatrix();
        ofTranslate(recPos16.x, recPos16.y);
        ofRotate(45);
        ofDrawRectangle(0, 0, width, height);
        ofPopMatrix();
    }
    else{//no contact
        
        ofSetColor(200, 0, 0);
        ofDrawCircle(cirPos.x, cirPos.y, radius);
        ofSetColor(0, 0, 0);
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofDrawRectangle(recPos16.x, recPos16.y, width, height);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
//    if(key == 'x'){
//        cirPos.x+=10;
//        cout<<"out";
//    }
    if(key==OF_KEY_LEFT)
        cirPos.x-=speed;
    if(key==OF_KEY_RIGHT)
        cirPos.x+=speed;
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
