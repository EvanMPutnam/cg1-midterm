#ifndef H_POLYGON
#define H_POLYGON

#include <utility>
#include <vector>

#include "Vertex.h"
#include "Edge.h"

class Polygon {

public:

  Polygon( int n, const float *x, const float *y );

  Polygon( int n, const double *x, const double *y );

  int size() const;

  Vertex& operator []( int index );

  const Vertex& operator []( int index ) const;

  std::vector<Edge> edge_list() const;

private:

  std::vector<Vertex> vertices;

};

#endif
