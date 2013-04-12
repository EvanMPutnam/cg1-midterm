#include "Polygon.h"

using namespace std;

Polygon::Polygon( int n, const float *x, const float *y )
{
  for ( int i = 0; i < n; ++i ) {
    vertices.push_back( Vertex( x[i], y[i] ) );
  }
}

Polygon::Polygon( int n, const double *x, const double *y )
{
  for ( int i = 0; i < n; ++i ) {
    vertices.push_back( Vertex( x[i], y[i] ) );
  }
}

int Polygon::size() const
{
  return vertices.size();
}

Vertex& Polygon::operator []( int index )
{
  return vertices[index];
}

const Vertex& Polygon::operator []( int index ) const
{
  return vertices[index];
}

vector<Edge> Polygon::edge_list() const
{
  vector<Edge> result;
  for ( int i = 0; i < vertices.size() - 1; ++i ) {
    result.push_back( Edge( vertices[i], vertices[i + 1] ) );
  }
  result.push_back( Edge( vertices.back(), vertices.front() ) );
  return result;
}
