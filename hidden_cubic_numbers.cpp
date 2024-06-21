#include <regex>
#include <numeric>
#include <cmath>
#include <sstream>

class Cubes
{
public:
  static bool check_cub(const std::string &s){
    int x=std::stoi(s);
    return x==std::accumulate(s.begin(),s.end(),0,
                             [](auto sum,auto curr){
                               return sum+=std::pow(std::stoi(std::string(1,curr)),3);
                             });
  }
  
  static std::string isSumOfCubes(std::string &str){
    std::cout<<str<<"\n";
    std::stringstream ss;
    std::regex r("[\\d]{1,3}");
    auto rb=std::sregex_iterator(str.begin(),str.end(),r);
    auto re=std::sregex_iterator();
    for(auto it=rb;it!=re;++it){
      std::cout<<(*it).str()<<"\n";
      if((*it).str().size()>1 && (*it).str().front()=='0'){
        if(!std::all_of((*it).str().begin(),(*it).str().end(),[](auto& c){return c=='0';})) ss<<"0"<<" ";
        else {
          std::string x=(*it).str().substr((*it).str().find_first_not_of('0'));
          ss<<x<<" ";
        }
      }else{
        check_cub((*it).str())?ss<<(*it).str()<<" ":ss<<"";
      }
    }
    int sum=0;
    if(ss.str().empty()) return "Unlucky";
    else{
      std::stringstream sss(ss.str());
      for(std::string w;std::getline(sss,w,' ');){
        sum+=std::stoi(w);
      }
    }
    return ss.str()+std::to_string(sum)+" Lucky" ;
  }
};

////////////////////////


#include <string>
#include <vector>
#include <regex>
#include <algorithm>

class Cubes
{
public:
  static std::string isSumOfCubes(std::string &str);
};

std::string Cubes::isSumOfCubes(std::string &str)
{
    std::vector<std::string> cubics = {"0", "00", "000", "1", "01", "001", "153", "370", "371", "407"};
    std::vector<std::string> nb = {};
    std::regex exp("\\d{1,3}");
    std::smatch res;
    std::string::const_iterator searchStart(str.cbegin());
    while (regex_search(searchStart, str.cend(), res, exp))
    {
        std::string r = res[0];
        nb.push_back(r);
        searchStart += res.position() + res.length();
    }
    int sum = 0; std::string result = "";
    for (unsigned int i = 0; i < nb.size(); i++)
    {
        std::string k = nb[i];
        if (std::find(cubics.begin(), cubics.end(), k) != cubics.end())
        {
            result += std::to_string(std::stoi(k)) + " ";
            sum += std::stoi(k);
        }
    }
    if (result == "")
        return "Unlucky";
    return result + std::to_string(sum) + " Lucky";
}

///////////////////////
#include <string>
#include <regex>
#include <numeric>

class Cubes
{
public:
    static std::string isSumOfCubes(std::string const& str)
    {
        int sum{0};
        std::string res{};
        std::regex number_reg("[0-9]{1,3}");
        for (auto i = std::sregex_iterator(str.begin(), str.end(), number_reg); i != std::sregex_iterator(); i++)
        {
            auto s = i->str();
            auto n = std::stoi(s);
            s = std::to_string(n);
            auto cubic = std::reduce(s.cbegin(), s.cend(), 0, [](int x, char c) { auto y = (c - '0'); return x + y * y * y; });
            if (n == cubic)
            {
                sum += n;
                res += s;
                res += ' ';
            }
        }
        if (res.empty()) return "Unlucky";
        return res + std::to_string(sum) + " Lucky";
    }
};

//////////////////////
#include <regex>
#include <sstream>

using namespace std;

namespace {
  string clean(string s) {
    regex garbage("[^\\d]+");
    s = regex_replace(s, garbage, " ");
    regex d3("\\d\\d\\d");
    s = regex_replace(s, d3, " $& ");
    return s;
  }

  vector<string> split(string s) {
    vector<string> v;
    std::regex r("[^ ]+");
    std::smatch m;
    while (std::regex_search(s, m, r)) {
      v.push_back(m.str());
      s = m.suffix();
    }
    return v;
  }

  bool cubic(int n) {
    int sum = 0;
    int rem = n;
    while (rem > 0) {
      int d = rem % 10;
      rem /= 10;
      sum += d*d*d;
    }
    return sum == n;
  }
}

namespace Cubes {
  string isSumOfCubes(string s) {
    s = clean(s);
    stringstream r;
    int sum = 0;
    for (const auto& n : split(s)) {
      int i = stoi(n);
      if (cubic(i)) {
        r << i << ' ';
        sum += i;
      }
    }
    s = r.str();
    return s.empty() ? "Unlucky" : s + to_string(sum) + " Lucky";
  }
};

///////////////////
