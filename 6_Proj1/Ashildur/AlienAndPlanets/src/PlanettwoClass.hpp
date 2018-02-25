//
//  PlanettwoClass.hpp
//  AlienAndPlanets
//
//  Created by Áshildur Friðriksdóttir on 24/02/2018.
//

#ifndef PlanettwoClass_hpp
#define PlanettwoClass_hpp


#include "ofMain.h"

class PlanettwoClass {
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
    
    float rotation = 0.0;

    
};




#endif /* PlanettwoClass_hpp */
