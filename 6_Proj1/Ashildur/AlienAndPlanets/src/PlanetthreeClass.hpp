//
//  PlanetthreeClass.hpp
//  AlienAndPlanets
//
//  Created by Áshildur Friðriksdóttir on 24/02/2018.
//

#ifndef PlanetthreeClass_hpp
#define PlanetthreeClass_hpp

#include "ofMain.h"

class PlanetthreeClass {
public:
    void setup();
    void update();
    void draw();
//    void keyPressed(int key);
    
    ofSoundPlayer bomb;
    
    ofParameterGroup planetGroups;
    ofParameter<float> rotateSpeed;
    ofParameter<float> posX;
    ofParameter<float> posY;
    ofParameter<int> red;
    ofParameter<int> green;
    ofParameter<int> blue;
    
    float rotation = 0.0;
    
};


#endif /* PlanetthreeClass_hpp */
