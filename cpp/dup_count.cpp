#include <iostream>
size_t duplicateCount(const std::string& in)
{
  std::cout<<in<<"\n";
  size_t ans=0;
  if(in.empty()) return 0;
  
  std::map<char,int>mp;
  for(auto&& i:in){
    if(isalpha(i)){
      mp[tolower(i)]++;
    }else if(i=='\'') {
      mp[i]++;
    }
    else if(i==' ') continue;
  }
  for(auto&& i:mp ){
    if(i.second>1){
      
      std::cout<<i.first<<"\n";
      ans++;
    }
    std::cout<<"\n";
   }
    return ans;
  
}
//////////////////////////////////////////////////////

#include <string>
#include <unordered_map>
#include <algorithm>

#include <cctype>

std::size_t duplicateCount(const char* in) {
  std::unordered_map<char, unsigned> counts;
  for (const char* c = in; *c != '\0'; ++c) {
    ++counts[tolower(*c)];
  }
  return std::count_if(cbegin(counts), cend(counts), [](const auto& count) {
      return count.second > 1;
    });
}