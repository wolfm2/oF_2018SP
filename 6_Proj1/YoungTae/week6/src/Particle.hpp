//
//  Particle.hpp
//  particlesAdvanced
//
//  Created by Jonathan Beilin on 11/6/17.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>

#include "ofMain.h"

class Particle {
public:
	void reset();
	void update();
	void draw();

	void toggleMode();

	ofPoint position;
	ofPoint velocity;
	ofPoint force;
	float drag;

	bool isAttracting = true;
    
    ofImage image;
};

#endif /* Particle_hpp */
