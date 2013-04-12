#include "Transformer.h"

#include <cmath>

namespace {
  const double PI = 3.14159265358979323856;

  double deg2rad( double degree ) {
    return ( degree / 180.0 ) * PI;
  }
}

void Transformer::rotate( double degrees ) {
  state = Rotate( degrees ) * state;
}

void Transformer::scale( double x, double y ) {
  state = Scale( x, y ) * state;
}

void Transformer::translate( double x, double y ) {
  state = Translate( x, y ) * state;
}

void Transformer::operator()( Vertex& v ) const {
  Matrix<3,1> m;
  m[0][0] = v.x; m[1][0] = v.y; m[2][0] = 1;
  m = state * m;

  v.x = m[0][0]; v.y = m[0][1];
}

Matrix<3,3> Transformer::Rotate( double degrees ) {
  double rad = deg2rad( degrees );
  Matrix<3,3> result;
  result[0][0] = cos( rad );
  result[1][0] = sin( rad );
  result[0][1] = -sin( rad );
  result[1][1] = cos( rad );
  return result;
}

Matrix<3,3> Transformer::Scale( double x, double y ) {
  Matrix<3,3> result;
  result[0][0] = x;
  result[1][1] = y;
  return result;
}

Matrix<3,3> Transformer::Translate( double x, double y ) {
  Matrix<3,3> result;
  result[0][2] = x;
  result[1][2] = y;
  return result;
}
