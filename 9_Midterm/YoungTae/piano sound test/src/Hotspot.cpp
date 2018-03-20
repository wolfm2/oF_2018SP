//
//  Hotspot.cpp
//  particlesAdvanced
//
//  Created by Philipp Schmitt on 01.12.17.
//

#include "Hotspot.hpp"

void Hotspot::setup(int x, int y, int _note) {
  position = ofPoint(x,y);
  note = _note;
  status = 0;
}

void Hotspot::draw() {
  ofSetColor(ofMap(note,0,8,100,255),ofMap(note,0,8,255,100),ofMap(note,0,8,100,255), ofMap(status,0,5,100,255));
  ofDrawCircle(position.x, position.y, 20);
  
  if( status > 0 ) {
    status--;
  }
  
  if( status > 5) {
    status = 5;
  }
}
