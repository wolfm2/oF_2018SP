//
//  buttons.cpp
//  pinterest
//
//  Created by a on 4/19/18.
//

#include "buttons.hpp"

ofEvent<ofVec2f> myButtons::clickedInsideGlobal = ofEvent<ofVec2f>();

// the static event, or any static variable, must be initialized outside of the class definition.
myButtons::myButtons() {
    bRegisteredEvents = false;
}

myButtons::~myButtons() {
    clear();
}

void myButtons::draw(){
    ofPushStyle();
    ofSetColor(color);
    ofDrawRectangle(x, y, 10 , 10 );
    ofPopStyle();
}

void myButtons::clear() {
    if(bRegisteredEvents) {
        ofUnregisterMouseEvents(this); // disable litening to mous events.
        bRegisteredEvents = false;
    }
}


void myButtons::mouseMoved(ofMouseEventArgs & args){}
void myButtons::mouseDragged(ofMouseEventArgs & args){}
void myButtons::mousePressed(ofMouseEventArgs & args){}
void myButtons::mouseReleased(ofMouseEventArgs & args){
    if (inside(args.x, args.y)) {
        // if the mouse is pressed over the circle an event will be notified (broadcasted)
        // the circleEvent object will contain the mouse position, so this values are accesible to any class that is listening.
        ofVec2f mousePos = ofVec2f(args.x, args.y);
        ofNotifyEvent(clickedInside, mousePos, this);
        ofNotifyEvent(clickedInsideGlobal, mousePos);
    }
}
void myButtons::mouseScrolled(ofMouseEventArgs & args){}
void myButtons::mouseEntered(ofMouseEventArgs & args){}
void myButtons::mouseExited(ofMouseEventArgs & args){}

//this function checks if the passed arguments are inside the circle.
bool myButtons::inside(float _x, float _y ){
    return (ofVec2f(_x, _y).distance(ofVec2f(x, y)) < (10,10));
}
