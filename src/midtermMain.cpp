//
//  midtermMain.cpp
//  
//
//  Created by Joe Geigel on 11/30/11.
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//
 
#include <SFML/Graphics.hpp>
#include "cg1Canvas.h"

/**
 * some globals since I didn't want to make a midtermMain class.
 */
int displayNumber = 1;

int triangle;
int square;
int octogon;
int star;

int drawHeight = 500;
int drawWidth = 500;

/**
 *
 * draw plain old polygons
 */
void drawPolys( cg1Canvas &D ) 
{
    /* 
     * Draw a red triangle
     */
    D.clearTransform();
    D.setColor( 1.0f, 0.0f, 0.0f );
    D.drawPoly (triangle);
    
    /* 
     * Draw a white square 	 
     */
    D.setColor( 1.0f, 1.0f, 1.0f );
    D.drawPoly (square);
    
    /* 
     * Draw a blue otcagon
     */
    D.setColor( 0.0f, 0.0f, 1.0f );
    D.drawPoly (octogon);
    
    /* 
     * Draw a green star
     */
    D.setColor( 0.0f, 1.0f, 0.0f );
    D.drawPoly (star);
}


/**
 * Draw the world transformed...used for transformation tests.
 */
void drawTPolys( cg1Canvas &D ) {
    
    /* 
     * Draw a red triangle rotated
     */
    D.clearTransform();
    D.rotate (-25.0f);
    D.setColor( 1.0f, 0.0f, 0.0f );
    D.drawPoly (triangle);
    
    /* 
     * Draw a white square translated	 
     */
    D.clearTransform();
    D.translate (80.0f, 75.0f);
    D.setColor( 1.0f, 1.0f, 1.0f );
    D.drawPoly (square);   
    
    /* 
     * Draw a blue otcagon scaled
     */
    D.clearTransform();
    D.scale (0.75f, 0.5f);
    D.setColor( 0.0f, 0.0f, 1.0f );
    D.drawPoly (octogon);
    
    /* 
     * Draw a green star translated, scaled, rotates, then scaled back
     */
    D.clearTransform();
    D.translate (50.0f, 50.0f);
    D.scale (2.0f, 2.0f);
    D.rotate (-10.0f);
    D.translate (-50.0f, 50.0f);
    D.setColor( 0.0f, 1.0f, 0.0f );
    D.drawPoly (star);
}


/**
 * the display function
 */
void doDraw(cg1Canvas &D)
{
    /* 
     * Set clear color to gray 
     */
    D.setColor ( 0.8f, 0.8f, 0.8f );
    D.clear();
    
    /* 
     * plain old polygon test
     */
    if ( (displayNumber % 4) == 1) {
        
        /* default clipping */
        D.setClipWindow( 0.0f, 500.0f, 0.0f, 500.0f );
        
        /* default viewport */
        D.setViewport( 0, 0, drawWidth, drawHeight );
        
        /* draw the polys */
        drawPolys(D);
    }
    else if ( (displayNumber % 4) == 2) {
        
        
        /* clipping test */
        D.setClipWindow( 35.0f, 175.0f, 35.0f, 165.0f );
        
        /* default viewport */
        D.setViewport( 0, 0, drawWidth, drawHeight );
        
        /* draw the polys */
        drawPolys(D);
        
    }
    else if ( (displayNumber % 4) == 3) {
        
        /* default clipping */
        D.setClipWindow( 0.0f, 500.0f, 0.0f, 500.0f );
        
        /* default viewport */
        D.setViewport( 0, 0, drawWidth, drawHeight );
        
        /* draw the tranformed polys */
        drawTPolys(D);
    }
    
    else /* displayNumber == 0 */ {
        
        /* default clipping */
        D.setClipWindow( 0.0f, 500.0f, 0.0f, 500.0f );
        
        /* have some fun with the view port */
        int wdiff = drawWidth / 5;
        int hdiff = drawHeight / 5;
        int x = 0;
        int y = 0;
        int i,j;
        for (i=0; i < 5; i++) {
            D.setViewport (x, y, wdiff, hdiff);
            drawPolys(D);
            y+= hdiff;
            x+= wdiff;
        }
    }
}


/**
 * callback for key presses.  Returns a flag indicating if the app should 
 * close as a result of this key press.
 */
bool keyTyped(char key)
{
    if ((key == 'Q') || (key == 'q')) return true; // quit
    
    if ((key == 'C') || (key == 'c')) displayNumber = 2; // clip
    if ((key == 'P') || (key == 'p')) displayNumber = 1; // polygon
    if ((key == 'T') || (key == 't')) displayNumber = 3; // transform
    if ((key == 'V') || (key == 'v')) displayNumber = 0; // viewport
    
    return false;
}



/**
 * 
 * main program for clipping assignment
 *
 */

int main (int argc, char *argv[])
{
    
    // define your canvas
    cg1Canvas D(drawWidth, drawHeight);
    
    // load all of your polygons
    float x[10];
    float y[10];
    
    // triangle
    x[0] = 25.0f; y[0] = 125.0f;
    x[1] = 75.0f; y[1] = 125.0f;
    x[2] = 50.0f; y[2] = 175.0f;
    triangle = D.addPoly (x, y, 3);
    
    // square
    x[0] = 125.0f; y[0] = 125.0f;
    x[1] = 175.0f; y[1] = 125.0f;
    x[2] = 175.0f; y[2] = 175.0f;
    x[3] = 125.0f; y[3] = 175.0f;
    square = D.addPoly (x, y, 4);
    
    // octogon
    x[0] = 25.0f; y[0] = 25.0f;
    x[1] = 35.0f; y[1] = 15.0f;
    x[2] = 55.0f; y[2] = 15.0f;
    x[3] = 75.0f; y[3] = 25.0f;
    x[4] = 75.0f; y[4] = 55.0f;
    x[5] = 55.0f; y[5] = 75.0f;
    x[6] = 35.0f; y[6] = 75.0f;
    x[7] = 25.0f; y[7] = 55.0f;
    octogon = D.addPoly (x, y, 8);
    
    // star
    x[0] = 150.0f; y[0] = 90.0f;
    x[1] = 140.0f; y[1] = 65.0f;
    x[2] = 110.0f; y[2] = 65.0f;
    x[3] = 140.0f; y[3] = 40.0f;
    x[4] = 110.0f; y[4] = 10.0f;
    x[5] = 150.0f; y[5] = 25.0f;
    x[6] = 190.0f; y[6] = 10.0f;
    x[7] = 160.0f; y[7] = 40.0f;
    x[8] = 190.0f; y[8] = 65.0f;
    x[9] = 160.0f; y[9] = 65.0f;
    star = D.addPoly (x, y, 10);
    
    // create and run the app
    sf::RenderWindow App(sf::VideoMode(drawWidth, drawHeight), "CG1 Midterm");
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();
            
            // Keypress
            if (Event.Type == sf::Event::KeyPressed)
                if (keyTyped (Event.Key.Code)) 
                    App.Close();
            
            // Mouse click
            if (Event.Type == sf::Event::MouseButtonPressed)
                displayNumber++;
        }
        
        // Clear screen
        App.Clear();
        
        // draw on your canvas
        doDraw(D);
        
        // Draw your canvas to your window
        D.draw (App);
    
        App.Display();
    }
    
    return 0;

}
