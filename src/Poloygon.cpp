#include "Polygon.h"

using namespace std;

Polygon::Vertex::Vertex( double x, double y )
  : x( x ),
    y( y )
{
}

Polygon::Polygon( int n, const int *x, const int *y )
{
  for ( int i = 0; i < n; ++i ) {
    vertices.push_back( Vertex( x[i], y[i] ) );
  }
}

int Polygon::size() const
{
  return vertices.size();
}

Polygon::Vertex& Polygon::operator []( int index )
{
  return vertices[index];
}

const Polygon::Vertex& Polygon::operator []( int index ) const
{
  return vertices[index];
}
