#ifndef H_MATRIX
#define H_MATRIX

template<int R, int C>
class Matrix {

public:

  Matrix();

  Matrix<R,C> operator +( const Matrix<R,C>& b ) const;

  Matrix<R,C> operator -( const Matrix<R,C>& b ) const;

  Matrix<R,C> operator -() const;

  Matrix<R,C> operator *( double b ) const;

  template<int N>
  Matrix<R,N> operator*( const Matrix<C,N>& b ) const;

  double* operator[]( int i );

  const double* operator[]( int i ) const;

private:

  double data[R][C];

};

template<int R, int C>
Matrix<R,C> operator*( double a, const Matrix<R,C>& b );

template<int R, int C>
Matrix<R,C>::Matrix() {
  for ( int j = 0; j < C; ++j ) {
    for ( int i = 0; i < R; ++i ) {
      data[i][j] = ( i == j ? 1 : 0 );
    }
  }
}

template<int R, int C>
Matrix<R,C> Matrix<R,C>::operator+( const Matrix<R,C>& b ) const {
  Matrix<R,C> result;
  for ( int j = 0; j < C; ++j ) {
    for ( int i = 0; i < R; ++i ) {
      result.data[i][j] = data[i][j] + b.data[i][j];
    }
  }
  return result;
}

template<int R, int C>
Matrix<R,C> Matrix<R,C>::operator-( const Matrix<R,C>& b ) const {
  return ( *this + -b );
}

template<int R, int C>
Matrix<R,C> Matrix<R,C>::operator-() const {
  Matrix<R,C> result;
  for ( int j = 0; j < C; ++j ) {
    for ( int i = 0; i < R; ++i ) {
      result.data[i][j] = -data[i][j];
    }
  }
  return result;
}

template<int R, int C>
Matrix<R,C> Matrix<R,C>::operator*( double b ) const {
  Matrix<R,C> result;
  for ( int j = 0; j < C; ++j ) {
    for ( int i = 0; i < R; ++i ) {
      result.data[i][j] = b * data[i][j];
    }
  }
  return result;
}

template<int R, int C>
template<int N>
Matrix<R,N> Matrix<R,C>::operator*( const Matrix<C,N>& b ) const {
  Matrix<R,N> result;
  for ( int j = 0; j < N; ++j ) {
    for ( int i = 0; i < R; ++i ) {
      int v = 0;
      for ( int k = 0; k < C; ++k ) {
        v += data[i][k] * b[k][j];
      }
      result[i][j] = v;
    }
  }
  return result;
}

template<int R, int C>
double* Matrix<R,C>::operator[]( int i ) {
  return data[i];
}

template<int R, int C>
const double* Matrix<R,C>::operator[]( int i ) const {
  return data[i];
}

template<int R, int C>
Matrix<R,C> operator*( double a, const Matrix<R,C>& b ) {
  return ( b * a );
}

#endif
