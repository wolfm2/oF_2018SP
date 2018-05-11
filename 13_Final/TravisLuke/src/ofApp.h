#pragma once

#include "ofMain.h"
#include "ofxEasyFft.h"
#include "ofxPostProcessing.h"

class ofApp : public ofBaseApp
{
  public:
    void setup();
    void update();
    void draw();

    void windowResized(int w, int h);

    vector<float> addSamples(vector<float> &val);
    vector<float> removeSamples(vector<float> &val);
    vector<float> sliceFft(vector<float> &prev, float fadePct, int start, int end, int winSize, float multiplier, bool peakify, bool normalize);
    void drawHist(vector<float> &val, int radius, ofColor color = ofColor(255, 255, 255), bool filled = false);

    int nBandsToGet;
    int numBins;

    vector<float> valFull;
    vector<float> newData;
    vector<float> tempVal;
    vector<float> ret;

    vector<float> lows;
    vector<float> mids;
    vector<float> highs;
    vector<float> all;

    ofxEasyFft fft;
    ofPath path;
    ofxPostProcessing post;
};