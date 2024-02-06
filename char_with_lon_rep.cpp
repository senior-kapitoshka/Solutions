#include <utility>
#include <string>
#include <optional>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>


std::optional<std::pair<char, unsigned int>> longestRepetition(const std::string &str) {
  if(str.empty()) return std::nullopt;
 // std::pair<char, unsigned int> p = {str[0],1};
  char startLetter =str[0];
 std::vector<std::pair<char, unsigned int>>resultArr;
  unsigned int maxCount = 0;
  

  for (auto i:str) {
    if (i == startLetter) {
      maxCount += 1;
    } else {
      resultArr.push_back({startLetter, maxCount});
      startLetter = i;
      maxCount = 1;
    }
  }

  resultArr.push_back({startLetter, maxCount});
  unsigned int maxValue=0;
  for(auto& i:resultArr){
    maxValue = std::max(i.second,maxValue);
  }

  auto it=find_if(resultArr.begin(),resultArr.end(),[&maxValue](auto& a)
                  {return a.second==maxValue;});
  return std::make_pair((*it).first,(*it).second);

}

  /*std::vector<std::pair<int,std::pair<char, unsigned int>>> vp;
  int j=0;
  char f = str[0];
  unsigned int s = 1;
  for(size_t i=1;i<str.size();++i){
    if(str[i-1]==str[i]){
      ++s;
    }
    if(str[i-1]!=str[i]){
      vp.push_back({j,{f,s}});
      ++j;
      f = str[i];
      s=1;
    }
    if(i==str.size()-1){
      vp.push_back({j,{f,s}});
    }
  }
//undefined behavior
  unsigned int fl = vp.front().second.second;
  std::sort(vp.begin(),vp.end(),[](auto& p1,auto& p2)
            { return p1.second.second<p2.second.second;});
  if(std::all_of(vp.begin(),vp.end(),[&fl](auto& p){return p.second.second == fl;})){ 
    auto it=find_if(vp.begin(),vp.end(),[](auto&p){ return p.first == 0;});
      return std::make_pair((*it).first,(*it).second);
}                                      

  return vp.back().second;
  
}*/

////////////////////////////////
