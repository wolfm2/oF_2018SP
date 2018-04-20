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

    //API
    std::string url = "https://api.darksky.net/forecast/9cfafc3a4acf5bceaf8fd34079970871/37.8267,-122.4233";
    json.open(url);
    
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
    
    //weather icons load
    iconRain.load("rain.png");
    iconSun.load("sun.png");
    iconCloudy.load("cloudy.png");
    
    //loading 5 carrots positions and images
    for(int i = 0; i < 5; i++){
        ofVec2f temp;
        temp.set(ofRandom(700), ofRandom(700));
        Carrot[i] = temp;
        cout << "position is "<<Carrot[i]<<endl;
        ofImage temp1;
        temp1.load("carrot.png");
        carrot[i] = temp1;
    }
    
    //loading 8 mashroons x and y and images
    for(int i = 0; i < 5; i++){
        ofVec2f temp;
        temp.set(ofRandom(700), ofRandom(700));
        Mashroom[i] = temp;
        ofImage temp1;
        temp1.load("mashroom.png");
        mashroom[i] = temp1;
    }
    
    //count how many carrots you eat, initial number is 0
    counter = 0;
    
    
    for(int i = 0; i < 5; i++){
        mSpeed[i] = ofRandom(0.2,1);
        float time = mSpeed[i] * ofGetElapsedTimef();
        mSpeed[i] = ofSignedNoise(time * 0.5) * 20.0;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    

    if(serial.available()){
        
        cout<<"begin: " << begin<<endl;
        cout <<"gameover: "<<gameOver<<endl;
        cout<<"win: "<<win <<endl;
        cout<<"counter: "<<counter<<endl;
        jumpMusic.play();
        
        

        value = serial.readByte();
        if(value == 3){
            yPos += offset;
        }
        if(value == 2){
            xPos += offset;
        }
        if(value == 1){
            yPos -= offset;
        }
        if(value == 4){
            xPos -= offset;
        }
        if(value == 5){
            frogMusic.play();
            for (int i = 0; i < 5; i ++) {
                if(ofDist(xPos, yPos, Carrot[i].x, Carrot[i].y) <= 100){
                    Carrot[i].x = ofRandom(700);
                    Carrot[i].y = ofRandom(700);
//                    frogMusic.play();
                    counter ++;
                }
            }
        }
    }
    
    
    for (int i = 0; i < 5; i ++) {
        if(ofDist(xPos, yPos, Mashroom[i].x, Mashroom[i].y) <= 60){
            xPos = -100;
            yPos = -100;
            gameOver = true;
            begin = false;
        }
    }
    
    
    if (counter >= 3) {
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
    ofSetColor(255, 255, 255);
    character.draw(xPos, yPos, 100, 100);
    
    
    
    for (int i = 0; i < 5; i ++) {
        
        if (i%2 == 0){
            if(counter > 1){
                Mashroom[i].x += mSpeed[i] * (counter - 0.5);
                }
                else{
                Mashroom[i].x += mSpeed[i];
                }
            if (Mashroom[i].x > ofGetWindowWidth() || Mashroom[i].x < 0){
                mSpeed[i] = -mSpeed[i];
            }}
        else{
            if(counter > 1){
                Mashroom[i].y += mSpeed[i] * (counter - 0.5);
            }
            else{
                Mashroom[i].y += mSpeed[i];
            }
            if (Mashroom[i].y > ofGetWindowHeight() || Mashroom[i].y < 0){
                mSpeed[i] = -mSpeed[i];
            }
        }
        
        
    }
    
    

    
    //API
    icon  = json["daily"]["icon"].asString();
    if(icon == "rain"){
        ofSetColor(255, 255, 255);
        iconRain.draw(0,0, 800, 800);
    }
    if(icon == "sun"){
        ofSetColor(255, 255, 255);
        iconSun.draw(0,0, 800, 800);
    }
    if(icon == "partly-cloudy-day"){
        ofSetColor(255, 255, 255);
        iconCloudy.draw(0, 0, 800, 800);
    }
    
    //draw all images
    if (!begin && !gameOver && !win) {
        start.draw(0, 0, 800, 800);
    }else{
        //draw carrot
            for (int i = 0; i < 5; i ++) {
                carrot[i].draw(Carrot[i], 50, 50);
            }
        //start button disappear
        start.draw(-100, -100, 0,0);
        for (int i = 0; i < 5; i ++) {
            mashroom[i].draw(Mashroom[i], 35, 35);
        }
    }
    if (gameOver) {
        ofSetColor(255, 255, 255, 70);
        ofDrawRectangle(0, 0, 800, 800);
        ofSetColor(206, 91, 77);
        overFont.drawString("GAME", 150, 400);
        overFont.drawString("OVER", 150, 500);
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
