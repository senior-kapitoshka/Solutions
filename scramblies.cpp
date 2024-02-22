#include<string>
#include <unordered_map>
#include <algorithm>

bool scramble(const std::string& s1, const std::string& s2){
  std::unordered_map<char,unsigned long long>mp1;
  std::unordered_map<char,unsigned long long>mp2;
  for(auto i:s1) ++mp1[i];
  for(auto i:s2) ++mp2[i];
  for(auto p:mp2){
    if(mp1.count(p.first)==0) return false;
    else{
      if(mp1[p.first]<mp2[p.first]) return false;
    }
  }
  return true;
}
///////////////////////////////////
#include <algorithm>
#include <string>

bool scramble(std::string s1, std::string s2) {
  std::sort(begin(s1), end(s1));
  std::sort(begin(s2), end(s2));
  return std::includes(begin(s1), end(s1), begin(s2), end(s2));
}
///////////////////////////
#include <unordered_map>
#include <algorithm>

bool scramble(const std::string &s1, const std::string &s2){
    std::unordered_map<char, unsigned> m1, m2;
    
    for(auto c : s1) ++m1[c];
    for(auto c : s2) ++m2[c];
    
    return std::all_of(m2.begin(), m2.end(), [&](const std::pair<char, unsigned> &p) {
        return m1[p.first] >= p.second;
    });
}
///////////////////////
#include<string>
bool scramble(const std::string& a, const std::string& b){
       int m[26] = {0};
       for(char c : a) m[c-'a']++;
       for(char c : b) if (m[c-'a']<=0) return false; else m[c-'a']--;
       return true;
}