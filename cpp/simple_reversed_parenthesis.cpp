#include <regex>

int solve(std::string s){
  while(true){
    if(s.find("()")==s.npos) break;
     std::regex r("(\\(\\))");
    s=std::regex_replace(s,r,"");
  }
  int cnt=0;
  if(s.size()%2!=0) return -1;
  for(size_t i=0;i<s.size();i+=2){
    if((s[i]==')' && s[i+1]==')')||(s[i]=='(' && s[i+1]=='(')){
      ++cnt;
    }else if(s[i]==')' && s[i+1]=='('){
      cnt+=2;
    }
  }
  return cnt;
}

////////////////
#include <bits/stdc++.h>
using namespace std;
int solve(std::string s){
  if(s.size()%2==1) return -1;  
  while(regex_search(s,regex("\\(\\)"))){
    s=regex_replace(s,regex("\\(\\)"),"");
  } 
  int x{0};
  for(auto e:s){
    if(e ==')') x++;
  }
  return (x%2==0) ? s.size()/2 : s.size()/2+1; 
}
///////////////
int solve(std::string s){
    if (s.length() % 2 != 0) return -1;
    int c = 0, k = 0;
    for(char& ch : s) {
        if (ch == '(')
            k++;
        else if (k > 0)
            k--;
        else
            k++, c++;
    }
    return c + k / 2;
}