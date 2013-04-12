#ifndef H_EDGE
#define H_EDGE

#include "Vertex.h"

struct Edge {

  Edge( double x0, double y0, double x1, double y1 );

  Edge( Vertex v0, Vertex v1 );

  double slope() const;

  double slope_inverse() const;

  bool operator<( const Edge &other ) const;

  Vertex first;

  Vertex second;

};

#endif
