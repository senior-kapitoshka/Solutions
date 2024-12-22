#include <set>


uint64_t vowelRecognition(const std::string &str){
  uint64_t res=0;
  std::string arr="AEIOUaeiou";
  for(size_t i=0;i<str.size();++i){
    if(arr.find(str[i])!=str.npos){
      res += (i + 1) * (str.size() - i);
    }
  }
  return res;
}

#if 0
void rec(const std::string&s, std::set<std::string>&st, uint64_t& sum){
  if(st.count(s))return;
  st.insert(s);
  sum+=std::count_if(s.begin(),s.end(),[](auto& c){
    return  c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
  });
}

uint64_t vowelRecognition(const std::string &str){
  uint64_t sum=0;
  std::set<std::string>st;
  rec(str,st,sum);
  size_t i=0;
  size_t j=str.size()-1;
  while(i<=j){
    for(size_t x=0;x<str.size();++x){
      rec(str.substr(i,x),st,sum);
    }
    for(size_t y=j;y>0;--y){
      rec(str.substr(y+1,j-y),st,sum);
    }
    ++i;--j;
  }
  return sum;
}

#endif
////////////////////////
#include <string>
#include <regex>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

uint64_t vowelRecognition(const std::string &str){
    // your code here
    std::string s = "AEIOUaeiou";
    std::vector<uint64_t> counts;
    uint64_t sum = 0, c = 0;
    for(uint64_t i = 0; i < str.size(); i++){
      if(s.find(str[i])!=std::string::npos) c++;
      sum+=c;
      counts.push_back(c);
    };
    uint64_t ans = 0, step = 0;
    for(uint64_t i = 0; i<counts.size(); i++){
      ans+=sum;
      sum-=counts[i]*(counts.size()-i);
      step+=counts[i];
      if(i<counts.size()-1)  counts[i+1]-=step;
    }
    return ans;
}
//////////////////////////
#include <algorithm>
#include <cctype>
#include <string>

uint64_t vowelRecognition(const std::string &str) {
  uint64_t c = 0;
  std::string s, vowels = "aeiou";
  std::transform(str.cbegin(), str.cend(), std::back_inserter(s),
                 [](char c) { return tolower(c); });
  for (size_t i = 0; i < s.length(); i++) {
    if (vowels.find(s[i]) != std::string::npos)
      c += (i + 1) * (s.length() - i);
  }
  return c;
}