//
//  PlanettwoClass.cpp
//  AlienAndPlanets
//
//  Created by Áshildur Friðriksdóttir on 24/02/2018.
//

#include "PlanettwoClass.hpp"


void PlanettwoClass::setup() {
    planetGroups.add(rotateSpeed.set("speed", 1.0));
    planetGroups.add(posX.set("X", 79.5918));
    planetGroups.add(posY.set("Y", 0));
    
//    planetGroups.add(red.set("red", 255, 0, 255));
//    planetGroups.add(green.set("green", 255, 0, 255));
//    planetGroups.add(blue.set("blue", 255, 0, 255));
// uncomment if you want to change colors
    

}

void PlanettwoClass::update() {
    rotation++;
}

void PlanettwoClass::draw() {
    ofSetColor(255, 255, 255);
    ofRotate(rotation * rotateSpeed);
    ofDrawCircle(posX, posY, 30);
}
