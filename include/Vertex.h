#ifndef H_VERTEX
#define H_VERTEX

struct Vertex {

  Vertex( double x, double y );

  bool operator<( const Vertex& b );

  double x;

  double y;

};

#endif
