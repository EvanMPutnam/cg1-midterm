#ifndef H_RASTERIZER
#define H_RASTERIZER

#include <vector>

#include "Polygon.h"
#include "simpleCanvas.h"

class Rasterizer {

public:

  Rasterizer( simpleCanvas &canvas );

  void draw_polygon( const Polygon &source );

private:

  void scan_line( std::vector<Edge> &edges );

  simpleCanvas& canvas;

};

#endif
