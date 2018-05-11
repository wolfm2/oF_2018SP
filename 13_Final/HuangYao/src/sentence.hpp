//
//  sentence.hpp
//  Yao
//
//  Created by Yao Huang on 5/10/18.
//

#include "ofMain.h"

class sentence{
    
public:
    sentence();
    void setup(string input);
    void update();
    void draw();
    
    string text;
    char character[100];
    ofPoint pos[100];
    ofPoint drop[100];
    ofPoint move;
    ofTrueTypeFont object;
    
    bool split= false;
    float posX;
    float posY;
};
