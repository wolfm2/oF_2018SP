#include "ofApp.h"
#include <iostream>
#include <string>
using namespace std;

ofPoint pos;
float catchUp=0.02f;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1280, 720);
    ofSetCircleResolution(220);
    
    ofSetFrameRate(60);
    ofSetLogLevel(OF_LOG_NOTICE);
    
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.setFPS(30.0);
    box2d.registerGrabbing();
    box2d.createBounds();
    
    particles.setup(box2d.getWorld(), 3000, 20, 1.5, 5, ofColor::cyan);
    particles.setParticleFlag(b2_elasticParticle);
    
    //drop pot outline

    potLine.addVertex(ofVec2f(651,277));
    potLine.addVertex(ofVec2f(651,376));
    potLine.addVertex(ofVec2f(681,406));
    potLine.addVertex(ofVec2f(823,406));
    potLine.addVertex(ofVec2f(853,376));
        potLine.addVertex(ofVec2f(853,277));

    potEdge.addVertexes(potLine);
    potEdge.create(box2d.getWorld());
   
//    myBluetooth.setup("/dev/cu.HC-05-DevB", 9600);
    //load image
    foam.load("foam.png");
    gelatin.load("gelatin.png");
    glycerin.load("glycerin.png");
    light.load("light.png");
    mould.load("mould.png");
    pigment.load("pigment.png");
    pot.load("pot.png");
    soap.load("soap.png");
    spoon.load("spoon.png");
    stove.load("stove.png");
    table.load("table.png");
    water.load("water.png");
    drop.load("drop.png");
    spoon2.load("spoon2.png");
    mould2.load("mould2.png");
    wave.load("wave.png");
    spoon3.load("spoon3.png");

//load sound
    liquid.load("liquid.wav");
    vibration.load("vibration.wav");
    boiling.load("water.mp3");
    
    liquid.setMultiPlay(true);
    vibration.setMultiPlay(true);
    boiling.setMultiPlay(true);
    
    wWidth=640;
    wHeight=480;
    
    hue=0;
    sat=0;
    val=0;
    
    wCam.initGrabber(wWidth, wHeight);
    
    origOutput.allocate(wWidth, wHeight);
    origOutputHSV.allocate(wWidth, wHeight);
    
    hueOutput.allocate(wWidth, wHeight);
    satOutput.allocate(wWidth, wHeight);
    briOutput.allocate(wWidth, wHeight);
    
    lockedOnPixels= new unsigned char [wWidth*wHeight];
    lockedOnTexture.allocate(wWidth, wHeight, GL_LUMINANCE);
    
    font.load("Batang.ttf",20);
    font2.load("organic.ttf",80);
}
 string name="CITIZEN SCIENTIST";
bool colorState=false;
ofColor circle(0,255,0);
bool step0=true, step1, step2, step3, step4, step5, step6, step7, step8;

float soapRz, soapY, dropY, potRz, potY, potX, stoveY, foamRz;

