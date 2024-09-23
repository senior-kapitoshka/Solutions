#include <string>
#include <algorithm>
#include <unordered_map>

std::string work_on_strings(const std::string &a, const std::string &b) {
  std::unordered_map<char,int>mp1,mp2;
  for(auto i:a){
    ++mp1[tolower(i)];
  }
  for(auto i:b){
    ++mp2[tolower(i)];
  }
  std::string res;
  res.reserve(a.size()+b.size());
  std::transform(a.begin(),a.end(),std::back_inserter(res),
                [&mp2](auto& c){
                  return (mp2[tolower(c)]%2!=0 && islower(c))?toupper(c)
                    :(mp2[tolower(c)]%2!=0 && isupper(c))?tolower(c):c;
                });
  std::transform(b.begin(),b.end(),std::back_inserter(res),
                [&mp1](auto& c){
                  return (mp1[tolower(c)]%2!=0 && islower(c))?toupper(c)
                    :(mp1[tolower(c)]%2!=0 && isupper(c))?tolower(c):c;
                });
  return res;
}

////////////////////////
#include <map>
#include <set>
#include <string>

std::set<char> build_table(const std::string &s) {
  std::map<char, int> d;
  std::set<char> r;
  for (auto &x : s) d[x | 32]++;
  for (auto &p : d) if (p.second % 2) r.insert(p.first);
  return r;
}

std::string work_on_strings(std::string a, std::string b) {
  auto da = build_table(a);
  auto db = build_table(b);
  for (auto &x : a) if (db.count(x | 32)) x ^= 32;
  for (auto &x : b) if (da.count(x | 32)) x ^= 32;
  return a + b;
}

//////////////////////
#include <string>
std::string work_on_strings(const std::string& a, const std::string& b) {
    std::string rA = a, rB = b;
    auto changeString = [&](std::string str1, std::string &str2) {
        for (auto i : str1) for (auto& j : str2) if (toupper(i) == toupper(j)) j = (isupper(j) ? tolower(j) : toupper(j));
    };
    return changeString(rA, rB), changeString(rB, rA), rA + rB;
}

////////////////////////