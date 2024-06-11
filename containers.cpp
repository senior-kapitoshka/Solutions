#include <vector>
#include <algorithm>
#include <cmath>

int Containers(std::string in){
  std::vector<std::vector<char>>vs;
  int m=0;
  std::for_each(in.begin(),in.end(),[&vs,&m,i=1](auto& curr)mutable{
      auto itv=std::find_if(vs.begin(),vs.end(),[k=curr](auto& v){
        return v.back()==k;
      });
      if(itv==vs.end()){
        auto itv2=std::find_if(vs.begin(),vs.end(),[k=curr](auto& v){
          return v.back()>k;
        });
        if(itv2==vs.end()){
          std::vector<char>t;
          t.push_back(curr);
          vs.push_back(t);
        }else{
          (*itv2).push_back(curr);
        }
      }else{
        (*itv).push_back(curr);
      }
    m=std::max(m,(int)vs.size());
    ++i;
  });
  return m;
}
//////////
#include <vector>
#include <set>
#include <algorithm>

int Containers(std::string input)
{
  std::multiset<char> stacks;
  for (char c : input)
  {
    if (!stacks.empty() && c <= *stacks.rbegin())
      stacks.erase(stacks.lower_bound(c)); // If we can place the container on an existing stack, we choose one for which the top element has the closest label
    stacks.insert(c);
  }
  return stacks.size();
}

///////////////

#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <iterator>

int Containers(const std::string &input){
    std::set<char> tops;
    std::unordered_set<char> ships;
    for(auto c : input)
    {
        ships.insert(c);
        auto iter = tops.lower_bound(c);
        if(iter != std::end(tops))
        {
            tops.erase(iter);
        }
        tops.insert(c);
    }
    return std::min(tops.size(), ships.size());
}
/////////////////
#include <vector>
#include <algorithm>

int Containers(const std::string &input){
    std::string stack;
    auto canload=[&](char c) {
      for (auto &s:stack) {
        if (c > s) continue;
        s=c;
        return true;
      }      
      return false;
    };
    for (char c : input) {
      if (!canload(c)) 
        stack.append(1,c);
    }
    return stack.size();
  }

///////////
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
int Containers(std::string input){
  int stacks=0;
  bitset<1001> U;
  for ( int i = 0; i<input.length(); i++) {
    if(U[i]) continue;
    auto ch=input[i];
    int tot = 0;
    for(int j=i;j<input.length();j++) {
      if(U[j]) continue;
      if(input[j] <= ch) {
        U[j]=1;
        tot++;
        ch = input[j];
      }
    }
    if(tot) stacks++;
  }
  return stacks;
}