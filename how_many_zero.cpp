#include <regex>
#include <iostream>

int countZero(std::string s)
{
  if(s.empty()) return 0;
    std::regex oz("[abdegopqDOPQR]|[069]");//([^()]*) для одной скобки
  std::regex tz("[%&]|[B]|[8]");
  auto ob = std::sregex_iterator(s.begin(),s.end(),oz);
  auto tb = std::sregex_iterator(s.begin(),s.end(),tz);
  auto e = std::sregex_iterator();
  int cnt=0;
  for(size_t i=0;i<s.size();++i){
    if(s[i]=='(' && s[i+1]==')') ++cnt;
  }
  for(auto i=ob;i!=e;++i){
    ++cnt;
  }
  for(auto i=tb;i!=e;++i){
    cnt+=2;
  }
  return cnt;
}

/////////////////////////////


#include <regex>

int countZero(std::string s)
{
    static const std::regex re{R"((?=([%&B8])?)([abdegopq069DOPQR%&B8]|\(\)))"};
    return std::count_if(std::regex_token_iterator{s.begin(), s.end(), re, {1, 2}},
                         {},
                         std::bind(std::invoke<const bool std::sub_match<std::string::iterator>::*,
                                               const std::sub_match<std::string::iterator>&>,
                                   &std::sub_match<std::string::iterator>::matched,
                                   std::placeholders::_1));
}

///////////////////////
#include <bits/stdc++.h>
using namespace std;
int countZero(std::string s){
    regex re0("\\(\\)");
    string res0 = regex_replace(s, re0, "o");
    regex re1("[abdegpq069DOPQR]");
    string res1 = regex_replace(res0, re1, "o");
    regex re2("[\\%\\&B8]");
    string res2 = regex_replace(res1, re2, "oo");
    
    int ans=0;
    for(size_t i=0;i<res2.size();++i){
        if(int(res2[i])==111)++ans;
    }
    return ans;
}

/// //////////////

template <typename String, typename Needle>
typename String::size_type count_any(const String& str, const Needle& needles) {
    typename String::size_type result = 0;
    for (auto it = str.find_first_of(needles); it != String::npos; it = str.find_first_of(needles, it + 1))
        ++result;
    return result;
}
template <typename String, typename Needle>
typename String::size_type count(const String& str, const Needle& needle) {
    typename String::size_type result = 0;
    for (auto it = str.find(needle); it != String::npos; it = str.find(needle, it + 1))
        ++result;
    return result;
}
int countZero(const std::string &str) {
    return count_any(str, "abdegopq069DOPQR") + 2 * count_any(str, "%&B8") + count(str, "()");
}

/////////////////////////////////////
#include <cstring>

int countZero(std::string s)
{
  int zeros = 0;

  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '(' && s[i+1] == ')')
      zeros++;
    else if (std::strchr("%&B8", s[i]))
      zeros+=2;
    else if (std::strchr("abdegopq069DOPQR", s[i]))
      zeros++;
  }

  return zeros;
}
////////////////////////////////
