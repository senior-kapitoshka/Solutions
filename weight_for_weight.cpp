#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

class WeightSort
{
public:
  struct Nums{
    int sm;
    std::string s;
    bool operator==(const Nums& o) const{
      return sm==o.sm && s == o.s;
    }
    bool operator >(const Nums& o) const{
      return sm > o.sm && s > o.s;
    }
    bool operator <(const Nums& o) const{
      return sm < o.sm && s < o.s;
    }
    
   
  };

  class Hasher {
    public:
      inline size_t operator()(const Nums& n) const{
        size_t hsh = std::hash<std::string>{}(n.s);
        return hsh;
    }

  };

  static std::unordered_map<Nums,int,Hasher>prs(const std::string &s){
    std::stringstream ss(s);
    std::unordered_map<Nums,int,Hasher> res;
    for(std::string w;ss>>w;){
      int t=0;
      for_each(w.begin(),w.end(),[&t](auto& c){
        t+=c-'0';
      });
      ++res[{t,w}];
    }

    return res;
  }
    static std::string orderWeight(const std::string &s){
      if(s.empty()) return "";
      std::unordered_map<Nums,int,Hasher>vs = prs(s);
     std::vector<std::pair<Nums,int>>vp;
    for(auto p:vs){
        vp.push_back({p.first,p.second});
    }
    std::sort(vp.begin(),vp.end(),[](auto a,auto b){
      if(a.first.sm==b.first.sm) return a.first.s<b.first.s;
      return a.first.sm<b.first.sm;
    });
    std::string res;
    for(auto p:vp){
        if(p.second>1){
            int i=0;
            while(i!=p.second){
                res+=p.first.s;
                res+=' ';
                ++i;
            }
        }else{
            res+=p.first.s;
            res+=' ';
            
        }
    }
    res=res.substr(res.find_first_not_of(' '),
                   res.find_last_not_of(' ')-res.find_first_not_of(' ')+1);
    return res;
    }
};
//////////////////////////////

#include <numeric>
#include <string>
#include <iterator>
#include <algorithm>
#include <sstream>

class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng) {
      std::vector<std::string> inputs;
      std::istringstream iss(strng);
      std::copy(std::istream_iterator<std::string>(iss), 
                std::istream_iterator<std::string>(),
                std::back_inserter(inputs));
      std::sort(inputs.begin(), inputs.end(),
                [](const std::string& s1, const std::string& s2) {
                  auto sum_func = [](const char c, int acc) { return acc + static_cast<int>(c-'0'); };
                  int s1sum = std::accumulate(s1.begin(), s1.end(), 0, sum_func);
                  int s2sum = std::accumulate(s2.begin(), s2.end(), 0, sum_func);
                  if (s1sum == s2sum)
                    return s1 < s2;
                  else
                    return s1sum < s2sum;
                });
      std::ostringstream oss;
      std::copy(inputs.begin(), inputs.end(), std::ostream_iterator<std::string>(oss, " "));
      std::string s = oss.str();
      return s.substr(0, s.size()-1);
    }
};
/////////////////////////////////////

#include <iostream>
#include <set>
#include <sstream>
#include <string>

auto getWeight = [](long long a) {
  int result{};
  while (a > 0) {
    result += a % 10;
    a /= 10;
  }
  return result;
};

auto cmp = [](long long a, long long b) {
  if (getWeight(a) == getWeight(b))
    return std::to_string(a) < std::to_string(b);
  return getWeight(a) < getWeight(b);
};

class WeightSort {
public:
  static std::multiset<long long, decltype(cmp)> set;

  static std::string orderWeight(const std::string &strng) {
    set.clear();
    std::istringstream iss(strng);
    for (std::string s; iss >> s;) {
      set.emplace(std::stoll(s));
    }
    std::string result{};
    for (const auto &x : set) {
      result += std::to_string(x) + " ";
    }
    result.pop_back();
    return result;
  };
};
std::multiset<long long, decltype(cmp)> WeightSort::set(cmp);

////////////////////////////////////////////////
#include <regex>
class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng) {
      using namespace std;
      string ret{""};
      vector<pair<int, string>> v;
      regex rex("(\\S+)");
      auto wbegin = sregex_iterator(begin(strng), end(strng), rex);
      for_each(wbegin, sregex_iterator(),
        [&](auto match) {
          // tokenize & weigh
          int weight = 0;
          string word = match.str();
          for (auto c : word) weight += c - 48;
          v.push_back({weight, word});
        });
      sort(begin(v), end(v));
      for (auto x : v) ret += x.second + ' ';
      ret.resize(ret.size() > 0 ? ret.size() - 1 : 0); // remove trailing space
      return ret;
    }
};
/////////////////////////// ////////////////////
class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng) {
      std::vector<std::pair<std::string, int>> list;
      std::stringstream ss(strng);
      for (std::string s; ss >> s;) {
          int sum = 0;
          for (char i : s) sum += i - '0';
          list.emplace_back(s, sum);
      }
      std::sort(list.begin(), list.end(), [](auto& left, auto& right) {
          return left.second == right.second ? left.first < right.first : left.second < right.second; });
      std::string result;
      for (auto& i : list) result += i.first + (&i != &list.back() ? " " : "");
      return result;
    }
};
///////////////////////////////////////////