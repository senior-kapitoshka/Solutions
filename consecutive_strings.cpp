#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class LongestConsec
{
public:
    static std::string longestConsec(const std::vector<std::string> &sr, int k){
      if(k<=0)return "";
      if(sr.empty())return "";
      if(k>(int)sr.size())return "";
      std::vector<std::string>vc;
      std::for_each(sr.begin(),prev(sr.end(),k-1),[i=0,&vc,&sr,k](auto& s)mutable
                         {
                           std::string t=std::accumulate(sr.begin()+i+1,sr.begin()+i+k,s,
                                                         [](auto& lhs,auto& rhs){
                                                           return lhs+rhs;
                                                         });
                           ++i;
                           vc.push_back(t);
                          });

      
      return *max_element(vc.begin(),vc.end(),[](auto& lhs,auto& rhs){return lhs.size()<rhs.size();});
      
    }
};
/////////////////
#include <functional>
#include <numeric>
#include <string>
#include <vector>

class LongestConsec {
public:
    static std::string longestConsec(const std::vector<std::string>& strings, int k) {
      k = std::max(k, 0);
      std::string longest;
      for (size_t i = k; i <= strings.size(); i += 1) {
        auto begin = std::next(strings.begin(), i - k);
        auto end = std::next(begin, k);
        std::string s = std::accumulate(begin, end, std::string());
        if (s.length() > longest.length()) {
          longest = s;
        }
      }
      return longest;
    }
};
//////////////////////
