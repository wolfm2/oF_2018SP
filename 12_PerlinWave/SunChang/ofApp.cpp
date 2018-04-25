#include "ofApp.h"


ofFbo fbo;
//vector <数据类型> 数组名；
vector<line> myline;


// constructor

line::line(){
}

void line::setup(){
 
    //这些是那一溜儿线的初始值
    
    pos = ofPoint(0,0,0);
    size = ofRandom(0.5,2);
    n = ofRandom(0.1,2);
    
    a= ofRandom(0.2,0.3);
    b = ofRandom(0.3,0.4);
    c =ofRandom(0.4,0.5);
    
    // 设置一个任意颜色的标准写法
    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
    
    
}


void line::update(){
    // ofGet。。。取此刻的时间（which永远在变化）
    // 让它们有不同的出发时间
  time = ofGetElapsedTimef()*n;
    
    
    // *0.3/4是为了动的更舒展   400是为了动的剧烈
    rX = ofSignedNoise(time*0.1)*100;
    rY = ofSignedNoise(time*0.1)*100;
    rZ = ofSignedNoise(time*0.1)*100;
    
    //  size跟上面的* 400 是一个意思
    scale=(1-ofNoise(time*0.4))*size;
    
    
    X = ofSignedNoise(time*a)*ofRandom(10,20);
    Y = ofSignedNoise(time*b)*ofRandom(10,20);
    Z = ofSignedNoise(time*c)*ofRandom(10,20);
    
    pos+= ofPoint(X, Y, Z);
    
    
    
}


void line :: draw(){
    ofPushMatrix();
    ofTranslate(pos.x, pos.y, pos.z);
    ofScale(scale,scale, scale);
    ofRotateX(rX);
    ofRotateY(rY);
    ofRotateZ(rZ);
    ofSetColor(color);
    ofDrawLine(-40,0,40,0);
    ofPopMatrix();

}



//--------------------------------------------------------------
void ofApp::setup(){
    
  
    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    fbo.begin();
    ofClear(255,255,255,0);
    
    fbo.end();
    
 
    for(int i = 0; i<=5 ;i++){
        line newline;
        newline.setup();
        // push_back是vector里的一个方法,把这个新建的方法扔回到数组里。查查查
        myline.push_back(newline);
        
    
        }

}

//--------------------------------------------------------------
void ofApp::update(){
    
  
    
    
    
    
    for(int i=0; i< myline.size();i++){
        myline[i].update();
        cout << "my Ponti"<<endl;
        
        
        //这步骤是出了屏幕就丢弃重新开始
        if(myline[i].pos.y < 0 || myline[i].pos.y > ofGetWindowWidth() || myline[i].pos.x<0 ||myline[i].pos.x >ofGetWindowWidth()){
            myline.erase(myline.begin()+i);
            line newline;
            newline.setup();
            myline.push_back(newline);
            
        }

        
    }
    
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
      ofBackground(0);
    
//_______这部分在开启FBO模式_________________
    
    fbo.begin();
    ofSetColor(255,255,255,5);
    
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    for(int i = 0; i<myline.size(); i++){
        
        myline[i].draw();
        
    }
    
    fbo.end();
    ofSetColor(255);
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
