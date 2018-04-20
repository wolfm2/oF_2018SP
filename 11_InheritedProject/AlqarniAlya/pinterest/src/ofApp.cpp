#include "ofApp.h"
#include <iostream>
#include <string>

ofSoundPlayer boop;


//--------------------------------------------------------------
void ofApp::setup(){
    
    //load font
    myFont.load("mono.ttf",14);
    image.loadImage("pinterest.jpg");
    pinimage.loadImage("ab.png");
    stone.loadImage("stone.png");
    sunset.loadImage("sunset.png");
    cave.loadImage("cave.jpg");
    ofBackground(255);  //set backgound color
    
    boop.loadSound("Small World.mp3");
    boop.play();
    
    //---------- init my button ---------
    mostPopular.setup(150, ofRandom(ofGetWidth()-200)+100, ofRandom(ofGetHeight()-200)+400, ofColor::red);
    ofDrawRectangle(150, 178, 400, 30);
    ofSetColor(255);  //Font color
    myFont.drawString(" press M to go to most popular pins", 160, 200);
    
    ofAddListener(mostPopular.clickedInside, this, &ofApp::onMouseInCircle);
    ofAddListener(myButtons::clickedInsideGlobal , this, &ofApp::onMouseInAnyCircle);
   
    
    //-------------------------------------------------------
    
    
    std::string url = "https://api.pinterest.com/v3/pidgets/boards/highquality/travel/pins/";
    //std::string url = "http://api.nytimes.com/svc/search/v2/articlesearch.json?q=new+york+times&page=2&sort=oldest&api-key=52697f63c9ade478ec6f2c7d71811aa6:17:61363877";
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);
    
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    mostPopular.draw();
    ofPushStyle();
    ofSetColor(0);
    
    
    ofDrawRectangle(clickedPoint, 10, 10);
    ofPopStyle();
    
    
    ofSetColor(255,255,255);
    image.draw(0,0,200, 100); // image of pinterest logo
    pinimage.draw(600,0, 378, 200);//image of account
    
  
    ofSetColor(255, 0, 102);//Button's color
    ofDrawRectangle(20, 178, 120, 30);
    ofSetColor(255);  //Font color
    myFont.drawString("Color Map", 30, 200);
    // building the "color map" button
    

