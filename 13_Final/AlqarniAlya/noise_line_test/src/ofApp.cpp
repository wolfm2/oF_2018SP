#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(Red.setup("Red", 0,0,255));
    gui.add(Green.setup("Green", 60,0,255));
    gui.add(Blue.setup("Blue", 255,60,255));

    gui.add(floatSlider.setup("float slider", 33.33, 0.0, 66.66));
    gui.add(toggle.setup("Type", true));
    
    font.loadFont("Bangla Sangam MN.ttf", 64);

    ofBackground(100,100,255);

}

//--------------------------------------------------------------
void ofApp::update(){
//   line1.draw();
    for (auto &vert : line1.getVertices()){
        vert.x += ofRandom(-1,1);
        vert.y += ofRandom(-1,1);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(Red,Green,Blue);
    gui.draw();


   
//    line2.draw();
    
    ofEnableAlphaBlending();
    
    float widthSmooth = 1;
    float angleSmooth;
    
    ofPoint lastLetter;
    float distanceToNextLetter = 20;
    
    
    string temp = "Out there in the cold, getting lonely getting old. Can you feel me?";


    
    int count = 0;
    
    for (int i = 0;  i < line2.getVertices().size(); i++){
        
        
        
        
        int me_m_one = i-1;
        int me_p_one = i+1;
        if (me_m_one < 0) me_m_one = 0;
        if (me_p_one ==  line2.getVertices().size()) me_p_one =  line2.getVertices().size()-1;
        
        ofPoint diff = line2.getVertices()[me_p_one] - line2.getVertices()[me_m_one];
        float angle = atan2(diff.y, diff.x);
        
        if (i == 0) angleSmooth = angle;
        else {
            
            angleSmooth = ofLerpDegrees(angleSmooth, angle, 1.0);
            
        }
        
        
        float dist = diff.length();
        
        float w = ofMap(dist, 0, 20, 1.1, 0.3, true);
        
        widthSmooth = 0.9f * widthSmooth + 0.1f * w;
        
        ofPoint offset;
        
        
        bool bDrawLetter = false;
        if (i == 0){
            bDrawLetter = true;
        } else if ( (line2.getVertices()[i] - lastLetter).length() >distanceToNextLetter) {
            bDrawLetter = true;
            
        }
        
        if (bDrawLetter == true){
            
            
            
            char c = temp[count];
            count ++;
            count %= temp.size();
            string s = "";
            s += c;
            
            ofRectangle rect = font.getStringBoundingBox(s, 0, 0);
            
            ofSetColor(0,0,0);
            
            ofPushMatrix();
            ofTranslate( line2.getVertices()[i].x,  line2.getVertices()[i].y, 0);
            ofRotate(angleSmooth * RAD_TO_DEG);
            ofScale(widthSmooth, widthSmooth, 1);
            font.drawString(s, -rect.x - rect.width/2.0, -rect.y - rect.height/2.0);
            ofPopMatrix();
            
            lastLetter = line2.getVertices()[i];
            distanceToNextLetter =  (rect.x + rect.width)*widthSmooth*0.7;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'f') ofToggleFullscreen();
    
    if ( key == 'l'){
        line1.draw();
    }
    
    if ( key == 't'){
        line2.draw();
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
    ofPoint pt;
    pt.set(x,y);
    line1.addVertex(pt);

    line2.addVertex(ofPoint(x,y));

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    line1.clear();
    line2.clear();

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
