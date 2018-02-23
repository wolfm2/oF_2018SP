#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	int numParticles = 50;
	for (int i = 0; i < numParticles; i++) {
		Particle newParticle;
		newParticle.reset();
		particles.push_back(newParticle);
	}
//    fbo.allocate(ofGetWidth(), ofGetHeight());
//    fbo.begin();
//    ofClear(25,25,25);
//    fbo.end();
    //want fbo on mosquito
    
    flykill.load("flykill.png");
    room.load("room.jpeg");
    mosquito.load("mosquito.png");
    mosquito1.load("mosquito1.mp3");
    mosquito1.setVolume(0.5);
    mosquito1.play();
    mosquito1.setLoop(true);
    


}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < particles.size(); i++) {
		particles[i].update();
        if(particles[i].position.x > ofGetWidth() || particles[i].position.x < 0) {
            particles[i].velocity.x *= -1;
        }
        if(particles[i].position.y > ofGetHeight() || particles[i].position.y < 0) {
            particles[i].velocity.y *= -5;
        }
        
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
    room.draw(0,0, 1100,850);

	for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
	}
    flykill.draw(ofGetMouseX()-30,ofGetMouseY()-30,280,280);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for (int i = 0; i < particles.size(); i++) {
        particles[i].toggleMode();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
//    fbo.begin();
//    ofCircle(0, 0, 30);
//    fbo.end();
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
