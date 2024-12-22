#include <algorithm>

int targetGame(const std::vector<int>& v) {
  // your code goes here
  
  int a=0,b=0;
  for(auto i: v)
  {
    int x=a;
    a=b;
    b=std::max(x+i,b);
  }
  return std::max(a,b);
}

////////////////////////
#include <algorithm>
int targetGame(const std::vector<int>& values) {
  int memo[3] = {0};
  
  for(int i = 0; i < values.size(); i++) 
    memo[i % 3] = std::max( memo[(i + 1) % 3] + values[i], memo[(i + 2) % 3]);

  return memo[(values.size() - 1) % 3];
}

///////////////////////////
#include <vector>

using namespace std;

int targetGame(const vector<int>& values)
{
  vector<int> max_score(values.size()+2, 0);
  for (int i = values.size()-1 ; i >= 0 ; i--)
    max_score[i] = max(values[i]+max_score[i+2], max_score[i+1]);
  return max_score.front();
}

////////////////////
