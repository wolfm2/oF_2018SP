#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    //set framerate
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    //set path stroke width because for some reason it defaults to 0
    path.setStrokeWidth(1);

    //initialize ofxPostProcessing object and add bloom effect
    post.init(ofGetWidth(), ofGetHeight());
    post.createPass<BloomPass>();

    //number of fft bins to get
    numBins = 2048;

    /*
    The FFT returns numBins/2 bins so in order to get numBins bins 
    we multiply by 2

    Half of the FFT is real and half imaginary, so in order 
    to get numBins real bins we need to multiply by two again 
    for a total multiplication factor of 4

    Also, I think technically there's some weirdness with the number 
    of samples vs number of bins due to openframeworks handling stereo 
    sound as interleaved samples, e.g. l[0], r[0], l[1], r[1], etc. but 
    things seem to be working
    */
    nBandsToGet = numBins * 4;

    //fft setup
    fft.setUseNormalization(false);
    fft.setup(nBandsToGet);

    //2 channels, 44.1khz sampling rate, numBins/2 audio buffer length, 4 total buffers
    fft.stream.setup(0, 2, 44100, static_cast<int>(numBins / 2.0), 4);
    fft.stream.setInput(fft);

    cout << fft.fft->getBinSize() << endl;

    ofBackground(0, 0, 0);

    //initialize arrays to prevent initial condition segfaults
    for (int i = 0; i < numBins - 1; i++)
    {
        valFull.push_back(0);
        tempVal.push_back(0);
        ret.push_back(0);
        lows.push_back(0);
        all.push_back(0);
        mids.push_back(0);
        highs.push_back(0);
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    //update FFT and retrieve data
    fft.update();
    newData = fft.getBins();

    //truncate FFT results to the real number portion
    for (int i = 0; i < numBins - 1; i++)
    {
        valFull[i] = newData[i];
    }

    //prev, fadePct, start, end, winSize, multiplier, peakify, normalize
    lows = sliceFft(lows, 0.5, 20, 500, 0, 2, 0, 0);
    all = sliceFft(all, 0.5, 20, 10000, 5, 0, 0, 1);
    mids = sliceFft(mids, 0.75, 250, 5000, 0, 0, 1, 1);
    highs = sliceFft(highs, 0.75, 5000, 10000, 0, 0, 1, 1);

    // lows = addSamples(lows);
    // all = removeSamples(all);
    // mids = addSamples(mids);
    // highs = addSamples(highs);

    if (ofGetFrameNum() % 60 == 0)
    {
        cout << ofGetFrameRate() << endl;
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    post.begin();
    drawHist(lows, 100, ofColor::fromHex(0xe59800));
    drawHist(all, 250);
    drawHist(mids, 400, ofColor::fromHex(0xffd500));
    drawHist(highs, 550, ofColor::fromHex(0x005c13));
    post.end();
}

//remove samples by averaging every other sample
vector<float> ofApp::removeSamples(vector<float> &valFull)
{
    vector<float> ret;

    for (int i = 0; i < valFull.size() - 1; i += 2)
    {
        ret.push_back((valFull[i] + valFull[i + 1]) / 2);
    }

    return ret;
}

//interpolate by adding a new sample between each existing sample
vector<float> ofApp::addSamples(vector<float> &valFull)
{
    vector<float> ret;

    for (int i = 0; i < 2 * valFull.size() - 1; i++)
    {
        ret.push_back(0);
    }

    for (int i = 0; i < valFull.size(); i++)
    {
        ret[i * 2] = valFull[i];
    }

    for (int i = 1; i < ret.size() - 1; i += 2)
    {
        ret[i] = (ret[i - 1] + ret[i + 1]) / 2;
    }

    return ret;
}

/*
Extract subarray from FFT based on start and end frequency ranges

FadePct determines the ratio between newly calculated values and 
previous values to keep which provides a fade/easing effect

If winSize is set, perform a sliding window mean over the slice

If peakify is set, square all samples to emphasize proportionally 
larger values

If normalize is set, use ofMap to threshold and scale values
*/
vector<float> ofApp::sliceFft(vector<float> &prev, float fadePct, int start, int end, int winSize, float multiplier, bool peakify, bool normalize)
{
    ret.clear();

    //calculate bins from frequency range
    int startBin = ofMap(start, 20, 22000, 0, valFull.size(), 1);
    int endBin = ofMap(end, 20, 22000, 0, valFull.size(), 1);

    /*
    Sanity check for nan values, which I was getting before 
    but seem to have fixed
    */
    if (isnan(valFull[0]))
    {
        for (int i = startBin; i < endBin; i++)
        {
            ret.push_back(0);
        }
        return ret;
    }

    //copy values in case options are enabled
    for (int i = startBin; i < endBin; i++)
    {
        ret.push_back(valFull[i]);
    }

    //scalar multiplier
    if (multiplier)
    {
        for (int i = 0; i < ret.size(); i++)
        {
            ret[i] *= multiplier;
        }
    }

    //sliding window mean for smoothing
    if (winSize > 0)
    {
        int winMidSize = (winSize - 1) / 2;

        for (int i = startBin + winMidSize; i < endBin - winMidSize; ++i)
        {
            float mean = 0;
            for (int j = i - winMidSize; j <= (i + winMidSize); ++j)
            {
                mean += valFull[j];
            }

            tempVal[i] = (mean / winSize);
        }

        for (int i = 0; i < ret.size(); i++)
        {
            ret[i] = tempVal[i + startBin];
        }
    }

    //emphasize larger values by taking squaring them
    if (peakify)
    {
        for (int i = 0; i < 1; i++)
        {
            for (int j = 0; j < ret.size(); j++)
            {
                ret[j] = pow(ret[j], 2.0);
            }
        }
    }

    //use ofMap to threshold and scale values
    if (normalize)
    {
        float min = 1;
        float max = 0;
        float mean = 0;

        for (int i = 0; i < ret.size(); i++)
        {
            if (ret[i] < min)
            {
                min = ret[i];
            }
            if (ret[i] > max)
            {
                max = ret[i];
            }
            mean += ret[i];
        }

        mean /= ret.size();

        for (int i = 0; i < ret.size(); i++)
        {
            ret[i] = ofMap(ret[i], mean, max, 0, 1, 1);
        }
    }

    //control the ratio of new:old values
    for (int i = 0; i < ret.size(); i++)
    {
        ret[i] = (prev[i] * fadePct) + (ret[i] * (1 - fadePct));
    }

    return ret;
}

//draw circular histogram of the FFT values
void ofApp::drawHist(vector<float> &valFull, int radius, ofColor color, bool filled)
{
    //draw histogram with lines
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    ofRotateZ(-90);

    ofSetColor(color);
    ofSetLineWidth(1);

    //draw outer right semicircle
    for (int i = 0; i < valFull.size(); i++)
    {
        ofPushMatrix();
        ofRotate(ofMap(i, 0, valFull.size() - 1, 0, 180));
        ofDrawLine(radius, 0, radius + 1, 0);
        if (valFull[i] >= 0.0)
        {
            ofDrawLine(radius, 0, radius + ofMap(valFull[i], 0, 1, 5, 50, 1), 0);
        }
        ofPopMatrix();
    }

    //draw outer left semicircle
    for (int i = 0; i < valFull.size(); i++)
    {
        ofPushMatrix();
        ofRotate(ofMap(i, 0, valFull.size() - 1, 0, -180));
        ofDrawLine(radius, 0, radius + 1, 0);
        if (valFull[i] >= 0.0)
        {
            ofDrawLine(radius, 0, radius + ofMap(valFull[i], 0, 1, 5, 50, 1), 0);
        }
        ofPopMatrix();
    }

    //draw inner right semicircle
    for (int i = 0; i < valFull.size(); i++)
    {
        ofPushMatrix();
        ofRotate(ofMap(i, 0, valFull.size() - 1, 0, 180));
        ofDrawLine(radius, 0, radius + 1, 0);
        if (valFull[i] >= 0.0)
        {
            ofDrawLine(radius, 0, radius - ofMap(valFull[i], 0, 1, 5, 100, 1), 0);
        }
        ofPopMatrix();
    }

    //draw inner left semicircle
    for (int i = 0; i < valFull.size(); i++)
    {
        ofPushMatrix();
        ofRotate(ofMap(i, 0, valFull.size() - 1, 0, -180));
        ofDrawLine(radius, 0, radius + 1, 0);
        if (valFull[i] >= 0.0)
        {
            ofDrawLine(radius, 0, radius - ofMap(valFull[i], 0, 1, 5, 100, 1), 0);
        }
        ofPopMatrix();
    }

    ofPopMatrix();
    ofPopStyle();

    //draw histogram with path
    path.clear();
    path.setColor(color);
    path.setFilled(filled);

    float x, y;

    //draw outer right semicircle
    for (int i = 0; i < valFull.size(); i++)
    {
        if (valFull[i] >= 0.0)
        {
            x = (radius + ofMap(valFull[i], 0, 1, 5, 50, 1)) * cos(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, 180)));
            y = (radius + ofMap(valFull[i], 0, 1, 5, 50, 1)) * sin(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, 180)));
        }
        else
        {
            x = radius * cos(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, 180)));
            y = radius * sin(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, 180)));
        }
        path.lineTo(x, y);
    }

    //draw outer left semicircle
    for (int i = valFull.size() - 1; i > 0; i--)
    {
        if (valFull[i] >= 0.0)
        {
            x = (radius + ofMap(valFull[i], 0, 1, 5, 50, 1)) * cos(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, -180)));
            y = (radius + ofMap(valFull[i], 0, 1, 5, 50, 1)) * sin(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, -180)));
        }
        else
        {
            x = radius * cos(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, -180)));
            y = radius * sin(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, -180)));
        }
        path.lineTo(x, y);
    }

    path.close();

    //draw inner right semicircle
    for (int i = 0; i < valFull.size(); i++)
    {
        if (valFull[i] >= 0.0)
        {
            x = (radius - ofMap(valFull[i], 0, 1, 5, 100, 1)) * cos(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, 180)));
            y = (radius - ofMap(valFull[i], 0, 1, 5, 100, 1)) * sin(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, 180)));
        }
        else
        {
            x = radius * cos(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, 180)));
            y = radius * sin(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, 180)));
        }
        path.lineTo(x, y);
    }

    //draw inner left semicircle
    for (int i = valFull.size() - 1; i > 0; i--)
    {
        if (valFull[i] >= 0.0)
        {
            x = (radius - ofMap(valFull[i], 0, 1, 5, 100, 1)) * cos(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, -180)));
            y = (radius - ofMap(valFull[i], 0, 1, 5, 100, 1)) * sin(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, -180)));
        }
        else
        {
            x = radius * cos(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, -180)));
            y = radius * sin(ofDegToRad(ofMap(i, 0, valFull.size() - 1, 0, -180)));
        }
        path.lineTo(x, y);
    }

    path.close();

    ofPushMatrix();
    ofTranslate(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
    ofRotateZ(-90);
    path.draw();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
    //reinitialize the post processing object if window is resized
    post.init(w, h);
}
