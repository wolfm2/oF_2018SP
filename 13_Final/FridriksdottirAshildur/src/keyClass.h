#ifndef __keyboardofxMaxim__keyClass__
#define __keyboardofxMaxim__keyClass__

#include <stdio.h>
#include "ofxMaxim.h"

class Key {
    
public:
    
    maxiOsc osc;
    maxiEnv env;
    
    double freq;
    Key( double _f);
    
    double play();
    void on();
    void off();
    
};

#endif /* defined(__keyboardofxMaxim__keyClass__) */

