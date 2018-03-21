#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     myFont.load("FW.ttf",50);
  
    ofSetFullscreen(true);
    
    video.setDeviceID(0);
    testMovie[0].load("tvtest2.mp4");
    testMovie[0].play();
    
    testMovie[1].load("tvtest3.mp4");
    testMovie[1].play();
    
    testMovie[2].load("tvtest4.mp4");
    testMovie[2].play();
    
    
    testMovie[3].load("tvtest8.mp4");
    testMovie[3].play();

    
    glitchStart = 0.1;
    
    serial.setup(0,9600);
    ofSetFrameRate(10);
    
    
    buffer.allocate(ofGetWidth(),ofGetHeight());
    postGlitch.setup(&buffer);
    
    
   
    
//    ofSetVerticalSync(true);
//    ofSetWindowShape(1024, 768);
//    ofSetWindowTitle("glitchtest");
//    ofSetFrameRate(60);
//    ofBackground(10, 10, 10);
    
    video.initGrabber(ofGetWidth(), ofGetHeight());
    
//    glitch1.load("tvglitch_1.gif");
    

    
    
//    sound
    soundplayer.load("tv-static-07.mp3");
    soundplayer.setLoop(true);
    soundplayer.setVolume(1.0);
    soundplayer.play();
    
//timer reset
    reset();

}
//--------------------------------------------------------------

void ofApp::reset() {
    startTime = (int)ofGetElapsedTimeMillis();
    preTime = (int)ofGetElapsedTimeMillis();
    nowTime = (int)ofGetElapsedTimeMillis();
    for (int i = 0; i < 144; i++) {
        for (int j = 0; j < 90; j++) {
            count[i][j] = j * 100 + ofRandom(0, 4000);
            p[i][j] = ofVec3f(i * 10, j * 10, 0);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
   
    
    string curFilename = "selfie.jpg";
    
    video.update();
    
    if(radius>=0 && radius< 200){
        testMovie[0].update();
        
    }else if(radius>=400 && radius<600){
        testMovie[1].update();
    
    
    }else if(radius>=800 && radius<1000){
        testMovie[2].update();
    }else if(radius==1023){
        testMovie[3].update();
    }
    
    ofBuffer file = ofBufferFromFile(curFilename, true);
    int fileSize = file.size();
    char * buffer = file.getData();
    
    int whichByte = (int) ofRandom(fileSize * glitchStart, fileSize);
    int whichBit = ofRandom(10);
    char bitMask = 1 << whichBit;
    
    buffer[whichByte] |= bitMask;
    
    ofBufferToFile(curFilename, file, true);
    
    
    //do something while there is more data
    while(serial.available()){
        char b= serial.readByte(); //read the signal from arduino once at a time
        cout<<b;
        if(b=='\n')
        {
            radius=ofToInt(buffer2);
            buffer2= "";
            
        }else{
            buffer2 +=b; // building up the string character by character
            
        }
        
    }
    
}
//
//


 
//    postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN,true);



//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    myFont.drawString("Hello",100,100);
   
    auto devs = video.listDevices();
    for(auto & d : devs) {
        std::cout << d.id << ": " << d.deviceName << " // " <<
        d.formats.size() << " formats" << std::endl;
        for(auto & f : d.formats) {
            std::cout << "  " << f.width << "x" << f.height << std::endl;
            for(auto & fps : f.framerates) {
                std::cout << "    " << fps << std::endl;
                
                
            }
        }
    }
    
    

//  glitch1.draw(0,0);
    

    
    if(radius>=200 && radius< 400){
        postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, true);
        postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, false);
        
    }else if(radius>=400 && radius <600){
        postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, false);
        postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, false);
        postGlitch.setFx(OFXPOSTGLITCH_NOISE, true);
    
    }else if(radius>=600 && radius < 800){
        postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, false);
        postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, true);
        postGlitch.setFx(OFXPOSTGLITCH_SHAKER, true);
    
    }else if(radius>=800 && radius < 1000){
        
        postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, false);
        postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, false);
        postGlitch.setFx(OFXPOSTGLITCH_SWELL, true);
        postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE, true);

        //        postGlitch.setFx(OFXPOSTGLITCH_TWIST, true);
        
    } else if(radius>=1000 && radius < 1000){
        
        postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, false);

        postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, true);
        
        postGlitch.setFx(OFXPOSTGLITCH_TWIST, true);
        postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE, true);
        postGlitch.setFx(OFXPOSTGLITCH_SWELL, true);
    
    }else if(radius == 1023){
        postGlitch.setFx(OFXPOSTGLITCH_SLITSCAN, false);
        postGlitch.setFx(OFXPOSTGLITCH_NOISE, false);
        postGlitch.setFx(OFXPOSTGLITCH_SHAKER, true);
        postGlitch.setFx(OFXPOSTGLITCH_SWELL, false);
        postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE, false);
        postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, false);
        postGlitch.setFx(OFXPOSTGLITCH_TWIST, false);
    
    
    
    }
    
   



