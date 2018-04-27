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
		
    
    ofTrueTypeFont myFont;
};



class line{
    
    
public:
    line();
    void setup();
    void update();
    void draw();
    
    
    ofPoint position;
    
private:
    //这是角度：
    float rX;
    float rY;
    float rZ;
    
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
    float Z;
    
    ofColor color;
    
};