//    ofSetColor(255, 102, 153);
//    ofDrawRectangle(150, 178, 400, 30);
//    ofSetColor(255);  //Font color
//    myFont.drawString(" press M to go to most popular pins", 160, 200);
    //building the "Most popupar pins" button
    
    
    
    ofSetColor(0);
    myFont.drawString("Pinterest Travel Pins",10, 100);
    ofDrawLine(10, 120, 750, 120);
    //Building the title
    
   // ________________________________________________
    
    Location = json["data"]["pins"][0]["pinner"]["location"].asString();
    myFont.drawString(Location,10, 150);
    
    DominantColor = json["data"]["pins"][0]["dominant_color"].asString();
    myFont.drawString(DominantColor, 10,250);
    ofColor c = ofColor::fromHex(0xa99076);
    ofSetColor(c);
    ofDrawRectangle(90, 238, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][1]["dominant_color"].asString();
    myFont.drawString(DominantColor, 160, 250);
    ofColor d = ofColor::fromHex(0x838a97);
    ofSetColor(d);
    ofDrawRectangle(240, 238, 40, 10);
    
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][2]["dominant_color"].asString();
    myFont.drawString(DominantColor, 310, 250);
    ofColor e = ofColor::fromHex(0x7495ad);
    ofSetColor(e);
    ofDrawRectangle(390, 238, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][3]["dominant_color"].asString();
    myFont.drawString(DominantColor, 460, 250);
    ofColor f = ofColor::fromHex(0x533717);
    ofSetColor(f);
    ofDrawRectangle(540, 238, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][4]["dominant_color"].asString();
    myFont.drawString(DominantColor, 610, 250);
    ofColor g = ofColor::fromHex(0x535348);
    ofSetColor(g);
    ofDrawRectangle(690, 238, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][5]["dominant_color"].asString();
    myFont.drawString(DominantColor, 760, 250);
    ofColor h = ofColor::fromHex(0x383838);
    ofSetColor(h);
    ofDrawRectangle(840, 238, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][6]["dominant_color"].asString();
    myFont.drawString(DominantColor, 10, 300);
    ofColor j = ofColor::fromHex(0x1f1b2c);
    ofSetColor(j);
    ofDrawRectangle(90, 288, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][7]["dominant_color"].asString();
    myFont.drawString(DominantColor, 160, 300);
    ofColor k = ofColor::fromHex(0x634b33);
    ofSetColor(k);
    ofDrawRectangle(240, 288, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][8]["dominant_color"].asString();
    myFont.drawString(DominantColor, 310, 300);
    ofColor l = ofColor::fromHex(0x587ab5);
    ofSetColor(l);
    ofDrawRectangle(390, 288, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][9]["dominant_color"].asString();
    myFont.drawString(DominantColor, 460, 300);
    ofColor q = ofColor::fromHex(0xf3e4ca);
    ofSetColor(q);
    ofDrawRectangle(540, 288, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][10]["dominant_color"].asString();
    myFont.drawString(DominantColor, 610, 300);
    ofColor w = ofColor::fromHex(0x433226);
    ofSetColor(w);
    ofDrawRectangle(690, 288, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][11]["dominant_color"].asString();
    myFont.drawString(DominantColor, 760, 300);
    ofColor r = ofColor::fromHex(0x12262f);
    ofSetColor(r);
    ofDrawRectangle(840, 288, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][12]["dominant_color"].asString();
    myFont.drawString(DominantColor, 10, 350);
    ofColor t = ofColor::fromHex(0x4f4e27);
    ofSetColor(t);
    ofDrawRectangle(90, 338, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][13]["dominant_color"].asString();
    myFont.drawString(DominantColor, 160, 350);
    ofColor y = ofColor::fromHex(0x434f4d);
    ofSetColor(y);
    ofDrawRectangle(240, 338, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][14]["dominant_color"].asString();
    myFont.drawString(DominantColor, 310, 350);
    ofColor u = ofColor::fromHex(0x3e6575);
    ofSetColor(u);
    ofDrawRectangle(390, 338, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][15]["dominant_color"].asString();
    myFont.drawString(DominantColor, 460, 350);
    ofColor i = ofColor::fromHex(0x7d6d69);
    ofSetColor(i);
    ofDrawRectangle(540, 338, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][16]["dominant_color"].asString();
    myFont.drawString(DominantColor, 610, 350);
    ofColor o = ofColor::fromHex(0x6c5a68);
    ofSetColor(o);
    ofDrawRectangle(690, 338, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][17]["dominant_color"].asString();
    myFont.drawString(DominantColor, 760, 350);
    ofColor p = ofColor::fromHex(0x66c6c7);
    ofSetColor(p);
    ofDrawRectangle(840, 338, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][18]["dominant_color"].asString();
    myFont.drawString(DominantColor, 10, 400);
    ofColor z = ofColor::fromHex(0x787072);
    ofSetColor(z);
    ofDrawRectangle(90, 388, 40, 10);
    
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][19]["dominant_color"].asString();
    myFont.drawString(DominantColor, 160, 400);
    ofColor x = ofColor::fromHex(0x5a5c5f);
    ofSetColor(x);
    ofDrawRectangle(240, 388, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][20]["dominant_color"].asString();
    myFont.drawString(DominantColor, 310, 400);
    ofColor v = ofColor::fromHex(0x535d73);
    ofSetColor(v);
    ofDrawRectangle(390, 388, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][21]["dominant_color"].asString();
    myFont.drawString(DominantColor, 460, 400);
    ofColor n = ofColor::fromHex(0x5b6668);
    ofSetColor(n);
    ofDrawRectangle(540, 388, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][22]["dominant_color"].asString();
    myFont.drawString(DominantColor, 610, 400);
    ofColor m = ofColor::fromHex(0x806739);
    ofSetColor(m);
    ofDrawRectangle(690, 388, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][23]["dominant_color"].asString();
    myFont.drawString(DominantColor, 760, 400);
    ofColor aa = ofColor::fromHex(0x70706d);
    ofSetColor(aa);
    ofDrawRectangle(840, 388, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][24]["dominant_color"].asString();
    myFont.drawString(DominantColor, 10, 450);
    ofColor bb = ofColor::fromHex(0x515658);
    ofSetColor(bb);
    ofDrawRectangle(90, 438, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][25]["dominant_color"].asString();
    myFont.drawString(DominantColor, 160, 450);
    ofColor cc = ofColor::fromHex(0x738da3);
    ofSetColor(cc);
    ofDrawRectangle(240, 438, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][26]["dominant_color"].asString();
    myFont.drawString(DominantColor, 310, 450);
    ofColor dd = ofColor::fromHex(0x666681);
    ofSetColor(dd);
    ofDrawRectangle(390, 438, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][27]["dominant_color"].asString();
    myFont.drawString(DominantColor, 460, 450);
    ofColor ee = ofColor::fromHex(0x613c24);
    ofSetColor(ee);
    ofDrawRectangle(540, 438, 40, 10);
    
    ofSetColor(0);
    DominantColor = json["data"]["pins"][28]["dominant_color"].asString();
    myFont.drawString(DominantColor, 610, 450);
    ofColor ff = ofColor::fromHex(0x6a5d38);
    ofSetColor(ff);
    ofDrawRectangle(690, 438, 40, 10);

    ofSetColor(0);
    DominantColor = json["data"]["pins"][29]["dominant_color"].asString();
    myFont.drawString(DominantColor, 760, 450);
    ofColor gg = ofColor::fromHex(0x8295a2);
    ofSetColor(gg);
    ofDrawRectangle(840, 438, 40, 10);
    
    
    MostPopular = json["data"]["pins"][Num]["aggregated_pin_data"]["aggregated_status"]["saves"].asInt();
    

    if(count >= 1){
        ofSetColor(255);
        ofDrawRectangle(10,210, 1000,1000);
        ofSetColor(255, 102, 153);
        myFont.drawString("pin by 133453", 600, 200);
        
        
    }if(count >= 2){
         ofSetColor(255, 102, 153);
        ofDrawRectangle(150 ,218, 850, 40);
        Address = json["data"]["pins"][21]["link"].asString();
        ofSetColor(255);
        myFont.drawString(Address, 158, 238);
        
    }if(count >= 3){
        stone.draw(150, 260,391,517);//image of stone
        
        ofSetColor(0);
        Description = json["data"]["pins"][21]["description"].asString();
        myFont.drawString("Description:" + Description, 560, 340);
        
        DominantColor = json["data"]["pins"][21]["dominant_color"].asString();
        myFont.drawString(DominantColor, 560, 400);
        myFont.drawString("Dominant Color", 560, 370);
        ofColor n = ofColor::fromHex(0x5b6668);
        ofSetColor(n);
        ofDrawRectangle(640, 388, 40, 10);
        
        
    }
    
    if(first >= 1 ){
        ofSetColor(255);
        ofDrawRectangle(10,210, 1000,1000);
        ofSetColor(255, 102, 153);
        myFont.drawString("pin by A B", 600, 200);
    }
    
    if(first >= 2){
        ofSetColor(255, 102, 153);
        ofDrawRectangle(150 ,218, 850, 40);
        Address = json["data"]["pins"][0]["link"].asString();
        ofSetColor(255);
        myFont.drawString(Address, 158, 238);
        
    }
    
    if(first >= 3) {
        sunset.draw(150, 260,391,517);//image of sunset
        
        ofSetColor(0);
        Description = json["data"]["pins"][0]["description"].asString();
        myFont.drawString("Description:" + Description, 560, 340);
        
        DominantColor = json["data"]["pins"][0]["dominant_color"].asString();
        myFont.drawString(DominantColor, 560, 400);
        myFont.drawString("Dominant Color", 560, 370);
        ofColor n = ofColor::fromHex(0x5b6668);
        ofSetColor(n);
        ofDrawRectangle(640, 388, 40, 10);
        
    }
    
    if(second >= 1 ){
        ofSetColor(255);
        ofDrawRectangle(10,210, 1000,1000);
        ofSetColor(255, 102, 153);
        myFont.drawString("pin by mary", 6100, 200);
    }
    
    if(second >= 2){
        ofSetColor(255, 102, 153);
        ofDrawRectangle(150 ,218, 850, 40);
        Address = json["data"]["pins"][1]["link"].asString();
        ofSetColor(255);
        myFont.drawString(Address, 158, 238);
        
    }
    
    if(second >= 3) {
        cave.draw(150, 260,391,517);//image of sunset
        
        ofSetColor(0);
        Description = json["data"]["pins"][1]["description"].asString();
        myFont.drawString("Description:" + Description, 560, 340);
        
        DominantColor = json["data"]["pins"][0]["dominant_color"].asString();
        myFont.drawString(DominantColor, 560, 400);
        myFont.drawString("Dominant Color", 560, 370);
        ofColor n = ofColor::fromHex(0x5b6668);
        ofSetColor(n);
        ofDrawRectangle(640, 388, 40, 10);
        
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'm'){
        count++;
        
    }

    if(key == '1'){
        first++;
    }
    
    if (key == '2'){
        second++;
    }
    if(key == 'z'){
       count--;
       first--;
      second--;
    }
}
void ofApp::onMouseInCircle(ofVec2f & e){
    clickedPoint.set(e);
     count++;
}
//--------------------------------------------------------------
void ofApp::onMouseInAnyCircle(ofVec2f & e){
    bg.set(ofRandom(255), ofRandom(255), ofRandom(255));
}


//--------------------------------------------------------------
