#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetupOpenGL(600, 600, OF_WINDOW);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(13,11,6,200);
    ofDrawTriangle(272, 127, 273, 195, 295, 196);
    ofSetColor(59,61,61,200);
    ofDrawTriangle(272, 127, 295, 196, 335, 165);
    ofSetColor(24,23,28,200);
    ofDrawTriangle(272, 127, 294, 142, 303, 128);
    ofSetColor(129,122,109,200);
    ofDrawTriangle(335, 165, 294, 142, 303, 128);
    ofSetColor(208,184,148,200);
    ofDrawTriangle(284, 216, 273, 195, 295, 196);
    
    ofSetColor(173,140,117,255);
    ofDrawTriangle(284, 216, 315, 212, 295, 196);
    ofSetColor(210,193,157,155);
    ofDrawTriangle(335, 165, 315, 212, 295, 196);
    ofSetColor(233,223,203,200);
    ofDrawTriangle(335, 165, 315, 212, 374, 177);
    ofSetColor(175,147,127,180);
    ofDrawTriangle(335, 165, 413, 165, 374, 177);
    ofSetColor(233,223,203,200);
    ofDrawTriangle(432, 212, 413, 165, 374, 177);
    
    ofSetColor(210,193,157,155);
    ofDrawTriangle(432, 212, 413, 165, 452, 196);
    ofSetColor(173,140,117,255);
    ofDrawTriangle(432, 212, 462, 216, 452, 196);
    ofSetColor(208,184,148,200);
    ofDrawTriangle(452, 196, 462, 216, 473, 195);
    ofSetColor(13,11,6,200);
    ofDrawTriangle(452, 196, 474, 127, 473, 195);
    ofSetColor(59,61,61,200);
    ofDrawTriangle(452, 196, 474, 127, 413, 165);

    ofSetColor(129,122,109,200);
    ofDrawTriangle(443, 128, 413, 165, 451, 142);
    ofSetColor(24,23,28,200);
    ofDrawTriangle(443, 128, 474, 127, 451, 142);
    ofSetColor(120,102,76,255);
    ofDrawTriangle(284, 216, 310, 270, 323, 262);
    ofSetColor(128,113,97,255);
    ofDrawTriangle(284, 216, 318, 236, 323, 262);
    ofSetColor(164,155,134,255);
    ofDrawTriangle(284, 216, 318, 236, 315, 212);
    
    ofSetColor(194,226,237,180);
    ofDrawTriangle(336, 218, 318, 236, 315, 212);
    ofSetColor(167,154,136,255);
    ofDrawTriangle(336, 218, 374, 177, 315, 212);
    ofSetColor(62,61,57,255);
    ofDrawTriangle(413, 218, 374, 177, 336, 218);
    ofSetColor(33,29,22,200);
    ofDrawTriangle(413, 218, 374, 256, 336, 218);
    ofSetColor(167,154,136,255);
    ofDrawTriangle(374, 177, 413, 218, 432, 212);
    
    ofSetColor(194,226,237,180);
    ofDrawTriangle(413, 218, 432,212, 430, 236);
    ofSetColor(164,155,134,255);
    ofDrawTriangle(462, 216, 432, 212, 430, 236);
    ofSetColor(128,113,97,255);
    ofDrawTriangle(462, 216, 425, 262, 430, 236);
    ofSetColor(120,102,76,255);
    ofDrawTriangle(462, 216, 425, 262, 437, 270);
    ofSetColor(26,22,14,255);
    ofDrawTriangle(318, 236, 323, 262, 340, 249);
    
    ofSetColor(198,188,183,255);
    ofDrawTriangle(318, 236, 324, 229, 340, 249);
    ofSetColor(29,31,32,255);
    ofDrawTriangle(336, 218, 324, 229, 340, 249);
    ofSetColor(48,45,52,255);
    ofDrawTriangle(336, 218, 346, 228, 340, 249);
    ofSetColor(167,202,207,255);
    ofDrawTriangle(355, 238, 346, 228, 340, 249);
    ofSetColor(65,41,57,255);
    ofDrawTriangle(355, 238, 355, 256, 340, 249);
    
    ofSetColor(65,41,57,255);
    ofDrawTriangle(355, 238, 355, 256, 374, 256);
    ofSetColor(65,41,57,255);
    ofDrawTriangle(393, 238, 393, 256, 374, 256);
    ofSetColor(65,41,57,255);
    ofDrawTriangle(393, 238, 393, 256, 407, 249);
    ofSetColor(167,202,207,255);
    ofDrawTriangle(393, 238, 402, 228, 407, 249);
    ofSetColor(48,45,52,255);
    ofDrawTriangle(413, 218, 402, 228, 407, 249);
    
    ofSetColor(29,31,32,255);
    ofDrawTriangle(413, 218, 423, 229, 407, 249);
    ofSetColor(198,188,183,255);
    ofDrawTriangle(430, 236, 423, 229, 407, 249);
    ofSetColor(26,22,14,255);
    ofDrawTriangle(430, 236, 430, 262, 407, 249);
    ofSetColor(205,192,198,255);
    ofDrawTriangle(310, 270, 335, 290, 349, 280);
    ofSetColor(222,213,199,255);
    ofDrawTriangle(310, 270, 323, 262, 349, 280);
    
    ofSetColor(74,66,64,255);
    ofDrawTriangle(340, 249, 323, 262, 355, 256);
    ofSetColor(55,51,54,255);
    ofDrawTriangle(323, 262, 349, 280, 355, 256);
    ofSetColor(55,51,54,255);
    ofDrawTriangle(374, 276, 349, 280, 355, 256);
    ofSetColor(17,15,10,200);
    ofDrawTriangle(374, 276, 393, 256, 355, 256);
    ofSetColor(55,51,54,255);
    ofDrawTriangle(374, 276, 399, 280, 393, 256);
    ofSetColor(55,51,54,255);
    ofDrawTriangle(425, 262, 399, 280, 393, 256);
    
    ofSetColor(222,213,199,255);
    ofDrawTriangle(425, 262, 399, 280, 437, 270);
    ofSetColor(205,192,198,255);
    ofDrawTriangle(399, 280, 413, 290, 437, 270);
    ofSetColor(222,213,199,255);
    ofDrawTriangle(335, 290, 349, 280, 361, 289);
    ofSetColor(68,67,77,255);
    ofDrawTriangle(374, 276, 349, 280, 361, 289);
    ofSetColor(17,15,10,255);
    ofDrawTriangle(374, 276, 369, 289, 361, 289);
    
    ofSetColor(124,123,124,200);
    ofDrawTriangle(374, 276, 364, 301, 383, 301);
    ofSetColor(17,15,10,255);
    ofDrawTriangle(374, 276, 379, 289, 386, 289);
    ofSetColor(68,67,77,255);
    ofDrawTriangle(374, 276, 399, 280, 386, 289);
    ofSetColor(222,213,199,255);
    ofDrawTriangle(413, 290, 399, 280, 386, 289);
    
    ofSetColor(73,72,82,255);
    ofDrawTriangle(335, 290, 369, 289, 364, 301);
    ofSetColor(73,72,82,255);
    ofDrawTriangle(379, 289, 413, 290, 383, 301);

    



    


    



    

    

    





    

    

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
