#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

std::string draw(std::vector<int> wvs)
{
  std::vector<std::string>vs;
  int x=*std::max_element(wvs.begin(),wvs.end());
  vs.reserve(x);
  std::transform(wvs.begin(),wvs.end(),std::back_inserter(vs),[x](auto& i){
    std::string t(x,'0');
    std::fill(t.begin()+(x-(size_t)i),t.end(),'1');
    return t;
  });
  std::stringstream ss;
  for(size_t i=0;i<vs[0].size();++i){
    for(size_t j=0;j<vs.size();++j){
      vs[j][i]=='0'?ss<<"□":ss<<"■";
    }
    if(i!=vs[0].size()-1)ss<<"\n";
  }
  
    return ss.str();
}

//////////////////////
#include <algorithm>
std::string draw(std::vector<int> waves)
{
    int max = *std::max_element(waves.begin(), waves.end());
    std::string result;
    for(int i = 0; i < max; ++i){
        for(int j = 0; j < waves.size(); ++j){
            if(waves[j] < max - i)
                result += "□";
            else
                result += "■";
        }
        result += "\n";
    }
    result.pop_back();
    return result;
}
////////////////
#include <cstddef>
#include <algorithm>
#include <string>
#include <vector>

std::string draw(const std::vector<int>& waves) {
  std::string res;
  std::size_t width = waves.size(), height = *std::max_element(waves.cbegin(), waves.cend());
  res.reserve((width * (sizeof("■") - 1) + 1) * height);
  for (std::size_t i = height; i >= 1; i--) {
    for (int h : waves)
      res += h >= i ? "■" : "□";
    res += '\n';
  }
  res.pop_back();
  return res;
}
////////////////
std::string draw(std::vector<int> waves) {
  std::ostringstream sb;
  int n = waves.size();
  for (int h = *std::max_element(waves.begin(), waves.end()); h>0; h--) {
    for (int i=0; i<n; i++)
      sb << ((waves[i] < h) ? "□" : "■");
    if (h > 1) sb << "\n";
  }
  return sb.str();
}