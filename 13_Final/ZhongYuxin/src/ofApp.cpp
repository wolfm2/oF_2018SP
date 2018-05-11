#include "ofApp.h"
#include "ofMath.h"
#include "ofMesh.h"
#include "ofTessellator.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    bgm.load("bgm.mp3");
    
    
    std::cout<<"start"<<std::endl;
    
    //Arduino
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    serial.listDevices();
    vector<ofSerialDeviceInfo>deviceList = serial.getDeviceList();
    serial.setup(0,9600);
    
    
    
    //Fbo
    
    fbo.allocate(ofGetWidth(), ofGetHeight(),GL_RGBA32F);
    
    fbo.begin();
    ofClear(255,255,255,0);
    fbo.end();
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofSetCircleResolution(64);
    
    ofSetWindowShape(1024, 768);
    ofBackground(0,0,0);
    ofSetFrameRate(30);
    
    mode1.set(ofRandom(0,10000), ofRandom(0,10000));
    mode2.set(ofRandom(0,10000),ofRandom(0,10000));
    
    pink.r = 255;
    pink.g = 192;
    pink.b = 203;
    
    violet.r = 161;
    violet.g = 4;
    violet.b = 90;
    
    rblue.r = 20;
    rblue.g = 26;
    rblue.b = 112;
    
    sblue.r = 135;
    sblue.g = 206;
    sblue.b = 235;
    
    kgreen.r = 154;
    kgreen.g = 205;
    kgreen.b = 50;
    
    lgreen.r = 0;
    lgreen.g = 100;
    lgreen.b = 0;
    
    yellow.r = 255;
    yellow.g = 225;
    yellow.b = 0;
    
    oranger.r = 255;
    oranger.g = 69;
    oranger.b = 0;
    
    orange.r = 255;
    orange.g = 165;
    orange.b = 0;
    
    red.r = 255;
    red.g = 36;
    red.b = 0;
    
    rRed.r = 120;
    rRed.g = 0;
    rRed.b = 0;
    
    dRed.r = 194;
    dRed.g = 24;
    dRed.b = 7;
    
    grey.r = 66;
    grey.g = 13;
    grey.b = 9;

    
    sTime = ofRandom(0.1,3);

    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if(serial.available()){
        value = serial.readByte();
    }

    
//        value = ofMap(value,0,500,0,110);

        R = value * 1.5;


    
