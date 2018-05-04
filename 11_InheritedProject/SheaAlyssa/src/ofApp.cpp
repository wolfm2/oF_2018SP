#include "ofApp.h"
ofSoundPlayer piano1;
ofSoundPlayer piano2;
ofSoundPlayer piano3;
ofSoundPlayer piano4;
ofSoundPlayer piano5;
ofSoundPlayer piano6;
ofSoundPlayer piano7;
ofSoundPlayer piano8;
int mouseX;
int mouseY;
//--------------------------------------------------------------
void ofApp::setup(){
    piano1.load("1.wav");
    piano1.play();
    piano2.load("2.wav");
    piano2.play();
    piano3.load("3.wav");
    piano3.play();
    piano4.load("4.wav");
    piano4.play();
    piano5.load("5.wav");
    piano5.play();
    piano6.load("6.wav");
    piano6.play();
    piano7.load("7.wav");
    piano7.play();
    piano8.load("8.wav");
    piano8.play();
    
    ofSetWindowShape(800, 800);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (ofDist(mouseX, mouseY, 260, 316) <= 8) {
        piano1.play();
    }
    if (ofDist(mouseX, mouseY, 266, 348) <= 8) {
        piano2.play();
    }
    if (ofDist(mouseX, mouseY, 275, 380) <= 8) {
        piano3.play();
    }
    if (ofDist(mouseX, mouseY, 285, 414) <= 8) {
        piano4.play();
    }
    if (ofDist(mouseX, mouseY, 298, 455) <= 8) {
        piano5.play();
    }
    if (ofDist(mouseX, mouseY, 315, 496) <= 8) {
        piano6.play();
    }
    if (ofDist(mouseX, mouseY, 338, 526) <= 8) {
        piano7.play();
    }
    if (ofDist(mouseX, mouseY, 367, 553) <= 8) {
        piano8.play();
    }
    if (ofDist(mouseX, mouseY, 400, 562) <= 8) {
        piano1.play();
    }
    if (ofDist(mouseX, mouseY, 439, 555) <= 8) {
        piano2.play();
    }
    if (ofDist(mouseX, mouseY, 472, 527) <= 8) {
        piano3.play();
    }
    if (ofDist(mouseX, mouseY, 497, 494) <= 8) {
        piano4.play();
    }
    if (ofDist(mouseX, mouseY, 518, 453) <= 8) {
        piano5.play();
    }
    if (ofDist(mouseX, mouseY, 531, 411) <= 8) {
        piano6.play();
    }
    if (ofDist(mouseX, mouseY, 538, 370) <= 8) {
        piano7.play();
    }
    if (ofDist(mouseX, mouseY, 543, 332) <= 8) {
        piano8.play();
    }
    if (ofDist(mouseX, mouseY, 545, 292) <= 8) {
        piano1.play();
    }
    if (ofDist(mouseX, mouseY, 509, 254) <= 8) {
        piano2.play();
    }
    if (ofDist(mouseX, mouseY, 488, 242) <= 8) {
        piano3.play();
    }
    if (ofDist(mouseX, mouseY, 462, 237) <= 8) {
        piano4.play();
    }
    if (ofDist(mouseX, mouseY, 435, 242) <= 8) {
        piano5.play();
    }
    if (ofDist(mouseX, mouseY, 412, 256) <= 8) {
        piano6.play();
    }
    if (ofDist(mouseX, mouseY, 339, 265) <= 8) {
        piano7.play();
    }
    if (ofDist(mouseX, mouseY, 317, 255) <= 8) {
        piano8.play();
    }
    if (ofDist(mouseX, mouseY, 295, 254) <= 8) {
        piano1.play();
    }
    if (ofDist(mouseX, mouseY, 276, 261) <= 8) {
        piano2.play();
    }
    if (ofDist(mouseX, mouseY, 262, 276) <= 8) {
        piano3.play();
    }
    if (ofDist(mouseX, mouseY, 308, 296) <= 8) {
        piano4.play();
    }
    if (ofDist(mouseX, mouseY, 328, 297) <= 8) {
        piano5.play();
    }
    if (ofDist(mouseX, mouseY, 345, 310) <= 8) {
        piano6.play();
    }
    if (ofDist(mouseX, mouseY, 328, 317) <= 8) {
        piano7.play();
    }
    if (ofDist(mouseX, mouseY, 312, 320) <= 8) {
        piano8.play();
    }
    if (ofDist(mouseX, mouseY, 295, 311) <= 8) {
        piano1.play();
    }
    if (ofDist(mouseX, mouseY, 425, 301) <= 8) {
        piano2.play();
    }
    if (ofDist(mouseX, mouseY, 440, 286) <= 8) {
        piano3.play();
    }
    if (ofDist(mouseX, mouseY, 461, 282) <= 8) {
        piano4.play();
    }
    if (ofDist(mouseX, mouseY, 479, 295) <= 8) {
        piano5.play();
    }
    if (ofDist(mouseX, mouseY, 463, 305) <= 8) {
        piano6.play();
    }
    if (ofDist(mouseX, mouseY, 446, 307) <= 8) {
        piano7.play();
    }
    if (ofDist(mouseX, mouseY, 381, 313) <= 8) {
        piano8.play();
    }
    if (ofDist(mouseX, mouseY, 381, 344) <= 8) {
        piano1.play();
    }
    if (ofDist(mouseX, mouseY, 381, 370) <= 8) {
        piano2.play();
    }
    if (ofDist(mouseX, mouseY, 383, 400) <= 8) {
        piano3.play();
    }
    if (ofDist(mouseX, mouseY, 363, 415) <= 8) {
        piano4.play();
    }
    if (ofDist(mouseX, mouseY, 375, 419) <= 8) {
        piano5.play();
    }
    if (ofDist(mouseX, mouseY, 363, 415) <= 8) {
        piano6.play();
    }
    if (ofDist(mouseX, mouseY, 375, 419) <= 8) {
        piano7.play();
    }
    if (ofDist(mouseX, mouseY, 363, 415) <= 8) {
        piano8.play();
    }
    if (ofDist(mouseX, mouseY, 387, 421) <= 8) {
        piano1.play();
    }
    if (ofDist(mouseX, mouseY, 400, 417) <= 8) {
        piano2.play();
    }
    if (ofDist(mouseX, mouseY, 413, 411) <= 8) {
        piano3.play();
    }
    if (ofDist(mouseX, mouseY, 376, 448) <= 8) {
        piano4.play();
    }
    if (ofDist(mouseX, mouseY, 363, 457) <= 8) {
        piano5.play();
    }
    if (ofDist(mouseX, mouseY, 413, 411) <= 8) {
        piano6.play();
    }
    if (ofDist(mouseX, mouseY, 365, 475) <= 8) {
        piano7.play();
    }
    if (ofDist(mouseX, mouseY, 375, 481) <= 8) {
        piano8.play();
    }
    if (ofDist(mouseX, mouseY, 394, 484) <= 8) {
        piano1.play();
    }
    if (ofDist(mouseX, mouseY, 412, 480) <= 8) {
        piano2.play();
    }
    if (ofDist(mouseX, mouseY, 428, 470) <= 8) {
        piano3.play();
    }
    if (ofDist(mouseX, mouseY, 443, 457) <= 8) {
        piano4.play();
    }
    if (ofDist(mouseX, mouseY, 426, 451) <= 8) {
        piano5.play();
    }
    if (ofDist(mouseX, mouseY, 409, 444) <= 8) {
        piano6.play();
    }
    if (ofDist(mouseX, mouseY, 428, 470) <= 8) {
        piano7.play();
    }
    if (ofDist(mouseX, mouseY, 392, 453) <= 8) {
        piano8.play();
    }
    if (ofDist(mouseX, mouseY, 376, 449) <= 8) {
        piano1.play();
    }
    if (ofDist(mouseX, mouseY, 352, 465) <= 8) {
        piano2.play();
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,105,180);
    ofDrawCircle(260, 316, 8);
    ofDrawCircle(266, 348, 8);
    ofDrawCircle(275, 380, 8);
    ofDrawCircle(285, 414, 8);
    ofDrawCircle(298, 455, 8);
    ofDrawCircle(315, 496, 8);
    ofDrawCircle(338, 526, 8);
    ofDrawCircle(367, 553, 8);
    ofDrawCircle(400, 562, 8);
    ofDrawCircle(439, 555, 8);
    ofDrawCircle(472, 527, 8);
    ofDrawCircle(497, 494, 8);
    ofDrawCircle(518, 453, 8);
    ofDrawCircle(531, 411, 8);
    ofDrawCircle(538, 370, 8);
    ofDrawCircle(543, 332, 8);
    ofDrawCircle(545, 292, 8);
    ofDrawCircle(509, 254, 8);
    ofDrawCircle(488, 242, 8);
    ofDrawCircle(462, 237, 8);
    ofDrawCircle(435, 242, 8);
    ofDrawCircle(412, 256, 8);
    ofDrawCircle(339, 265, 8);
    ofDrawCircle(317, 255, 8);
    ofDrawCircle(295, 254, 8);
    ofDrawCircle(276, 261, 8);
    ofDrawCircle(262, 276, 8);
    ofDrawCircle(308, 296, 8);
    ofDrawCircle(328, 297, 8);
    ofDrawCircle(345, 310, 8);
    ofDrawCircle(328, 317, 8);
    ofDrawCircle(312, 320, 8);
    ofDrawCircle(295, 311, 8);
    ofDrawCircle(425, 301, 8);
    ofDrawCircle(440, 286, 8);
    ofDrawCircle(461, 282, 8);
    ofDrawCircle(479, 295, 8);
    ofDrawCircle(463, 305, 8);
    ofDrawCircle(446, 307, 8);
    ofDrawCircle(381, 313, 8);
    ofDrawCircle(381, 344, 8);
    ofDrawCircle(381, 370, 8);
    ofDrawCircle(383, 400, 8);
    ofDrawCircle(363, 415, 8);
    ofDrawCircle(375, 419, 8);
    ofDrawCircle(363, 415, 8);
    ofDrawCircle(387, 421, 8);
    ofDrawCircle(400, 417, 8);
    ofDrawCircle(413, 411, 8);
    
    ofDrawCircle(376, 448, 8);
    ofDrawCircle(363, 457, 8);
    ofDrawCircle(413, 411, 8);
    ofDrawCircle(365, 475, 8);
    ofDrawCircle(375, 481, 8);
    ofDrawCircle(394, 484, 8);
    ofDrawCircle(412, 480, 8);
    ofDrawCircle(428, 470, 8);
    ofDrawCircle(443, 457, 8);
    ofDrawCircle(426, 451, 8);
    ofDrawCircle(409, 444, 8);
    ofDrawCircle(428, 470, 8);
    ofDrawCircle(392, 453, 8);
    ofDrawCircle(376, 449, 8);
    ofDrawCircle(352, 465, 8);
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
