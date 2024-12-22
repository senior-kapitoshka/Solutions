#include <algorithm>

std::vector<std::vector<int>> rotateMatrixLeft(std::vector<std::vector<int>> mx)
{
  std::for_each(mx.begin(),mx.end(),[](auto& v){
    std::reverse(v.begin(),v.end());
  });
  std::vector<std::vector<int>>nm(mx[0].size(),std::vector<int>(mx.size(),0));
  for(size_t i=0;i<mx[0].size();++i){
    for(size_t j=0;j<mx.size();++j){
      nm[i][j]=mx[j][i];
    }
  }
    return nm;
}
////////////////
std::vector<std::vector<int>> rotateMatrixLeft(std::vector<std::vector<int>> matrix)
{
    std::vector<std::vector<int>> result_matrix(matrix[0].size());
    for(int i = 0; i < matrix.size(); i++)
    {
         std::reverse(matrix[i].begin(),matrix[i].end());
        for(int j = 0; j < matrix[0].size(); j++)
        {
            result_matrix[j].push_back(matrix[i][j]);
        }
    }
    return result_matrix;
}
////////////////
std::vector<std::vector<int>> rotateMatrixLeft(std::vector<std::vector<int>> matrix)
{
    std::vector<std::vector<int>> rotated (matrix[0].size());

    for (size_t i = 0; i < rotated.size(); i++)
        for (size_t j = 0; j < matrix.size(); j++)
            rotated[i].push_back(matrix[j][matrix[0].size()-i-1]);

    return rotated;
}
/////////
using namespace std;

std::vector<std::vector<int>> rotateMatrixLeft(std::vector<std::vector<int>> matrix)
{
    int colLen = matrix.size();
    int rowLen = matrix[0].size();
    vector<vector<int>> v(rowLen, vector<int>(colLen));
    for (int i = 0; i < rowLen; i++) {
        for (int j = 0; j < colLen; j++) {
            v[i][j] = matrix[j][rowLen - i - 1];
        }
    }
    return v;
}
/////////
