
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
using namespace std;

int change(int x){
  std::string s=std::to_string(x);
  std::transform(s.begin(),s.end(),s.begin(),[](auto& c){return c=='3'?'7':c=='7'?'3':c;});
  x=std::stoi(s);
  return x;
}

vector <int> sortTwisted37 (vector <int> ns) {
  std::map<int,std::pair<size_t,int>>mp;
  std::vector<int>res;
  res.reserve(ns.size());
  std::for_each(ns.begin(),ns.end(),[&mp](auto& i){
    int x=change(i);
    if(mp.count(x)){
      ++mp[x].first;
    }else{
      mp[x]={1,i};
    } 
  });
  std::for_each(mp.begin(),mp.end(),
                 [&res](auto& p){
                   if(p.second.first>1){
                     res.insert(res.end(),p.second.first,p.second.second);
                 }else{
                     res.push_back(p.second.second);
                   } 
                 });
  return res;
}

///////////////////////
#include <vector>
#include <algorithm>

int change(int num)
{
    std::string num_str{ std::to_string(num) };
    std::transform(num_str.begin(), num_str.end(), num_str.begin(),
        [](char c) {return c == '3' ? '7' : c == '7' ? '3' : c; });
    return std::stoi(num_str);
}

std::vector<int> sortTwisted37(std::vector<int> numbers) {
    std::sort(numbers.begin(), numbers.end(),
        [](int a, int b) {return change(a) < change(b); });
    return numbers;
}
///////////////////////
#include <vector>
using namespace std;

int twist(int x) {
  auto str = to_string(x);
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '3') {
      str[i] = '7';
    } else if (str[i] == '7') {
      str[i] = '3';
    }
  }
  return atoi(str.c_str());
}

vector <int> sortTwisted37 (vector <int> numbers) {
  sort(numbers.begin(), numbers.end(), [](int a, int b) {
    return twist(a) < twist(b);
  });
  return numbers;
}
//////////////
#include <vector>
#include <algorithm>
using namespace std;

int twist37 (int i) {
  int r, t = 0, d = 1, p = i < 0 ? -i : i;
  do r=p%10, p/=10, t += d*(r==3 ? 7 : r==7 ? 3 : r), d*=10; while (p);
  return i < 0 ? -t : t;
}

vector <int> sortTwisted37 (vector <int> numbers) {
  vector <int> sorted (numbers);
  sort (sorted.begin (), sorted.end (), [] (int a, int b) { return twist37 (a) < twist37 (b); }); 
  return sorted;
}
////////////////
