#include <cassert>

#include "Vertex.h"

using namespace std;

Vertex::Vertex( double x, double y )
  : x( x ),
    y( y )
{
}

Vertex::Vertex( const Matrix<3,1>& src )
  : x( src[0][0] ),
    y( src[1][0] )
{
}

bool Vertex::operator<( const Vertex& b )
{
  return ( y < b.y ) || ( y == b.y && x < b.x );
}

Vertex::operator Matrix<3,1>()
{
  Matrix<3,1> result;
  result[0][0] = x;
  result[1][0] = y;
  result[2][0] = 1;
  return result;
}
