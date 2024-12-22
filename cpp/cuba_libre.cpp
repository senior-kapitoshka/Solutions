#include <vector>
#include <algorithm>
std::vector<std::vector<int>> CubaLibre(std::vector<std::vector<std::vector<int>>> C)
{
  std::vector<std::vector<int>>cnv(C.front().size()+C.size()-1,std::vector<int>(C.front()[0].size()+C.size()-1)); 
  std::for_each(C.rbegin(),C.rend(),[x=cnv.size()-C.front().size(),y=0,&cnv](auto& m)mutable{
    for(int i=x,k=0;k<(int)m.size();++i,++k){
      for(int j=y,l=0;l<(int)m[0].size();++j,++l){
        cnv[i][j]+=m[k][l];
      }
    }
    --x;
    ++y;
  });
  return cnv;
}

//////////////////////////
#include <vector>
std::vector<std::vector<int>> CubaLibre(std::vector<std::vector<std::vector<int>>> Cube)
{
  int row = Cube[0].size(), col = Cube[0][0].size(), layer = Cube.size();
  std::vector<std::vector<int>> cube(row + layer - 1, std::vector<int>(col + layer - 1, 0));
  for (int i = 0; i < layer; i++)
    for (int j = 0; j < row; j++)
      for (int k = 0; k < col; k++)
        cube[j + i][k + layer - i - 1] += Cube[i][j][k];
  return cube;
}

/////////////////
