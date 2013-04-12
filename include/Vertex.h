#ifndef H_VERTEX
#define H_VERTEX

#include "Matrix.h"

struct Vertex {

  Vertex( double x, double y );

  bool operator<( const Vertex& b ) const;

  double x;

  double y;

};

#endif
