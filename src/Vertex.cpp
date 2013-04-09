#include "Vertex.h"

using namespace std;

Vertex::Vertex( double x, double y )
  : x( x ),
    y( y )
{
}

bool Vertex::operator<( const Vertex& b )
{
  return ( y < b.y ) || ( y == b.y && x < b.x );
}
