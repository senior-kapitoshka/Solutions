#include <array>
#include <set>

bool validate(const std::array<std::array<int, 9>, 9>& arr) {
  std::set<int>rw,cl;
  for(size_t i=0;i<arr.size();++i){
        for(size_t j=0;j<arr[0].size();++j){
          if(arr[i][j]<=0||arr[i][j]>9) return false;
            rw.insert(arr[j][i]);
            cl.insert(arr[i][j]);
        }
        if(rw.size()!=9 || cl.size()!=9) return false;
      rw.clear();cl.clear();
    }  
  std::set<int>st;
  for(size_t i=0;i<9;i+=3){
    for(size_t j=0;j<9;j+=3){
      for(size_t k=i;k<i+3;++k){
        for(size_t m=j;m<j+3;++m){
          st.insert(arr[k][m]);
        }
      }
      if(st.size()!=9) return false;
      st.clear();
    }
  }
  return true;;
}
//////////////////////
#include <array>

bool validate(const std::array<std::array<int, 9>, 9>& board) {
   for (int r = 0; r < 9; r++)
   {
        int row = 0;
        int col = 0;
        int box = 0;
        for (int c = 0; c < 9; c++) 
        {
            int i = (r % 3) * 3 + c % 3;
            int j = (r / 3) * 3 + c / 3;
            row ^= 1 << (int)board[r][c];
            col ^= 1 << (int)board[c][r];
            box ^= 1 << (int)board[j][i];
        }
        if (row != 1022 || col != 1022 || box != 1022) {
            return false;
        }
    }
    return true;
}
///////////////
#include <array>
bool validate(const std::array<std::array<int, 9>, 9>& M)
{
    for (int i = 0; i < 9; i++) {
    int R[10] = {0}, C[10] = {0}, B[10] = {0};
    for (int j = 0; j < 9; j++) {
      if (!M[i][j] || R[ M[i][j] ]++) return false;
      if (!M[j][i] || C[ M[j][i] ]++) return false;
      if (!M[i/3 * 3 + j/3][i%3 * 3 + j%3]|| B[M[i/3 * 3 + j/3][i%3 * 3 + j%3]]++) return false; 
    }
  }
  return true;
}
///////////////
