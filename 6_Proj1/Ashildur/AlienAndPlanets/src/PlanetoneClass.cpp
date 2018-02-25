//
//  PlanetoneClass.cpp
//  AlienAndPlanets
//
//  Created by Áshildur Friðriksdóttir on 24/02/2018.
//

#include "PlanetoneClass.hpp"


void PlanetoneClass::setup() {
    planetGroups.add(rotateSpeed.set("speed", 1.0));
    planetGroups.add(posX.set("X", 0, 0, 600));
    planetGroups.add(posY.set("Y", 0, 0, 600));
    
      
}

void PlanetoneClass::update() {
    rotation++;
}

void PlanetoneClass::draw() {
    ofSetColor(130, 131, 255);
    ofRotate(rotation * rotateSpeed);
    ofDrawCircle(posX, posY, 30);
}
