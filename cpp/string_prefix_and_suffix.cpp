//random decision, does not pass all tests

#include <iostream>
#include <string>
#include <set>

bool is_palindrom(std::string s){
  std::string t(s.rbegin(),s.rend());
  return s==t;
}


int solve(std::string s){ 
	size_t ans=0;
  if(s.size()==1||s.empty()) return ans;
  if(is_palindrom(s)) return (int)s.size()/2;
  int i=0;
  int j=(int)s.size()/2;
  std::set<int>st;
  while(j!=(int)s.size()){
    if(s[i]==s[j] && !st.count(i) ){
      st.insert(i);
      st.insert(j);
      ++i;
      ++j;
      
    }else if(s[i]!=s[j]){
      i=0;
      ++j;
      st.clear();
    }
    else if(s[i]==s[j] && st.count(i) ){
      i=1;
      ++j;
      st.clear();
    }
  }
  return i;
}

/////////////////////
int solve(std::string s){
	int c = 0; 
    int l = s.length();
    for (int i = 0; i <= l/2; i++) {
      c =  s.substr(0, i) == s.substr(l-i) ? i : c;
    }
    return c;
}

//////////////
int solve(std::string s)
{
    int max {0};
    for (size_t i {}; i < s.size()/2; ++i)
        if (std::equal(s.begin(), s.begin() + i + 1, s.end() - i - 1)) max = i+1; 
    return max;
}

////////////
#include <string>
#include <vector>
using namespace std;
int solve(std::string s){
for(int i=s.size()/2;i>0;--i)
  {
  string prefix=s.substr(0,i);
  string surfix=s.substr(s.size()-i);
  if(prefix==surfix)
    return i;
}
  return 0;
}

//////////
#include <regex>

int solve(const std::string& s){
	  static std::regex prefix{ R"(^(.*).*\1$)" };
    std::smatch match;
    if(!std::regex_match(s, match, prefix)) return 0;
    return match[1].str().size();
}
