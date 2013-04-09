//
//  simpleCanvas.h
//  
//
//  Created by Joe Geigel on 11/30/11.
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//

#ifndef _simpleCanvas_h
#define _simpleCanvas_h

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>

using namespace std;

/**
 * Simple canvas class that allows for pixel-by-pixel rendering.
 *
 */
class simpleCanvas {
    
private:
    /**
     * height and witdh of the canvas
     */
    int width;
    int height;
    
    sf::Image myImage;
    sf::Color myColor;
    
    vector<sf::Shape> polys;
    
public:
    /**
     * Constructor
     *
     * @param w width of canvas
     * @param h height of canvas
     */
    simpleCanvas(int w, int h);
    
    /**
     * clears the canvas using the current color
     */
    void clear();
    
    /**
     * draw yourself into a given renderWindow
     *
     * @param R - the window in which to draw.
     */
    void draw (sf::RenderWindow &R);
    
    
    /**
     * Sets the current color
     *
     * @param r - The red component of the new color (between 0-1)
     * @param g - The green component of the new color (between 0-1)
     * @param b - The blue component of the new color (between 0-1);
     */
    void setColor (float r, float g, float b);
    
    /**
     * ONLY USE THIS VERSION OF drawPoly() if you were not
     * able to create a working drawPoly() Rasterizer routine of your
     * own.
     *
     * This method will only draw the outline of the polygon
     */
    void drawPoly (int n, int x[], int y[] );
    
    /**
     * writes a pixel using the passed in color.  Does not modify the 
     * current color
     *
     * @param x - The x coord of the pixel to be set
     * @param y - The y coord of the pixel to be set
     * @param r - The red component of the new color (between 0-1)
     * @param g - The green component of the new color (between 0-1)
     * @param b - The blue component of the new color (between 0-1)
     */
    void setPixel (int x, int y, float r, float g, float b);
    
    /**
     * writes a pixel using the current color
     *
     * @param x - The x coord of the pixel to be set
     * @param y - The y coord of the pixel to be set
     */
    void setPixel (int x, int y);
    
};


#endif
