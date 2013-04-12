#include <algorithm>
#include <cmath>

#include "Rasterizer.h"

using namespace std;

void increment_edge_list( vector<Edge> &edge_list );
vector<Edge> active_edge_list( const vector<Edge> &edge_list );
vector<Edge> global_edge_list( const vector<Edge> &edge_list );

Rasterizer::Rasterizer( simpleCanvas &canvas )
  : canvas( canvas )
{
}

void Rasterizer::draw_polygon( const Polygon &source )
{
  vector<Edge> edge_list = source.edge_list();
  edge_list = global_edge_list( edge_list );
  while ( edge_list.size() > 0 ) {
    scan_line( edge_list );
    increment_edge_list( edge_list );
  }
}

void Rasterizer::scan_line( vector<Edge> &edges )
{
  vector<Edge> active_edges = active_edge_list( edges );
  int parity = 0;
  vector<Edge>::iterator i = active_edges.begin(); 
  int x = i->first.x, y = i->first.y;
  while ( i != active_edges.end() ) {
    if ( i->first.x < x ) {
      ++parity;
      ++i;
    }
    if ( parity & 1 ) {
      canvas.setPixel( x, y );
    }
    ++x;
  }
}

void increment_edge_list( vector<Edge> &edge_list )
{
  int line = edge_list.front().first.y;
  for ( int i = 0; i < edge_list.size(); ++i ) {
    if ( edge_list[i].first.y > line ) {
      break;
    }
    double x = edge_list[i].first.x + edge_list[i].slope_inverse();
    double y = edge_list[i].first.y + 1;
    if ( y >= edge_list[i].second.y ) {
      edge_list.erase( edge_list.begin() + i-- );
    } else {
      edge_list[i].first = Vertex( x, y );
    }
  }
  sort( edge_list.begin(), edge_list.end() );
}

vector<Edge> active_edge_list( const vector<Edge> &edge_list )
{
  vector<Edge> result;

  int line = edge_list.front().first.y;
  for ( int i = 0; i < edge_list.size(); ++i ) {
    if ( edge_list[i].first.y > line ) {
      break;
    } else {
      result.push_back( edge_list[i] );
    }
  }

  return result;
}

vector<Edge> global_edge_list( const vector<Edge> &edge_list )
{
  vector<Edge> result;
  for ( int i = 0; i < edge_list.size(); ++i ) {
    if ( edge_list[i].first.y != edge_list[i].second.y ) {
      result.push_back( edge_list[i] );

      // actual floating point values fubar all the things
      result.back().first.x = int(result.back().first.x);
      result.back().first.y = int(result.back().first.y);
      result.back().second.x = int(result.back().second.x);
      result.back().second.y = int(result.back().second.y);
    }
  }
  sort( result.begin(), result.end() );
  return result;
}
