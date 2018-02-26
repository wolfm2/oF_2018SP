//
//  PlanetthreeClass.cpp
//  AlienAndPlanets
//
//  Created by Áshildur Friðriksdóttir on 24/02/2018.
//

#include "PlanetthreeClass.hpp"



void PlanetthreeClass::setup() {
    

    
    planetGroups.add(rotateSpeed.set("speed", 1.0));
    planetGroups.add(posX.set("X", 251.02));
    planetGroups.add(posY.set("Y", 0));
    
//    planetGroups.add(red.set("red", 255, 0, 255));
//    planetGroups.add(green.set("green", 255, 0, 255));
//    planetGroups.add(blue.set("blue", 255, 0, 255));
    

}

//void PlanetthreeClass::keyPressed(<#int key#>) {
//    switch(key) {
//        case ' ':
//            bomb.play();
//            break;
//
//
//        case 'a':
//            bomb.stop();
//            break;
//
//    }


void PlanetthreeClass::update() {
    rotation++;
}

void PlanetthreeClass::draw() {
    ofSetColor(255, 255, 255);
    ofRotate(rotation * rotateSpeed);
    ofDrawCircle(posX, posY, 30);
}
