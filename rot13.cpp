#include <string>
#include <unordered_map>
#include <algorithm>

std::string rot13(const std::string& str) {
  using namespace std::literals;
    std::string s ="ABCDEFGHIJKLMabcdefghijklm"s;
    std::string c = "NOPQRSTUVWXYZnopqrstuvwxyz"s;
    std::unordered_map<char,char> mp;
    int i=0;
    std::for_each(s.begin(),s.end(),[&i,&c,&mp](auto z){
        mp[z]=c[i];
        mp[c[i]]=z;
        ++i;
    });

  std::string res;
  std::transform(str.begin(),str.end(),std::back_inserter(res),[&mp](auto& c){
    if(mp.count(c)) return mp[c];
    return c;
  });
  return res;
}

////////////////////////////
#include <string>

char rot13c(const char c) {
  if (islower(c))
    return (c - 'a' + 13) % 26 + 'a';
  if (isupper(c))
    return (c - 'A' + 13) % 26 + 'A';
  return c;
}

std::string rot13(const std::string& str) {
  std::string s;
  std::transform(str.begin(), str.end(), std::back_inserter(s), rot13c);
  return s;
}
/////////////////////////
#include <string_view>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/transform.hpp>

std::string rot13(std::string_view str) {
  return str
    | ranges::views::transform([](char c) {
      char l = c | 'A' ^ 'a';
      return c + ('a' <= l && l <= 'm' ? 13 : 'n' <= l && l <= 'z' ? -13 : 0);
    })
    | ranges::to<std::string>;
}
//////////////////////////
