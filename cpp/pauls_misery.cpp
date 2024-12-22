#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <regex>
#include <numeric>

using namespace std::literals;

void helper(std::unordered_map<std::string,int>&mp){
  std::string s="kata = 5 Petes kata = 10 life = 0 eating = 1"s;
  std::regex r("([\\w]+[\\s]{0,}[\\w]+)[\\s]{1}[=]{1}[\\s]{1}([\\d]+)");
  auto rb=std::sregex_iterator(s.begin(),s.end(),r);
  auto re=std::sregex_iterator();
  std::smatch m;
  for(auto it=rb;it!=re;++it){
    std::string t=(*it).str();
    std::regex_match(t,m,r);;
    mp[m[1]]=std::stoi(m[2]);
  }
}

std::string paul(const std::vector<std::string>& x) {
  std::unordered_map<std::string,int>mp;
  helper(mp);
  int res=std::accumulate(x.begin(),x.end(),0,[&mp]
                  (int& sum,auto& c){
                    return sum+=mp[c];
                  });
  return res<40?"Super happy!"s:
  (res<70 && res>=40)?"Happy!"s:(res<100 && res>=70)?"Sad!"s:"Miserable!"s;
}

/////////////////////
