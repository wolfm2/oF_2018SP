#include "ofApp.h"
#include <math.h> 

ofEasyCam easyCam;


ofImage spider;
ofImage buildL;
ofImage buildR1, buildR2, buildR3;
ofSoundPlayer soundBlow;

//adjustable for creating mesh

float threshold = 30;
float connectDistance = 5;

int numVertices;
int width ;
int height;
int x, y, z;
float intensity;
float hue;
float saturation;
ofColor c;

float realDistance;

//for mouse controlling
int mouseCircleX;
int mouseCircleY;
ofVec2f mouseCircle2d;
int mouseCircleRadius =50;
ofVec3f testSphere;

int keyPressedControllingDepth;

// for spiderFlying
float xRotate, yRotate, zRotate = 0;
float spiderScale =1;
int xTranslate, yTranslate;
ofVec2f screenPos;
ofVec3f worldPos;
ofVec2f mousePre;
ofVec2f movePos;
ofVec2f dest;
float speed =0.1;
int ballMark=0;

//--------------------------------------------------------------
void ofApp::setup(){
	
    ofSetWindowShape(1000, 800);
	spider.load("whole.png");
    buildL.load("buildL.png");
    buildR1.load("buildR1.png");
    buildR2.load("buildR2.png");
    buildR3.load("buildR3.png");
    soundBlow.load("blow.wav");
    
	width = spider.getWidth();
	height = spider.getHeight();


	//****************ENABLE------ MODE/ COLOR/ INDEX******************
	//mesh.setMode(OF_PRIMITIVE_POINTS);
	mesh.setMode(OF_PRIMITIVE_LINES);			//v1-v2; v3-v4
	//mesh.setMode(OF_PRIMITIVE_LINE_STRIP);		//v1-v2; v2-v3; v3-v4
	//mesh.setMode(OF_PRIMITIVE_LINE_LOOP);		//v1-v2; v2-v3; v3-v4; v4-v1

	mesh.enableColors();

	mesh.enableIndices();

	//****************Example of how to use mesh vertex******************
	//****************ADD---------VERTEX/ COLOR/ INDEX***************
	//ofVec3f top(100.0, 50.0, 0.0);
	//mesh.addVertex(top);
	//mesh.addColor(ofFloatColor(1.0, 0.0, 0.0)); // Red
	//mesh.addIndex(0);
	//mesh.addIndex(1);
	


	for (x = 0; x<width; ++x) {
		for (y = 0; y<height; ++y) {
			c = spider.getColor(x, y);
			intensity = c.getLightness();
			
			if (intensity >= threshold) {
				saturation = c.getSaturation();
				z = ofMap(saturation, 0, 255, -100, 100);
				ofVec3f pos(x, y, 0);
				mesh.addVertex(pos);
				// When addColor(...), the mesh will automatically convert
				// the ofColor to an ofFloatColor
				mesh.addColor(c);
			}
		}
	}


	numVertices = mesh.getNumVertices();
	//cout << numVertices;
	for (int a = 0; a<numVertices; ++a) {
		ofVec3f verta = mesh.getVertex(a);
		if (a == 50) {
			testSphere = verta;
	
		}
		for (int b = a + 1; b<numVertices; ++b) {
			ofVec3f vertb = mesh.getVertex(b);
			realDistance = verta.distance(vertb);
			if (realDistance <= connectDistance) {
				// In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
				// connected to form a line
				mesh.addIndex(a);
				mesh.addIndex(b);
			}
		}
	}
	
}


