#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(19,22,25,200);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetWindowTitle("GLowing dress");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    
    ofColor c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
    c1.setHsb(126.8, 12.75, 188.7);
    c2.setHsb(156.5, 127.5, 45.9);
    c3.setHsb(151,66.3, 66.3);
    c4.setHsb(33.5, 30.6, 153);
    c5.setHsb(131.75, 71.4, 122.4);
    c6.setHsb(129.6, 66.3, 86.9);
    c7.setHsb(126.8, 30.6, 160.65);
    c8.setHsb(129.6, 0, 255);
    c9.setHsb(131.75, 68.85, 109.65);
    c10.setHsb(136, 12.75, 252.45);
    
    //1,15
    ofSetColor(c10);
    ofDrawTriangle(214.5, 179, 214.5, 224, 244.5, 175);
    ofDrawTriangle(452.5, 148, 452.5, 199, 443.5, 199);
    
    //2,14
    ofSetColor(c5);
    ofDrawTriangle(241.5, 224, 214.5, 224, 244.5, 175);
    ofDrawTriangle(452.5, 148, 443.5, 199, 414.5, 164);
    
    //3,13
    ofSetColor(c2,200);
    ofDrawTriangle(241.5, 224, 267.5, 182, 244.5, 175);
    ofDrawTriangle(431.5, 221, 443.5, 199, 414.5, 164);
    
    //4,12
    ofSetColor(c3,200);
    ofDrawTriangle(241.5, 224, 267.5, 182, 288.5, 190);
    ofDrawTriangle(431.5, 221, 392.5, 179, 414.5, 164);
    
    //5,11
    ofSetColor(c6);
    ofDrawTriangle(241.5, 224, 249.5, 247.5, 288.5, 190);
    ofDrawTriangle(431.5, 221, 392.5, 179, 423.5, 255.5);
    
    //6,10
    ofSetColor(c4);
    ofDrawTriangle(307.5, 202.5, 249.5, 247.5, 288.5, 190);
    ofDrawTriangle(374.5, 197, 392.5, 179, 423.5, 255.5);
    
    //7,9
    ofSetColor(c7);
    ofDrawTriangle(307.5, 202.5, 249.5, 247.5, 254.5, 273.5);
    ofDrawTriangle(374.5, 197, 350.5, 247, 423.5, 255.5);
    
    ofSetColor(c7);
    ofDrawTriangle(350.5, 247, 254.5, 273.5, 307.5, 202.5);
   
    //16,19,21,23,45,50,51,56
    ofSetColor(c8);
    ofDrawTriangle(568, 616, 267.5, 412, 431.5, 394);
    ofDrawTriangle(254.5, 273, 423.5, 255.5, 350.5, 247);
    ofDrawTriangle(405.5, 352, 278.5, 352, 402.5, 296);
    ofDrawTriangle(405.5, 352, 267.5, 412, 278.5, 384);
    ofDrawTriangle(140.5, 807, 157.5, 833, 195.5, 553);
    ofDrawTriangle(466.5, 843, 275.5, 854, 345.5, 879);
    ofDrawTriangle(598.5, 807, 544.5, 843, 466.5, 843);
    ofDrawTriangle(213.5, 845, 182.5, 854,466.5, 843);

    //17
    ofSetColor(c10);
    ofDrawTriangle(254.5, 273, 423.5, 255.5, 402.5, 296);
    //18,20,22,24,31,33,39,42,48
    ofSetColor(c10);
    ofDrawTriangle(254.5, 273, 278.5, 352, 402.5, 296);
    ofDrawTriangle(405.5, 352, 278.5, 352, 278.5, 384);
    ofDrawTriangle(405.5, 352, 267.5, 412, 431.5, 394);
    ofDrawTriangle(568, 616, 267.5, 412, 253.5, 444);
    ofDrawTriangle(256.5, 593.3, 316.5, 768.5, 228.5, 623.5);
    ofDrawTriangle(256.5, 593.3, 349.5, 496, 377.12, 511.5);
    ofDrawTriangle(316.5, 768.5, 627.5, 780, 213.5, 845);
    ofDrawTriangle(216.5, 571, 213.5, 514, 213.5, 845);
    ofDrawTriangle(213.5, 514, 157.5, 833, 213.5, 845);
    ofDrawTriangle(598.5, 807, 275.5, 854, 213.5, 845);
    //25->28
    ofSetColor(c1);
    ofDrawTriangle(233.5, 470, 349.5, 496, 253.5, 444);
    //26
    ofSetColor(c5);
    ofDrawTriangle(568, 616, 516.5, 512, 431.5, 394);
    //27,30,37
    ofSetColor(c6);
    ofDrawTriangle(466.5, 433, 516.5, 512, 431.5, 394);
    ofDrawTriangle(216.5, 571, 349.5, 496, 228.5, 623.5);
    ofDrawTriangle(316.5, 768.5, 568, 616, 615.5, 746);
    //28,29,35
    ofSetColor(c4);
    ofDrawTriangle(233.5, 470, 349.5, 496, 213.5, 514);
    ofDrawTriangle(316.5, 768.5, 345.74, 532.83, 399.5, 523);
    ofSetColor(c5);
    ofDrawTriangle(216.5, 571, 349.5, 496, 213.5, 514);
    //32,34
    ofSetColor(c1);
    ofDrawTriangle(256.5, 593.3, 316.5, 768.5, 345.74, 532.83);
    ofDrawTriangle(377.12, 511.5, 345.74, 532.83, 399.5, 523);
    //36,38,40,41
    ofSetColor(c7);
    ofDrawTriangle(316.5, 768.5, 399.5, 523, 568, 616);
    ofDrawTriangle(228.5, 623.5, 269.87, 803.44, 316.5, 768.5);
    ofSetColor(c9);
    ofDrawTriangle(316.5, 768.5, 627.5, 780, 615.5, 746);
    ofDrawTriangle(216.5, 571, 269.87, 803.44, 213.5, 845);
  
    //43,52,53,54,55
    ofSetColor(c3);
    ofDrawTriangle(182.5, 854, 157.5, 833, 213.5, 845);
    ofDrawTriangle(296.5, 872, 275.5, 854, 345.5, 879);
    ofDrawTriangle(466.5, 843, 427.5, 865, 345.5, 879);
    ofDrawTriangle(500.5, 854, 544.5, 843, 466.5, 843);
    ofDrawTriangle(598.5, 807, 544.5, 843, 581.5, 830);
    
    //44,46,47,49
    ofSetColor(c1);
    ofDrawTriangle(213.5, 514, 157.5, 833, 195.5, 553);
    ofDrawTriangle(140.5, 807, 154.5, 674, 195.5, 553);
    ofDrawTriangle(598.5, 807, 627.5, 780, 213.5, 845);
    ofDrawTriangle(598.5, 807, 275.5, 854, 466.5, 843);

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
