#include <iostream>

bool check(int **mat,const int mat2[3][3],int i,int j){
  for(int y=i,k=0;k<3;++y,++k){
    for(int x=j,m=0;m<3;++x,++m){
      if(mat[y][x]!=mat2[k][m]) return false;
    }
  }
  return true;
}

void check_is_contained(int **mat1, const int mat2[3][3],const int nrows, const int ncols, int &row, int &col)
{
  row=-1;
  col=-1;
  for(int i=0;i<nrows;++i){
    for(int j=0;j<ncols;++j){
      if(check(mat1,mat2,i,j)){
        row=i;
        col=j;
        return;
      }
    }
  } 
}
////////////////
void check_is_contained( int** m1, const int m2[ 3 ][ 3 ],
                         const int rr, const int cc, int& row, int& col ) {
  for ( row = rr - 3; row >= 0; --row )
    for ( col = cc - 3; col >= 0; --col ) {
      bool f{ true };
      for ( int r{}; r < 3 && f; ++r )
        for ( int c{}; c < 3 && f; ++c )
          if ( m1[ r + row ][ c + col ] != m2[ r ][ c ] ) f = false;
      if ( f ) return;
    }
  row = col = -1;
}
///////////////
bool is_match(int **mat1, const int mat2[3][3], int r, int c)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if ( mat1[r+i][c+j] != mat2[i][j] )
                return false;
    return true;
}
void check_is_contained(int **mat1, const int mat2[3][3], const int nrows, const int ncols, int &row, int &col)
{
    for (row = 0; row <= nrows-3; row++)
        for (col = 0; col <= ncols-3; col++)
            if ( is_match(mat1, mat2, row, col) )
                return;
    row = col = -1;
}
//////////////////
void check_is_contained(int **mat1, const int mat2[3][3],const int nrows, const int ncols, int &row, int &col)
{
  for(int j=0;j<=nrows-3;j++) for(int i=0;i<=ncols-3;i++) {
    if(mat1[j][i+0]  !=mat2[0][0]) continue;
    if(mat1[j][i+1]  !=mat2[0][1]) continue;
    if(mat1[j][i+2]  !=mat2[0][2]) continue;
    if(mat1[j+1][i+0]!=mat2[1][0]) continue;
    if(mat1[j+1][i+1]!=mat2[1][1]) continue;
    if(mat1[j+1][i+2]!=mat2[1][2]) continue;
    if(mat1[j+2][i+0]!=mat2[2][0]) continue;
    if(mat1[j+2][i+1]!=mat2[2][1]) continue;
    if(mat1[j+2][i+2]!=mat2[2][2]) continue;
    row=j; col=i;
    return;
  }
  row=-1; col=-1;
}
/////////////