//--------------------------------------------------------------
void ofApp::update(){
    wCam.update();
    if(wCam.isFrameNew()){
        origOutput.setFromPixels(wCam.getPixels().getData(), wWidth, wHeight);
        
        origOutputHSV=origOutput;
        origOutputHSV.convertRgbToHsv();
        
         //Copies the different channels of the ofxCvColorImage into 3 different grayscale images using the R G and B channels of the ofxCvColorImage, here is h, s, v
        origOutputHSV.convertToGrayscalePlanarImages(hueOutput, satOutput, briOutput);
        
        //Flag whether the image pixel data has changed so that the ofTexture can be updated
        hueOutput.flagImageChanged();
        satOutput.flagImageChanged();
        briOutput.flagImageChanged();
        
        unsigned char * huePixels=hueOutput.getPixels().getData();
        unsigned char * satPixels=satOutput.getPixels().getData();
        unsigned char * briPixels=briOutput.getPixels().getData();
        
        for(int i=0; i<(wWidth*wHeight); i++){
            if((huePixels[i]> 42 && huePixels[i]<= 85)&& (satPixels[i]>=140)){
                lockedOnPixels[i]=255;
            }else{
                lockedOnPixels[i]=0;
            }
        }
        lockedOnTexture.loadData(lockedOnPixels, wWidth, wHeight, GL_LUMINANCE);
        lockedOutput.setFromPixels(lockedOnPixels, wWidth, wHeight);
        
        lockedContours.findContours(lockedOutput, 160, (wWidth*wHeight)/3, 1, false);
        if (lockedContours.blobs.size() > 0){
        int x=lockedContours.blobs.at(0).centroid.x;
        int y=lockedContours.blobs.at(0).centroid.y;
            if(circle.g>100 && circle.r<100 && circle.b<100){
                circle=origOutput.getPixels().getColor(x+y*wWidth);
            }            colorState=true;
        }else{
            colorState=false;
        }
    }
    if(step1 && dropY<77){
        soapRz+=0.7;
        soapY-=0.7;
        dropY++;
    }
    
    if(step8 && potY<5){
        potRz+=4;
        potY+=1;
        potX+=8;
    }
    
    if(step7){
        foamRz++;
    }
    
    
    
    pos.x +=catchUp*(mouseX-pos.x);
    pos.y +=catchUp*(mouseY-pos.y);
    
    box2d.update();
}
int start, end;
 time_t epoch;
