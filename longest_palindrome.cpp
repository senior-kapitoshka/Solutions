#include <unordered_map>
#include <algorithm>
#include <numeric>

unsigned int longestPalindrome(const std::string& str){
  std::unordered_map<char,int>mp;
  std::for_each(str.begin(),str.end(),[&mp](auto& c){
    if(isalpha(c) || isdigit(c))++mp[tolower(c)];
  });
  bool flag=false;
  return std::accumulate(mp.begin(),mp.end(),0,[&flag](int sum,auto curr){
    if(!flag && curr.second%2!=0 && curr.second==1){ 
      flag=true;
      return sum+=1;
    }else if(!flag && curr.second%2!=0 && curr.second>=3){
      flag=true;
      return sum+=curr.second;
    }                           
    return sum+=curr.second%2==0?curr.second:(curr.second%2!=0 && curr.second>=3)?curr.second-1:0;
  });
}

///////////////
#include <unordered_map>

unsigned int longestPalindrome(const std::string& s) {
  std::unordered_map<char, int> d;
  for (char c : s) c = tolower(c), (c > 47 && c < 58) || (c > 96 && c < 123) ? d[c] = d[c] + 1 : 0;
  int r = 0;
  for (auto x : d) r += x.second / 2 * 2 + (x.second % 2 >> r % 2);
  return r;
}

////////////////
#include <map>
#include <cctype>
#include <numeric>

unsigned int longestPalindrome(const std::string& str) {
  std::map<char, unsigned int> count;
  for (auto c: str) if (std::isalnum(c)) count[std::tolower(c)] ++;
  return std::accumulate(cbegin(count), cend(count), 0, [] (auto a, auto x) {
    return a + 2 * (x.second / 2) + (x.second % 2 >> a % 2);
  });
}
///////////
