//
//  agent.cpp
//  midterm_chouchou
//
//  Created by 江旻哲 on 4/20/18.
//

#include "agent.hpp"

#define MAX_AGENTS 100
// constructor
agent::agent(){
    velDir.set(0, ofRandom(.5, 2));    // init random speed
    velDir.rotate(ofRandom(360));        // init random direction
    
    mouse.set(0,0);
}

// update all variables in an agent
void agent::update(agent *arr){  // influence the main vector
    ofVec2f noVec(-1,-1);
    
    if (!active)
        return;
    
    // Where are agents near you headed? Align with that.
    float alignDelta = calcAlignment(arr, MAX_AGENTS);    // set up alignment
    velDir.rotate(alignDelta*.05);            // apply alignment delta (weighted)
    
    
    if (location.distance(mouse) < 100) {                // set mouse gravity
        float alignMouse = velDir.angle(mouse - location);  // velDir vector delta from distance between mouse & location
        velDir.rotate(alignMouse*.06);            // apply mouse gravity (weighted)
    }
    
    // For agents nearby, get centroid, head that way
    ofVec2f middle = calcCohesion(arr, MAX_AGENTS);    // get centroid of nearby mass of agents
    if (middle != noVec) {
        float alignMouse = velDir.angle(middle - location);    // delta between centroid & location gives us a VECTOR
        velDir.rotate(alignMouse*.02);            // apply centroid gravity (weighted)
    }
    
    // For too-close agents try to move away from them
    ofVec2f tooClose = calcDispersion(arr, MAX_AGENTS);        // get avg heading of too-close agents
    if (tooClose != noVec) {
        float tooCloseDelta;
        if (velDir.angle((tooClose - location)) < 0)             // if it is on our left side
            tooCloseDelta = velDir.angle((tooClose - location).rotate(90));    // move opposite to mass
        else
            tooCloseDelta = velDir.angle((tooClose - location).rotate(-90));  // move opposite to mass
        velDir.rotate(tooCloseDelta*.03);                    // apply centroid gravity (weighted)
    }
    
    location += velDir;    // move to current location
}

void agent::draw(){
    if (!active)          // if not active, do nothing
        return;
    
    ofVec2f top(0,-1);        // top of origin used as control, point up
    ofVec2f p1(6.25,  12);    // triangle pointing up w middle at origin
    ofVec2f p2(0, -12);
    ofVec2f p3(-6.25,  12);
    
    float angle = top.angle(velDir);    // get direction angle, differenct between point up to the movement angle
    
    p1.rotate(angle);    // point in direction of movement
    p2.rotate(angle);
    p3.rotate(angle);
    
    // if it moves off the board, move it to opposite side
    if (location.x > ofGetWidth()) location.x = 0;
    if (location.x < 0) location.x = ofGetWidth();
    if (location.y > ofGetHeight()) location.y = 0;
    if (location.y < 0) location.y = ofGetHeight();
    
    p1 += location;    // move to current location
    p2 += location;
    p3 += location;
    ofDrawTriangle(p1, p2, p3);
    
}

void agent::start(float x, float y){
    active = true; // turn this one on!
    location.set(x,y);
}


// Get relative angle from me -180  180
float agent::getRelAngle(ofVec2f neighbor){
    float angle = velDir.angle(neighbor);
    return (angle);
}


// get mouse location for gravity
void agent::calcGravityWell(float x,float y){
    mouse.set(x,y);
}

// average & return neighbor's VECTORS
float agent::calcAlignment(agent* arr, int max){
    float sum = 0;  // sum of angles
    int sumNum = 0; // num of angles summed
    
    for (int i=0; i < max; i++) {
        float distance = location.distance(arr[i].location);
        if (distance < 150 && distance > 0 && arr[i].active) {     // if a neighbor is close & active
            //cout  << " Dist: " << distance << "\n";
            sum += getRelAngle(arr[i].velDir);            // add its angle to sum
            sumNum++;                            // count how many are summed
        }
    }
    if (sumNum > 0) {   // avoid div by 0
        return(sum/sumNum);
    } else
        return(0);
}

// average and return neighbor's LOCATIONS
ofVec2f agent::calcCohesion(agent* arr, int max){
    ofVec2f centroid, nearArr[max];                // centroid & arr of Neighbors near us
    int lenArr = 0;
    
    for (int i=0; i < max; i++) {
        float distance = location.distance(arr[i].location);
        
        if (distance < 70 && distance > 20 && arr[i].active) {     // if a neighbor is close & active
            nearArr[lenArr] = arr[i].location;            // add its location to array
            lenArr++;                            // count how many are added
        }
    }
    
    if (lenArr > 0) {
        centroid.average(nearArr, lenArr);    // average the location of all neighbor agents
        return (centroid);
    } else {
        ofVec2f noVec(-1,-1);
        return (noVec);              // no nearby agents
    }
}

// average and return too-close neighbor's LOCATIONS
ofVec2f agent::calcDispersion(agent *arr, int max){
    ofVec2f centroid, nearArr[max];        // centroid & arr of Neighbors near us
    int lenArr = 0;
    
    for (int i=0; i < max; i++) {
        float distance = location.distance(arr[i].location);
        
        if (distance < 20 && arr[i].active) {     // if a neighbor is close & active
            nearArr[lenArr] = arr[i].location;    // add its location to array
            lenArr++;                    // count how many are added
        }
    }
    
    if (lenArr > 0) {
        centroid.average(nearArr, lenArr);        // average the location of all too-close neighbor agents
        return (centroid);
    } else {
        ofVec2f noVec(-1,-1);
        return (noVec);                // no nearby agents
    }
}


