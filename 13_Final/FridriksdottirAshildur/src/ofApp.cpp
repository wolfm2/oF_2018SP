#include "ofApp.h"
int byteData;
//--------------------------------------------------------------
void ofApp::setup(){
    
    
    
//    sampleRate = 44100;
//    bufferSize = 512;
    
    for( int i = 0; i < n.size(); i ++) {
        
        keys.emplace_back( new Key(n[i]));
    }
    
//    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
    
    serial.setup("/dev/cu.usbmodem144231", 9600);
    
    
    
    ofSetFrameRate(30);
    ofSetBackgroundColor(0);
    phase = 0;
    totalSum = 0;
    ofSoundStreamSetup(2, 0); // 2 output channels (stereo), 0 input channels
    updateWaveform(32);
    ofstream myfile;
    myfile.open ("verdana.ttf");
    font.load("verdana.ttf", 14, true, true);
    
    for(int i = 0 ; i < dimension ; i++){
        for(int j = 0 ; j < dimension ; j++){
            totalSum += i*j;
            cells[i][j] = Cell::Cell();
        }
    }
    
    for(int i = 0 ; i < dimension ; i++){
        for(int j = 0 ; j < dimension ; j++){
            if(i > 0 && j > 0)
                cells[i][j].addNeighbour(&cells[i-1][j-1]);
            if(i > 0)
                cells[i][j].addNeighbour(&cells[i-1][j]);
            if(i > 0 && j < dimension)
                cells[i][j].addNeighbour(&cells[i-1][j+1]);
            if(j > 0)
                cells[i][j].addNeighbour(&cells[i][j-1]);
            if(j < dimension)
                cells[i][j].addNeighbour(&cells[i][j+1]);
            if(i < dimension && j > 0)
                cells[i][j].addNeighbour(&cells[i+1][j-1]);
            if(i < dimension)
                cells[i][j].addNeighbour(&cells[i+1][j]);
            if(i < dimension && j < dimension)
                cells[i][j].addNeighbour(&cells[i+1][j+1]);
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    float sum = 0;
    float nCellsAlive = 0;
    for(int i = 0 ; i < dimension ; i++){
        for(int j = 0 ; j < dimension ; j++){
            cells[i][j].update();
        }
    }
    for(int i = 0 ; i < dimension ; i++){
        for(int j = 0 ; j < dimension ; j++){
            cells[i][j].Cell::updateStatus();
            nCellsAlive++;
            sum += float(i*j) * float(cells[i][j].getStatus());
        }
    }

    frequency = ofMap(sum, 0, totalSum, 200, 2000, true);
    
    ofSetColor(0, 0, 0);
    //Simple if statement to inform user if Arduino is sending serial messages.
    if (serial.available() < 0) {
        msg = "Arduino Error";
    }
    else {
        //While statement looping through serial messages when serial is being provided.
        while (serial.available() > 0) {
            
            //byte data is being writen into byteData as int.
            byteData = serial.readByte();
            
            //byteData is converted into a string for drawing later.
            msg = "cm: " + ofToString(byteData);
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if(byteData >= 0 && byteData <= 2 ){
        keys[0]->on();
        
    }else{
        keys[0]->off();
    }
    if(byteData >= 3 && byteData <= 4){
        keys[1]->on();
        ofSetColor(255, 99, 99);
       
        
       
        

    }else{
        keys[1]->off();
    }
    if(byteData >= 5 && byteData <= 6){
        keys[2]->on();
        for(int i = 0 ; i < dimension ; i++){
            for(int j = 0 ; j < dimension ; j++){
                cells[i][j].randomizeStatus();
            }
           
            
        }
    }else{
        keys[2]->off();
    }
    if(byteData >= 7 && byteData <= 8){
        keys[3]->on();
        for(int i = 0 ; i < dimension ; i++){
            for(int j = 0 ; j < dimension ; j++){
                cells[i][j].randomizeStatus();
            }
            
            
        }
    }else{
        keys[3]->off();
    }
    if(byteData >= 9 && byteData <= 10){
        
        keys[4]->on();
    }else{
        keys[4]->off();
    }
    if(byteData >= 11 && byteData <= 12){
        keys[5]->on();
    }else{
        keys[5]->off();
    }
    if(byteData >= 13 && byteData <= 14){
        keys[6]->on();
    }else{
        keys[6]->off();
    }
    if(byteData >= 15 && byteData <= 16){
        keys[7]->on();
    }else{
        keys[7]->off();
        
    }
    
    int color = ofMap(frequency, 200, 2000, 100, 255);
    ofSetColor(color);
    for(int i = 1 ; i <= dimension ; i++){
        for(int j = 1 ; j <= dimension ; j++){
            if(cells[i-1][j-1].getStatus() == 1){
                
                ofDrawCircle(i*spacing, j*spacing, radius);

                ofDrawLine(i*spacing, j*spacing, ofRandom(400), ofRandom(400));
            }
        }
    }
    
   
    //drawing the string version pf byteData on oF window.
    font.drawString(msg, 600, 100);
    
   
    
    //printing byteData into console.
    cout << byteData << endl;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
//    for(int i = 0 ; i < dimension ; i++){
//        for(int j = 0 ; j < dimension ; j++){
//            cells[i][j].randomizeStatus();
//        }
//    }
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

void ofApp::updateWaveform(int waveformResolution) {
    waveform.resize(waveformResolution);
    
    // "waveformStep" maps a full oscillation of sin() to the size
    // of the waveform lookup table
    float waveformStep = (M_PI * 2.) / (float) waveform.size();
    
    for(int i = 0; i < waveform.size(); i++) {
        waveform[i] = sin(i * waveformStep);
    }
}

void ofApp::audioOut( float * output, int bufferSize, int nChannels ) {
    ofScopedLock waveFormLock(waveformMutex);
    float phaseStep = frequency/sampleRate;

    for(int i = 0; i < bufferSize * nChannels; i += 2) {
        phase += phaseStep;
        int waveformIndex = (int)(phase * waveform.size()) % (waveform.size());
        output[i] = waveform[waveformIndex];
        output[i+1] = waveform[waveformIndex];
    }
    
//    ??? f ofan
    
    //    for ( int i = 0; i < bufferSize; i ++) {
    //
    //        freq = byteData * 100;
    //
    //        wave = osc.sinewave(freq);
    //
    //        output[i * nChannels] = wave ;
    //        output[ i * nChannels + 1] = wave;
    //
    //    }
    for(int i = 0; i < bufferSize; i ++) {
        
        for(int j = 0; j < n.size(); j ++) {
            
            notes += keys[j]->play() / n.size();
        }
        
        myMix.stereo(notes, outputs, 0.5);
        
        output[i * nChannels] = outputs[0];
        output[i * nChannels + 1] = outputs[1];
        
    }

}
