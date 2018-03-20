//
//  Hotspot.hpp
//  particlesAdvanced
//
//  Created by Philipp Schmitt on 01.12.17.
//

#ifndef Hotspot_hpp
#define Hotspot_hpp

#include <stdio.h>
#include "ofMain.h"

class Hotspot {
public:
  void setup(int x, int y, int _note);
  void draw();
  
  ofPoint position;
  int note;
  int status;
  
};


#endif /* Hotspot_hpp */
