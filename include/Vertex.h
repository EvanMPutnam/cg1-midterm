#ifndef H_VERTEX
#define H_VERTEX

#include "Matrix.h"

struct Vertex {

  Vertex( double x, double y );

  explicit Vertex( const Matrix<3,1>& src );

  bool operator<( const Vertex& b ) const;

  operator Matrix<3,1>();

  double x;

  double y;

};

#endif
