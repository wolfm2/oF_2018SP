#include "demoParticle.h"



demoParticle::demoParticle(){
	attractPoints = NULL;
}


void demoParticle::setMode(particleMode newMode){
	mode = newMode;
}


void demoParticle::setAttractPoints( vector <ofPoint> * attract ){
	attractPoints = attract;
}


void demoParticle::reset(){

	uniqueVal = ofRandom(-10000, 10000);
	
	pos.x = ofRandomWidth();
	pos.y = ofRandomHeight();
	
	vel.x = ofRandom(-2.2, 2);
	vel.y = ofRandom(-2.2, 2);
	
	frc   = ofPoint(0,0,0);
	
	scale = ofRandom(0.2, 1.0);
	
    drag  = ofRandom(0.95, 0.998);
    
    alpha = ofRandom(0,255);
}


void demoParticle::update(float x, float y){
    
    ofPoint attractPt(x, y);
    frc = attractPt-pos;
    frc.normalize();
    vel *= drag;
    vel += frc * 0.6;
    pos += vel;
    
    if( pos.x > ofGetWidth() ){
        pos.x = ofGetWidth();
        vel.x *= -1.0;
    }else if( pos.x < 0 ){
        pos.x = 0;
        vel.x *= -1.0;
    }
    if( pos.y > ofGetHeight() ){
        pos.y = ofGetHeight();
        vel.y *= -1.0;
    }
    else if( pos.y < 0 ){
        pos.y = 0;
        vel.y *= -1.0;
    }

    }

void demoParticle::draw(){

        ofSetColor(255, 215, 0, alpha);
        ofDrawCircle(pos.x, pos.y, scale * 6.0);
    
}


