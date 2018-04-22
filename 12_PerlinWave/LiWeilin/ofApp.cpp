#include "ofApp.h"

const int N = 256; //Number of bands in spectrum
float spectrum[ N ]; //Smoothed spectrum values
float Rad = 500; //stars radius parameter
float Vel = 0.1; //stars points velocity parameter
int bandRad = 2; //Band index in spectrum, affecting Rad value
int bandVel = 100; //Band index in spectrum, affecting Vel value
const int n = 300; //Number of stars points
//Offsets for Perlin noise calculation for points
float tx[n], ty[n];
ofPoint p[n]; //star's points positions
float time0 = 0; //Time value, used for dt computing

//--------------------------------------------------------------
void ofApp::setup(){

    //set font, image, video, sound
    myFont.load("Montserrat-Regular.ttf",12);
    video.load("stars.mp4");
    image.load("light.png");
    serial.setup( 1, 9600 );
    sound.load( "solitude.wav" );
    sound.setLoop( true );
    sound.play();
    
    for (int i=0; i<N; i++) {
        spectrum[i] = 0.0f;
    }
    //Initialize points offsets by random numbers
    for ( int j=0; j<n; j++ ) {
        tx[j] = ofRandom( 0, 1000 );
        ty[j] = ofRandom( 0, 1000 );
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    video.update();
    
    //serial communication with Arduino
    while ( true ) {
        int c = serial.readByte();
        if ( c == OF_SERIAL_NO_DATA || c == OF_SERIAL_ERROR || c == 0 )
            break;
        if ( c == '\n' ) {
            //alpha  = ofToFloat( str );
            vector<string> list = ofSplitString( str, " " );
            if ( list.size() >= 3 ) {
                alpha = ofToFloat( list[0] );
                volume = ofToFloat( list[1] );
                distance = ofToFloat( list[2] );
            }
            str = "";
            alphaA = ofMap(alpha, 700, 940, 255, 150);
            vol = ofMap(volume, 0, 1023, 0, 1);
            dis = ofMap(distance, 0, 3200, 1.2, 1.6);
        }
        else str.push_back( c );
    }
    
    //Update sound engine
    ofSoundUpdate();
    //Get current spectrum with N bands
    float *val = ofSoundGetSpectrum( N );

    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.97; //Slow decreasing
        spectrum[i] = max( spectrum[i], val[i] );
    }
    
    //Update particles using spectrum values
    //Computing dt as a time between the last
    //and the current calling of update()
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp( dt, 0.0, 0.1 );
    time0 = time; //Store the current time
    //Update Rad and Vel from spectrum
    //map for current music
    Rad = ofMap( spectrum[ bandRad ], 1, 3, 400, 800, true );
    Vel = ofMap( spectrum[ bandVel ], 0, 0.1, 0.05, 0.5 );
    
    //Update particles positions
    for (int j=0; j<n; j++) {
        tx[j] += Vel * dt; //move offset
        ty[j] += Vel * dt; //move offset
        //Calculate Perlin's noise in [-1, 1] and
        //multiply on Rad
        p[j].x = ofSignedNoise( tx[j] ) * Rad;
        p[j].y = ofSignedNoise( ty[j] ) * Rad;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    sound.setVolume(vol);
    ofBackground(0);
    video.draw(0, 0, ofGetWidth(), ofGetHeight());
    video.play();
    
    ofSetColor(255);
    myFont.drawString("Dancing Stars", 50, 70);

    //Draw spectrum
    ofSetColor(255 );
    for (int i=0; i<N; i++) {
        //Draw bandRad and bandVel by black color,
        //and other by gray color
        if ( i == bandRad || i == bandVel ) {
            ofSetColor(255); //Black color
        } else {
            ofSetColor( 128, 128, 128 ); //Gray color
        }
        ofDrawRectangle( 50 + i * 5, 700, 3, -spectrum[i] * 100 );
    }
    
    
    //Draw stars
    //Move center of coordinate system to the screen center
    
    ofPushMatrix();
    //fbo.begin();
    ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
    ofScale(dis,dis);
    //Draw cloud's points
    ofSetColor(ofRandom(50,150),ofRandom(50,150),ofRandom(50,150),alphaA);
    ofFill();
    for (int i=0; i<n; i++) {
        //ofDrawCircle( p[i], 2 );
        image.draw( p[i], 20 ,20);
    }

    //Restore coordinate system
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
            
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
