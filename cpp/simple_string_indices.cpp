#include <string>
#include <map>

int solve(std::string str, int index){
  std::vector<size_t>vs;
  std::map<size_t,size_t>mp;
  for(size_t i=0;i<str.size();++i){
    if(str[i]=='(' || str[i]==')'){
      if(str[i]=='('){
        vs.push_back(i);
    }else{
        mp[vs.back()]=i;
        vs.pop_back();
      }
  }
  }
    return mp.count(index)?mp[index]:-1;
}

//////////////////////
include <string>

int solve(std::string str, int index){
  if (str[index] != '(') return -1;
  int c = 0;
  for (size_t i = index; i < str.size(); ++i) {
    if (str[i] == '(') ++c;
    if (str[i] == ')') --c;
    if (c == 0) return i;
  }
  return -1;
}

//////////////////
#include <string>

int solve(std::string str, int index)
{
  if (str[index] != '(')
    return -1;
  int count = 1;
  while (count)
    count += (str[++index]=='(')-(str[index]==')');
  return index;
}