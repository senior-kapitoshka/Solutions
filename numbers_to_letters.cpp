#include <string>
#include <vector>
#include <map>
#include <algorithm>

void helper(std::map<int,char>&mp){
  char i='z';
    for(int j=1;j<=26;++j){
      mp[j]=i;
      --i;
    }
  mp[27]='!';
  mp[28]='?';
  mp[29]=' ';
}

std::string switcher(const std::vector<std::string>& arr) {
  std::map<int,char>mp;
  helper(mp);
  std::string res;
  std::transform(arr.begin(),arr.end(),std::back_inserter(res),
                [&mp](auto& i){
                  return mp[std::stoi(i)];
                });
  return res;
}

///////////////////
#include <string>
#include <vector>

std::string switcher(const std::vector<std::string>& arr) {
  std::string s = " zyxwvutsrqponmlkjihgfedcba!? ";
  std::string r;
  for (const std::string& n: arr) r += s[stoi(n)];
  return r;
}

//////////
