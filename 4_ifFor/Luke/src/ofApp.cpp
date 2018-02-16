#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
}

//--------------------------------------------------------------
void ofApp::update()
{
}

int x = 0;
int y = 0;

//--------------------------------------------------------------
void ofApp::draw()
{

    int deltaX = ofMap(mouseX, 0, ofGetWidth(), 0, 50); // scale position of mouse
    int deltaY = ofMap(mouseY, 0, ofGetHeight(), 0, 50);
    for (int y = 0; y < ofGetHeight(); y += 20 + deltaY)
    { // don't get closer than 20
        for (int x = 0; x < ofGetWidth(); x += 20 + deltaX)
        {
            int mouseDistX = abs(x - mouseX);
            int mouseDistY = abs(y - mouseY);
            if (mouseDistX < 100 && mouseDistY < 100)
            { // if mouseX is < 100 px away from a circle
                ofNoFill();
            }
            else
            {
                ofFill();
            }
            ofSetColor(ofMap(mouseX, 0, ofGetWidth(), 0, 255), ofMap(mouseY, 0, ofGetHeight(), 0, 255), ofMap(sqrt(pow(float(mouseX),2)+pow(float(mouseY),2)), 0, sqrt(pow(float(ofGetWidth()),2)+pow(float(ofGetHeight()),2)), 0, 255));
            ofDrawCircle(x, y, 20); // Get y value from for statement.
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

    mouseX = x;
    mouseY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}