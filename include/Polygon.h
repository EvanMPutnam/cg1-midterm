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

  template<typename T>
  void apply( const T& t );

private:

  std::vector<Vertex> vertices;

};

template<typename T>
void Polygon::apply( const T& t ) {
  for ( int i = 0; i < vertices.size(); ++i ) {
    t( vertices[i] );
  }
}

#endif
