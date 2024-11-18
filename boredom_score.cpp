#include <map>
#include <string>
#include <regex>
#include <string_view>
#include <numeric>

void process_string(std::string_view s,std::unordered_map<std::string,int>& mp){
  std::regex r("([\\w]+[\\s]*[\\w]*) [\\=]{1} ([\\d]+)");
  std::string str=(std::string)s;
  auto rb=std::sregex_iterator(str.begin(),str.end(),r);
  auto re=std::sregex_iterator();
  for(auto it=rb;it!=re;++it){
    std::smatch s;
    std::string t=it->str();
    if(std::regex_match(t,s,r)){
      mp[s[1]]=std::stoi(s[2]);
    }
  }
}

std::string boredom(const std::map<std::string, std::string> &st){
  std::string s="accounts = 1 finance = 2 canteen = 10 regulation = 3 trading = 6 change = 6 IS = 8 retail = 5 cleaning = 4 pissing about = 25";
  std::unordered_map<std::string,int>mp;
  process_string(s,mp);
  int res=std::accumulate(st.begin(),st.end(),0,[&mp](auto sum,auto curr){
    return sum+=mp[curr.second];
  });
  return res<=80?"kill me now":(res>80 && res<100)? "i can handle this":"party time!!";
}

///////////////////
#include <map>
#include <string>
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/view/transform.hpp>
#include <limits>

static inline const std::map<int,std::string> sentimap{
  {80, "kill me now"},
  {99,"i can handle this"},
  {std::numeric_limits<int>::max(), "party time!!"},
};
 
static inline const std::map<std::string,int> scoremap{
  {"accounts",1},
  {"finance",2},
  {"canteen",10},
  {"regulation",3},
  {"trading",6},
  {"change",6},
  {"IS",8},
  {"retail",5},
  {"cleaning",4},
  {"pissing about",25}
};

std::string boredom(const std::map<std::string,std::string> &staff,
                    const std::map<int,std::string>         &semap=sentimap,
                    const std::map<std::string,int>         &scmap=scoremap){
  auto vals=staff | ranges::views::transform([&](auto &v){return scmap.at(v.second);});
  const auto boredomscore=ranges::accumulate(vals.begin(),vals.end(),0);
  return semap.lower_bound(boredomscore)->second;
}