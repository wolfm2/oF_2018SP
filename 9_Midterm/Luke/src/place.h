#pragma once

#include <string>
#include "ofxJSON.h"
#include "ofMain.h"

class place : public ofBaseApp
{
    public:
        place();
        place(std::string nameIn, float angleIn, float distanceIn, std::string addressIn, vector<vector<vector<int>>> timeVectorIn, int currDayIn);
        void setup();
        void update();
        void draw(ofTrueTypeFont *);
        void easing();

        ofPoint origin;
        int detectRadius = 10;
        float drawRadius = 0;
        float ringHeight = 0;

        float newDrawRadius = 50;
        float newRingHeight = 25;

		int currDay;

        bool expanded = false;

        bool operator< (const place key);

        std::string name;
        std::string address;
		float angle;
		float distance;
		vector<vector<vector<int>>> timeVector;
        vector<vector<int>> timeVectorProcessed;
        ofPath ring;
        ofPath backgroundRing;
        ofPath backgroundHighlight;
        ofPath dividers;
        ofPath ticks;
        ofColor color = ofColor(ofRandom(128, 255), ofRandom(128, 255), ofRandom(128, 255));
};