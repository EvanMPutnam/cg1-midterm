#ifndef H_POLYGON
#define H_POLYGON

#include <utility>
#include <vector>

#include "Vertex.h"
#include "Edge.h"

class Polygon {

public:

  Polygon( int n, const int *x, const int *y );

  int size() const;

  Vertex& operator []( int index );

  const Vertex& operator []( int index ) const;

  std::vector<Edge> edges() const;

private:

  std::vector<Vertex> vertices;

};

#endif
