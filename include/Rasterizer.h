#ifndef H_RASTERIZER
#define H_RASTERIZER

#include "Polygon.h"
#include "simpleCanvas.h"

class Rasterizer {

public:

  Rasterizer( simpleCanvas &canvas  );

  void draw_polygon( const Polygon &polygon );

private:

  simpleCanvas &canvas;

};

#endif
