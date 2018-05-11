#include "ofApp.h"
//这是复制的可修改的sketch


ofFbo fbo;
vector<Ball> balls;    //记得自强说过，这是建立一个新的空数组array


// constructor

Ball::Ball(){
}

void Ball::setup(){
    
    x=0;
     y=0;  //思
    size = ofRandom(0,5);
    n = ofRandom(0.1,2);    //一个random的变量
    
    a= ofRandom(0.2,0.3);
    b = ofRandom(0.3,0.4);
   
    radius = ofRandom(30,80);
    // 设置一个任意颜色的标准写法
    color.set(ofRandom(255));
    
    
}


void Ball::update(){
    // ofGet。。。取此刻的时间（which永远在变化）
    // 让它们有不同的出发时间
    time = ofGetElapsedTimef()*n;

    
    //  size跟上面的* 400 是一个意思
    scale=(1-ofNoise(time*0.4))*size;
    
    //此处是位置、左边的值
    X = ofSignedNoise(time*a)*ofRandom(1000,8000);
    Y = ofSignedNoise(time*b)*ofRandom(1000,8000);
   
    
    
    
}


void Ball :: draw(){
    ofPushMatrix();
   //ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofScale(scale,scale, scale);
    ofSetColor(color);
    ofDrawCircle(X,Y,radius);
    ofPopMatrix();

}



//--------------------------------------------------------------
void ofApp::setup(){
    
  // 先清空fbo
    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    fbo.begin();
    ofClear(255,255,255,0);
    
    fbo.end();
    
 
    for(int i = 0; i<=5 ;i++){
        Ball newball;
        newball.setup();
        // push_back是vector里的一个方法,把这个新建的方法扔回到数组里。查查查
        balls.push_back(newball);
        
    
        }
    
    
    ofSetBackgroundColor(0);
    song.load("song.mp3");
    while (! song.isLoaded()); // spin wheels till loaded
    song.play();
    nBandsToGet = 360;  // up to 512

}
float *val;
//--------------------------------------------------------------
void ofApp::update(){
    
  
    
    
     val = ofSoundGetSpectrum(nBandsToGet);  // get array of floats (1 for each band)
    
    for(int i=0; i< balls.size();i++){
        balls[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
 
    for (int i = 0;i <100; i++){
        // (we use negative height here, because we want to flip them
        // because the top corner is 0,0)
      //  ofDrawRectangle(100+i*2,ofGetHeight()-100,2,(-1 * val[i]) * 8000);
        float r= ofMap(val[0]*8000, 0,1,100,255);    //low
         float g= ofMap(val[50]*8000, 0,1,100,255);    // middle
         float b= ofMap(val[100]*8000, 0,1,100,255);    //high
        ofBackground(r);
    }
    
    
     // ofBackground(0);
    
//_______这部分在开启FBO模式_________________
    
    fbo.begin();
    ofSetColor(255,255,255,5);
    
     ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    for (int i = 0;i < 100; i++){
        // (we use negative height here, because we want to flip them
        // because the top corner is 0,0)
        float radius= ofMap(ofNoise(val[i]), 0, 1, 50, val[i]*1000000);
        float xpos = ofMap(val[i], 0, 1, ofGetWidth()/2, ofGetWidth());
       float  ypos= ofMap(val[i+5], 0,1, ofGetHeight()/2, ofGetHeight());
       float r=ofRandom(255);
      
        // ofSetColor(0, 20); // background color with alpha
        // ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofSetColor(r);
        
        ofDrawCircle(xpos, ypos, radius);
    }
    
   
    for(int i = 0; i<balls.size(); i++){
        
        balls[i].draw();
        
    }
    
    fbo.end();
    ofSetColor(255);
    fbo.draw(0,0);
    
    
 //_______画noise波浪线呢_________________。             <---------------------------此处最好还能让它动起来！！！！
    
    //ofSetColor( 0, 0, 0 );
    //float start=0;
    for (int x=0; x<1000; x++) {
        // float t = x * 0.01;
        float t = x * 0.03;
        float y = ofNoise( t );
        
        float y2= ofRandom(0, ofGetWindowHeight());
        float y3= ofMap(y, 0, 1, 0, ofGetWindowHeight());
        // ofSetLineWidth(0.5);
        int r= int(ofRandom(255));
        int g= int(ofRandom(255));
        int b= int(ofRandom(255));
        ofSetColor(r);
        //        ofLine( x, 300, x, 300 - y * 300 );
        ofDrawEllipse(x, y3, 3, 3);
    }
    
    //start++;
    
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
