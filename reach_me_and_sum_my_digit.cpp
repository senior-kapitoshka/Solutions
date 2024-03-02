#include <vector>

int sumDigNthTerm(int init, const std::vector<int> pat, int nt) {
  for(size_t i=0;i<(size_t)nt-1;++i){
    init+=pat[i%pat.size()];
  }
  int res=0;
  while(init!=0){
    res+=init%10;
    init/=10;
  }
  return res;
}

//////////////////
#include <vector>
#include <numeric>

int sumDigNthTerm(int initval, const std::vector<int> patternl, int nthterm)
{
    for (size_t i = 0; i < nthterm - 1; i++) initval += patternl[i % patternl.size()];
    std::string result = std::to_string(initval);
    return std::accumulate(result.begin(), result.end(), 0, [](char a, char b){ return (int)a + (int)b - 48; });
}
///////////////
