//
//  agent.hpp
//  midterm_chouchou
//
//  Created by 江旻哲 on 4/20/18.
//

#ifndef agent_hpp
#define agent_hpp

#include <stdio.h>
#include "ofMain.h"
class agent {
public:
    agent();
    void update(agent* arr);
    void draw();
    void start(float X, float Y);
    void calcGravityWell(float x,float y);
private:
    float getRelAngle(ofVec2f neighbor);
    float calcAlignment(agent* arr, int max);
    ofVec2f calcCohesion(agent* arr, int max);
    ofVec2f calcDispersion(agent* arr, int max);
    ofVec2f location;
    ofVec2f velDir; // velocity & direction for each step
    ofVec2f mouse;  //
    
    bool active = false;    // if this agent is active
};

#endif /* agent_hpp */
