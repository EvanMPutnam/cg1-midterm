#ifndef H_RASTERIZE
#define H_RASTERIZE

#include <utility>
#include <vector>

class Polygon {

public:

  struct Vertex {
    double x;
    double y;

    Vertex( double x, double y );
  };

  Polygon( int n, const int *x, const int *y );

  int size() const;

  Vertex& operator []( int index );

  const Vertex& operator []( int index ) const;

private:

  std::vector<Vertex> vertices;

};

#endif
