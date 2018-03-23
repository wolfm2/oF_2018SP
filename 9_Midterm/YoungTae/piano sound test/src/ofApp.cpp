#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	int numParticles = 1;
	// create particles
    
  for (int i = 0; i < numParticles; i++) {
		Particle newParticle;
		newParticle.reset();
		particles.push_back(newParticle);
	}
  
  // create hotspots
  for (int i = 1; i < 9; i++) {
    Hotspot hotspot;
    hotspot.setup( ofRandom(100,ofGetWidth()-100), ofRandom(100,ofGetHeight()-100), i);
    hotspots.push_back(hotspot);
  }
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < particles.size(); i++) {
		particles[i].update();
    
    // check for hotspot collisions
    for (int j = 0; j < hotspots.size(); j++) {
      if( ofDist(particles[i].position.x, particles[i].position.y, hotspots[j].position.x, hotspots[j].position.y) < 20 ) {
        particles[i].play(ofToString(hotspots[j].note));
        hotspots[j].status += 1;
      }
    }
    
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor(35, 35, 35), ofColor(5, 5, 5));
	// draw particles
  for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
  // draw hotspots
  for (int j = 0; j < hotspots.size(); j++) {
    hotspots[j].draw();
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  Particle newParticle;
  newParticle.reset();
  particles.push_back(newParticle);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
