#include "ofApp.h"
#include "ofxJSON.h"
#include <iostream>
#include <string>

//GLOBAL VARIABLES:

ofImage toneIcon;
ofImage logo;


using namespace std;
int main();
int joy_circle = 0;
float value = 0;
int sentence_id = 0;
int size = 0;
bool joyd;

float score = 0;

void update(int score);

ofTrueTypeFont myfont;
ofTrueTypeFont lightfont;
ofTrueTypeFont mediumfont;
string enterString;
string tone_id;

string joys;
ofSoundPlayer beeb;





//--------------------------------------------------------------
void ofApp::setup(){
    


    std::string file = "tweets.json";
    
    myfont.load("HelveticaNeue.ttf",30);
    
    lightfont.load("HelveticaLight.ttf",10);
    
    mediumfont.load("HelveticaLight.ttf",20);
    
    toneIcon.load ("toneanalyzer.png");
    
    logo.load("twitterlogo.png");
    
    beeb.load("beeb.wav");
    
    
    // Now parse the JSON
    bool parsingSuccessful = result.open(file);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << result.getRawString();
        
        // now write pretty print
        if (!result.save("example_output_pretty.json", true))
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written unsuccessfully.";
        }
        else
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written successfully.";
        }
        
        // now write without pretty print
        if (!result.save("example_output_fast.json", false))
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written unsuccessfully.";
        }
        else
        {
            ofLogNotice("ofApp::setup") << "example_output_pretty.json written successfully.";
        }
        
    }
    else
    {
        ofLogError("ofApp::setup")  << "Failed to parse JSON" << endl;
    }

    ofSetBackgroundColor(239);
    ofSetFrameRate(40);
    
    
//    ofBackground(39);
//    ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
    
   
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    //TONES IN RIGHT CORNER:
    
    ofSetColor(248,232,160); //JOY color
//    ofDrawCircle(830, 600, 100, 30); //Joy circle
    ofSetColor(70, 74, 81);
    mediumfont.drawString(eventString, 870, 715);

    
    
    //    CIRCLE THAT CHANGES COLOR
    ofSetColor(change);
    ofDrawCircle(830, 600, 100,  30);


   
    
    
    ofSetColor(255);
    toneIcon.draw(50,600);
  
    logo.draw(50,60);
    
    ofSetColor(0);
    myfont.drawString("#METOO", 100,100);
    ofSetColor(70, 74, 81);
    lightfont.drawString("Analyzing the emotions from the most recent tweets", 100,130);
    lightfont.drawString("Analyzed with IBM Watson Tone Analyzer", 60,720);
    

    
    ofSeedRandom(39);
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
//    Making a definition for tonenames and drawing it on the canvas
//    ofSetColor(0);
//    myfont.drawString("Tone: ", 100, 100);
//    std::string tone_name = result["sentences_tone"][8]["tones"][0]["tone_name"].asString();
//    myfont.drawString(tone_name, 250, 100);
    
    int sentence_id = result["sentences_tone"][sentence_id]["tones"][sentence_id].asInt();
   
    //    GETTING DATA FROM JSON FILE:
    std::stringstream ss;
    

    ss << "tone_name      = " << result["sentences_tone"][0]["tones"][0]["tone_name"].asString() << std::endl;
    
    ss << "score         = " << result["sentences_tone"][0]["tones"][0]["score"].asString() <<
    std::endl;

    //WRITING VALUES FROM JSON FILE:
//     ofDrawBitmapString(ss.str(), 50, 50);

    
    
    //Making functions for the graphics
    
    std::string tone_id = result["sentences_tone"][sentence_id]["tones"][sentence_id]["tone_id"].asString();

    std::string score = result["sentences_tone"][sentence_id]["tones"][sentence_id]
        ["score"].asString();
    
    
    string joys = result["sentences_tone"][2]["tones"][0]["tone_tone"].asString();
    
   
    
//    document_tone.tones[0].tone_name

//    for (int score = 0.787368; score < 0.1; score++) {
//        ofSetColor(10, 10, 90);
//        ofDrawCircle(30, 100, 30);
//    }

    
    
//    JOY
    
    float radius = 230;
    for (int i = 0; i < 19; i++) {
    
    float size = ofRandom(25.f);
    
    float deg = ofRandom(360.f) + ofGetFrameNum() * ofMap(size, 0, 20, 0.8, 0.15);
    float noise_value = ofMap(ofNoise(i * 0.5, ofGetFrameNum() * 0.005), 0, 1, 0.8, 1.2);
    float x = radius * noise_value * cos(deg * DEG_TO_RAD);
    float y = radius * noise_value * sin(deg * DEG_TO_RAD);
    ofPoint point = ofPoint(x, y);
    
    //YEllOW JOY COLOR
    ofColor joycolor;
    joycolor.setHsb(290, 160, 619);
        
        
    
    for (int score = 0.515079; score <1; score++) {
        ofSetColor(joycolor, 139);
        ofDrawCircle(point, size);
        
    }
    
     
    }
    
//    SADNESS
    
            float blueradius = 230;
            for (int i = 0; i < 23; i++) {
            
            float size = ofRandom(25.f);
            
            float deg = ofRandom(360.f) + ofGetFrameNum() * ofMap(size, 0, 20, 0.8, 0.15);
            float noise_value = ofMap(ofNoise(i * 0.5, ofGetFrameNum() * 0.005), 0, 1, 0.8, 1.2);
            float bluex = blueradius * noise_value * cos(deg * DEG_TO_RAD);
            float bluey = blueradius * noise_value * sin(deg * DEG_TO_RAD);
            ofPoint bluepoint = ofPoint(bluex, bluey);
        
                ofColor sadnesscolor;
                sadnesscolor.setHsb(140, 160, 619); //blue
        
        for (int score = 0.589773; score <1; score++) {
            ofSetColor(sadnesscolor, 139);
            ofDrawCircle(bluepoint, size);
            
            ofDrawCircle(200, 600, 20);
        }
        
            }
    
