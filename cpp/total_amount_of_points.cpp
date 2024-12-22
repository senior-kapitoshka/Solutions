#include <numeric>
int points(const std::array<std::string, 10>& g) {
    return std::accumulate(g.begin(),g.end(),0,[](int sum, auto c){
      return sum+=((c.front()-'0')>(c.back()-'0'))?3:
      ((c.front()-'0')==(c.back()-'0'))?1:0;
    });
}

//////////////////////////
#include <array>
#include <string>
#include <numeric>
using namespace std;
int points(const array<string, 10>& games) {
  static int x,y;
  return accumulate(begin(games), end(games), 0, 
    [&](const int& a, const string& s){
      sscanf(s.c_str(),"%d:%d",&x,&y);
      if(x >y)return a + 3;
      if(x==y)return a + 1;
      return a;      
    }
  );
}

