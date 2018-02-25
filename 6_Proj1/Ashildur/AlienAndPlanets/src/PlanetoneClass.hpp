//
//  PlanetoneClass.hpp
//  AlienAndPlanets
//
//  Created by Áshildur Friðriksdóttir on 24/02/2018.
//

#ifndef PlanetoneClass_hpp
#define PlanetoneClass_hpp

#include "ofMain.h"

class PlanetoneClass {
public:
    void setup();
    void update();
    void draw();
    
    ofParameterGroup planetGroups;
    ofParameter<float> rotateSpeed;
    ofParameter<float> posX;
    ofParameter<float> posY;
    ofParameter<int> red;
    ofParameter<int> green;
    ofParameter<int> blue;
    
    bool bRemove;
    
    
    float rotation = 0.0;
    
};



#endif /* PlanetoneClass_hpp */