//    ANGER
    
        float redradius = 230;
        for (int i = 0; i < 20; i++) {
        
        float size = ofRandom(25.f);
        
        float deg = ofRandom(360.f) + ofGetFrameNum() * ofMap(size, 0, 20, 0.8, 0.15);
        float noise_value = ofMap(ofNoise(i * 0.5, ofGetFrameNum() * 0.005), 0, 1, 0.8, 1.2);
        float x = redradius * noise_value * cos(deg * DEG_TO_RAD);
        float y = redradius * noise_value * sin(deg * DEG_TO_RAD);
        ofPoint point = ofPoint(x, y);
    
            ofColor angercolor;
            angercolor.setHsb(256, 239, 239);

            
            for (int score = 0.820455; score <1; score++) {
               ofSetColor(angercolor, 139);
                ofDrawCircle(point, size);
            }
        }
    
//    FEAR
    
    float purpleradius = 230;
    for (int i = 0; i < 20; i++) {
        
        float size = ofRandom(25.f);
        
        float deg = ofRandom(360.f) + ofGetFrameNum() * ofMap(size, 0, 20, 0.8, 0.15);
        float noise_value = ofMap(ofNoise(i * 0.5, ofGetFrameNum() * 0.005), 0, 1, 0.8, 1.2);
        float x = purpleradius * noise_value * cos(deg * DEG_TO_RAD);
        float y = purpleradius * noise_value * sin(deg * DEG_TO_RAD);
        ofPoint point = ofPoint(x, y);
        
        ofColor fearcolor;
        fearcolor.setHsb(200, 160, 619);
        
        
        for (int score = 0.931034; score <1; score++) {
            ofSetColor(fearcolor, 139);
            ofDrawCircle(point, size);
        }
    }
    
    //    Tentative
    
    float greenradius = 230;
    for (int i = 0; i < 20; i++) {
        
        float size = ofRandom(25.f);
        
        float deg = ofRandom(360.f) + ofGetFrameNum() * ofMap(size, 0, 20, 0.8, 0.15);
        float noise_value = ofMap(ofNoise(i * 0.5, ofGetFrameNum() * 0.005), 0, 1, 0.8, 1.2);
        float x = greenradius * noise_value * cos(deg * DEG_TO_RAD);
        float y = greenradius * noise_value * sin(deg * DEG_TO_RAD);
        ofPoint point = ofPoint(x, y);
        
        ofColor greencolor;
        greencolor.setHsb(100, 200, 219);
        
        
        for (int score = 0.767592; score <1; score++) {
            ofSetColor(greencolor, 139);
            ofDrawCircle(point, size);
        }
    }
    
    //    ANALYTICAL
    
    float orangeradius = 230;
    for (int i = 0; i < 20; i++) {
        
        float size = ofRandom(25.f);
        
        float deg = ofRandom(360.f) + ofGetFrameNum() * ofMap(size, 0, 20, 0.8, 0.15);
        float noise_value = ofMap(ofNoise(i * 0.5, ofGetFrameNum() * 0.005), 0, 1, 0.8, 1.2);
        float x = orangeradius * noise_value * cos(deg * DEG_TO_RAD);
        float y = orangeradius * noise_value * sin(deg * DEG_TO_RAD);
        ofPoint point = ofPoint(x, y);
        
        ofColor orangecolor;
        orangecolor.setHsb(280, 390, 619);
        
        
        for (int score = 0.767592; score <1; score++) {
            ofSetColor(orangecolor, 139);
            ofDrawCircle(point, size);
        }
    }
    
    //    CONFIDENCE
    
    float darkblueradius = 230;
    for (int i = 0; i < 35; i++) {
        
        float size = ofRandom(25.f);
        
        float deg = ofRandom(360.f) + ofGetFrameNum() * ofMap(size, 0, 20, 0.8, 0.15);
        float noise_value = ofMap(ofNoise(i * 0.5, ofGetFrameNum() * 0.005), 0, 1, 0.8, 1.2);
        float x = darkblueradius * noise_value * cos(deg * DEG_TO_RAD);
        float y = darkblueradius * noise_value * sin(deg * DEG_TO_RAD);
        ofPoint point = ofPoint(x, y);
        
        ofColor darkbluecolor;
        darkbluecolor.setHsb(170, 500, 339);
        

        for (int score = 0.767592; score <1; score++) {
            ofSetColor(darkbluecolor, 139);
            ofDrawCircle(point, size);
        }
    }
    
   
 
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    if (key == '1') {
        eventString = "Joy";
        change.set(248,232,160);
        beeb.play();
    }
    
    else {
        change.set(239);
    }
    
    if (key == '2') {
        eventString = "Anger";
        change.set(239,120,116);
        beeb.play();
    }
    
    if (key == '3') {
        eventString = "Sadness";
        change.set(160,222,248);
        beeb.play();
    }
    
    if (key == '4') {
        eventString = "Fear";
        change.set(222,160,248);
        beeb.play();
    }
    
    if (key == '5') {
        eventString = "Tentative";
        change.set(134,228,137);
        beeb.play();
    }
    
    if (key == '6') {
        eventString = "Analytical";
        change.set(248,190,109);
        beeb.play();
    }
    
    if (key == '7') {
        eventString = "Confidence";
        change.set(109,109,248);
        beeb.play();
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
