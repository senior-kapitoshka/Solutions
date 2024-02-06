
/////

#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <iostream>


std::string slice(const std::string &s){
  std::stack<std::pair<char,size_t>>st;
  std::vector<std::pair<size_t,size_t>>vc;
  std::string res;
  for(size_t i=0;i<s.size();++i){
    if(s[i]=='('){
        st.push({'(',i});
    }
    if(s[i]==')'){
        if(st.size()==1){
            vc.push_back({st.top().second,i});
            st.pop();
        }else if(st.size()>1){
            st.pop();
        }else if(st.empty()) continue;
    }
  }
  res=s.substr(0,vc.front().first);
    for(size_t i=1;i<vc.size();++i){
        for(size_t j=vc[i-1].second+1;j<vc[i].first;++j){
            res+=s[j];
        }
    }
  res+=s.substr(vc.back().second+1);
  return res;
}

std::string remove_parentheses(const std::string &str)
{
  if(str.empty()) return "";
  if(std::find(str.begin(),str.end(),')')==str.end() && std::find(str.begin(),str.end(),'(')==str.end()) return str;
  std::string res=slice(str);
  return res;
}
///////////////////////////////////////////////////////////////////////
std::string remove_parentheses(const std::string &str)
{
  std::string res;
  std::cout<<str<<"\n";
  int i=0;
  int cnt=0;
  while(str[i]!='\0'){
    if(str[i]=='('){
      ++cnt;
    }else if(str[i]==')'){
      --cnt;
    }else if(cnt==0){
      res+=str[i];
    }
    ++i;
  }
  return res;
}
/////////////////////////////////////////////////////////

#include <string>
#include <regex>

std::string remove_parentheses(const std::string &str)
{
    std::string result = str;
    std::regex regex("\\(([^\\(\\)]*)\\)");
    
    while (std::regex_search(result, regex))
        result = std::regex_replace(result, regex, "");  

    return result;
}