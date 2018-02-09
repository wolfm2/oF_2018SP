#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //here is how you set canvas in OF
//    ofSetBackgroundColor(0,0,0);
//    ofSetColor(255,255,255);
//
    //在“.h” 的文件中declare了对象和variable后，在“.cpp”文档中的draw function中定义具体的value 【赋值】
    // 相当于ofVec2f.set（xxx，xxx）；
    //set（xxx，xxx）一定是属于ofVec2f这个class中的一个function
    //以下这行代码的意思是：设置一个vector向x轴方向走ofGetWidth（）／2的位置；再向y轴走ofGetHight（）／2的位置
    
    circlePosition.set(ofGetWidth()/2, ofGetHeight()/2);
    circleVelocity.set(0,0);
    radius = 50;
    friction = 0.1f;
    
    
     ofBackground(255);

   
}

//--------------------------------------------------------------
//update physics in every frame。  ------？？？？？How to understand the frame??
void ofApp ::update(){
    
    // update the circle's position based on its velocity
    // 记得我们在ofVec2f文档中看到的两个vector的对象可以随意加减乘除
    circlePosition += circleVelocity;
    //上面这行代码的意思就是：
    // simulate friction 给速度加上摩擦--->减速
    circleVelocity *= friction;
   
    
    

}

//--------------------------------------------------------------
// this the c++ syntax :
void ofApp::draw(){
    
    ofSetColor(50,70,150,86);
    ofDrawTriangle(400,70,500,200,400,333);

    ofSetColor(30,130,70,76);
    ofDrawTriangle(390,200,390,450,300,300);
    
    ofSetColor(150,170,100);
    ofDrawTriangle(500,230,400,360,500,360);
    
    ofSetColor(130,70,40,50);
    ofDrawTriangle(500,380,400,380,500,690);
    
    ofSetColor(150,130,80);
    ofDrawTriangle(410,460,200,460,485,700);
    
    ofSetColor(80,122,122,88);
    ofDrawTriangle(380,450,260,450,260,253);
    
    ofSetColor(80,170,70,36);
    ofDrawTriangle(180,460,380,650,100,650);
    
    ofSetColor(230,00,50,63);
    ofDrawTriangle(650,230,590,503,750,503);
    
    ofSetColor(30,170,10,77);
    ofDrawTriangle(520,150,520,700,630,300);
   
    ofSetColor(100,0,150,90);
    ofDrawTriangle(590,520,520,700,750,520);
    
    ofSetColor(0,70,150,45);
    ofDrawTriangle(750,540,630,630,900,630);
    
    
    
    
    

}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //在名字叫circleVelocity的ofVec2f的对象中，分别对（）中的arguments x,y 做变化
    circleVelocity.x += 5 - ofRandom(10);
    circleVelocity.y += 5 - ofRandom(10);
    
    
    



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


