#include <string>
#include <vector>
#include <numeric>

int arrow_search(const std::string& s) {
  std::vector<int> vc;
  for(size_t i=0;i<s.size();){
    if(s[i]=='.') ++i;
    if(s[i]=='-'){
      char c='-';
      int n=0;
      while(s[i]==c){
        ++n;
        ++i;
        if(s[i]=='=' || s[i]=='.' || s[i]=='<'){
          n=0;
          break;
        }else if(s[i]=='>'){
          vc.push_back(n+1);
          ++i;
          break;
        }
      }
    }
    if(s[i]=='='){
      char c='=';
      int n=0;
      while(s[i]==c){
        n+=2;
        ++i;
        if(s[i]=='-' ||  s[i]=='.' || s[i]=='<'){
          n=0;
          break;
        }else if(s[i]=='>'){
          ++i;
          vc.push_back(n+2);
          break;
        }
      }
    }
    if(s[i]=='>'){
      ++i;
      vc.push_back(1);
    }
    if(s[i]=='<'){
      int n=-1;
      ++i;
      if(s[i]=='>'){
        vc.push_back(0);
        ++i;
      }
      else if(s[i]=='='||s[i]=='-'){
        if(s[i]=='='){
          char c='=';
          while(s[i]==c){
            n-=2;
            ++i;
            if(s[i]=='-' || s[i]=='.' || s[i]=='<'|| i==s.size()){
              vc.push_back(n-1);
              n=0;
              break;
            }else if(s[i]=='>'){
              ++i;
              n=0;
              vc.push_back(0);
              break;
            }
          }
        }else if(s[i]=='-'){
          char c='-';
          while(s[i]==c){
            --n;
            ++i;
          if(s[i]=='=' || s[i]=='.' || s[i]=='<' || i==s.size()){
            vc.push_back(n);
            n=0;
            break;
          }
          if(s[i]=='>'){ 
            ++i;
            n=0;
            vc.push_back(0);
            //
            break;
          }
        }
         }
      }
      else{
        vc.push_back(n);
      }
    }
  }
  return std::accumulate(vc.begin(),vc.end(),0);
}

////////////////////////////////

#include <functional>
#include <numeric>
#include <regex>
#include <string>

int arrow_search(const std::string& s) {
  static const std::regex re("(<?)([-=])?\\2*(>?)");
  return std::transform_reduce(
    std::sregex_iterator(s.begin(), s.end(), re),
    std::sregex_iterator(),
    0,
    std::plus<>(),
    [](auto&& m) { return ((m[3] == '>') - (m[1] == '<')) * m.length() << (m[2] == '='); }
  );
}
/////////////////////////
#include <string>

int arrow_search(const std::string& s) {
  int count = 0, i = 0, j = 0, k = 0, n = 0;
  char tail = '#';
  
  for (i = 0; i < s.size(); ++i){
    
    if (s[i] == '>'){ // count forward-facing arrows --> / ==>  
      k = 1; j = i - 1; n = 1;
      
      if (j >= 0 && (s[j] == '=') || (s[j] == '-')) tail = s[j];
      else tail = '#';
      
      while ((j >= 0) && (s[j] == tail)) {++n; --j;}
      
      if (tail == '=') k = 2;
      count += k*n;
    }
    
    if (s[i] == '<'){ // count backward-facing arrows <-- / <== 
      k = -1; j = i + 1; n = 1;
      
      if (j < s.size() && (s[j] == '=') || (s[j] == '-')) tail = s[j];
      else tail = '#';
      
      while ((j < s.size()) && (s[j] == tail)) {++n; ++j;}
      
      if (tail == '=') k = -2;
      count += k*n;     
    }
  }
  return count;
}
//////////////////////////////////////////
#include <string>

namespace
{
  std::string mirror(const std::string& s) {
    std::string res;
    res.reserve(s.size());
    for (int i = static_cast<int>(s.size())-1; i >= 0; --i) {
      auto c = s[i];
      switch (c) {
        case '>': c = '<'; break;
        case '<': c = '>'; break;
      }
      res.push_back(c);
    }
    return res;
  }

  int score(const std::string& s) {
    char tailChar = 0;
    int tailLen = 0;
    int value = 0;
    
    for (auto c : s) {
      switch(c) {
        case '-':
        case '=':
          tailLen = 1 + (tailChar == c ? tailLen : 0);
          tailChar = c;
          break;
        case '>':
          value += (1 + tailLen) << (tailChar == '=');
        default:
          tailChar = 0;
          tailLen = 0;
      }
    }
    return value;
  }
}



int arrow_search(const std::string& s) {
  return score(s) - score(mirror(s));
}
////////////////////////
