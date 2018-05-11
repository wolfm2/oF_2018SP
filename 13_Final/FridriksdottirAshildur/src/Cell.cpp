//
//  Cell.cpp
//  GameOfLife
//
//  Created by Hippolyte Dubois on 29/09/16.
//
//

#include <stdio.h>
#include "Cell.h"
#include <cstdlib>

Cell::Cell(){
    state = std::rand()%2;
    isDying = 0;
    isGrowing = 0;
}

void Cell::update(){
    int neighboursAlive = 0;
    for(Cell *c : neighbours){
        neighboursAlive+= c->getStatus();
    }
    
    if(state == 1 && neighboursAlive < 2){
        //DIES
        isDying = 1;
    } else if(state == 1 && neighboursAlive > 3){
        //DIES
        isDying = 1;
    } else if(neighboursAlive == 3){
        isGrowing = 1;
    }
}

void Cell::updateStatus(){
    if(isDying)
        state = 0;
    if(isGrowing)
        state = 1;
    isDying = 0;
    isGrowing = 0;
}

void Cell::randomizeStatus(){
    state = std::rand()%2;
}

void Cell::addNeighbour(Cell *neighbour){
    neighbours.push_back(neighbour);
}

int Cell::getStatus(){
    return state;
}