//    postGlitch.generateFx();
//    buffer.draw(0,0);
    
    buffer.begin();
//
    

    //ofcam
//    ofSetColor(0);
//    ofFill();
//    ofRectangle(0,0,ofGetWidth(),ofGetHeight());
//    ofSetColor(255, 255, 255);
//    video.draw(0, 0, cam.getWidth()*2.0, cam.getHeight()*2.0);
    
    video.draw(0,0,ofGetWidth(), ofGetHeight());
    
        if(radius>=0 && radius<200){
        testMovie[0].play();

        testMovie[0].draw(0, 0, ofGetWidth(), ofGetHeight());
        testMovie[3].stop();
   
    }else if(radius>=400 &&radius <600){
        testMovie[1].play();
        testMovie[1].draw(0, 0, ofGetWidth(), ofGetHeight());
        testMovie[3].stop();
    
    
    }else if(radius>=800 &&radius <1000){
        testMovie[2].play();
        testMovie[2].draw(0, 0, ofGetWidth(), ofGetHeight());
        testMovie[3].stop();
    
    }else if (radius== 1023){
        testMovie[3].play();

        testMovie[3].draw(0, 0, ofGetWidth(), ofGetHeight());
        testMovie[0].stop();
        testMovie[1].stop();
        testMovie[2].stop();

    }

    
    buffer.end();
//
//

    
//    postGlitch.setFx(OFXPOSTGLITCH_NOISE, 400<radius);
//    
//    postGlitch.setFx(OFXPOSTGLITCH_SWELL, pressedKey2);
//    
//     postGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE, 300<radius);
//    
//    postGlitch.setFx(OFXPOSTGLITCH_TWIST, 800<radius);
//    
//     postGlitch.setFx(OFXPOSTGLITCH_SHAKER, radius<300);
    
    
//    postGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT, peessedKeyb);
//    
//    postGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE, peessedKeyg);
//    
//    postGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT, peessedKeyr);
    
    
    
   
    
    
//
    postGlitch.generateFx();
//
//    buffer.draw(0,0);
//
    
    
    float r= ofMap(radius,0,800,0,300);
    buffer.draw(0,0);

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'v'){
    
        glitch1.draw(0, 0);
    
    }
    
    if (key == 'r')
        reset();

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == '1'){
        pressedKey = !pressedKey;
    
    
    }
    if(key == '2'){
        pressedKey2= !pressedKey2;
    }
    
    if(key == 'r'){
        peessedKeyr= !peessedKeyr;
    
    
    }
    
    if(key == 'b'){
    
        peessedKeyb= !peessedKeyb;
        
    
    
    }
    
    
    if(key == 'g'){
        
        peessedKeyg= !peessedKeyg;
        
        
        
    }
    
    if(key == 'v'){
        
        peessedKeyv = !peessedKeyv;
        
    
    
    }

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
