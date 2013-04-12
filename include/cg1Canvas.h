//
//  cg1Canvas.h
//  
//
//  Created by Joe Geigel on 11/30/11.
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//

#ifndef _cg1Canvas_h
#define _cg1Canvas_h

#include "simpleCanvas.h"
#include "Transformer.h"
#include "Polygon.h"

/**
 * Simple wrapper class for midterm assignment
 *
 */
class cg1Canvas : public simpleCanvas {
    
public:
    /**
     * Constructor
     *
     * @param w width of canvas
     * @param h height of canvas
     */
    cg1Canvas(int w, int h);
 
    /**
     *
     * addPoly - Adds and stores a polygon to the canvas.  Note that this method does not
     *           draw the polygon, but merely stores it for later draw.  Drawing is 
     *           initiated by the draw() method.
     *
     *           Returns a unique integer id for the polygon.
     *
     * @param x - Array of x coords of the vertices of the polygon to be added.
     * @param y - Array of y coords of the vertices of the polygin to be added.
     * @param n - Number of verticies in polygon
     *
     * @return a unique integer identifier for the polygon
     */
    int addPoly (float x[], float y[], int n);
    
    
    /**
     *
     * clearTransform - sets the current transformation to be the identity 
     *
     */
    void clearTransform();
    
    /**
     *
     * drawPoly - Draw the polygon with the given id.  Draw should draw the polygon after 
     *        applying the current transformation on the vertices of the polygon.
     *
     * @param polyID - the ID of the polygin to be drawn.
     */
    void drawPoly (int polyID);
    
    /**
     *
     * rotate - Add a rotation to the current transformation by premultiplying the appropriate
     *          rotation matrix to the current transformtion matrix.
     *
     * @param degrees - Amount of rotation in degrees.
     *
     */
    void rotate (float degrees);
    
    /**
     *
     * scale - Add a scale to the current transformation by premultiplying the appropriate
     *          scaling matrix to the current transformtion matrix.
     *
     * @param x - Amount of scaling in x.
     * @param y - Amount of scaling in y.
     *
     */
    void scale (float x, float y);
    
    /**
     *
     * setClipWindow - defines the clip window
     *
     * @param bottom - y coord of bottom edge of clip window (in world coords)
     * @param top - y coord of top edge of clip window (in world coords)
     * @param left - x coord of left edge of clip window (in world coords)
     * @param right - x coord of right edge of clip window (in world coords)
     *
     */
    void setClipWindow (float bottom, float top, float left, float right);
    
    /**
     *
     * setViewport - defines the viewport
     *
     * @param xmin - x coord of lower left of view window (in screen coords)
     * @param ymin - y coord of lower left of view window (in screen coords)
     * @param width - width of view window (in world coords)
     * @param height - width of view window (in world coords)
     *
     */
    void setViewport (int x, int y, int width, int height);
    
    /**
     *
     * translate - Add a translation to the current transformation by premultiplying the appropriate
     *          translation matrix to the current transformtion matrix.
     *
     * @param x - Amount of translation in x.
     * @param y - Amount of translation in y.
     *
     */
    void translate (float x, float y);

private:

    Transformer transformer;

    vector<Polygon> polygons;

};


#endif
