//
//  particle.hpp
//  bacteria_animation
//
//  Created by echo jiang on 3/15/18.
//

#ifndef particle_hpp
#define particle_hpp

#include "ofMain.h"
#include <stdio.h>
class particle
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    particle();
    virtual ~particle(){};
    //A member of a class that can be redefined in its derived classes is known as a virtual member.
    //~ destructor
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    
    float damping;
};

#endif /* particle_hpp */
