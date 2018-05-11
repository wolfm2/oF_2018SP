/* Have an explosion of particles by clicking on the screen. */
#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    myFont.load("mono.ttf",30);
    
    image.loadImage("back.png"); // load background image
    boat01.loadImage("boat01.png"); //load boat01 image
    boat02.loadImage("boat02.png"); //load boat02 image
    button.loadImage("button.png");
    microphone.loadImage("microphone.png");
    earth.loadImage("earth.png");
    song.load("2001space.mp3");//load <2001 space> music
    bomb.load("bomb.wav");
    
    phase = 0;
    ofSoundStreamSetup(1, 0);
    
    
    while(!song.isLoaded());
    song.play();
    nBandsToGet = 512; //play song
    
    while(!bomb.isLoaded());
    bomb.play();
    
    
    
    
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofSetCircleResolution(80);
    
    soundStream.printDeviceList();
    
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter = 0;
    drawCounter = 0;
    smoothedVol = 0.0;
    
    
    
    x = ofGetWindowWidth()/2;
    y = ofGetWindowHeight()/2;

	for (int i = 0; i < 8000; i++){
		particle myParticle;
		float vx = ofRandom(-4,4);
		float vy = ofRandom(-4,4);
		myParticle.setInitialCondition(300,300,vx, vy);
		// more interesting with diversity :)
		// uncomment this: 
		//myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
    
    decayRate = 0.05;
    minimumThreshold = 0.1;
    threshold = minimumThreshold;
}
float *val;

//--------------------------------------------------------------
void ofApp::update(){
    
    val = ofSoundGetSpectrum(nBandsToGet);
    
    if(Image_pos.x < 300){
        Image_pos.x ++;
    }
    
    if(Image_pos.y < 500){
        Image_pos.y ++;
        
    }//set first boat move speed
    
    if(Boat_pos.x < 1000){
        Boat_pos.x ++;
        
    }//set second boat move speed
   
    

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update

	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		//particles[i].addForce(0,0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
   
   
    ofSetColor(255, 0, 102);
    image.draw(0, 0, 1920, 1080);
    
    ofSetColor(255);
    myFont.drawString("John, the most intelligent robot in the world", 200, 50);
    //

    ofSetColor(255);
    ofDrawBitmapString(ofGetTimestampString("%Y-%m-%d-%H-%M"), 1200, 100);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 120);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 140);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 160);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 180);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 200);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 220);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 240);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 260);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 280);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 300);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 320);
    ofDrawBitmapString(ofGetTimestampString("%X"),1200, 340);
    //set the current time ont the right of screen
    
    
    ofSetColor(255, 0, 102);
    boat01.draw(Image_pos.x, Image_pos.y, 120, 80);
    
    boat02.draw(Boat_pos.x, 300, 240, 100);
	ofSetColor(244, 236, 255);
    earth.draw(1200, 500);
    
   

	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
    
    ofSetColor(0, 197, 144, 255);
    ofToString("");
    
    for(int i = 0; i < nBandsToGet; i++){
        ofDrawRectangle(50+i*2, ofGetHeight()-50, 2, (-1 * val[i]) * 5000);
        
    }
    
    ofPushMatrix();
    ofTranslate(x, y);
    ofScale(scaleW, scaleH);
    ofRotateX(rotateX);
    ofRotate(rotateY);
    ofRotate(rotateZ);
    boat01.draw(0 - boat01.getWidth()/2, 0 - boat01.getHeight()/2);
    ofPopMatrix();
    
    button.draw(700, 280, 50,50);
    
    if(count >= 1;drawString){
        ofSetColor(255);
        myFont.drawString("Hi, I am John", 50,200);
      
        
    }
    if(count >= 2){
        myFont.drawString("What can I do for you", 500, 200);
        
    }
    
        
        
        
    
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	for (int i = 0; i < particles.size(); i++){
		float vx = ofRandom(-10,10);
		float vy = ofRandom(-10,10);
		particles[i].setInitialCondition(mouseX,mouseY,vx, vy);	
	}
}



//--------------------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'x'){
        
        rotateX -= 2;
        
    }
    
    if(key == 'X'){
        rotateX += 2;
        
    }
    
    if(key == 'y'){
        rotateY -= 2;
        
    }
    
    if(key == 'Y'){
        
        rotateY += 2;
        
    }
    
    if(key == 'z'){
        rotateZ -= 2;
        
    }
    
    if(key == 'Z'){
        rotateZ += 2;
        
    }
    
    
    if(key == 't'){
        count ++;
    }
    
    if(key == 'r'){
        drawString = !drawString;
        
    }
    
    
    
}


//-------------------------------------------------------------------------

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    
    threshold = ofLerp(threshold, minimumThreshold, decayRate);
    
    if(rms > threshold) {
        // onset detected!
        threshold = rms;
    }
    
    
    
}

//-------------------------------------------------------------------------

void ofApp::audioOut(float * input, int bufferSize, int nChannels){
    
    
}



















