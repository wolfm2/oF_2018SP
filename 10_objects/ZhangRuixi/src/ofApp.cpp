#include "ofApp.h"
#include "ofMain.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    
    for(int i=0; i <squareNum; i++){
       mySquare[i].setup();
        cout<<"number of class_set up"<<endl;
        
    };

}
//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0; i<squareNum; i++){
    mySquare[i].update();
           cout<<"number of class_update"<<endl;
    };

 
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<squareNum; i++){
    mySquare[i].draw();
           cout<<"number of class_draw"<<endl;
    };
}
