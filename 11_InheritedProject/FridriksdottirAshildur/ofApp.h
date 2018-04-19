
#include "ofMain.h"
#include "ofxSlitScan.h"



class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
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
    
    void setupArduino(const int & version);
    ofSoundPlayer mySound;
    
//    ofxThermalPrinter printer;
    
    
    //New serial object.
    ofSerial printer;
    ofArduino myArduino;
    
    ofxSlitScan slitScan;
    ofVideoGrabber grabber;
    
    //Main processing function which
    //computes the pixel color (x, y) using frames buffer
    ofColor getSlitPixelColor( int x, int y );
    
    ofPixels imagePixels;
    
    ofImage    img;
    
    ofTrueTypeFont verdana;
    
//    //    Framebuffer:
//    deque<ofPixels> frames;
//    int N;
    
    int window_width    = 1000;
    int window_height   = ofGetWindowHeight();
    int draw_position_x = 0;
    bool newFrame  = false;
    
   
    ofFbo       fbo[2];
    ofShader    shader;
    
    ofPoint     mouse;
    
    float       offset;
    float       dispersion;
    float       grainSize;
    int         count;
    
    
};

