#pragma once
// ???????
#include "ofMain.h"


//??? is this build a class?
//what if you want to build a new class?
//the class name of this class is ofBaseApp?
class ofApp : public ofBaseApp{
    
    
    //Homework 1112
    //1st Step, declare variables:
    //圆的位置：【class类型 class名称】
    ofVec2f circlePosition;     //what is ofVec2f? ofVec2f是一个建立2维图像的class
    // 圆的速度
    ofVec2f circleVelocity;
    //建立圆的半径
    int radius;
    //建立圆的运动轨迹的摩擦---定义速度
    float friction;

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
		
};