/*void ball(ofVec2f vect, ofVec2f dest){
    movePos.x = vect.x;
    movePos.y = vect.y;
    while (1){
        movePos.x+= (dest.x-movePos.x)/vect.distance(dest)*speed;
        movePos.y+= (dest.y -movePos.y)/vect.distance(dest)*speed;
        ofDrawCircle(movePos.x, movePos.y, 5);
        if (dest.distance(movePos)<5){
            break;
        }
    }
    
}*/
//--------------------------------------------------------------
void ofApp::update(){

	//cout << "x" << ofGetMouseX()<<"y"<<ofGetMouseY()<<"\n";

	mouseCircleX = ofGetMouseX();
	mouseCircleY = ofGetMouseY();
	mouseCircle2d.x = mouseCircleX-314;
	mouseCircle2d.y = mouseCircleY-581;
	mouseCircle2d.y *= -1;
	//cout << mouseCircle2d.x << "|" << mouseCircle2d.y;
	
	
	switch (keyPressedControllingDepth){
	case 1:
		for (int i = 0; i < numVertices; ++i) {
			ofVec3f vertTemp = mesh.getVertex(i);
			ofVec2f vertTemp2d;
			vertTemp2d.x = vertTemp.x;
			vertTemp2d.y = vertTemp.y;
			if (mouseCircle2d.distance(vertTemp2d) < mouseCircleRadius) {
				float deltaZOrigin = ofMap(mouseCircle2d.distance(vertTemp2d), 0, mouseCircleRadius, 0, PI/6);
				float deltaZ = cos(deltaZOrigin)-0.5;
				vertTemp.z -= deltaZ*10;
				mesh.setVertex(i, vertTemp);
			}
		}
		keyPressedControllingDepth = 0;
		break;
	case -1:
		for (int i = 0; i < numVertices; ++i) {
			ofVec3f vertTemp = mesh.getVertex(i);
			ofVec2f vertTemp2d;
			vertTemp2d.x = vertTemp.x;
			vertTemp2d.y = vertTemp.y;
			if (mouseCircle2d.distance(vertTemp2d) < mouseCircleRadius) {
				float deltaZOrigin = ofMap(mouseCircle2d.distance(vertTemp2d), 0, mouseCircleRadius, 0, PI/6);
				float deltaZ = cos(deltaZOrigin)-0.5;
				vertTemp.z += deltaZ*10;
				mesh.setVertex(i, vertTemp);
			}
		}
		keyPressedControllingDepth = 0;
		break;
	
	}

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(50,50,50);
    ofSetColor(255, 255, 255);
    buildL.draw(0,0,0);
    buildR1.draw(710,200);
    buildR2.draw(780,200);
    buildR3.draw(900,200);
    
	easyCam.begin();
		ofPushMatrix();
            //----300,350 x,y
            ofTranslate(xTranslate, yTranslate);
            ofRotateX(xRotate);
            ofRotateY(yRotate);
            ofRotateZ(zRotate);
            ofScale(spiderScale,spiderScale);
                mesh.draw();
                ofSetColor(255, 255, 255);
                ofDrawSphere(testSphere, 10);
                //cout << testSphere.x << "/" << testSphere.y << "/" << testSphere.z<<"\n";
                ofDrawAxis(100);
		ofPopMatrix();
	easyCam.end();

	ofSetColor(0, 255, 0,10);
	ofDrawCircle(mouseCircleX, mouseCircleY, mouseCircleRadius);
	
//    ball(mousePre,dest);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key)
	{
            
		case 'w':
            soundBlow.play();
			keyPressedControllingDepth = 1;
			break;
		case 's':
            soundBlow.play();
			keyPressedControllingDepth = -1;
			break;
        case 'f':
            mousePre.set(ofGetMouseX(), ofGetMouseY());
            cout<<mousePre;
		default:
			break;
	}

	//cout << keyPressedControllingDepth<<"\n";
}



void actAsRight(int x, int y){
    
 
    //zRotate = 30;
    xTranslate = x-mousePre.x;
    yTranslate = mousePre.y-y;
   
    dest.set(x,y);
    ballMark=1;
    
   
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
    if(x>=700&&x<=1000&&y>=200&&y<=800){
        actAsRight(x,y);
        
    }
    
    easyCam.reset();
    cout<<ofGetMouseX()<<"|"<<ofGetMouseY();
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



//710,210    900,200
//815,770    1000,800
