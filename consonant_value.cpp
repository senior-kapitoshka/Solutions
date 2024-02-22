#include <string>
#include <vector>
#include <algorithm>

int solve(const std::string &s)
{
  std::vector<int>vc;
  int t=0;
  if(s[0]!='a'&&s[0]!='e'&&s[0]!='i'&&
         s[0]!='o'&&s[0]!='u'){
             t+= s[0] - 'a' + 1;
             vc.push_back(t);
    }else{
        vc.push_back(t);
    }
        
    for(size_t i=1;i<s.size();++i){
   
      if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&
         s[i]!='o'&&s[i]!='u'){
          vc.back()+=s[i] - 'a' + 1;
      }else{
        t=0;
        vc.push_back(t);
      }
      
    }
  return *std::max_element(vc.begin(),vc.end());
}


/////////////////////////////////////////////////////////


#include <string>

int solve(const std::string &s) {
  int max = 0, test = 0;
  for (auto c: s) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      max = std::max(max, test);
      test = 0;
    }
    else test += c - 'a' + 1;
  }
  return std::max(max, test);
}

////////////////////////////////////////////////////////////

#include <string>

int solve(const std::string &s) {
  std::string v = "aeiou";
  int m = 0, t = 0;
  for (const char& c: s) 
    if (v.find(c) == std::string::npos)
      t += c - 'a' + 1;
    else {
      m = std::max(m,t);
      t = 0;
    }
  m = std::max(m,t);
  return m;
}