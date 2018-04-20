#include "ofApp.h"
#include<iostream>
#include<string>
using namespace std;

int myByte;
int sensorRead;
//--------------------------------------------------------------
void ofApp::setup(){
    mySerial.setup("/dev/cu.usbmodem14411", 9600);
    ofSetWindowShape(1680, 1050);
    bk.load("bk.jpg");
    ofSetCircleResolution(220);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    //Title
    faceNavi3d.setup(OF_TTF_SERIF, 30, 0.3); // fontsize, font depthrate
    faceNavi3d.setup("Batang.ttf", 20, 0.3);
    
    face.setup("Batang.ttf", 64, 0.3);
    face.setLineHeight(face.getFontSize()*2);
    face.setLetterSpacing(0.1);
    face.setTextDirection(UL2_TEXT_DIRECTION_LTR, UL2_TEXT_DIRECTION_TTB); //right to left, top to bottom
    show.append(L"Human Microbiome \n");
    align=UL2_TEXT_ALIGN_V_TOP|UL2_TEXT_ALIGN_CENTER;
    strAlign="top-center[8]";
    strDirection="Left to Right (TTB)";
	
	renderingMode=true;
	bRotation=false;

    //Particle
   /* for(int i=0; i<1000; i++){
        particle myParticle;
        float vx=ofMap(ofNoise(ofGetElapsedTimef(),200), 0, 1, -100, 100);
        float vy=ofMap(ofNoise(ofGetElapsedTimef(),-200), 0,1, -100, 100);
        myParticle.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, vx, vy);
        myParticle.damping=ofRandom(0.01, 0.05);
        particles.push_back(myParticle);
    } */
    
    flute.load("Flute.wav");
    triangle.load("Triangle.wav");
    
    flute.setMultiPlay(true);
    triangle.setMultiPlay(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    //on every frame, we reset the forces, add in any forces on the particle
    //perform damping and then update
    
    for(int i=0; i<particles.size(); i++){
        particles[i].resetForce();
//        particles[i].addForce(0.04, 0.04);//gravity
        particles[i].addDampingForce();
        particles[i].update();
    }
    
    int myByte=mySerial.readByte();
    if(myByte<0){
        sensorRead=sensorRead;
    }else{
        sensorRead=myByte;
    }
    cout<<sensorRead<<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    //Draw background image
    bk.draw(ofGetWidth()/2-bk.getWidth()/2, ofGetHeight()/2-bk.getHeight()/2, 2048, 1536);
    
    //Draw title
    int w,h,x,y;
    x=50;
    y=50;
    //w=mouseX-x;
    //h=mouseY-y;
    w=500;
    h=100;
    
    ofSetColor(ofColor::deepSkyBlue, 100);
    ofNoFill();
    glPushMatrix();{
        if(renderingMode){
            light.enable();
            light.setPosition(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth());
        }
        if(bRotation){
            //Returns the bounding box of a string as a rectangle
            ofRectangle rc=face.getStringBoundingBox(show,x,y,w,h,align);
            glTranslatef(ofGetWidth()/2, 0, 0);
            glRotatef(ofGetElapsedTimef()*10,0,1,0);
            glTranslatef(x-rc.x-rc.width, 0,0);
        }

        if(renderingMode){
            ofSetColor(ofColor::deepSkyBlue, 100);
            face.draw3dString(show, x,y,0,w,h,align);
        }else{
            ofSetColor(ofColor::lightSkyBlue, 100);
            glPolygonMode(GL_FRONT, GL_FILL);
            face.draw3dString(show, x,y,0,w,h,align);
            glPolygonMode(GL_FRONT, GL_FILL);
        }
        light.disable();
        glDisable(GL_LIGHTING);
    }glPopMatrix();

/*    ofSetColor(ofColor::dimGray);
    ofNoFill();
    faceNavi3d.draw3dString("Rendering mode[Space]: "+ofToString(renderingMode?"Face":"Wire-frame"), 400,ofGetHeight()-80,10);
    faceNavi3d.draw3dString("Rotate [R]: "+ofToString(bRotation?"YES":"NO"), ofGetWidth()/2+200, ofGetHeight()-80, 10);
    faceNavi3d.draw3dString("Alignment-mode [key e]: "+ofToString(face.getAlignByPixel()?"Alignment by Pixel":"Optimized"),400 , ofGetHeight()-50,10);
    faceNavi3d.draw3dString("Visualize data on microbiome using light,sound and temperature sensor", 400, ofGetHeight()-20,10);
   */
    ofSetColor(ofColor::dimGray);
    ofNoFill();
        faceNavi3d.draw3dString("Click to see the health report [Space]",100 , ofGetHeight()-50,10);
    faceNavi3d.draw3dString("Visualize data on microbiome using light,sound and temperature sensor", 100, ofGetHeight()-20,10);
    
    // Draw Circle
    ofSetColor(0, 0, sensorRead, ofRandom(20,80));
    ofFill();
    float x0=ofMap(sin(ofGetElapsedTimef()), -1, 1, ofGetWidth()/2-150, ofGetWidth()/2+150);
    float y0=ofMap(ofNoise(ofGetElapsedTimef()/10), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x0, y0, ofNoise(ofGetElapsedTimef()/10,100)*50);
    
    float x1=ofMap(cos(ofGetElapsedTimef()), -1, 1, ofGetWidth()/2-150, ofGetWidth()/2+150);
    float y1=ofMap(ofNoise(ofGetElapsedTimef()/10, 500), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x1, y1, ofNoise(ofGetElapsedTimef()/10,200)*50);
    
    float x2=ofMap(ofNoise(ofGetElapsedTimef()/10, 300), -1, 1, ofGetWidth()/2-150, ofGetWidth()/2+150);
    float y2=ofMap(ofNoise(ofGetElapsedTimef()/10, -500), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x2, y2, ofNoise(ofGetElapsedTimef()/10,300)*50);
    
    float x3=ofMap(ofNoise(ofGetElapsedTimef()/10, 200), -1, 1, ofGetWidth()/2-150, ofGetWidth()/2+150);
    float y3=ofMap(ofNoise(ofGetElapsedTimef()/10, -200), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x3, y3, ofNoise(ofGetElapsedTimef()/10,400)*50);
    
    float x4=ofMap(ofNoise(ofGetElapsedTimef()/10, 600), -1, 1, ofGetWidth()/2-150, ofGetWidth()/2+150);
    float y4=ofMap(ofNoise(ofGetElapsedTimef()/10, -600), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x4, y4, ofNoise(ofGetElapsedTimef()/10,500)*50);
    
    float x9=ofMap(ofNoise(ofGetElapsedTimef()/10, 1000), -1, 1, ofGetWidth()/2-250, ofGetWidth()/2+50);
    float y9=ofMap(ofNoise(ofGetElapsedTimef()/10, -1000), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x9, y9, ofNoise(ofGetElapsedTimef()/10,500)*50);
    
    float x10=ofMap(ofNoise(ofGetElapsedTimef()/10, 1100), -1, 1, ofGetWidth()/2-250, ofGetWidth()/2+50);
    float y10=ofMap(ofNoise(ofGetElapsedTimef()/10, -1200), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x10, y10, ofNoise(ofGetElapsedTimef()/10,500)*50);
    
    ofSetColor(0,sensorRead,0, 40);
    
    float x5=ofMap(ofNoise(ofGetElapsedTimef()/10, 700), -1, 1, ofGetWidth()/2-150, ofGetWidth()/2+150);
    float y5=ofMap(ofNoise(ofGetElapsedTimef()/10, -700), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x5, y5, ofNoise(ofGetElapsedTimef()/10,600)*50);
    
    float x6=ofMap(ofNoise(ofGetElapsedTimef()/10, 700), -1, 1, ofGetWidth()/2-150, ofGetWidth()/2+150);
    float y6=ofMap(ofNoise(ofGetElapsedTimef()/10, -700), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x6, y6, ofNoise(ofGetElapsedTimef()/10,600)*50);
    
    float x7=ofMap(ofNoise(ofGetElapsedTimef()/10, 800), -1, 1, ofGetWidth()/2-150, ofGetWidth()/2+150);
    float y7=ofMap(ofNoise(ofGetElapsedTimef()/10, -800), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x7, y7, ofNoise(ofGetElapsedTimef()/10,700)*50);
    
    float x8=ofMap(ofNoise(ofGetElapsedTimef()/10, 900), -1, 1, ofGetWidth()/2-150, ofGetWidth()/2+150);
    float y8=ofMap(ofNoise(ofGetElapsedTimef()/10, -900), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x8, y8, ofNoise(ofGetElapsedTimef()/10,800)*50);
    
    float x11=ofMap(ofNoise(ofGetElapsedTimef()/10, 1300), -1, 1, ofGetWidth()/2-250, ofGetWidth()/2+50);
    float y11=ofMap(ofNoise(ofGetElapsedTimef()/10, -1300), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x11, y11, ofNoise(ofGetElapsedTimef()/10,500)*50);
    
    float x12=ofMap(ofNoise(ofGetElapsedTimef()/10, 1400), -1, 1, ofGetWidth()/2-250, ofGetWidth()/2+50);
    float y12=ofMap(ofNoise(ofGetElapsedTimef()/10, -1400), 0, 1, ofGetHeight()/2-150, ofGetHeight()/2+150);
    ofDrawCircle(x12, y12, ofNoise(ofGetElapsedTimef()/10,500)*50);
    
    //Draw membrane
    ofSetLineWidth(ofMap(ofNoise(ofGetElapsedTimef()/10), 0, 1, 0, 5));
    ofSetColor(0, ofRandom(50,150));
    ofNoFill();
    ofPushMatrix();
    ofScale(1.2, 1.2);
    ofTranslate(-129.6, -81);
    ofBeginShape();
    ofCurveVertex(613,316);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 100), 0, 1, 700, 760),ofMap(ofNoise(ofGetElapsedTimef()/10, -100), 0, 1, 280, 323));
    ofCurveVertex(888,268);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 200), 0, 1, 960, 1020),ofMap(ofNoise(ofGetElapsedTimef()/10, -200), 0, 1, 300, 400));
    ofCurveVertex(1036,419);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 300), 0, 1, 970, 1100),ofMap(ofNoise(ofGetElapsedTimef()/10, -300), 0, 1, 480, 550));
    ofCurveVertex(1011,623);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 400), 0, 1, 900, 960),ofMap(ofNoise(ofGetElapsedTimef()/10, -400), 0, 1, 580, 660));
    ofCurveVertex(846,679);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 500), 0, 1, 680, 750),ofMap(ofNoise(ofGetElapsedTimef()/10, -500), 0, 1, 600, 650));
    ofCurveVertex(605,596);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 600), 0, 1, 550, 630),ofMap(ofNoise(ofGetElapsedTimef()/10, -600), 0, 1, 400, 500));
    ofCurveVertex(613, 316);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 100), 0, 1, 700, 760),ofMap(ofNoise(ofGetElapsedTimef()/10, -100), 0, 1, 280, 323));
    ofCurveVertex(888,268);
    ofEndShape();
    ofPopMatrix();
    
    ofBeginShape();
    ofCurveVertex(613,316);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 100), 0, 1, 700, 760),ofMap(ofNoise(ofGetElapsedTimef()/10, -100), 0, 1, 280, 323));
    ofCurveVertex(888,268);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 200), 0, 1, 960, 1020),ofMap(ofNoise(ofGetElapsedTimef()/10, -200), 0, 1, 300, 400));
    ofCurveVertex(1036,419);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 300), 0, 1, 970, 1100),ofMap(ofNoise(ofGetElapsedTimef()/10, -300), 0, 1, 480, 550));
    ofCurveVertex(1011,623);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 400), 0, 1, 900, 960),ofMap(ofNoise(ofGetElapsedTimef()/10, -400), 0, 1, 580, 660));
    ofCurveVertex(846,679);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 500), 0, 1, 680, 750),ofMap(ofNoise(ofGetElapsedTimef()/10, -500), 0, 1, 600, 650));
    ofCurveVertex(605,596);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 600), 0, 1, 550, 630),ofMap(ofNoise(ofGetElapsedTimef()/10, -600), 0, 1, 400, 500));
    ofCurveVertex(613, 316);
    ofCurveVertex(ofMap(ofNoise(ofGetElapsedTimef()/10, 100), 0, 1, 700, 760),ofMap(ofNoise(ofGetElapsedTimef()/10, -100), 0, 1, 280, 323));
    ofCurveVertex(888,268);
    ofEndShape();
    
    //draw wave lines
    ofSetLineWidth(ofMap(ofNoise(ofGetElapsedTimef()/5,300), 0, 1, 0, 5));
    ofBeginShape();
    for(int i=0; i<5;i++){
        float x=ofMap(ofNoise(ofGetElapsedTimef()*i/20,-800), 0, 1, ofGetWidth()/2-600, ofGetWidth()/2+600);
        float y=ofMap(ofNoise(ofGetElapsedTimef()*i/20,1000), 0, 1, ofGetHeight()/2-100, ofGetHeight()/2+200);
        ofCurveVertex(x, y);
    };
    ofEndShape();
    
    ofBeginShape();
    for(int i=0; i<5;i++){
        float x=ofMap(ofNoise(ofGetElapsedTimef()*i/20,800), 0, 1, ofGetWidth()/2-400, ofGetWidth()/2+300);
        float y=ofMap(ofNoise(ofGetElapsedTimef()*i/20,-1000), 0, 1, ofGetHeight()/2-300, ofGetHeight()/2);
        ofCurveVertex(x, y);
    };
    ofEndShape();
    
    ofBeginShape();
    for(int i=0; i<5;i++){
        float x=ofMap(ofNoise(ofGetElapsedTimef()*i/20,900), 0, 1, ofGetWidth()/2-600, ofGetWidth()/2+100);
        float y=ofMap(ofNoise(ofGetElapsedTimef()*i/20,-9000), 0, 1, ofGetHeight()/2-200, ofGetHeight()/2+300);
        ofCurveVertex(x, y);
    };
    ofEndShape();
    
    ofBeginShape();
    for(int i=0; i<5;i++){
        float x=ofMap(ofNoise(ofGetElapsedTimef()*i/20,1100), 0, 1, ofGetWidth()/2, ofGetWidth()/2+400);
        float y=ofMap(ofNoise(ofGetElapsedTimef()*i/20,-1100), 0, 1, ofGetHeight()/2, ofGetHeight()/2+200);
        ofCurveVertex(x, y);
    };
    ofEndShape();
    
    ofSetLineWidth(ofMap(ofNoise(ofGetElapsedTimef()/10,400), 0, 1, 0, 5));
    
    ofBeginShape();
    for(int i=0; i<5;i++){
        float x=ofMap(ofNoise(ofGetElapsedTimef()*i/20,1200), 0, 1, ofGetWidth()/2-600, ofGetWidth()/2-100);
        float y=ofMap(ofNoise(ofGetElapsedTimef()*i/20,-1200), 0, 1, ofGetHeight()/2-400, ofGetHeight()/2);
        ofCurveVertex(x, y);
    };
    ofEndShape();
    
    ofSetLineWidth(ofMap(ofNoise(ofGetElapsedTimef()/10,100), 0, 1, 0, 5));
    ofPushMatrix();
    ofTranslate(500, 800);
    ofRotateZ(-60);
    ofBeginShape();
    for (int i = 0; i < 300; i++){
        float x = i;
        float noise = ofNoise(i/100.0);
        float y = ofMap(noise, 0,1, 0, 100);
        ofCurveVertex(x,y);
    }
    ofEndShape();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(400, 400);
    ofRotateZ(30);
    ofBeginShape();
    for (int i = 0; i < 300; i++){
        float x = i;
        float noise = ofNoise(i/100.0,100);
        float y = ofMap(noise, 0,1, 0, 100);
        ofCurveVertex(x,y);
    }
    ofEndShape();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(1000, 400);
    ofRotateZ(100);
    ofBeginShape();
    for (int i = 0; i < 600; i++){
        float x = i;
        float noise = ofNoise(i/200.0,200);
        float y = ofMap(noise, 0,1, 0, 100);
        ofCurveVertex(x,y);
    }
    ofEndShape();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(900, 200);
    ofRotateZ(40);
    ofBeginShape();
    for (int i = 0; i < 500; i++){
        float x = i;
        float noise = ofNoise(i/130.0,300);
        float y = ofMap(noise, 0,1, 0, 100);
        ofCurveVertex(x,y);
    }
    ofEndShape();
    ofPopMatrix();
    
    ofSetLineWidth(ofMap(ofNoise(ofGetElapsedTimef()/5,200), 0, 1, 0, 5));
    
    ofPushMatrix();
    ofTranslate(650, 400);
    ofRotateZ(-50);
    ofBeginShape();
    for (int i = 0; i < 400; i++){
        float x = i;
        float noise = ofNoise(i/150.0,300);
        float y = ofMap(noise, 0,1, 0, 100);
        ofCurveVertex(x,y);
    }
    ofEndShape();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(500, 300);
    ofRotateZ(40);
    ofBeginShape();
    for (int i = 0; i < 450; i++){
        float x = i;
        float noise = ofNoise(i/180.0,400);
        float y = ofMap(noise, 0,1, 0, 100);
        ofCurveVertex(x,y);
    }
    ofEndShape();
    ofPopMatrix();
    
    ofSetLineWidth(0.1);

    //Draw Particles
    ofSetColor(sensorRead,0,0, 100);
    ofFill();
    for(int i=0; i<particles.size();i++){
        particles[i].draw();
        
        float vx=ofMap(ofNoise(ofGetElapsedTimef()*sensorRead/10, 100), 0,1, -100, 100);
        float vy=ofMap(ofNoise(ofGetElapsedTimef()*sensorRead/10, -100), 0,1, -100, 100);
        particles[i].setInitialCondition(ofGetWidth()/2, ofGetHeight()/2, vx , vy );
    }
    
    ofSetColor(255,255);
    
    flute.setSpeed(ofMap(sensorRead/100,0.01, 2.5,0.8,1.2));
    triangle.setSpeed(ofMap(sensorRead/100,0.01, 2.5,0.8,1.2));
    

//    flute.play();
    triangle.play();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
/*    switch(key){
        case' ':
            //renderingMode=!renderingMode;
 ofSetColor(ofColor::dimGray);
 ofNoFill();
 faceNavi3d.draw3dString("Click to see the health report [Space]",100 , ofGetHeight()-50,10);
 
            break;
        case'r':
            bRotation=!bRotation;
            break;
        case'e':
        case'E':
            face.setAlignByPixel(!face.getAlignByPixel());
            break;
    }
*/
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
