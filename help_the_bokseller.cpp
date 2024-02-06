#include <unordered_map>
#include <algorithm>
#include <numeric>

class StockList
{
public:
  static std::string stockSummary(std::vector<std::string> &art, std::vector<std::string> &cd){
    if(art.empty()) return "";
    std::unordered_map<char, int>mp;
    for_each(art.begin(),art.end(),[&mp](auto& s){
      if(!mp.count(s[0])){
        mp[s[0]] = std::stoi(s.substr(s.find_first_of(' ')+1));
      }else if(mp.count(s[0])){
        mp[s[0]] += std::stoi(s.substr(s.find_first_of(' ')+1));
      }
      });
    std::string ans;
   for(size_t i=0;i<cd.size();++i){
      if(mp.count(cd[i][0])){
        ans+="(" +cd[i]+" : " + std::to_string(mp[cd[i][0]]) + ")";
        if(i!=cd.size()-1) ans+=" - ";
      }else if(!mp.count(cd[i][0])){
        ans+= "("+ cd[i] + " : 0)";
        if(i!=cd.size()-1) ans+=" - ";
      }
    }
    return ans;
  }
};




////////////////////////////////////////////

#include <numeric>

class StockList
{
public:
    static std::string stockSummary(std::vector<std::string> &L, std::vector<std::string> &M)
    {
        return L.empty() ? "" : std::accumulate(M.begin(), M.end(), std::string(), [&L](auto &&res, auto &&m)
        {
            return res + std::string(res.empty() ? "" : " - ") + '(' + m + " : " + std::to_string(std::accumulate(L.begin(), L.end(), 0, [&m](auto sum, auto &&l)
            {
                return sum + (l[0] == m[0] ? atoi(l.data() + l.find(' ')) : 0);
            })) + ")";
        });
    }
};