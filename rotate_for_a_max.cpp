#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

class MaxRotate
{
public:
  static long long maxRot(long long n){
    std::string s=std::to_string(n);
    std::vector<long long>vs;
    vs.push_back(std::stoll(s));
    for(size_t i=0;i<s.size();++i){
      char c=s[i];
      std::string t;
      for(size_t j=0;j<s.size();++j){
        if(i!=j)t+=s[j];
      }
      t+=c;
      vs.emplace_back(std::stoll(t));
      s=t;
      t.erase();
    }
    return *std::max_element(vs.begin(),vs.end());
  }
  
};
//////////////////////////
#include <algorithm>
#include <string>

class MaxRotate
{
public:
  static long long maxRot(long long n);
};

long long MaxRotate::maxRot(long long n) 
{
    std::string s = std::to_string(n);
    for (int i = 0; i < s.length()-1; ++i)
    {
        std::rotate(s.begin()+i, s.begin()+i+1, s.end());
        n = std::max(stoll(s), n);
    }
    return n;
}
///////////////////////
