#include <map>
void parse(int n,std::vector<int>&v){
  v.push_back(n%10);
  int tmp=n/10;
  if(tmp==0) return;
  parse(tmp,v);
}

bool is_dd(int n){
  std::vector<int>v;
  parse(n,v);
  std::map<int,int>mp;
  for(auto& i:v){ 
    ++mp[i];
  }
  for(auto&p:mp){
    if(p.first==p.second) return true;
  }
  return false;

}
////////////////////////////////

bool is_dd(int n){
  std::string num = std::to_string(n);
	bool result = false;
	for_each(num.begin(), num.end(), [&](char c){if(count(num.begin(), num.end(), c) == c - '0') result = true;});
	return result;
}
////////////////////////////////
#include <string>
#include <set>

bool is_dd(int n){
  std::string s = std::to_string(n);
  std::set<char> sets;
  for(char c: s)
    sets.insert(c);
  for(char c: sets){
    if(c - '0' == std::count(s.begin(), s.end(), c))
      return true;
  }
  return false;
}
//////////////////////////////