//--------------------------------------------------------------
void ofApp::draw(){
//draw background
    ofColor bg_up(226,234,217);
    ofColor bg_down(199,176,114);
    ofBackgroundGradient(bg_down, bg_up, OF_GRADIENT_LINEAR);
    
//draw name
    ofSetColor(127, 143, 134);
    if(step0){
    float fontWidth=font.stringWidth(name);
    float fontHeight=font.stringHeight(name);
    font2.drawString(name, ofGetWindowWidth()/2-2*fontWidth, ofGetWindowHeight()/2+2.5*fontHeight);
    }
//draw time on canvas
    struct tm* timeinfo; //* points to a structure
    bool currentTime=true;
    if(currentTime){
        time(&epoch); //& gets the variable address
    }
    timeinfo=localtime(&epoch);
    font.drawString(asctime(timeinfo), 50, 100);
    
    ofSetColor(255);
    //testing blob
//    wCam.draw(0, 0);
//    origOutputHSV.draw(640,0);
//    lockedContours.draw();
//
//    lockedOnTexture.draw(0,480);
//    hueOutput.draw(640,480);
    
    //start bioplastic tutorial
    ofSetColor(255);
    light.draw(900,0, 168, 199);
    
    
    for(int i=0; i<boxes.size(); i++){
        ofFill();
        ofSetColor(219, 236, 228);
        boxes[i].get()->draw();
    }
    
    particles.draw();
    
    if(step1){
    table.draw(ofGetWidth()/2-423,300,846,364);
    ofPushMatrix();
        ofTranslate(600, 180);
        ofRotateZ(-soapRz);
        soap.draw(0, 0, 125,182);
    ofPopMatrix();
    ofPushMatrix();
        ofTranslate(0, dropY);
        drop.draw(570, 200, 62/2,79/2);
    ofPopMatrix();
    mould.draw(510,231,135.5,188);
        if(dropY==77){
            mould2.draw(510,231,135.5,188);
        }
    }
    if(step2){
    table.draw(ofGetWidth()/2-423,300,846,364);
    pot.draw(650,278, 338, 130);
    gelatin.draw(pos.x,pos.y, 134/2, 145/2);
    particles.draw();
    }
    
    if(step3){
    table.draw(ofGetWidth()/2-423,300,846,364);
    glycerin.draw(532,274, 127/2, 250/2);
    pot.draw(650,278, 338, 130);
    spoon2.draw(pos.x, pos.y, 217/2, 54/2);
    particles.draw();
    }
    
    if(step4){
    table.draw(ofGetWidth()/2-423,300,846,364);
    water.draw(500,284.4, 149/2, 206/2);
    pot.draw(650,278, 338, 130);
    spoon2.draw(pos.x,pos.y, 217/2, 54/2);
    particles.draw();
    }
    if(step5){
    pigment.draw(ofGetWindowWidth()/2-406/2, ofGetWindowHeight()/2-406/2, 406, 406);
    if(colorState){
        ofSetColor(circle);
        
    }else{
        ofSetColor(0);
    };
    ofDrawCircle(ofGetWindowWidth()/2-41, ofGetWindowHeight()/2+41, 153);
    }
    
    if(step6){
    table.draw(ofGetWidth()/2-423,300,846,364);
    stove.draw(ofGetWindowWidth()/2-120,ofGetWindowHeight()/2-150, 348, 220);
        ofColor r(123,123,123);
        ofColor lerp=bg_up.lerp(r,ofNoise(ofGetElapsedTimef()));
        ofPushStyle();
        ofSetColor(lerp);
        wave.draw(590,100, 94, 115);
        ofPopStyle();
        
    int end=epoch;
        if((int)(end-start)==300){
            vibration.setSpeed(1.5);
            vibration.play();
            myBluetooth.writeByte('a');
        }
    }
    
    if(step7){
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2-100, ofGetWindowHeight()/2+50);
    ofRotateZ(foamRz);
    foam.draw(0-foam.getWidth()/2, 0-foam.getHeight()/2, 356, 356);
    ofPopMatrix();
    spoon3.draw(pos.x, pos.y,56, 231);
    }
    
    if(step8){
    table.draw(ofGetWidth()/2-423,300,846,364);
    mould.draw(450, 221, 135.5, 188);
        pot.draw(600,280, 338,130);
//    ofPushMatrix();
//    ofRotateZ(-potRz);
//    ofTranslate(550-potX, 308-potY);
//    pot.draw(0, 0, 338, 130);
//    ofPopMatrix();
        if(potY==5){
            myBluetooth.writeByte(step8);
        }
}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == '1'){
            step1=true;
            step0=false;
    }
    if(key =='2'){
            step2=true;
            step1=false;
            myBluetooth.writeByte(step1);
        float radius=ofRandom(20,40);
        particles.setParticleFlag(b2_elasticParticle);
        ofColor color;
        color.setHsb(ofRandom(25,42), 127, 255);
        particles.createCircleParticleGroup(ofVec2f(mouseX, mouseY), radius, color);
    }
    if(key =='3'){
            step3=true;
            step2=false;
            myBluetooth.writeByte(step2);
        float w = ofRandom(20, 40);
        float h= ofRandom(20,40);
        particles.setParticleFlag(b2_elasticParticle);
        ofColor color;
        color.setHsb(ofRandom(170,205), 127, 255);
        particles.createRectParticleGroup(ofVec2f(mouseX, mouseY), ofVec2f(w,h), color);
    }
    if(key == '4'){
        step4=true;
        step3=false;
        myBluetooth.writeByte(step3);
        float w=ofRandom(20,30);
        float h=ofRandom(20,30);
        boxes.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
        boxes.back().get()->setPhysics(4.0, 0.53, 0.1);
        boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w,h);

        liquid.setSpeed(1.2);
        liquid.play();
    }
    if(key =='5'){
        step5=true;
        step4=false;
        myBluetooth.writeByte(step4);
        liquid.stop();
        potLine.clear();
        particles.destroy();
        potEdge.clear();
        boxes.clear();
        
    }
    
    if(key =='6'){
            step6=true;
            step5=false;
            start=epoch;
             myBluetooth.writeByte(step5);
        boiling.play();
    }
    if(key =='7'){
            step7=true;
            step6=false;
             myBluetooth.writeByte(step6);
        boiling.stop();
    }
    if(key == '8'){
            step8=true;
            step7=false;
            myBluetooth.writeByte(step7);
    }
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
