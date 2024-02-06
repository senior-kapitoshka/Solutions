#include <algorithm>
#include <sstream>
#include <vector>
#include <string_view>
#include <iostream>


#if 1


std::string reverse_words(std::string str)
{
  if(str.empty()) return "";
  std::string res;
  if(str.front()==' '){
    auto p=str.find_first_not_of(" ");
    res+=str.substr(0,p);
    str.erase(0,p);
  }
  while(!str.empty()){
    auto p=str.find_first_of(" ");
    std::string t;
    if(p!=str.npos){
      t=str.substr(0,p);
      str.erase(0,p);
    }
    else {
      t=str;
      str.clear();
    }
    std::reverse(t.begin(),t.end());
    res+=t;
    if(!str.empty()){
      auto w=str.find_first_not_of(" ");
      res+=str.substr(0,w);
      str.erase(0,w);
    }
  }
  return res; 

}
#endif
/////////////////////////////////
std::string reverse_words(std::string str)
{
  std::string out;
  std::string cword;
  for (char c : str) {
    if (c == ' ') {
      out += cword;
      out += c;
      cword = "";
      continue;
    }
    cword = c + cword;
  }
  out += cword;
  return out;
}
////////////////////////////
#include <algorithm>
#include <string>

std::string reverse_words(std::string str) {
  auto i = str.begin();
  auto j = str.end();
  while (i < j) {
    auto k = std::find(i, j, ' ');
    std::reverse(i, k);
    i = k+1;
  }
  return str;
}
//////////////////
std::string reverse_words(std::string str)
{ 
  for (auto begin = str.begin(), end = begin; end != str.end(); begin = end + 1) {
    end = find(begin, str.end(), ' ');
    std::reverse(begin, end);
  } 
  return str;
}