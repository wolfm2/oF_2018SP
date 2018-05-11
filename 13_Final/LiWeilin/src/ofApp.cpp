#include "ofApp.h"


//3d shape
vector<ofPoint> vertices;
vector<ofColor> colors;
int nTri; //The number of triangles
int nVert; //The number of the vertices

//sound
const int N = 256;
float spectrum[ N ];
float Rad = 500; //stars radius
float Vel = 0.1; //stars velocity
int bandRad = 2; //Band index in spectrum, affecting Rad value
int bandVel = 100; //Band index in spectrum, affecting Vel value
const int n = 300; //Number of stars points
//Offsets for Perlin noise calculation for points
float tx[n], ty[n], tz[n];
ofPoint p[n]; //star's points positions
float time0 = 0;

//--------------------------------------------------------------
void ofApp::setup(){
    
    //3d
    nTri = 1500; //The number of the triangles
    nVert= nTri * 3; //The number of the vertices
    float Rads = 300; //sphere radius
    float rad = 5; //triangle radius

    vertices.resize( nVert ); //Set the array size
    for (int i=0; i<nTri; i++) {
        ofPoint center( ofRandom( -1, 1 ),
                       ofRandom( -1, 1 ),
                       ofRandom( -1, 1 ) );
        center.normalize(); //Normalize vector's length to 1
        center *= Rads;
        for (int j=0; j<3; j++) {
            vertices[ i*3 + j ] =center + ofPoint( ofRandom( -rad, rad ),
                                                  ofRandom( -rad, rad ),
                                                  ofRandom( -rad, rad ) );
        }
    }
    //Fill the array of triangles' colors
    colors.resize( nTri );
    for (int i=0; i<nTri; i++) {
        //Take a random color from black to red
        colors[i] = ofColor(ofRandom(50,150),ofRandom(50,150),ofRandom(50,150),ofRandom(50,150));
    }
    
    //gui.setup();
    //gui.add(spectrumAlpha.setup("spectrumAlpha",100,0,255));
    //gui.add(titleAlpha.setup("titleAlpha",100,0,255));
    //showGui = true;
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    //set font, image, video, sound
    myFont.load("Montserrat-Regular.ttf",12);
    
    video.load("stars.mp4");
    video.setLoopState(OF_LOOP_NORMAL);
    
    image.load("light.png");
    image2.load("galaxy.jpg");
    
    
    serial.setup( 1, 9600 );
    
    sound.load( "solitude.wav" );
    
    //fftsmooth
    fftSmooth = new float [8192];
    for (int k=0; k<8192; k++){
        fftSmooth[k] = 0;
    }
    sound.setLoop( true );
    sound.play();
    fftSmooth = new float [8192];
    for (int i=0; i<N; i++) {
        spectrum[i] = 0.0f;
        fftSmooth[i] = 0;
    }
    //Initialize points offsets by random numbers
    for ( int j=0; j<n; j++ ) {
        tx[j] = ofRandom( 0, 1000 );
        ty[j] = ofRandom( 0, 1000 );
        tz[j] = ofRandom( 0, 1000 );
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    video.update();
    
/*    //serial communication with Arduino
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
*/
    
    //Update sound engine
    ofSoundUpdate();
    //Get current spectrum with N bands
    float *val = ofSoundGetSpectrum( N );
    
    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.97; //Slow decreasing
        spectrum[i] = max( spectrum[i], val[i] );
    }
    
    for ( int k=0; k<N; k++){
        fftSmooth[k] *= 0.9f;
        if(fftSmooth[k]<val[k]){
            fftSmooth[k]=val[k];
        }
    }
    

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
        tz[j] += Vel * dt;
        //Calculate Perlin's noise in [-1, 1] and
        //multiply on Rad
        p[j].x = ofSignedNoise( tx[j] ) * Rad;
        p[j].y = ofSignedNoise( ty[j] ) * Rad;
        p[j].z = ofSignedNoise( ty[j] ) * Rad;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    video.draw(0, 0, ofGetWidth(), ofGetHeight());
    video.play();
    for(int k=0; k<N; k++){
    ofSetColor(255,fftSmooth[k]*255);
    myFont.drawString("Dancing Stars", 50, 70);
    }
    
    //ofEnableDepthTest();
    //Draw spectrum
    //ofSetColor(255 );
    for (int i=0; i<N; i++) {
        if ( i == bandRad || i == bandVel ) {
            ofSetColor(255); //Black color
        } else {
            ofSetColor( 128, 128, 128); //Gray color
        }
        ofDrawRectangle( 50 + i * 5, 700, 3, -spectrum[i] * 100 );
    }
    
    fbo.begin();
    ofSetColor(255,10);
    video.draw(0, 0, ofGetWidth(), ofGetHeight());
    video.play();
    ofSetColor(255,50);
    image2.draw(0, 0, ofGetWidth(), ofGetHeight());
    //sound.setVolume(vol);
    sound.setVolume(1);
    
    //Draw stars

    ofPushMatrix();
    ofTranslate( ofGetWidth() / 2, ofGetHeight() / 2 );
    //ofScale(dis,dis);
    //Draw star's points
    ofSetColor(ofRandom(50,150),ofRandom(50,150),ofRandom(50,150));
    ofFill();
    for (int i=0; i<n; i++) {
        image.draw( p[i], 30 ,30);
    }
    
    //Calculate the rotation angle
    float time = ofGetElapsedTimef();
    float angle = time * 5;
    ofRotate( angle, 0, 1, 0 );
    
    //Draw the triangles
    for (int i=0; i<nTri; i++) {
        ofSetColor( colors[i] ); //Set color
        ofDrawTriangle( vertices[ i*3 ],
                   vertices[ i*3 + 1 ],
                   vertices[ i*3 + 2 ] ); //Draw triangle
        ofDrawTriangle( vertices[ i*3 + 3 ],
                       vertices[ i*3 + 4 ],
                       vertices[ i*3 + 5 ] ); //Draw triangle
        ofDrawTriangle( vertices[ i*3 + 6 ],
                       vertices[ i*3 + 7 ],
                       vertices[ i*3 + 8 ] ); //Draw triangle
    }

    ofPopMatrix();
    fbo.end();
    
    ofSetColor(255,255,255);
    fbo.draw(0,0);


    
    
    //if ( showGui ) gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
            
    }
    
    //if ( key == 'z' ) showGui = !showGui;
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
