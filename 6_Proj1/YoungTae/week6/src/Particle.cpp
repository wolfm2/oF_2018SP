
#include "Particle.hpp"

void Particle::reset() {
    image.load("mosquito.png");
	position.x = ofRandomWidth();
	position.y = ofRandomHeight();

	velocity.x = ofRandom(-3.9, 3.9);
	velocity.y = ofRandom(-3.9, 3.9);

	drag = ofRandom(0.95, 0.998);

	force = ofPoint(0, 0);
}

void Particle::update() {
	if (isAttracting) {

		ofPoint attractPoint = ofPoint(ofGetMouseX(), ofGetMouseY());

		force = attractPoint - position;
		force.normalize();


		velocity *= drag;
		velocity += force * 0.6;
        position += velocity;
	} else {
		ofPoint repulsePoint = ofPoint(ofGetMouseX(), ofGetMouseY());
		force = repulsePoint - position;

		float distance = force.length();
		force.normalize();

		if (distance < 150) {
			velocity -= force * 0.6;
		}
	}

	position += velocity;
}

void Particle::draw() {
    image.draw(position, 60,60);
    
	if (isAttracting) {
        ofSetColor(20, 20, 20);
	} else {
		ofSetColor(250, 250, 250);
	}

//    ofDrawCircle(position.x, position.y, 2.0);
}

void Particle::toggleMode() {
	isAttracting = !isAttracting;
	reset();
}
