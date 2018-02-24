#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    // ofSetBackgroundColor(150, 90, 0);
    ofSetBackgroundColor(85, 40, 0);
    myCat.setup(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0);
    myDog.setup(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0);
}

//--------------------------------------------------------------
void ofApp::update()
{

    if (ofGetFrameNum() % 60 == 0)
    {
        cout << ofGetElapsedTimeMillis() << endl;
        cout << ofGetFrameNum() << endl;
        cout << myCat.orig << endl;
        cout << myCat.dst << endl;
        cout << (myCat.orig == myCat.dst) << endl;
        cout << myCat.drawRadius << endl;
        cout << "------------------------------" << endl;
    }

    if (ofGetFrameNum() % 5 == 0)
    {
        oldPos = ofPoint(mouseX, mouseY);
    }

    ofPoint catPos = myCat.getPos();
    ofPoint mousePos = ofPoint(mouseX, mouseY);
    float mouseDist = (catPos - mousePos).length();

    if (mouseDist <= 100)
    {
        myCat.hiss(true);
        myCat.setDst((catPos - mousePos));
    }

    myCat.update();

    if (mousePos != oldPos && (mousePos - oldPos).length() >= 5)
    {
        ofPoint diff = mousePos - oldPos;
        myDog.update(mousePos, atan2(diff.y, diff.x) * RAD_TO_DEG - 90);
    }
    else
    {
        myDog.update(mousePos);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{

    ofSetColor(0, 0, 0);
    int boardCount = 25;
    for (int i = 1; i < boardCount; i++)
    {
        int x = i * ofGetWindowWidth() / boardCount;
        ofDrawLine(x, 0, x, ofGetWindowHeight());
    }

    myCat.draw();
    myDog.draw();
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