//    cout<<"pulse"<<endl;
    cout<<value<<endl;
    
    ofSetColor(0,0,0,10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  
    

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    

    if(value >= 90 && value < 95){
        
        bgm.play();
    
        for (float radius = R; radius > 0; radius -= 5){
    
            int r = ofMap(radius,0,R,violet.r, pink.r);
            int g = ofMap(radius,0,R,violet.g,pink.g);
            int b = ofMap(radius,0,R,violet.b,pink.b);
            
            ofSetColor(r,g,b);
        
            ofBeginShape();
            

            for(float angle = 0; angle < 360; angle += 10){

                float time = sTime * ofGetElapsedTimef() * value * 0.02;
                float radians = ofDegToRad(angle);

                float x = radius * cos(radians);
                float y = radius * sin(radians);


                float nx = x + ofMap(ofSignedNoise(x + mode1.x * 0.05 + time * 0.01 + value,y * 0.2 + mode1.y * 0.03 + time * 0.04 + value, time * 0.9), 0, 1, -20, 20);
                float ny = y + ofMap(ofSignedNoise(x + mode2.x * 0.03 + time * 0.05 + value,y * 0.1 + mode2.y * 0.07 + time * 0.03 + value, time * 0.7),0,1,-20,20);
        
                ofCurveVertex(nx, ny);
            }
            
            ofEndShape();
        }

    }
    
    
    
    if(value >= 95 && value <100){
        
        bgm.play();
        
        for (float radius = R; radius > 0; radius -= 5){
            
            int r = ofMap(radius,0,R,rblue.r, violet.r);
            int g = ofMap(radius,0,R,violet.g,rblue.g);
            int b = ofMap(radius,0,R,violet.b,rblue.b);

            ofSetColor(r,g,b);
            

            
            ofBeginShape();
            
            for(float angle = 0; angle < 360; angle += 10){
                
                float time = sTime * ofGetElapsedTimef() * value * 0.02;
                float radians = ofDegToRad(angle);
                
                float x = radius * cos(radians);
                float y = radius * sin(radians);
                
                
                float nx = x + ofMap(ofSignedNoise(x + mode1.x * 0.05 + time * 0.01 + value,y * 0.2 + mode1.y * 0.03 + time * 0.04 + value, time * 0.9), 0, 1, -20, 20);
                float ny = y + ofMap(ofSignedNoise(x + mode2.x * 0.03 + time * 0.05 + value,y * 0.1 + mode2.y * 0.07 + time * 0.03 + value, time * 0.7),0,1,-20,20);
                
                ofCurveVertex(nx, ny);
            }
            
            ofEndShape();
        }
        
    }
    
    
    
    if(value >= 100 && value < 105){
        
        bgm.play();
        
        for (float radius = R; radius > 0; radius -= 5){
            
            int r = ofMap(radius,0,R,rblue.r, sblue.r);
            int g = ofMap(radius,0,R,rblue.g,sblue.g);
            int b = ofMap(radius,0,R,rblue.b,sblue.b);
            
            ofSetColor(r,g,b);
            
            ofBeginShape();
            
            for(float angle = 0; angle < 360; angle += 10){
                
                float time = sTime * ofGetElapsedTimef() * value * 0.02;
                float radians = ofDegToRad(angle);
                
                float x = radius * cos(radians);
                float y = radius * sin(radians);
                
                
                float nx = x + ofMap(ofSignedNoise(x + mode1.x * 0.05 + time * 0.01 + value,y * 0.2 + mode1.y * 0.03 + time * 0.04 + value, time * 0.9), 0, 1, -20, 20);
                float ny = y + ofMap(ofSignedNoise(x + mode2.x * 0.03 + time * 0.05 + value,y * 0.1 + mode2.y * 0.07 + time * 0.03 + value, time * 0.7),0,1,-20,20);
                
                ofCurveVertex(nx, ny);
            }
            
            ofEndShape();
        }
        
    }
    
    
    
    if(value >= 105 && value <110){
        
        bgm.play();
        
        for (float radius = R; radius > 0; radius -= 5){
            
            int r = ofMap(radius,0,R,lgreen.r, kgreen.r);
            int g = ofMap(radius,0,R,lgreen.g,kgreen.g);
            int b = ofMap(radius,0,R,lgreen.b,kgreen.b);
            
            ofSetColor(r,g,b);
            
            ofBeginShape();
            
            for(float angle = 0; angle < 360; angle += 10){
                
                float time = sTime * ofGetElapsedTimef() * value * 0.02;
                float radians = ofDegToRad(angle);
                
                float x = radius * cos(radians);
                float y = radius * sin(radians);
                
                
                float nx = x + ofMap(ofSignedNoise(x + mode1.x * 0.05 + time * 0.01 + value,y * 0.2 + mode1.y * 0.03 + time * 0.04 + value, time * 0.9), 0, 1, -20, 20);
                float ny = y + ofMap(ofSignedNoise(x + mode2.x * 0.03 + time * 0.05 + value,y * 0.1 + mode2.y * 0.07 + time * 0.03 + value, time * 0.7),0,1,-20,20);
                
                ofCurveVertex(nx, ny);
            }
            
            ofEndShape();
        }
        
    }
    
    
    if(value >=110 && value < 115){
        
        bgm.play();
        
        for (float radius = R; radius > 0; radius -= 5){
            
            int r = ofMap(radius,0,R,oranger.r, yellow.r);
            int g = ofMap(radius,0,R,oranger.g,yellow.g);
            int b = ofMap(radius,0,R,oranger.b,yellow.b);
            
            ofSetColor(r,g,b);
            
            ofBeginShape();
            
            for(float angle = 0; angle < 360; angle += 10){
                
                float time = sTime * ofGetElapsedTimef() * value * 0.02;
                float radians = ofDegToRad(angle);
                
                float x = radius * cos(radians);
                float y = radius * sin(radians);
                
                
                float nx = x + ofMap(ofSignedNoise(x + mode1.x * 0.05 + time * 0.01 + value,y * 0.2 + mode1.y * 0.03 + time * 0.04 + value, time * 0.9), 0, 1, -20, 20);
                float ny = y + ofMap(ofSignedNoise(x + mode2.x * 0.03 + time * 0.05 + value,y * 0.1 + mode2.y * 0.07 + time * 0.03 + value, time * 0.7),0,1,-20,20);
                
                ofCurveVertex(nx, ny);
            }
            
            ofEndShape();
        }
        
    }
    
    if(value >=115 && value < 120){
        
        bgm.play();
        
        for (float radius = R; radius > 0; radius -= 5){
            
            int r = ofMap(radius,0,R,red.r,orange.r);
            int g = ofMap(radius,0,R,red.g,orange.g);
            int b = ofMap(radius,0,R,red.b,orange.b);
            
            ofSetColor(r,g,b);
            
            ofBeginShape();
            
            for(float angle = 0; angle < 360; angle += 10){
                
                float time = sTime * ofGetElapsedTimef() * value * 0.02;
                float radians = ofDegToRad(angle);
                
                float x = radius * cos(radians);
                float y = radius * sin(radians);
                
                
                float nx = x + ofMap(ofSignedNoise(x + mode1.x * 0.05 + time * 0.01 + value,y * 0.2 + mode1.y * 0.03 + time * 0.04 + value, time * 0.9), 0, 1, -20, 20);
                float ny = y + ofMap(ofSignedNoise(x + mode2.x * 0.03 + time * 0.05 + value,y * 0.1 + mode2.y * 0.07 + time * 0.03 + value, time * 0.7),0,1,-20,20);
                
                ofCurveVertex(nx, ny);
            }
            
            ofEndShape();
        }
        
    }
    
    if(value >= 120 && value < 125){
        
        
        bgm.play();
        
        for (float radius = R; radius > 0; radius -= 5){
            
            int r = ofMap(radius,0,R,rRed.r, red.r);
            int g = ofMap(radius,0,R,rRed.g,red.g);
            int b = ofMap(radius,0,R,rRed.b,red.b);
            
            ofSetColor(r,g,b);
            
            ofBeginShape();
            
            for(float angle = 0; angle < 360; angle += 10){
                
                float time = sTime * ofGetElapsedTimef() * value * 0.02;
                float radians = ofDegToRad(angle);
                
                float x = radius * cos(radians);
                float y = radius * sin(radians);
                
                
                float nx = x + ofMap(ofSignedNoise(x + mode1.x * 0.05 + time * 0.01 + value,y * 0.2 + mode1.y * 0.03 + time * 0.04 + value, time * 0.9), 0, 1, -20, 20);
                float ny = y + ofMap(ofSignedNoise(x + mode2.x * 0.03 + time * 0.05 + value,y * 0.1 + mode2.y * 0.07 + time * 0.03 + value, time * 0.7),0,1,-20,20);
                
                ofCurveVertex(nx, ny);
            }
            
            ofEndShape();
        }
        
    }
    
    if(value >= 125){
        
        bgm.play();
        
        for (float radius = R; radius > 0; radius -= 5){
            
            int r = ofMap(radius,0,R,grey.r, dRed.r);
            int g = ofMap(radius,0,R,grey.g,dRed.g);
            int b = ofMap(radius,0,R,grey.b,dRed.b);
            
            ofSetColor(r,g,b);
            
            ofBeginShape();
            
            for(float angle = 0; angle < 360; angle += 10){
                
                float time = sTime * ofGetElapsedTimef() * value * 0.02;
                float radians = ofDegToRad(angle);
                
                float x = radius * cos(radians);
                float y = radius * sin(radians);
                
                
                float nx = x + ofMap(ofSignedNoise(x + mode1.x * 0.05 + time * 0.01 + value,y * 0.2 + mode1.y * 0.03 + time * 0.04 + value, time * 0.9), 0, 1, -20, 20);
                float ny = y + ofMap(ofSignedNoise(x + mode2.x * 0.03 + time * 0.05 + value,y * 0.1 + mode2.y * 0.07 + time * 0.03 + value, time * 0.7),0,1,-20,20);
                
                ofCurveVertex(nx, ny);
            }
            
            ofEndShape();
        }
        
    }
    
    
    serial.flush();
    
    
    
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
//
//    if (key == '1'){
//        value = 155;
//    }
//    if (key == '2'){
//        value = 60;
//    }
//    if (key == '3'){
//        value = 165;
//    }
//    if (key == '4'){
//        value = 180;
//    }
//    if (key == '5'){
//        value = 75;
//    }
//    if (key == '6'){
//        value = 80;
//    }
//    if (key == '7'){
//        value = 85;
//    }
//    if (key == '8'){
//        value = 90;
//    }
//    if (key == '9'){
//        value = 95;
//    }

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
