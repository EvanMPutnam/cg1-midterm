#ifndef H_RASTERIZE
#define H_RASTERIZE

#include <vector>

#include "simpleCanvas.h"
#include "Polygon.h"

class Rasterizer {

public:

  Rasterizer( simpleCanvas &canvas );

  void draw_polygon( const Polygon &source );

private:

  void scan_line( std::vector<Edge> &edges );

  simpleCanvas& canvas;

};

#endif
