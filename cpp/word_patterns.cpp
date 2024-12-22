#include <map>
std::string wordPattern(const std::string &w) {
  std::string ans;
  std::map<char,int>mp;
  int c=0;
  for(size_t i=0;i<w.size();++i){
    if(mp.count(tolower(w[i]))==0){
      mp[tolower(w[i])]=c;
      
      ans+=std::to_string(c);
      ++c;
      if(i!=w.size()-1) ans+='.';
    }else if(mp.count(tolower(w[i]))!=0){
      ans+=std::to_string(mp[tolower(w[i])]);
      if(i!=w.size()-1) ans+='.';
    }
  }
  return ans;
}

///////////////////////////////////
#include <algorithm>
#include <map>
#include <string>
std::string wordPattern(const std::string &word) {
  std::string word_copy = word;
  std::transform(word_copy.begin(), word_copy.end(), word_copy.begin(),
                [](char c){return std::tolower(c);});
  
  std::map<char, int> char_idx;
  
  int index = 0;
  std::string answer = "";
  
  for(const auto& c : word_copy)
  {
    if(char_idx.find(c) == char_idx.end())
    {
      char_idx[c] = index;
      index++;
    }
    answer += (std::to_string(char_idx[c]) + ".");
  }
  
  return answer.substr(0, answer.size()-1);
}
////////////////////////////////////////

std::string wordPattern(const std::string &word) {
  std::string word2;
  std::string result;
  if (word == "")
  return "";
  for(auto i : word)
    if(word2.find(tolower(i)) > word2.length())
      word2 += tolower(i);
  for(auto i : word)
          result += std::to_string(word2.find(tolower(i))) + '.';
      result.pop_back();
    return result;
}
////////////////////////////////////////
