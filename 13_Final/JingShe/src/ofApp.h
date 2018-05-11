#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "particle.h"

class ofApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);
        void keyPressed(int key);
        void audioIn(float * input, int bufferSize, int nChannels);
         void audioOut(float * output, int bufferSize, int nChannels);
		
     std::vector<float>waveform;
    double phase;
    float frequency;
    
    ofMutex waveformMutex;
    
    
    
		// let's make a vector of them
	 	vector <particle> particles;
       ofColor color;
       ofImage image;
    ofImage boat01;
      ofImage boat02; // load image
     ofImage microphone;
     ofImage button;
    ofImage earth;
    
    ofSoundPlayer song;
    ofSoundPlayer bomb;
    int nBandsToGet;
    
    int x = 0;
    int y = 0;
    
    float scaleW = 1.0f;
    float scaleH = 1.0f; // matrix for spaceship
    
    float rotateX = 0;
    float rotateY = 0;
    float rotateZ = 0; // matrix for spaceship
    
    ofTrueTypeFont myFont; //set font
    
    vector<float>left;
    vector<float>right;
    vector<float>volHistory;
    
    int bufferCounter;
    int drawCounter;
    
    float smoothedVol;
    float scaleVol;
    
    float threshold;
    float minimumThreshold;
    float decayRate;
    float rms;
    
    ofPoint Image_pos;
    ofPoint Boat_pos;
    float Image_catchupspeed = 0.1f;
    
    ofFbo fbo;
    
    ofSoundStream soundStream;
    
    int count = 0;
    bool drawString = true;
    int click = 0;
   
    
};

#endif
