
#include "keyClass.h"

Key::Key(double _f) {
    
    freq = _f;
    
    env.setAttack(1000);
    env.setDecay(1);
    env.setSustain(1);
    env.setRelease(1000);
    
}

void Key::on() {
    
    env.trigger = 1;
}

void Key::off() {
    
    env.trigger = 0;
}

double Key:: play(){
    
    return env.adsr(osc.sinewave(freq), env.trigger);
    
}

