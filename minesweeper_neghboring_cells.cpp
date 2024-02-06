#include <iostream>

void c_out(char **board, const int rows, const int cols){
  for(int i=0;i<rows;++i){
    for(int j=0;j<cols;++j){
      if(board[i][j]==' ')std::cout<<'@';
      else std::cout<<board[i][j];
    }
    std::cout<<"\n";
  }
}

void compute_number_mines(char **board, const int rows, const int cols)
{
  std::cout<<"cols: "<<cols<<"\n";
  std::cout<<"rows: "<<rows<<"\n";
  c_out(board,rows,cols);
  #if 1
  for(int i=0;i<rows;++i){
    for(int j=0;j<cols;++j){
      if(board[i][j]=='R'){
        char c = '0';
        if(i==0 && j==0){
          if(board[i+1][j]=='o')++c;
          if(board[i][j+1]=='o')++c;
          if(board[i+1][j+1]=='o')++c;
        }
        else if(i==0 && j!=0 && j<cols-1){
          if(board[i][j+1]=='o')++c;
          if(board[i+1][j]=='o')++c;
          if(board[i][j-1]=='o')++c;
          if(board[i+1][j+1]=='o')++c;
          if(board[i+1][j-1]=='o')++c;
        }
        //
        else if(i==0 && j==cols-1){
          if(board[i][j-1]=='o')++c;
          if(board[i+1][j]=='o')++c;
          if(board[i+1][j-1]=='o')++c;
        }
        else if(i==rows-1 && j==0){
          if(board[i-1][j]=='o')++c;
          if(board[i-1][j+1]=='o')++c;
          if(board[i][j+1]=='o')++c;
        }
        else if(i==rows-1 && j<cols-1 && j!=0){
          if(board[i][j+1]=='o')++c;
          if(board[i][j-1]=='o')++c;
          if(board[i-1][j]=='o')++c;
          if(board[i-1][j-1]=='o')++c;
          if(board[i-1][j+1]=='o')++c;
        }
        else if(i==rows-1 && j==cols-1){
          if(board[i][j-1]=='o')++c;
          if(board[i-1][j-1]=='o')++c;
          if(board[i-1][j]=='o')++c;
        }
        else if(i!=0 && i!=rows-1 && j==0){
          if(board[i][j+1]=='o')++c;
          if(board[i-1][j]=='o')++c;
          if(board[i+1][j]=='o')++c;
           if(board[i+1][j+1]=='o')++c;
           if(board[i-1][j+1]=='o')++c;
        }
        else if(i!=0 && i!=rows-1 && j==cols-1){//RW
          if(board[i][j-1]=='o')++c;//L
          if(board[i-1][j]=='o')++c;//U
          if(board[i+1][j]=='o')++c;//D
          if(board[i+1][j-1]=='o')++c;//UL
          if(board[i-1][j-1]=='o')++c;//DL
        }
        else if(i!=0 && i!=rows-1 && j!=0 && j!=cols-1){
          if(board[i][j-1]=='o')++c;
          if(board[i][j+1]=='o')++c;
          if(board[i-1][j]=='o')++c;
          if(board[i+1][j]=='o')++c;
          if(board[i+1][j+1]=='o')++c;
          if(board[i-1][j-1]=='o')++c;
          if(board[i+1][j-1]=='o')++c;
          if(board[i-1][j+1]=='o')++c;
        }
        board[i][j]=c;
      }
    }
  }
  std::cout<<"\n";
  c_out(board,rows,cols);
  #endif
}

///////////////////////////////////
void compute_number_mines(char **board, const int rows, const int cols) {
    for (int y = 0; y < rows; ++y) {
        int y2_begin = std::max(0, y - 1), y2_end = std::min(y + 2, rows);
        for (int x = 0; x < cols; ++x) {
            if (board[y][x] == 'R') {
                int count = 0, x2_begin = std::max(0, x - 1), x2_end = std::min(x + 2, cols);
                for (int y2 = y2_begin; y2 < y2_end; ++y2)
                    for (int x2 = x2_begin; x2 < x2_end; ++x2)
                        count += (board[y2][x2] == 'o');
                board[y][x] = '0' + count;
            }
        }
    }
}
///////////////////////////
using namespace std;

void compute_number_mines(char **board, const int rows, const int cols)
{
  int nbMines = 0;
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      if(board[i][j] == 'R')
      {
        for(int k = max<int>(i - 1, 0); k <= min<int>(i + 1, rows - 1); k++)
        {
          for(int l = max<int>(j - 1, 0); l <= min<int>(j + 1, cols - 1); l++)
          {
            if(board[k][l] == 'o')
            {
              nbMines++;
            }
          }
        }
        board[i][j] = '0' + nbMines;
        nbMines = 0;
      }
    }
  }
}
/////////////////////////////
void compute_number_mines(char **board, const int rows, const int cols)
{
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      if (board[i][j] == 'R') {
        int count = 0;
        if (i != 0 && j != 0 && board[i-1][j-1] == 'o') count++;
        if (i != 0 && board[i-1][j] == 'o') count++;
        if (i != 0 && j != cols-1 && board[i-1][j+1] == 'o') count++;
        if (j != 0 && board[i][j-1] == 'o') count++;
        if (j != cols-1 && board[i][j+1] == 'o') count++;
        if (i != rows-1 && j != 0 && board[i+1][j-1] == 'o') count++;
        if (i != rows-1 && board[i+1][j] == 'o') count++;
        if (i != rows-1 && j != cols-1 && board[i+1][j+1] == 'o') count++;
        board[i][j] = count + '0';
      }
}
////////////////////////
void compute_number_mines(char **board, const int rows, const int cols)
{
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      if (board[r][c] == 'R') {
        int rmin = r > 0 ? r - 1 : 0;
        int rmax = r < rows - 1 ? r + 1 : rows - 1;
        int cmin = c > 0 ? c - 1 : 0;
        int cmax = c < cols - 1 ? c + 1 : cols - 1;
        int cnt = 0;
        for (int r2 = rmin; r2 <= rmax; ++r2) {
          for (int c2 = cmin; c2 <= cmax; ++c2) {
            if (board[r2][c2] == 'o') cnt++;
          }
        }
        board[r][c] = '0' + cnt;
      }
    }
  }
}
/////////////////////////////////////////
void compute_number_mines(char** board, const int rows, const int cols,
                          const int row, const int col) {
    board[row][col] = '0';
    for (int i = -1; i <= 1; ++i) {
        if (row + i < 0 || row + i >= rows) continue;
        for (int j = -1; j <= 1; ++j) {
            if (col + j < 0 || col + j >= cols) continue;
            board[row][col] += board[row + i][col + j] == 'o';
        }
    }
}

void compute_number_mines(char** board, const int rows, const int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (board[i][j] != 'R') continue;
            compute_number_mines(board, rows, cols, i, j);
        }
    }
}
/////////////////////////
void compute_number_mines(char **board, const int rows, const int cols)
{
  
  int dx[]={-1, -1, -1, 0 ,0, 1, 1, 1};
  int dy[]={-1, 0, 1, -1, 1, -1, 0, 1};
  
  for(int row=0; row<rows; row++){
    for(int col=0; col<cols; col++){
      if(board[row][col]=='R'){
        int count=0;
        for(int i=0; i<8; i++){
          int newRow=row+dx[i];
          int newCol=col+dy[i];
          
          if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols){
            if(board[newRow][newCol]=='o'){
              count++;
            }
          }
        }
        
        board[row][col]='0'+count;
      }
    }
  }
  
  

}////////////////////////////////