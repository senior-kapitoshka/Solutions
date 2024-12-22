#include <utility>
#include <algorithm>
#include <numeric>
#include <sstream>

class Rank
{
public:
    static std::string nthRank(const std::string &st, std::vector<int> &we,[[maybe_unused]] int n){
      using namespace std::literals;
      if(st.empty()) return "No participants"s;
      std::vector<std::string>str;
      std::stringstream ss;
      ss.str(st);
      for(std::string w;std::getline(ss,w,',');){
        str.emplace_back(std::move(w));
      }
      if(str.size()<(size_t)n) return "Not enough participants"s;
      std::vector<std::pair<std::string,int>>vc;
      vc.reserve(str.size());
      std::for_each(str.begin(),str.end(),[i=0,&vc,&we](auto& s)mutable{
        vc.emplace_back(std::make_pair(s,((int)s.size()+std::accumulate(s.begin(),s.end(),0,[](int& sum,auto& c){return sum+=tolower(c)-96;}))*we[i++]));
      });
      std::sort(vc.begin(),vc.end(),[](auto& lhs, auto& rhs)
                {return lhs.second==rhs.second?lhs.first<rhs.first:lhs.second>rhs.second;});
      return vc[n-1].first;
    }
};