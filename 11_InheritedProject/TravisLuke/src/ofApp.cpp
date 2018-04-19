#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

    ofSetWindowShape(1500, 900);

    bottle01.load("images/01.png"); //images
    bottle02.load("images/02.png");
    bottles.load("images/bottles.png");
    table.load("images/table.png");

    myfont.load("fonts/TheLightFont.ttf", 20); //font

    fireSound.load("Sounds/fire.mp3"); //load sounds
    waterSound.load("Sounds/water.mp3");
    beakerSound.load("Sounds/beaker.mp3");
    glassSound.load("Sounds/glass.mp3");

    box2d.init();
    box2d.setGravity(0, 10);
    box2d.setFPS(30.0);

    box2d.registerGrabbing();
    box2d.createBounds();

    particles.setParticleFlag(b2_colorMixingParticle);
    particles.setup(box2d.getWorld());

    beakerLine.addVertex(ofVec2f(409, 422));
    beakerLine.addVertex(ofVec2f(409, 518));
    beakerLine.addVertex(ofVec2f(509, 517));
    beakerLine.addVertex(ofVec2f(507, 420));
    beaker.addVertexes(beakerLine);
    beaker.create(box2d.getWorld());

    roundFlaskLine.addVertex(ofVec2f(770, 345));
    roundFlaskLine.addVertex(ofVec2f(718, 376));
    roundFlaskLine.arcNegative(ofVec2f(680, 417), 55, 55, 315, 20, 100);
    roundFlaskLine.addVertex(ofVec2f(734, 406));
    roundFlaskLine.addVertex(ofVec2f(793, 377));
    roundFlask.addVertexes(roundFlaskLine);
    roundFlask.create(box2d.getWorld());

    burnerLine.addVertex(ofVec2f(897, 393));
    burnerLine.addVertex(ofVec2f(899, 434));
    burnerLine.addVertex(ofVec2f(854, 465));
    burnerLine.addVertex(ofVec2f(856, 515));
    burnerLine.addVertex(ofVec2f(987, 514));
    burnerLine.addVertex(ofVec2f(991, 467));
    burnerLine.addVertex(ofVec2f(948, 432));
    burnerLine.addVertex(ofVec2f(948, 393));
    burner.addVertexes(burnerLine);
    burner.create(box2d.getWorld());

    erlenmeyerFlaskLine.addVertex(ofVec2f(1094,  302));
    erlenmeyerFlaskLine.addVertex(ofVec2f(1096,  414));
    erlenmeyerFlaskLine.addVertex(ofVec2f(1034,  516));
    erlenmeyerFlaskLine.addVertex(ofVec2f(1034,  515));
    erlenmeyerFlaskLine.addVertex(ofVec2f(1199,  515));
    erlenmeyerFlaskLine.addVertex(ofVec2f(1140,  415));
    erlenmeyerFlaskLine.addVertex(ofVec2f(1139,  303));
    erlenmeyerFlask.addVertexes(erlenmeyerFlaskLine);
    erlenmeyerFlask.create(box2d.getWorld());
}

//--------------------------------------------------------------
void ofApp::update()
{
    box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{

    //    background color
    ofColor colorOne(77, 77, 255);
    ofColor colorTwo(102, 0, 204);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);

    //number
    myfont.drawString("1", ofGetWidth() / 5 + 150, ofGetHeight() / 3 * 2 - 20);
    myfont.drawString("2", ofGetWidth() / 5 + 380, ofGetHeight() / 3 * 2 - 20);
    myfont.drawString("3", ofGetWidth() / 5 + 620, ofGetHeight() / 3 * 2 - 20);
    myfont.drawString("4", ofGetWidth() / 5 + 820, ofGetHeight() / 3 * 2 - 20);

    bottles.draw(ofGetWidth() / 5 + 100, ofGetHeight() / 3, 800, 220);

    ofSetColor(255, 255, 255);
    ofNoFill();
    table.draw(ofGetWidth() / 9, ofGetHeight() / 3 + 100, 1230, 460);

    myfont.drawString("Hello,Chemistry!!", 100, 100);

    particles.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == '1')
    {
        beakerSound.play();
        particles.setColor(ofColor(0, 50, 255));
    }

    if (key == '2')
    {
        waterSound.play();
        particles.setColor(ofColor(127, 255, 0));
    }

    if (key == '3')
    {
        fireSound.play();
        particles.setColor(ofColor(255, 0, 0));
    }

    if (key == '4')
    {
        glassSound.play();
        particles.setColor(ofColor(255, 255, 0));
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    for (int i = 0; i < 1; i++)
    {
        float radius = 10;
        float x = cos(ofRandom(PI * 2.0)) * radius + mouseX;
        float y = sin(ofRandom(PI * 2.0)) * radius + mouseY;
        ofVec2f position = ofVec2f(x, y);
        // ofVec2f velocity = ofVec2f(ofRandom(-5, 5), ofRandom(0, 20));
        ofVec2f velocity = ofVec2f(0, 0);
        particles.createParticle(position, velocity);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    cout << x << " " << y << endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}

//--------------------------------------------------------------
