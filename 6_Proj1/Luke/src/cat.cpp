#include "cat.h"

cat::cat()
{
}

void cat::setup(int xIn, int yIn, float rotIn)
{
    animal::setup(xIn, yIn, rotIn);
    newRadius = drawRadius;
    color = ofColor(115, 115, 115);
    newColor = color;
}

void cat::update()
{
    easing();

    if ((orig - dst).length() < 1)
    {
        orig = dst;
        hiss(false);
    }

    float angle = (ofGetFrameNum() % 360);
    float noise = ofSignedNoise(angle / 72);
    float scaledNoise = ofMap(noise, -1, 1, -100, 100);
    pos.set(orig.x + scaledNoise + moveRadius * cos(angle * DEG_TO_RAD), orig.y + scaledNoise + moveRadius * sin(angle * DEG_TO_RAD));
    rot = angle;

    animal::update(rot);
}

void cat::easing()
{
    if (orig != dst)
    {
        orig += 0.1 * hissCount / 5 * (dst - orig);
    }

    if (drawRadius != newRadius)
    {
        drawRadius += 0.1 * hissCount / 5 * (newRadius - drawRadius);
    }

    if (color != newColor)
    {
        color.r += 0.1 * (newColor.r - color.r);
        color.g += 0.1 * (newColor.g - color.g);
        color.b += 0.1 * (newColor.b - color.b);
    }

    if (earColor != newEarColor)
    {
        earColor.r += 0.1 * (newEarColor.r - earColor.r);
        earColor.g += 0.1 * (newEarColor.g - earColor.g);
        earColor.b += 0.1 * (newEarColor.b - earColor.b);
    }
}

void cat::hiss(bool state)
{
    if (state != isHiss)
    {
        if (hissCount > 0)
        {
            isHiss = state;
            if (state)
            {
                // drawRadius += 25;
                newRadius += 25;
                newColor = ofColor(255, 255 * (1 - (hissCount / 5)), 255 * (1 - (hissCount / 5)));
                newEarColor = newColor;
            }
            if (!state)
            {
                // drawRadius -= 25;
                newRadius -= 25;
                newColor = ofColor(115, 115, 115);
                newEarColor = ofColor(255, 255, 255);
                hissCount -= 1;
            }
        }
    }
}

void cat::setDst(ofPoint vecIn)
{
    dst = orig + vecIn;
}