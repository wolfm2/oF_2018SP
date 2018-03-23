
#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main(){
    ofSetupOpenGL(640, 520,OF_WINDOW);            // <-------- setup the GL context
    
    ofRunApp(new ofApp());
}
