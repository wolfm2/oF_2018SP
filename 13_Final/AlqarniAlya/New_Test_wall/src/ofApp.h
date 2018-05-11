#pragma once
#include "ofMain.h"
#include "lineBrush.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    lineBrush brush1; // added Brush1 class based on your brush (see Brush1.hpp, Brush1.cpp)
    LineBrush brush2; // added sample Brush2 class with red circle (see above)
    Brush3 brush3;
    ParticleSystem brush4;
    
    
    int brush = 1;    // which brush # are we using?
    
    int page = 1; // what page are we on? (i.e. which background to draw?)
    
    
    //brush 1
    ofPolyline straightSegmentPolyline;
    ofPolyline curvedSegmentPolyline;
    ofPolyline closedShapePolyline;
    ofPolyline currentPolyline;
    bool LeftMouseButtonPressed;
    ofVec2f lastpoint;
    float minDistance;
    vector <ofPolyline> polylines;
    int r,g,b;
    
    //    //brush3
    //    vector<Brush3> Brush3vec;
    //    ofVec3f gravity;
    //    float lastUpdateTime;
    
    
    // add images
    
    ofImage night;
    ofImage tree;
    ofImage boy;
    ofImage boy1;
    ofImage boy3;
    
    //add text
    
    ofTrueTypeFont     Avenir;
    string introString;
    
    //brush 4
    float lastUpdateTime;
    vector<ParticleSystem> systems;
    ofVec3f gravity;
    
    ofEasyCam cam;
    
    ofEasyCam cam1;
    
    
};
};
