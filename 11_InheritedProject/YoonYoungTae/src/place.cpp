#include "place.h"

place::place()
{
}

place::place(std::string nameIn, float angleIn, float distanceIn, std::string addressIn, vector<vector<vector<int>>> timeVectorIn, int currDayIn)
{
    name = nameIn;
    address = addressIn;
    angle = angleIn;
    distance = distanceIn * 2;
    timeVector = timeVectorIn;
    currDay = currDayIn;

    //calculate origin as point on a circle, using place distance and heading
    origin = ofPoint((distance * cos(angle * DEG_TO_RAD)) + ofGetWindowWidth()/2, (distance * sin(angle * DEG_TO_RAD)) + ofGetWindowHeight()/2);

    //copy hour data from extracted json to class variable
    for (int i = 0; i < timeVector.size(); i++) {
        vector<int> dayData;
        dayData.reserve(24);
        for(int x = 0; x < 24; x++) {
            dayData.push_back(0);
        }

        for (int j = 0; j < timeVector[i].size(); j++) {

            dayData[timeVector[i][j][0]] = timeVector[i][j][1];

        }

        timeVectorProcessed.push_back(dayData);

    }

    //initialize colors and settings
    ofSetBackgroundColor(255, 255, 255);
    ring.setColor(color);
    ring.setCircleResolution(1000);
    backgroundRing.setColor(ofColor(200,200,200));
    backgroundRing.setCircleResolution(1000);
    backgroundHighlight.setColor(ofColor(0, 0, 0));
    backgroundHighlight.setStrokeWidth(1);
    backgroundHighlight.setFilled(false);
    backgroundHighlight.setCircleResolution(1000);
    dividers.setColor(ofColor(0, 0, 0));
    dividers.setStrokeWidth(1);
    dividers.setFilled(false);
    dividers.setCircleResolution(1000);
}

void place::setup()
{
}

void place::update() {

    easing();

    //update origin in case window size changes
    origin = ofPoint((distance * cos(angle * DEG_TO_RAD)) + ofGetWindowWidth()/2, (distance * sin(angle * DEG_TO_RAD)) + ofGetWindowHeight()/2);

    //clear all paths
    ring.clear();
    backgroundRing.clear();
    backgroundHighlight.clear();
    dividers.clear();
    ticks.clear();

    //generate background ring
    ofPoint backgroundRingStart = ofPoint(drawRadius * cos(0 * DEG_TO_RAD) + origin.x, drawRadius * sin(0 * DEG_TO_RAD) + origin.y);
    backgroundRing.moveTo(backgroundRingStart);
    backgroundRing.arc(origin, drawRadius, drawRadius, 0, 360);
    backgroundRing.arcNegative(origin, drawRadius+ringHeight, drawRadius+ringHeight, 360, 0);
    backgroundRing.close();

    //generate background outline
    ofPoint backgroundHighlightStart = ofPoint((drawRadius + ringHeight) * cos(0 * DEG_TO_RAD) + origin.x, (drawRadius + ringHeight) * sin(0 * DEG_TO_RAD) + origin.y);
    backgroundHighlight.moveTo(backgroundHighlightStart);
    backgroundHighlight.arc(origin, drawRadius + ringHeight, drawRadius + ringHeight, 0, 360);
    backgroundHighlight.close();

    //generate heightmap for each hour
    for (int i = 0; i < timeVectorProcessed[currDay].size(); i++) {

            int popularity = ofMap(timeVectorProcessed[currDay][i], 0, 100, 0, ringHeight);

            ofPoint startPoint = ofPoint(drawRadius * cos(((i * 15)-90) * DEG_TO_RAD) + origin.x, drawRadius * sin(((i * 15)-90) * DEG_TO_RAD) + origin.y);

            //create hour indicator
            ring.moveTo(startPoint);
            ring.arc(origin, drawRadius, drawRadius, (i*15)-90, ((i+1)*15)-90);
            ring.arcNegative(origin, drawRadius+popularity, drawRadius+popularity, ((i+1)*15)-90, (i*15)-90);
            ring.close();

            ofPoint lineStart = ofPoint(drawRadius * cos((((i + 1) * 15)-90) * DEG_TO_RAD) + origin.x, drawRadius * sin((((i + 1) * 15)-90) * DEG_TO_RAD) + origin.y);
            ofPoint lineEnd = ofPoint((drawRadius + popularity) * cos((((i + 1) * 15)-90) * DEG_TO_RAD) + origin.x, (drawRadius + popularity) * sin((((i + 1) * 15)-90) * DEG_TO_RAD) + origin.y);

            //create hour divider
            dividers.moveTo(lineStart);
            dividers.lineTo(lineEnd);
            dividers.arcNegative(origin, drawRadius + popularity, drawRadius + popularity, ((i + 1) * 15)-90, (i * 15)-90);

            lineEnd = ofPoint(drawRadius * cos(((i * 15)-90) * DEG_TO_RAD) + origin.x, drawRadius * sin(((i * 15)-90) * DEG_TO_RAD) + origin.y);

            dividers.lineTo(lineEnd);
            dividers.close();

    }
}

void place::draw(ofTrueTypeFont * font)
{
    //render non-mousover shape
    if (expanded == false) {
        ofSetColor(color);
        ofDrawCircle(origin, detectRadius);

        ofPushMatrix();
        ofTranslate(detectRadius, detectRadius/2);
        ofSetColor(0, 0, 0);
        font->drawString(name, origin.x, origin.y);
        ofPopMatrix();
    }
    //render mouseover shape
    else {
        backgroundRing.draw();
        backgroundHighlight.draw();
        ring.draw();

        //generate background 0, 6, 12, 18 hour markers
        for (int i = 0; i < 4; i++) {
            ofDrawLine(
                ofPoint(drawRadius * cos(i * 90 * DEG_TO_RAD) + origin.x, drawRadius * sin(i * 90 * DEG_TO_RAD) + origin.y), 
                ofPoint((drawRadius + ringHeight) * cos(i * 90 * DEG_TO_RAD) + origin.x, (drawRadius + ringHeight) * sin(i * 90 * DEG_TO_RAD) + origin.y)
            );
        }

        dividers.draw();

        ofPushMatrix();
        ofTranslate(drawRadius+ringHeight, ringHeight + drawRadius/2);
        ofSetColor(0, 0, 0);
        font->drawString(name, origin.x, origin.y);
        ofPopMatrix();
    }
}

//easing
void place::easing()
{
    if (drawRadius != newDrawRadius)
    {
        drawRadius += 0.1 * (newDrawRadius - drawRadius);
    }

    if (ringHeight != newRingHeight)
    {
        ringHeight += 0.1 * (newRingHeight - ringHeight);
    }

    if (drawRadius < detectRadius && ringHeight < detectRadius && expanded)
    {
        drawRadius = detectRadius;
        ringHeight = detectRadius;
        expanded = false;
    }
}
