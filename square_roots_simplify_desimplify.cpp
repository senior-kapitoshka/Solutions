#include <string>
#include <cmath>
#include <fmt/format.h>

std::string simplify(int n)
{
  if(n==1) return "1";
  for(int i=2;i*i<=n;++i){
    if(n==i*i) return std::to_string(i);
  }
  std::string res;
  for(int i=2;i*i<=n;++i){
    for(int j=2;j<n;++j){
      if(n==i*i*j){
         res=fmt::format("{} sqrt {}",i,j);
      }
    }
  }
    return !res.empty()?res:"sqrt "+std::to_string(n);  
}

int desimplify(std::string s)
{    return (isdigit(s.front()) && s.find("sqrt")==s.npos)?
      std::stoi(s.substr(0,s.find_first_of(' ')))*
      std::stoi(s.substr(0,s.find_first_of(' '))):
  (isdigit(s.front()) && s.find("sqrt")!=s.npos)?
    std::stoi(s.substr(0,s.find_first_of(' ')))*
      std::stoi(s.substr(0,s.find_first_of(' ')))*
    std::stoi(s.substr(s.find_last_of(' '))):
  std::stoi(s.substr(s.find_last_of(' ')));
}


//////////////////////////
#include <string>
#include <map>

std::string simplify(int n)
{
    if (n == 1) return "1";
  
    std::map<int, int> factors;
    int num = n, tmp = 2;
    while (num >= tmp)
    {
        if (num % tmp == 0)
        {
            factors[tmp]++;
            num /= tmp;
        }
        else
            ++tmp;
    }
    
    int x = 1;
    for (auto [f, c] : factors)
        for (auto i = 0; i < c / 2; i++)
            x *= f;
    if (x == 1) return "sqrt " + std::to_string(n);
  
    int y = n / (x * x);
    return std::to_string(x) + (y == 1 ? "" : " sqrt " + std::to_string(y));
}

int desimplify(std::string s)
{
    auto s1 = s.find(' ');
    if (s1 == std::string::npos)
    {
        auto n = std::stoi(s);
        return n * n;
    }
  
    auto s2 = s.find(' ', s1 + 1);
    if (s2 == std::string::npos)
        return std::stoi(s.substr(s1 + 1));
  
    auto x = std::stoi(s.substr(0, s1));
    auto y = std::stoi(s.substr(s2 + 1));
  
    return x * x * y;
}

///////////////////
#include <regex>

std::string simplify(int n)
{
    int a = std::sqrt(n);
    for (; a >= 1; --a)
        if (n % (a * a) == 0)
            break;
    int b = n / (a * a);
    if (b == 1) return std::to_string(a);
    if (a == 1) return "sqrt " + std::to_string(b);
    return std::to_string(a) + " sqrt "  + std::to_string(b);
}

int desimplify(const std::string& s)
{
    std::smatch match;
    std::regex_match(s, match, std::regex(R"((?:(\d+)(?: sqrt (\d+))?)|(?:sqrt (\d+)))"));
    assert(!match.empty());
    const auto atoi = [](const std::string& s, int if_empty=0) { return s.size()? std::atoi(s.c_str()) : if_empty; };
    int a = atoi(match.str(1), 1);
    int b = atoi(match[2].length()? match.str(2): match.str(3), 1);
    return a * a * b;
}
/////////////////
#include <string>
#include <cmath>
#include <regex>

std::string simplify(int n)
{
    //your code here   
    std::string ans = "";
    for(int i = n ; i > 1 ; i--){
      if(n%i==0){
        int root = sqrt(i), rest = n/i;
        if(root*root==i) return std::to_string(root)+ (rest == 1 ? "" : " sqrt "+std::to_string(n/i));
      }
    }
    return n == 1 ? "1" : "sqrt "+std::to_string(n);
}

int desimplify(std::string s)
{
    //your code here
    std::regex pattern("\\d+");
    auto begin = std::sregex_iterator(s.begin(), s.end(), pattern);
    int ans = 0;
    ans = stoi(begin->str())*stoi(begin->str());
    bool notContainsSqrt = s.find("sqrt")==std::string::npos;
    if(notContainsSqrt) return ans;
    begin++;
    if(begin!=std::sregex_iterator()) return ans*stoi(begin->str());
    return sqrt(ans);
}