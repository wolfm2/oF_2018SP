#include "ofApp.h"

int alpha =0;
//--------------------------------------------------------------
void ofApp::setup(){
    //    Avenir.load("Avenir.ttc", 12);
    
    //ofSetBackgroundAuto(false);    // TYLER - try without this ?
    
    ofBackground(100,100,255);

    
    minDistance = 10;
    
    LeftMouseButtonPressed=false;
    
    gravity = ofVec2f(0.00001,ofRandom(0,0.0002));
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (LeftMouseButtonPressed) {
        ofVec2f mousePos(ofGetMouseX(), ofGetMouseY());
        if (lastpoint.distance(mousePos) >= minDistance) {
            currentPolyline.curveTo(mousePos);
            lastpoint = mousePos;
            alpha=+0.5;
        }
    }
    
    
    float timeDiff = ofGetElapsedTimef() - lastUpdateTime;
    
    for (int i=0; i<systems.size(); i++)
    {
        systems[i].update(gravity, timeDiff);    // update
        
    }
    
    lastUpdateTime = ofGetElapsedTimef();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // ofBackground(0);    // TYLER -
    // ofBackground(0) clears the screen,
    // so this would cancel the effect of ofSetBackgroundAuto(false)
    
    
    // TYLER - draw page background
    
    if (page == 1)
    {   boy.draw(0,0, 1000, 500);
        //        introString =    "Hi. This is Ted. Will you help him complete his drawing? Press Y to continue or N to terminate";"\n";
        //        ofSetHexColor(0xffffff);
        //        Avenir.drawString(introString, 20, 30);
    }
    
    else if (page == 2)
    {
        boy1.draw(0,0, 1000, 500);
    }
    
    else if (page == 3)
    {
        boy3.draw(0,0, 1000, 500);
    }
    
    else if (page == 4)
    {
        tree.draw(0,0, 1000, 500);
    }
    // draw the brush drawings
    
    
    for (int i=0; i<polylines.size(); i++) {
        
        ofPolyline polyline = polylines[i];
        ofPushStyle();
        ofSetColor(0);
        polyline.draw();
        ofPopStyle();
        vector<ofVec3f> vertices = polyline.getVertices();
        for (int vertexIndex=0; vertexIndex<vertices.size(); vertexIndex++) {
            
            
            ofVec3f vertex = vertices[vertexIndex];  // ofVec3f is like ofVec2f, but with a third dimension,
            
            if (brush == 1)
            {   cam1.begin();
                brush1.draw(vertex);
                cam1.begin();// draw the Brush1 pattern at this position
            }
            
            else if (brush == 2)
            {   cam.begin();
                brush2.draw(vertex);
                cam.end();
            }
            
            else if (brush == 3)
            {
                brush3.draw(vertex);
            }
            
            else if (brush == 4)
            {
                
                brush4.pos = vertex;
                brush4.update(gravity, timeDiff);
                brush4.draw();
            }
            
            
        }
        
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //different scenes background
    
    if (key == 'x')
    {
        // switch to page 1 and brush 1
        
        page = 1;
        
        brush = 1;
        
        // clear the drawing by clearing the polylines
        
        polylines.clear();
    }
    
    else if (key == '0')
    {
        
        page = 2;
        
        brush = 1;
        
        polylines.clear();
        
    }
    
    else if (key == '1')
    {
        
        page = 3;
        
        brush = 1;
        
        polylines.clear();
        
    }
    
    else if (key == '2')
    {
        
        page = 4;
        
        brush = 1;
        
        polylines.clear();
        
    }
    
    else if (key == 'a')
    {
        // switch to brush 1
        brush = 1;
    }
    else if (key == 'b')
    {
        // switch to brush 2
        brush = 2;
    }
    
    else if (key == 'c')
    {
        // switch to brush 3
        brush = 3;
        
    }
    
    else if (key == 'd')
    {
        // switch to brush 4
        brush = 4;
        
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
    
    if (button == OF_MOUSE_BUTTON_LEFT) {
        
        LeftMouseButtonPressed = true;
        currentPolyline.curveTo(x, y);
        currentPolyline.curveTo(x, y);
        lastpoint.set(x, y);
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (button == OF_MOUSE_BUTTON_LEFT) {
        LeftMouseButtonPressed = false;
        currentPolyline.curveTo(x, y);
        polylines.push_back(currentPolyline);
        currentPolyline.clear();
    }
    
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
