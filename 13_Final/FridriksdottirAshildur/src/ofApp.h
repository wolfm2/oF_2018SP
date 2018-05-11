#pragma once

#include "ofMain.h"
#include <vector>
#include "Cell.h"
#include <string>
#include "ofxMaxim.h"
#include "keyClass.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        int static const dimension = 35;
        Cell cells[dimension][dimension];
        int totalSum;
    
        //GUI Parameters
        float spacing = 15.F;
        float radius = 1.F;
        ofTrueTypeFont font;
    
        //Sound variables
        double phase;
        float frequency;
        float sampleRate = 44100; 
        std::vector<float> waveform;

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
        void updateWaveform(int waveformResolution);
        void audioOut( float * output, int bufferSize, int nChannels );
    

//    int bufferSize, sampleRate;
    double notes;
    double outputs[ 2 ];
    
    vector<double> n {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88, 523.25 };
    
    vector<unique_ptr<Key>> keys;
    
    maxiMix myMix;
    
      ofMutex waveformMutex;
    
    
    //    maxiOsc osc;
    //    double freq, wave;
    //
    //    int bufferSize, sampleRate;
    //
    //Custom variables for on screen string and font.
    string msg;
    //ofTrueTypeFont font;
    
    //New serial object.
    ofSerial serial;
};
