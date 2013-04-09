#include <utility>

#include "Edge.h"

using namespace std;

Edge::Edge( double x0, double y0, double x1, double y1 )
  : first( x0, y0 ), second( x1, y1 )
{
  if ( second < first ) {
    swap( first, second );
  }
}

Edge::Edge( Vertex v0, Vertex v1 )
  : first( v0 ), second( v1 )
{
  if ( second < first ) {
    swap( first, second );
  }
}

double Edge::slope() const 
{
  return ( second.y - first.y ) / ( second.x - first.x );
}

double Edge::slope_inverse() const 
{
  return ( second.x - first.x ) / ( second.y - first.y );
}
