#pragma once

#include "ofMain.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVideoPlayer video;
    ofImage image;
    ofImage image2;
    ofSoundPlayer sound;
    float * fftSmooth;
    int bands;
    
    //Arduino communication
    ofSerial serial;
    string str;
    
    
    int alpha;
    int alphaA;
    float volume;
    float vol;
    float distance;
    float dis;
    
    ofTrueTypeFont myFont;
    ofFbo fbo;
    
    //ofxPanel gui;
    //ofxFloatSlider spectrumAlpha;
    //ofxFloatSlider titleAlpha;
    
    //bool showGui;

};

