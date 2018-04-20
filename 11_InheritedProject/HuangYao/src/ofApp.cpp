#include "ofApp.h"
ofImage leaf;

int x=0;
ofImage galaxy;
int num=0;
float dia ;
float radius;
Boolean keyyyy = false;
ofSoundPlayer space;

//--------------------------------------------------------------
void ofApp::setup(){
    leaf.load("asteroid1.png");
    //galaxy.load("4.png");
    //galaxy.load("3.png");
    galaxy.load("6.png");
    //std::string file = "example.json";
    std::string file = "neo.json";
    mySound.load("xx.mp3");
    mySound.play();
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
    
}

float rX = 0;
float rY = 0;
float rZ = 0;
float dScaleX = 1; // delta scale
float dScaleY = 1;
float dScaleZ = 1;
//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.5, time * 0.5, time * 0.5) * 400.0;  // rotate +- 400deg
    // https://www.reddit.com/r/gamedev/comments/4y23pn/how_do_i_generate_deterministic_noise_that/
    rY = ofSignedNoise(time * 0.3) * 400.0;
    rZ = ofNoise(time * 0.9)* 2;
    dScaleX = 1 - ofNoise(time * 0.2);
    dScaleY = 1 - ofNoise(time * 0.4);
    dScaleZ = 1 - ofNoise(time * 0.6);
    
    //x++;
    x=x+1.5;
    deg+= rZ;
    space.play();
}

//--------------------------------------------------------------
void ofApp::draw(){
    //
    //    if(keyyyy == true){
    
    galaxy.draw(0, 0,ofGetWidth(),ofGetHeight());
    
    
    
    
    std::stringstream ss;
    
    ss << "Date            = " << "2018-03-15" << std::endl;
    ss << "Number          = " << result["near_earth_objects"]["2018-03-15"][num]["neo_reference_id"].asString()<< std::endl;
    ss << "Neo Id          = " << result["near_earth_objects"]["2018-03-15"][num]["neo_reference_id"].asString()<< std::endl;
    ss << "Diameter         = " << result["near_earth_objects"]["2018-03-15"][num]["estimated_diameter"]["meters"]["estimated_diameter_min"].asString() << "  Meters" <<std::endl;
    
    // dia =  result["near_earth_objects"]["2018-03-15"][num]["estimated_diameter"]["meters"]["estimated_diameter_min"].asFloat();
    //     ofDrawBitmapString(dia , 30,100);
    
    
    
    ss << "Velocity         = " << result["near_earth_objects"]["2018-03-15"][num]["close_approach_data"][0]["relative_velocity"]["kilometers_per_second"].asString() << std::endl;
    
    ss << "Is it harmful to Earth?      = " << result["near_earth_objects"]["2018-03-15"][num]["is_potentially_hazardous_asteroid"].asString() << std::endl;
    
    
    
    ofPushMatrix();
    
    if (x<ofGetWidth()){
        // ofScale(1,1,1);       // scale 0.5 in height
        //ofScale(1, dScaleY, dScaleZ);
        //    radius= (dia/2100)*1024;
        //    ofSetColor(255);
        // leaf.draw(x, 300,radius,radius);
        ofTranslate(x, 200);
        ofRotateZ(deg);
        leaf.draw(-25, -50,50,100);
        
    }
     else{x=0;}
    ofPopMatrix();
    
    
    ofPushMatrix();
    
    
    //    ofDrawCircle(50, 100, radius);
    //ofSetColor(0,255,0);
    ofDrawBitmapString(ss.str(), 50, 550);
    ofPopMatrix();
    
    //}
    //   keyyyy= false;
}



//--------------------------------------------------------------
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //Use key presses 0-7 to print the above for each day in the forecast.
    
    if (key == '0'){
        num =0;
        //      std::string highTemperature  = json["daily"]["data"][0]["temperatureHigh"].asString();
        //      std::string summaryText  = json["daily"]["data"][0]["summary"].asString();
        
        cout<<"low";    }
    
    if (key == '1'){
        num =1;
        
        cout<<"1";    }
    
    if (key == '2'){
        num =2;
        
        cout<<"2";    }
    
    if (key == '3'){
        num =3;
        
        cout<<"3";    }
    
    if (key == '4'){
        num =4;
        cout<<"4";    }
    
    if (key == '5'){
        num =5;
        
        cout<<"5";    }
    
    if (key == '6'){
        num =6;
        
        cout<<"6";    }
    
    if (key == '7'){
        num =7;
        
        cout<<"7";    }
    //    if (key == '9'){
    //        keyyyy= true;
    //
    //        cout<<"7";    }
    
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
