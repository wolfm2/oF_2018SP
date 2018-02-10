#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetBackgroundColor(232, 234, 233);
    dog.load("dog.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    //nose
    ofSetColor(10, 8, 13);
    ofDrawTriangle(400, 490, 365, 530, 435, 530);
    
    ofSetColor(33,33,36);
    ofDrawTriangle(400, 490, 365, 530, 350, 500);
    
    ofSetColor(26,26,28);
    ofDrawTriangle(400, 490, 350, 500, 350, 460);
    
    ofSetColor(33,33,36);
    ofDrawTriangle(400, 490, 435, 530, 450, 500);
    
    ofSetColor(26,26,28);
    ofDrawTriangle(400, 490, 450, 460, 450, 500);
    
    ofSetColor(43,38,46);
    ofDrawTriangle(400, 490, 350, 460, 450, 460);
    
    ofSetColor(42, 38, 46);
    ofDrawTriangle(450, 460, 350, 460, 400, 435);

    
    ofSetColor(10,8,12);
    ofDrawTriangle(365, 530, 435, 530, 400, 545);
    
     //----face
    ofSetColor(144,91,58); //up left small
    ofDrawTriangle(165, 270, 340, 180, 280, 120);
    
    ofSetColor(144, 91, 58); //up right small
    ofDrawTriangle(635, 270, 460, 180, 520, 120);
    
    ofSetColor(124, 65, 29); // mid left big
    ofDrawTriangle(165, 270, 340, 180, 270, 460);
    
    ofSetColor(124, 65, 29); //mid right big
    ofDrawTriangle(460, 180, 635, 270, 530, 460);
    
    ofSetColor(144, 91, 57); // bottom left small
    ofDrawTriangle(340, 180, 270, 460, 350, 340);
    
    ofSetColor(144, 91, 57);// bottom right small
    ofDrawTriangle(460, 180, 450, 340, 530, 460);
    
    //--------- eyes
    
    ofSetColor(50, 30, 30); // left top eye
    ofDrawTriangle(210, 305, 260, 260, 335, 300);
    
    ofSetColor(50, 50, 30); // right top eye
    ofDrawTriangle(460, 300, 530, 260, 585, 305);
    
    ofSetColor(25, 20, 20); // left bottom eye
    ofDrawTriangle(210, 305, 280, 340, 335, 300);
    
    ofSetColor(25, 20, 20); //right bottom eye
    ofDrawTriangle(460, 300, 510, 340, 585, 305);
    
    ofSetColor(0, 0, 0); // left eye
    ofDrawCircle(270, 300, 30);
    
    ofSetColor(0, 0, 0); //right eye
    ofDrawCircle(520, 300, 30);
    
    ofSetColor(70, 70, 90); // eye light big
    ofDrawCircle(285, 290, 7);
    
    ofSetColor(70, 70, 90); //eye light big
    ofDrawCircle(505, 290, 7);
    
    ofSetColor(80, 100, 100); //eye light small
    ofDrawCircle(270, 285, 5);
    
    ofSetColor(80, 100, 100);
    ofDrawCircle(520, 285, 5); //eye light small

    //------mouth
    ofSetColor(200, 40, 0);
    ofDrawTriangle(350, 560, 450, 560, 400, 600);
    
    //----ear
//    ofSetColor(255, 255, 255); //dog pic
//    dog.draw(0, 0, 800, 800);
    
    ofSetColor(90, 60, 40); //left top ear
    ofDrawTriangle(50, 60, 40, 125, 145, 60);
    
    ofSetColor(90, 60, 40); //right top ear
    ofDrawTriangle(655, 60, 770, 125, 750, 60);
    
    ofSetColor(40, 20, 10); //left bottom ear
    ofDrawTriangle(40, 125, 10, 160, 20, 165);
    
    ofSetColor(40, 20, 10); //right bottom ear
    ofDrawTriangle(770, 125, 790, 165, 800, 160);
    
    
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
