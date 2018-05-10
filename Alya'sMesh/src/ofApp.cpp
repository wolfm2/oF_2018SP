#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.loadImage("IMG.JPG");
    
    
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    // Don't forget to change to lines mode!
//    mesh.setMode(OF_PRIMITIVE_LINES);

    // We are going to be using indices this time
    mesh.enableIndices();
    
    float connectionDistance = 100;
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                // In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
                // connected to form a line
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }
    
    //making it 3D

    float intensityThreshold = 50;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            
            
            
            if (intensity >= intensityThreshold) {
                float saturation = c.getSaturation();
                float z = ofMap(saturation, 0, 255, -100, 100);
//                ofVec3f pos(x, y, 0.0);
                ofVec3f pos(x*4, y*4, z);

                mesh.addVertex(pos);
                mesh.addColor(c);
            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
   
    //color of pbject
//    int alpha = 150;
//    ofColor purple(198, 0, 205, alpha);
//    ofColor aqua(0, 252, 255, alpha);
//    ofColor inbetween = aqua.getLerped(purple, ofRandom(1.0));
    
    
    //changing the background color
    //and adding gradient
    
//    ofColor centerColor = ofColor(85, 78, 68);
//    ofColor edgeColor(0, 0, 0);
//    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    mesh.draw();
    image.loadImage("IMG.JPG");
    image.resize(200, 200);
   
    ofColor centerColor = ofColor(255,255, 255);
    ofColor edgeColor(255, 255, 255);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
   
    //easyCam part
    
    easyCam.begin();
    ofPushMatrix();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
    mesh.draw();
    ofPopMatrix();
    easyCam.end();
        cout << mesh.getNumVertices() << endl;  // It should be ~64,000
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
