#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

    //load assets
    sound.loadSound("alert.wav");
    font.loadFont("Roboto-Regular.ttf", 10);

    //load data from file
    bool parsingSuccessful = json.open("places_as_json.json");

    cout << parsingSuccessful << endl;

    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << "Loaded JSON.";
    }
    else
    {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }

    //get current day
    const string DAY[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t rawtime;
    tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    int wday = timeinfo->tm_wday;

    //extract hourly data from json data structure
    for (int i = 0; i < json.size(); i++)
    {
        vector<vector<vector<int>>> timeVector;

        if (!json[i]["timeData"].isNull())
        {
            
            for (int j = 0; j < json[i]["timeData"].size(); j++)
            {
                vector<vector<int>> tempDayVector;

                if (!json[i]["timeData"][j][1].isNull()) {

                    for (int k = 0; k < json[i]["timeData"][j][1].size(); k++)
                    {

                        vector<int> tempValueVector;

                        tempValueVector.push_back(json[i]["timeData"][j][1][k][0].asInt());
                        tempValueVector.push_back(json[i]["timeData"][j][1][k][1].asInt());

                        tempDayVector.push_back(tempValueVector);
                    }
                }

                timeVector.push_back(tempDayVector);
            }

            placeList.push_back(place(json[i]["name"].asString(), json[i]["angle"].asFloat(), json[i]["distance"].asFloat(), json[i]["vicinity"].asString(), timeVector, wday));
        }
    }
}

//--------------------------------------------------------------
void ofApp::update()
{

    changed = false;

    //mouseover detection
    for (int i = 0; i < placeList.size(); i++)
    {
        if (abs(ofDist(mouseX, mouseY, placeList[i].origin.x, placeList[i].origin.y)) < placeList[i].detectRadius && !changed) {  
            placeList[i].expanded = true;
            placeList[i].newDrawRadius = 50;
            placeList[i].newRingHeight = 25;
            changed = true;
            break;
        }
        else {
            placeList[i].newDrawRadius = 0;
            placeList[i].newRingHeight = 0;
        }
    }

    for (int i = 0; i < placeList.size(); i++)
    {
        placeList[i].update();
    }

    //if mouseover make circles more transparent
    if (changed) {
        for (int i = 0; i < placeList.size(); i++) {
            if (!placeList[i].expanded) {
                placeList[i].color.a = 128;
            }
        }
    }

    else {
        for (int i = 0; i < placeList.size(); i++) {
            placeList[i].color.a = 255;
        }
    }

    //play sound if rollover happens
    if (changed && !soundState) {
        sound.play();
        soundState = !soundState;
    }

    if (!changed && soundState) {
        soundState = !soundState;
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(0, 0, 0);
    ofSetLineWidth(1);
    ofDrawLine(0, ofGetWindowHeight()/2, ofGetWindowWidth(), ofGetWindowHeight()/2);
    ofDrawLine(ofGetWindowWidth()/2, 0, ofGetWindowWidth()/2, ofGetWindowHeight());

    for (int i = 0; i < placeList.size(); i++)
    {
        placeList[i].draw(&font);
    }
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