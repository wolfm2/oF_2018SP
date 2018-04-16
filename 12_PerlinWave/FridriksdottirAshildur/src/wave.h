//
//  wave.h
//  Perlin_Noise_HW
//
//  Created by Áshildur Friðriksdóttir on 15/04/2018.
//

#include "ofMain.h"
#include "ofApp.h"

#ifndef wave_h
#define wave_h

class wave {
    
public:
    wave();
    void setup();
    void update();
    void draw();
    ofPoint loc;
    ofPoint p1;
    ofPoint p2;
    ofPoint t;
    ofPoint lctn;
    
    ofFbo fbo;
    ofColor color;
    ofColor black;

    
private:
    
    float time;
    float n;
    
    float sTime;	// start time
    float sWeight;      // scale weight
    float fallSpeed;	// how fast to fall
    float fallWiggle;   // back and forth
    
    float scale;
    float scaleX;	// delta scales
    float scaleY;
    float scaleZ;
    float rX;		// rotate angles
    float rY;
    float rZ;
    float x;
    float y;
    float z;
    float a;
    float b;
    float c;
    
};

#endif /* wave_h */
