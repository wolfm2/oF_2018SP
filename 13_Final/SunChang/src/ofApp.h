#pragma once

#include "ofMain.h"

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
    
    
    ofSoundPlayer         song;
    int nBandsToGet;
		
};





class Ball{

    
public:
    Ball();
    void setup();
    void update();
    void draw();
    //_______________________________________________
    float radius;   // this is the radius of the ball
    //    float t1;       // noise 1
    //    float t2;       // noise 2
    //    float inc;      // this is the increment of the t of noise
    float clr;
    float x;
    float y;
private:

    
    //
    float scale;
    float size;
   
    
    float time;
    // 让time random变的数值
    float n;
    
    // 乘以ofNoise的参数
    float a,b,c;
    
    
    //移动速度
    float X;
    float Y;
    
    ofColor color;
    
};


