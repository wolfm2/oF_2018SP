
/**
 *
 *
 * project01 openframeworks homework
 *
 *
 *by Rita Zhang  Jan 27 2018
 *zhanr526@newschool.edu
 *
 */

#include "ofMain.h"
#include "ofApp.h"


//========================================================================
using namespace std;

int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
    cout << "Hello world!"<< endl;
    return 0;
    //if without using namespace std. need write:
    //std::cout << "Hello world" << std::endl;
    

}
