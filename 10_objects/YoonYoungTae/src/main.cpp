#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}

//Identify all the variables and functions required to make the square move.
//Write a class that encapsulates all the above variables, with an update and draw method in a class declaration.
//The class should include two other methods: setCUSpeed, and setColor.  Both should be called only once from the constructor.
//Make 5 objects of this class each initialized with a different catchUpSpeed and color.
//Each should start at a random x,y within the canvas.
//The ONLY globals should be your 5 objects.

