#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Arduino
    serial.listDevices();
    vector<ofSerialDeviceInfo>deviceList = serial.getDeviceList();
    serial.setup(1, 9600);
    
    //font
    overFont.load("overfont.TTF", 90);
    winFont.load("winfont.ttf", 90);
    
    //character's initial position
    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    offset = 14;
    
    // sounds load
    bgMusic.load("bgMusic.mp3");
    winMusic.load("winMusic.mp3");
    loseMusic.load("loseMusic.mp3");
    jumpMusic.load("jumpMusic.mp3");
    frogMusic.load("frogMusic.mp3");
    
    //images load
    backgroundImage.load("lawn.jpg");
    start.load("start.jpg");
    character.load("character.png");
    night.load("night.jpg");

    //loading 5 carrots positions and images
    for(int i = 0; i < 5; i++){
        ofVec2f temp;
        temp.set(ofRandom(700), ofRandom(700));
        Carrot[i] = temp;
        ofImage temp1;
        temp1.load("carrot.png");
        carrot[i] = temp1;
    }
    
    //loading 8 mashroons x and y and images
    for(int i = 0; i < 8; i++){
        ofVec2f temp;
        temp.set(ofRandom(700), ofRandom(700));
        Mashroom[i] = temp;
        ofImage temp1;
        temp1.load("mashroom.png");
        mashroom[i] = temp1;
    }
    
    //count how many carrots you eat, initial number is 0
    counter = 0;
    for(int i = 0; i < 8; i++){
        speed[i] = ofRandom(0.2,0.5);
        float time = speed[i] * timer;
        speed[i] = ofSignedNoise(time * 0.2) * 2.0;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //time
    timer = ofGetElapsedTimef();
    cout << "time is "<< timer << endl;
    if (timer > 10 && timer < 27)
        alpha = timer * 15;
    if(timer >= 29)
        alpha = 200 - (timer - 28) * 15;
    
    //sound
    ofSoundUpdate();
    if(serial.available()){
        jumpMusic.play();
        
    //arduino values
        value = serial.readByte();
        if(value == 2){
            yPos += offset;
        }
        if(value == 3){
            xPos += offset;
        }
        if(value == 4){
            yPos -= offset;
        }
        if(value == 1){
            xPos -= offset;
        }
        if(value == 5){
            frogMusic.play();
            for (int i = 0; i < 5; i ++) {
                if(ofDist(xPos, yPos, Carrot[i].x, Carrot[i].y) <= 100){
                    Carrot[i].x = ofRandom(700);
                    Carrot[i].y = ofRandom(700);
                    counter ++;
                }
            }
        }
    }
    
    for (int i = 0; i < 9; i ++) {
        if(ofDist(xPos, yPos, Mashroom[i].x, Mashroom[i].y) <= 40){
            xPos = -100;
            yPos = -100;
            gameOver = true;
            begin = false;
        }
    }
    
    if (counter >= 5) {
        win = true;
        begin = false;
    }
    
    //music
    if (begin && !bgMusic.isPlaying()) {
        bgMusic.play();
        winMusic.stop();
        loseMusic.stop();
    }
    
    if(win && !winMusic.isPlaying()){
        winMusic.play();
        bgMusic.stop();
        loseMusic.stop();
    }
    
    if (gameOver && !loseMusic.isPlaying()) {
        loseMusic.play();
        bgMusic.stop();
        winMusic.stop();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(255, 255, 255);
    backgroundImage.draw(0, 0, 800, 800);
    character.draw(xPos, yPos, 100, 100);

    for(int i = 0; i < 8; i ++){
        if(counter >= 1){
            Mashroom[i].x += speed[i] * ofRandom(0, 5);
            Mashroom[i].y -= speed[i] /2 + ofRandom(-5,3);
       
        }
        if(Mashroom[i].x > ofGetWidth() && Mashroom[i].y > ofGetHeight()){
            Mashroom[i].x = ofRandom(70);
            Mashroom[i].y = ofRandom(600);
            
        }
    }
    
    // canvas's boundary
    if (xPos > 800)
        xPos = 0;
    if(xPos < 0)
        xPos = 800;
    if(yPos > 800)
        yPos = 0;
    if(yPos < 0)
        yPos = 800;

    //draw all images
    if (!begin && !gameOver && !win) {
        start.draw(0, 0, 800, 800);
        alpha = 0;
        alpha1 = 0;
    }else{
        for (int i = 0; i < 5; i ++) {
            carrot[i].draw(Carrot[i], 50, 50);
        }
        //start button disappear
        start.draw(-100, -100, 0,0);
        for (int i = 0; i < 8; i ++) {
            mashroom[i].draw(Mashroom[i], 35, 35);
        }
    }
    
    //night image show
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,alpha);
    night.draw(0,0);
    ofSetColor(255, 255, 255, alpha1);
    alpha1 = 255;
    character.draw(xPos, yPos, 100, 100);
    
    if (gameOver) {
        ofSetColor(255, 255, 255, 70);
        ofDrawRectangle(0, 0, 800, 800);
        ofSetColor(206, 91, 77);
        overFont.drawString("GAME", 150, 400);
        overFont.drawString("OVER", 150, 500);
        alpha = 0;
    }

    
    // when you eat 3 carrots you win
    if (win) {
        ofSetColor(255, 255, 255, 90);
        ofDrawRectangle(0, 0, 800, 800);
        ofSetColor(107, 165, 17);
        winFont.drawString("~YOU~", 180, 400);
        ofSetColor(255, 95, 6);
        winFont.drawString("~~WIN~~", 110, 500);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    begin = true;
    
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
