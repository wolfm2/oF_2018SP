#include "wave.h"

wave::wave()
{
}

void wave::setup()
{
    pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
    dir.set(0, 0, 0);
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    offset = ofRandom(100);
    speed = ofRandom(0.5, 5);

    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);

    fbo.begin();
    ofClear(255, 255, 255, 0);
    fbo.end();
}

void wave::update()
{
    dir.set(
        ofSignedNoise(ofGetElapsedTimef() / 10.0, offset),
        ofSignedNoise(ofGetElapsedTimef() / 10.0, offset - 100),
        ofSignedNoise(ofGetElapsedTimef() / 10.0, offset + 100));

    dir.normalize();

    ofVec3f zero(0, -1, 0);

    axis = zero.crossed(dir);
    axis.normalize();

    rot = zero.angle(dir);

    pos += dir * speed;

    if (pos.x < 0)
    {
        pos.x = ofGetWindowWidth();
    }
    if (pos.x > ofGetWindowWidth())
    {
        pos.x = 0;
    }

    if (pos.y < 0)
    {
        pos.y = ofGetWindowHeight();
    }
    if (pos.y > ofGetWindowHeight())
    {
        pos.y = 0;
    }

    // int zmin = -100;
    // int zmax = 100;

    // if (pos.z < zmin)
    // {
    //     pos.z = zmax;
    // }
    // if (pos.z > zmax)
    // {
    //     pos.z = zmin;
    // }

    fbo.begin();
        ofSetColor(0, 0, 0, 1);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofPushMatrix();
            ofTranslate(pos);
            ofRotate(rot, axis.x, axis.y, axis.z);
            ofEnableDepthTest();
                ofSetColor(color);
                ofDrawLine(-20, 0, 20, 0);
            ofDisableDepthTest();
        ofPopMatrix();
    fbo.end();
}

void wave::draw()
{
    fbo.draw(0, 0);
}