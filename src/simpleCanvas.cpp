//
//  simpleCanvas.cpp
//  
//
//  Created by Joe Geigel on 11/30/11.
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//

#include "simpleCanvas.h"
#include <SFML/Config.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/String.hpp>

#include <iostream>

using namespace std;


/**
 * Simple canvas class that allows for pixel-by-pixel rendering.
 *
 */

/**
 * Constructor
 *
 * @param w width of canvas
 * @param h height of canvas
 */
simpleCanvas::simpleCanvas(int w, int h) : myImage(w,h), myColor (0,0,0),
    width (w), height (h)
{
    myImage.SetSmooth (false);
}

/**
 * clears the canvas using the current color
 */
void simpleCanvas::clear()
{
    for (int i=0; i < width; i++)
        for (int j=0; j < height; j++) {
            myImage.SetPixel (i, j, myColor);
        }
    polys.clear();
}

/**
 * draw yourself into a given renderWindow
 *
 * @param R - the window in which to draw.
 */
void simpleCanvas::draw (sf::RenderWindow &R)
{
    // Add your image as a sprite
    sf::Sprite S(myImage);
    S.SetPosition (0,0);
    R.Draw (S);
    
    // draw your polys
    vector<sf::Shape>::iterator it;
    for (it = polys.begin(); it != polys.end(); it++) {
        R.Draw ((*it));
    }
}

/**
 * ONLY USE THIS VERSION OF drawPoly() if you were not
 * able to create a working drawPoly() Rasterizer routine of your
 * own.
 *
 * This method will only draw the outline of the polygon
 */
void simpleCanvas::drawPoly (int n, int x[], int y[] )
{
    sf::Shape P;
    for (int i=0; i < n; i++)
        P.AddPoint (x[i], height - y[i], myColor, myColor);
    
    P.EnableFill (false);
    P.EnableOutline (true);
    P.SetOutlineWidth (1);
    
    polys.push_back (P);
}


/**
 * Sets the current color
 *
 * @param r - The red component of the new color (between 0-1)
 * @param g - The green component of the new color (between 0-1)
 * @param b - The blue component of the new color (between 0-1);
 */
void simpleCanvas::setColor (float r, float g, float b)
{
    unsigned char R = (unsigned char)(r * 255);
    unsigned char G = (unsigned char)(g * 255);
    unsigned char B = (unsigned char)(b * 255);
    myColor = sf::Color (R, G, B);
}



/**
 * writes a pixel using the current color
 *
 * @param x - The x coord of the pixel to be set
 * @param y - The y coord of the pixel to be set
 */
void simpleCanvas::setPixel (int x, int y)
{
    myImage.SetPixel (x, (height - y - 1), myColor);
}
