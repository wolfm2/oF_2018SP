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

	void play(string note);

	ofPoint position;
	ofPoint velocity;
	ofPoint force;
	float drag;
  
  int status;
  uint64_t lastTriggered;
  
  ofSoundPlayer soundPlayer;

	bool isAttracting = true;
};

#endif /* Particle_hpp */
