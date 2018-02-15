#include "ofApp.h"
#include "ofMain.h"

float rect_catchUpSpeed = 0.01f;  // speed with which we pursue the mouse
                                  // here we can see the speed of the rect
ofPoint rect_pos;  // point is a vector
ofPoint rect2_pos;
float rect2_catchUpSpeed = 0.015f;

// 如果我们要新加一个rectangle，需要新设一个vector（新rect的x,y位置）+ 一个新的移动速度。 What if the 速度is 一样？
ofPoint rect3_pos;
float rect3_catchUpSpeed = 0.018f;


//--------------------------------------------------------------
void ofApp::setup(){
    // macs by default run on non vertical sync, which can make animation very, very fast
    // this fixes that:
    ofSetVerticalSync(true);   //如果想要禁止这个频幕重绘同步的功能则直接改为false即可
    
    // set background:
    ofEnableAlphaBlending();   //这个ofEnableAlphaBlending（）没什么卵用，就是启不启用alpha透明度显示的功能
    ofBackground(204, 255, 255);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
                      rect_pos.x += rect_catchUpSpeed * (mouseX - rect_pos.x);
    // 上面那句话意味着：rect_pos.x= rect_pos.x + 0.1 * (mouseX - rect_pos.x);
    //    x+=1； --->   x=x+1;
    rect_pos.y += rect_catchUpSpeed * (mouseY - rect_pos.y);
    
    rect2_pos.x += rect2_catchUpSpeed * (mouseX - rect2_pos.x);
        rect2_pos.y += rect2_catchUpSpeed * (mouseY - rect2_pos.y);
    rect3_pos.x += rect3_catchUpSpeed * (mouseX - rect3_pos.x);
    rect3_pos.y += rect3_catchUpSpeed * (mouseY - rect3_pos.y);
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(rect_pos.x,rect_pos.y, 20,20);
    ofSetColor(255, 0, 102);
    ofRect(rect2_pos.x,rect2_pos.y, 28,28);
    ofSetColor(255, 255, 0);
    ofRect(rect3_pos.x,rect3_pos.y, 23,23);
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
