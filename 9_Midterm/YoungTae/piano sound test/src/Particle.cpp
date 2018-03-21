//
//  Particle.cpp
//  particlesAdvanced
//
//  Created by Jonathan Beilin on 11/6/17.
//

#include "Particle.hpp"

void Particle::reset() {
	position.x = ofRandomWidth();
	position.y = ofRandomHeight();

	velocity.x = ofRandom(-10, 10);
	velocity.y = ofRandom(-4, 4);

	drag = ofRandom(0.90, 0.998);

	force = ofPoint(.3, 0);
  
  status = 0;
  lastTriggered = ofGetElapsedTimeMillis();
}

void Particle::update() {
  // Get mouse coords, save to
  // attractPoint
  ofPoint attractPoint = ofPoint(ofGetMouseX(), ofGetMouseY());

  // calculate force
  // then normalize it
  force = attractPoint - position;
  force.normalize();

  // apply drag to velocity
  // apply force to velocity
  velocity *= drag;
  velocity += force * 0.5;

	// update position
	position += velocity;
  
}

void Particle::draw() {

  
  int distance = ofDist(position.x, position.y, ofGetMouseX(), ofGetMouseY());
  
  ofSetColor(ofMap(distance,0,500,50,255), ofMap(distance,500,0,50,255), ofMap(distance,50,100,0,255));

	ofDrawCircle(position.x, position.y, 2.0); //size of particle
}

void Particle::play(string note) {
  if( soundPlayer.isPlaying() && ofGetElapsedTimeMillis() - lastTriggered < 250 ) {
    return;
  }
  soundPlayer.load("piano/"+ note +".wav");
  soundPlayer.play();
  lastTriggered = ofGetElapsedTimeMillis();
}
