//
//  Cell.h
//  GameOfLife
//
//  Created by Hippolyte Dubois on 29/09/16.
//
//

#pragma once
#include <vector>
class Cell {
    private :
    int state;
    int isDying;
    int isGrowing;
    std::vector<Cell*> neighbours;
    
public:
    Cell();
    void update();
    void updateStatus();
    void randomizeStatus();
    void addNeighbour(Cell *neighbour);
    int getStatus();
};
