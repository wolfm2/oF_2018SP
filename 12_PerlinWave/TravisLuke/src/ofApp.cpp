#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

    ofSetFrameRate(60);
    ofBackground(0, 0, 0);

    for (int i = 0; i < numWaves; i++)
    {
        waveList.push_back(wave());
    }

    for (int i = 0; i < numWaves; i++)
    {
        waveList[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (int i = 0; i < numWaves; i++)
    {
        waveList[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (int i = 0; i < numWaves; i++)
    {
        waveList[i].draw();
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