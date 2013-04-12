//
//  cg1Canvas.cpp
//  
//
//  Created by Joe Geigel on 11/30/11.
//  Copyright 2011 Rochester Institute of Technology. All rights reserved.
//

#include "Rasterizer.h"

#include "cg1Canvas.h"


/**
 * Simple wrapper class for line drawing assignment
 *
 */

/**
 * Constructor
 *
 * @param w width of canvas
 * @param h height of canvas
 */
cg1Canvas::cg1Canvas(int w, int h)
  : simpleCanvas (w,h),
    w( w ),
    h( h )
{
}

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
int cg1Canvas::addPoly (float x[], float y[], int n)
{    
  polygons.push_back( Polygon( n, x, y ) );
  return polygons.size() - 1;
}


/**
 *
 * clearTransform - sets the current transformation to be the identity 
 *
 */
void cg1Canvas::clearTransform()
{
  transformer = Transformer();
}

/**
 *
 * draw - Draw the polygon with the given id.  Draw should draw the polygon after 
 *        applying the current transformation on the vertices of the polygon.
 *
 * @param polyID - the ID of the polygin to be drawn.
 */
void cg1Canvas::drawPoly (int polyID)
{
  Rasterizer r( *this );
  Transformer t( transformer );
  t.scale( double(viewport.width) / double(w), double(viewport.height) / double(h) );
  t.translate( viewport.x, viewport.y );

  Polygon p( polygons[polyID] );
  p.apply( t );
  r.draw_polygon( p );
}

/**
 *
 * rotate - Add a rotation to the current transformation by premultiplying the appropriate
 *          rotation matrix to the current transformtion matrix.
 *
 * @param degrees - Amount of rotation in degrees.
 *
 */
void cg1Canvas::rotate (float degrees)
{
  transformer.rotate( degrees );
}

/**
 *
 * scale - Add a scale to the current transformation by premultiplying the appropriate
 *          scaling matrix to the current transformtion matrix.
 *
 * @param x - Amount of scaling in x.
 * @param y - Amount of scaling in y.
 *
 */
void cg1Canvas::scale (float x, float y)
{
  transformer.scale( x, y );
}


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
void cg1Canvas::setClipWindow (float bottom, float top, float left, float right)
{
}

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
void cg1Canvas::setViewport (int x, int y, int width, int height)
{
  viewport.x = x;
  viewport.y = y;
  viewport.width = width;
  viewport.height = height;
}

/**
 *
 * translate - Add a translation to the current transformation by premultiplying the appropriate
 *          translation matrix to the current transformtion matrix.
 *
 * @param x - Amount of translation in x.
 * @param y - Amount of translation in y.
 *
 */
void cg1Canvas::translate (float x, float y)
{
  transformer.translate( x, y );
}
