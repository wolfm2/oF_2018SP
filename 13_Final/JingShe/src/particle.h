//
//  particle.h
//  19-noise
//
//  Created by Jane on 4/26/18.
//

#ifndef particle_h
#define particle_h

#include "ofMain.h"

class particle
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
    
    particle();
    virtual ~particle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addDampingForce();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    
    float damping;
    ofColor color;
    
protected:
private:
};

#endif /* particle_h */
