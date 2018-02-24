#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    x1=951;
    y1=331;
    x2=844;
    y2=285;
    x3=986;
    y3=187;
    
    for(int i=0; i< 80; i++){
        pos[i].set(ofRandom(20, 1920), ofRandom(540, 1060));
        r[i]= ofRandom(10, 20);
        vel[i]= ofRandom(3,7);
        count[i]= 0;
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    if(state== true){
        if(deg<60){
            deg+=1;
        }else{
            x1++;
            x2++;
            x3++;
            y1+=2;
            y2+=2;
            y3+=2;
        }
    }
    
    if(move== true){
        for(int i=0; i< 80; i++){
            if(pos[i].x> 600 && pos[i].x< 1066 && pos[i].y< 427){
                vel[i]*= -1;
            }

            if(pos[i].y< 0 || pos[i].y> 1080){
                count[i]= 1;
            }
            
            s+= count[i];
            pos[i].y-= vel[i];
        }

        
    }
    
    if(s> 2000){
        state= !state;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(133,133,135);
    ofDrawTriangle(844,143,986,187,844,285);
    ofSetColor(120,120,120);
    ofDrawTriangle(844,143,844,285,693,181);
    ofSetColor(135,135,140);
    ofDrawTriangle(844,143,986,187,974,88);
    ofSetColor(135,137,145);
    ofDrawTriangle(974,88,986,187,1066,204);
    ofSetColor(115,115,120);
    ofDrawTriangle(986,187,1006,321,1066,204);
    ofSetColor(163,163,163);
    ofDrawTriangle(1006,321,951,331,849,427);
    ofSetColor(115,115,115);
    ofDrawTriangle(844,285,849,427,951,331);
    ofSetColor(125,125,135);
    ofDrawTriangle(986,187,1006,321,951,331);
    ofSetColor(163,163,163);
    ofDrawTriangle(844,285,849,427,722,356);
    ofSetColor(173,173,173);
    ofDrawTriangle(844,285,722,356,693,181);
    ofSetColor(183,183,183);
    ofDrawTriangle(693,181,844,143,714,93);
    ofSetColor(193,193,193);
    ofDrawTriangle(714,93,693,181,623,177);
    ofSetColor(203,203,203);
    ofDrawTriangle(693,181,643,298,722,356);
    ofSetColor(213,213,213);
    ofDrawTriangle(693,181,643,298,623,177);
    
    if(state== true){
            ofPushMatrix();
            ofSetColor(123,123,125);
            ofTranslate(x2, y2);
            ofRotateZ(deg);
            ofPushMatrix();
            ofTranslate(-848, -288);
            ofDrawTriangle(x1,y1,x2,y2,x3,y3);
            ofPopMatrix();
            ofPopMatrix();
    }else{
        ofDrawTriangle(x1,y1,x2,y2,x3,y3);
    }
    
    for(int i=0; i< 80; i++){
        ofSetColor(255);
        ofDrawCircle(pos[i], r[i]);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    move= !move;
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
