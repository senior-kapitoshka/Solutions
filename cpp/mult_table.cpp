#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
vector<vector<int>> multiplication_table(int n){
  std::vector<int>vc(n,0);
  std::iota(vc.begin(),vc.end(),1);
  vector<vector<int>>res;
  res.reserve(n);
  res.emplace_back(vc);
  for(int i=2;i<=n;++i){
    std::vector<int>t;
    t.reserve(n);
    std::for_each(vc.begin(),vc.end(),[i,&t](auto& j){
      t.emplace_back(j*i);
    });
    res.emplace_back(t);
  }
  return res;
}

/////////////////////////
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> multiplication_table(int n)
{
  vector<vector<int>> result(n , vector<int>(n));
  
  std::generate(result.begin(), result.end(), [row = 1, &n] () mutable 
  {
    vector<int> tempLine(n);
    std::generate(tempLine.begin(), tempLine.end(), [iterator = 1, &row] () mutable { return iterator++ * row;});
    row++;
    return tempLine;
  });
  
  return result;
}
////////////////
#include <vector>

using namespace std;
vector<vector<int>> multiplication_table(int n) {
  vector<vector<int>> result(n, vector<int>(n));
  for (int i = 0; i < n ; i ++) {
    for (int j = 0; j < n ; j ++) result[i][j] = (i + 1) * (j + 1);
  }
  return result;
}
///////////////
#include <vector>
std::vector<std::vector<int>> multiplication_table(int n) {
  std::vector<std::vector<int>> res (n, std::vector<int> (n));
  for (int i {1}; i <= n; i++)
    for (int j {1}; j <= n; j++)
      res[i-1][j-1] = i*j;
  return res;
}
//////////////////
#include <vector>

std::vector<std::vector<int>> multiplication_table(int n){
  
  std::vector<std::vector<int>> table;
  for (int i = 1; i <= n; i++) {
    std::vector<int> row;
    for (int j = 1; j <= n; j++) {
      row.push_back(i*j);
    }
    table.push_back(row);
  }
  
  return table;
}

