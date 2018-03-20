#include "ofApp.h"
#include <iostream>
#include <string>

string myString;
ofTrueTypeFont font;


int mouseX;
int mouseY;
ofSoundPlayer plink;
ofFbo fbo;



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(1400, 600);
    plink.load("plink.mp3");
    
    font.loadFont("Borgen.ttf", 12);
    
    std::string url = "https://data.cityofnewyork.us/resource/qadw-5h9s.json";
    
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful) {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    fbo.begin();
    ofClear(255,255,255, 0); //clear it of artifacts
    fbo.end();
    
    
    _ShakeCanvas.setup();
    _ShakeCanvas.startShake();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    int mouseX;
    int mouseY;
        
        
    if( ofGetFrameNum() % 5 == 0)
    {
        _ShakeCanvas.update();
    }
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

}


//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    font.loadFont("Borgen.ttf", 20);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/5);
    ofSetColor(255, 0, 0);
    font.drawString("LinkNYC: Bandwidth & Subscribers", 0, 0);
    font.drawString("March 2016 - March 2018", 0, 25);
    ofPopMatrix();
    
    
    fbo.begin();
    ofSetColor(30,30,30, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255,0,0);
    ofFill();
    ofDrawCircle(mouseX, mouseY, 8);
    ofFill();
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(0,0);
    
    ofPushStyle();
    _ShakeCanvas.begin();
    {
     

        //cumulative bandwidth wk 10/2/2017  79.11 = 632,880,000,000,000; 632,880 GB
        if(((abs(ofDist(mouseX,mouseY, 300, 300)) < 160)) && ((abs(ofDist(mouseX,mouseY, 300, 300)) > 140))) {
            plink.play();
            ofSetColor(255, 0, 0, 180);
            std::string str20  = json[96]["bandwidth_utilization_per_week_tb"].asString();
            float myint20 = std::stoi(str20);
            ofDrawCircle(300, 300, myint20*2);
            ofSetColor(255, 0, 0);
            ofDrawLine(411,193,600,193);
            ofSetColor(255, 0, 0);
            font.drawString("Week of 10/2/2017: 79.11 TB, 632,216 subscribers", 600, 198);
            
        } else{
            ofSetColor(100,149,237);
            std::string str20  = json[96]["bandwidth_utilization_per_week_tb"].asString();
            float myint20 = std::stoi(str20);
            ofDrawCircle(300, 300, myint20*2);
        }

        
        //cumulative bandwidth wk 2/26/2018  70.38 = 563,040,000,000,000; 563,040 GB
        if(((abs(ofDist(mouseX,mouseY, 300, 300)) < 140)) && ((abs(ofDist(mouseX,mouseY, 300, 300)) > 132))) {
            plink.play();
            ofSetColor(255, 0, 0, 180);
            std::string str25  = json[84]["bandwidth_utilization_per_week_tb"].asString();
            float myint25 = std::stoi(str25);
            ofDrawCircle(300, 300, myint25*2);;
            ofSetColor(255, 0, 0);
            ofDrawLine(420,237,600,237);
            ofSetColor(255, 0, 0);
            font.drawString("Week of 2/26/2018: 70.38 TB, 618,980 subscribers", 600, 242);
            
        } else{
            ofSetColor(25,25,112);
            std::string str25  = json[84]["bandwidth_utilization_per_week_tb"].asString();
            float myint25 = std::stoi(str25);
            ofDrawCircle(300, 300, myint25*2);
        }
        
        //cumulative bandwidth wk 1/29/2018  67.7 = 541,600,000,000,000; 541,600 GB
        ofSetColor(0,0,205);
        if(((abs(ofDist(mouseX,mouseY, 300, 300)) < 132)) && ((abs(ofDist(mouseX,mouseY, 300, 300)) > 128))) {
            plink.play();
            ofSetColor(255, 0, 0, 180);
            std::string str24  = json[0]["bandwidth_utilization_per_week_tb"].asString();
            float myint24 = std::stoi(str24);
            ofDrawCircle(300, 300, myint24*2);
            ofSetColor(255, 0, 0);
            ofDrawLine(429,320,600,320);
            ofSetColor(255, 0, 0);
            font.drawString("Week of 1/29/2018: 67.70 TB, 586,949 subscribers", 600, 325);
        } else{
            ofSetColor(0,0,205);
            std::string str24  = json[0]["bandwidth_utilization_per_week_tb"].asString();
            float myint24 = std::stoi(str24);
            ofDrawCircle(300, 300, myint24*2);
        }
        
        //cumulative bandwidth wk 9/4/2017  65.75 = 526,000,000,000,000; 526,000 GB
        ofSetColor(0,0,205);
        if(((abs(ofDist(mouseX,mouseY, 300, 300)) < 128)) && ((abs(ofDist(mouseX,mouseY, 300, 300)) > 125))) {
            plink.play();
            ofSetColor(255, 0, 0, 180);
            std::string str23  = json[57]["bandwidth_utilization_per_week_tb"].asString();
            float myint23 = std::stoi(str23);
            ofDrawCircle(300, 300, myint23*2);
            ofSetColor(255, 0, 0);
            ofDrawLine(400,375,600,375);
            ofSetColor(255, 0, 0);
            font.drawString("Week of 9/4/2017: 65.75 TB, 601,834 subscribers", 600, 380);
            
        } else{
            ofSetColor(30,144,255);
            std::string str19  = json[57]["bandwidth_utilization_per_week_tb"].asString();
            float myint19 = std::stoi(str19);
            ofDrawCircle(300, 300, myint19*2);
        }
        
        //cumulative bandwidth wk 1/1/2018  63.67 = 509,360,000,000,000; 509,360 GB
        ofSetColor(0,0,205);
        if(((abs(ofDist(mouseX,mouseY, 300, 300)) < 125)) && ((abs(ofDist(mouseX,mouseY, 300, 300)) > 120))) {
            plink.play();
            ofSetColor(255, 0, 0, 180);
            std::string str23  = json[99]["bandwidth_utilization_per_week_tb"].asString();
            float myint23 = std::stoi(str23);
            ofDrawCircle(300, 300, myint23*2);
            ofSetColor(255, 0, 0);
            ofDrawLine(370,401,600,402);
            ofSetColor(255, 0, 0);
            font.drawString("Week of 1/1/2018: 63.67 TB, 542,104 subscribers", 600, 408);
            
        } else{
            ofSetColor(0,0,255);
            std::string str23  = json[99]["bandwidth_utilization_per_week_tb"].asString();
            float myint23 = std::stoi(str23);
            ofDrawCircle(300, 300, myint23*2);
        }
        
        
        //cumulative bandwidth wk 8/7/2017  61.91 = 495,280,000,000,000; 495,280 GB
        ofSetColor(0,191,255);
        std::string str18  = json[5]["bandwidth_utilization_per_week_tb"].asString();
        float myint18 = std::stoi(str18);
        ofDrawCircle(300, 300, myint18*2);
        
        //cumulative bandwidth wk 12/4/2017  61.45 = 491,600,000,000,000; 491,600 GB
        ofSetColor(65,105,225);
        std::string str22  = json[5]["bandwidth_utilization_per_week_tb"].asString();
        float myint22 = std::stoi(str22);
        ofDrawCircle(300, 300, myint22*2);
        
        //cumulative bandwidth wk 11/6/2017  60.84 = 486,720,000,000,000; 486,720 GB
        ofSetColor(70,130,180);
        std::string str21  = json[80]["bandwidth_utilization_per_week_tb"].asString();
        float myint21 = std::stoi(str21);
        ofDrawCircle(300, 300, myint21*2);
        
        //cumulative bandwidth wk 7/10/2017  53.11 = 424,880,000,000,000; 424,880 GB
        ofSetColor(135,206,235);
        std::string str17  = json[80]["bandwidth_utilization_per_week_tb"].asString();
        float myint17 = std::stoi(str17);
        ofDrawCircle(300, 300, myint17*2);
    
        //cumulative bandwidth wk 5/15/2017  47.6 = 380,800,000,000,000; 380,800 GB
        ofSetColor(0,0,205);
        if(((abs(ofDist(mouseX,mouseY, 300, 300)) < 95)) && ((abs(ofDist(mouseX,mouseY, 300, 300)) > 80))) {
            plink.play();
            ofSetColor(255, 0, 0, 180);
            std::string str23  = json[86]["bandwidth_utilization_per_week_tb"].asString();
            float myint23 = std::stoi(str23);
            ofDrawCircle(300, 300, myint23*2);
            ofSetColor(255, 0, 0);
            ofDrawLine(330,388,600,388);
            ofSetColor(255, 0, 0);
            font.drawString("Week of 5/15/2017: 47.60 TB, 448,986 subscribers", 600, 393);
            
        } else{
            ofSetColor(173,216,230);
            std::string str15  = json[86]["bandwidth_utilization_per_week_tb"].asString();
            float myint15 = std::stoi(str15);
            ofDrawCircle(300, 300, myint15*2);
        }
        
        
        //cumulative bandwidth wk 4/3/2017  41.49 = 331,920,000,000,000; 331,920 GB
        ofSetColor(0,255,255);
        std::string str14  = json[78]["bandwidth_utilization_per_week_tb"].asString();
        float myint14 = std::stoi(str14);
        ofDrawCircle(300, 300, myint14*2);
        
        //cumulative bandwidth wk 6/12/2017  40.4 = 323,200,000,000,000; 323,200 GB
        ofSetColor(135,206,250);
        std::string str16  = json[100]["bandwidth_utilization_per_week_tb"].asString();
        float myint16 = std::stoi(str16);
        ofDrawCircle(300, 300, myint16*2);
        
        //cumulative bandwidth wk 3/6/2017  36.08 = 288,640,000,000,000; 288,640 GB
        ofSetColor(224,255,255);
        std::string str13  = json[91]["bandwidth_utilization_per_week_tb"].asString();
        float myint13 = std::stoi(str13);
        ofDrawCircle(300, 300, myint13*2);
        
        //cumulative bandwidth wk 2/6/2017  31.07 = 248,560,000,000,000; 248,560 GB
        ofSetColor(127,255,212);
        std::string str12  = json[32]["bandwidth_utilization_per_week_tb"].asString();
        float myint12 = std::stoi(str12);
        ofDrawCircle(300, 300, myint12*2);
        
        //cumulative bandwidth wk 12/12/2016  27.53 =220,240,000,000,000; 220,240 GB
        ofSetColor(64,224,208);
        std::string str10  = json[51]["bandwidth_utilization_per_week_tb"].asString();
        float myint10 = std::stoi(str10);
        ofDrawCircle(300, 300, myint10*2);
        
        //cumulative bandwidth wk 1/9/2017  26.75 = 214,000,000,000,000; 214,000 GB
        ofSetColor(175,238,238);
        std::string str11  = json[94]["bandwidth_utilization_per_week_tb"].asString();
        float myint11 = std::stoi(str11);
        ofDrawCircle(300, 300, myint11*2);
        
        //cumulative bandwidth wk 11/14/2016  26.27 = 210,160,000,000,000; 210160 GB
        ofSetColor(0,206,209);
        std::string str9  = json[13]["bandwidth_utilization_per_week_tb"].asString();
        float myint9 = std::stoi(str9);
        ofDrawCircle(300, 300, myint9*2);
        
        //cumulative bandwidth wk 10/17/2016  22.58 = 180,640,000,000,000; 180,640 GB
        ofSetColor(0,0,205);
        if(((abs(ofDist(mouseX,mouseY, 300, 300)) < 46)) && ((abs(ofDist(mouseX,mouseY, 300, 300)) > 30))) {
            plink.play();
            ofSetColor(255, 0, 0, 180);
            std::string str8  = json[63]["bandwidth_utilization_per_week_tb"].asString();
            float myint8 = std::stoi(str8);
            ofDrawCircle(300, 300, myint8*2);
            ofSetColor(255, 0, 0);
            ofDrawLine(330,330,600,330);
            ofSetColor(255, 0, 0);
            font.drawString("Week of 10/17/2016: 22.58 TB, 225,031 subscribers", 600, 335);
            
        } else{
            ofSetColor(32,178,170);
            std::string str8  = json[63]["bandwidth_utilization_per_week_tb"].asString();
            float myint8 = std::stoi(str8);
            ofDrawCircle(300, 300, myint8*2);
        }
        

        
        //cumulative bandwidth wk 9/19/2016  16.42 = 131,360,000,000,000; 131,360 GB
        ofSetColor(95,158,160);
        std::string str7  = json[89]["bandwidth_utilization_per_week_tb"].asString();
        float myint7 = std::stoi(str7);
        ofDrawCircle(300, 300, myint7*2);
        
        //cumulative bandwidth wk 8/21/2016  13.91 = 111,280,000,000,000; 111,280 GB
        ofSetColor(0,0,205);
        if(((abs(ofDist(mouseX,mouseY, 300, 300)) < 28)) && ((abs(ofDist(mouseX,mouseY, 300, 300)) > 15))) {
            plink.play();
            ofSetColor(255, 0, 0, 180);
            std::string str6  = json[71]["bandwidth_utilization_per_week_tb"].asString();
            float myint6 = std::stoi(str6);
            ofDrawCircle(300, 300, myint6*2);
            ofSetColor(255, 0, 0);
            ofDrawLine(321,314,600,314);
            ofSetColor(255, 0, 0);
            font.drawString("Week of 8/21/2016: 13.91 TB, 83,605 subscribers", 600, 319);
            
        } else{
            ofSetColor(0,139,139);
            std::string str6  = json[71]["bandwidth_utilization_per_week_tb"].asString();
            float myint6 = std::stoi(str6);
            ofDrawCircle(300, 300, myint6*2);
        }
        
        //cumulative bandwidth wk 7/25/2016  8.65 = 69,200,000,000,000; 69,200 GB
        ofSetColor(154,205,50);
        std::string str5  = json[44]["bandwidth_utilization_per_week_tb"].asString();
        float myint5 = std::stoi(str5);
        ofDrawCircle(300, 300, myint5*2);
        
        //cumulative bandwidth wk 6/27/2016  5.7 = 45,600,000,000,000; 45,600 GB
        ofSetColor(128,128,0);
        std::string str4  = json[81]["bandwidth_utilization_per_week_tb"].asString();
        float myint4 = std::stoi(str4);
        ofDrawCircle(300, 300, myint4*2);
        
        //cumulative bandwidth wk 5/30/2016  4.75 = 38,000,000,000,000; 38,000 GB
        ofSetColor(189,183,107);
        std::string str3  = json[33]["bandwidth_utilization_per_week_tb"].asString();
        float myint3 = std::stoi(str3);
        ofDrawCircle(300, 300, myint3*2);
        
        //cumulative bandwidth wk 5/2/2016  3.74 = 29,920,000,000,000; 29,920 GB
        ofSetColor(255,255,0);
        std::string str2  = json[62]["bandwidth_utilization_per_week_tb"].asString();
        float myint2 = std::stoi(str2);
        ofDrawCircle(300, 300, myint2*2);
        
        //cumulative bandwidth wk 4/4/2016  1.975 = 15,800,000,000,000; 158,00 GB
        ofSetColor(255,255,153);
        std::string str1  = json[21]["bandwidth_utilization_per_week_tb"].asString();
        float myint1 = std::stoi(str1);
        ofDrawCircle(300, 300, myint1*2);
        
        
        //small center circle (initial bandwidth usage)
        //cumulative bandwidth wk 3/7/2016  0.635
        if(abs(ofDist(mouseX,mouseY, 300, 300)) < 8){
            plink.play();
            ofSetColor(255, 0, 0, 150);
            std::string str4  = json[81]["bandwidth_utilization_per_week_tb"].asString();
            float myint4 = std::stoi(str4);
            ofDrawCircle(300, 300, myint4*2);
            ofSetColor(255, 0, 0, 150);
            ofDrawLine(300,300,600,300);
            ofSetColor(255, 0, 0);
            font.drawString("Week of 3/7/2016: 0.635 TB, 4,041 subscribers", 600, 305);
            
        } else{
            ofSetColor(255,255,204);
            std::string str4  = json[24]["bandwidth_utilization_per_week_tb"].asString();
            float myint4 = std::stoi(str4);
            ofDrawCircle(300, 300, myint4*2);
        }
    }
    
    
    _ShakeCanvas.end();
    ofPopStyle();
    
    //draw shake canvas
    _ShakeCanvas.draw();
    



    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mouseX = x;
    mouseY = y;

    cout << x << endl;
    cout << y << endl;
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
