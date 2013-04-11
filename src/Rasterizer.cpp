#include "Rasterizer.h"

Rasterizer::Rasterizer( simpleCanvas &canvas )
  : canvas( canvas )
{
}

void Rasterizer::draw_polygon( const Polygon &polygon ) {
  int *x = new int[polygon.size()];
  int *y = new int[polygon.size()];
  for ( int i = 0; i < polygon.size(); ++i ) {
    x[i] = polygon[i].x;
    y[i] = polygon[i].y;
  }
  canvas.drawPoly( polygon.size(), x, y );
  delete [] x;
  delete [] y;
}
