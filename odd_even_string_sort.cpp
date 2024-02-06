
using namespace std;

string sortMyString(const string &s)
{
  list<char>vc={' '};
  auto it=vc.begin();
  for(size_t i=0;i<s.size();++i){
    if(i%2==0){
      vc.insert(it,s[i]);
    }
    else if(i%2!=0){
      vc.push_back(s[i]);
    }
    
  }
  string ans(vc.begin(),vc.end());
  return ans;
}
////////////////////////////////////stable_partition!!!!!!!!!!!!!!!!!

#include <algorithm>
#include <string>

std::string sortMyString(std::string s) {
  auto is_odd = [](auto value) { return value & 1; };
  auto is_even = [&](auto value) { return !is_odd(value); };
  
  auto mid = std::stable_partition(s.begin(), s.end(), 
             [&](auto& ch) { return is_even(&ch - &s[0]); });
  s.insert(mid, ' ');
  return s;
}

///////////////////////////////
using namespace std;

string sortMyString(const string &s)
{
  string first, second;
  for (auto j = 0; j < s.size(); j ++) {
    if (j % 2) second.push_back(s[j]);
    else first.push_back(s[j]);
  }  
  return first + " " + second;
}

////////////////////////////
#include <string>

std::string sortMyString(const std::string &s) {
  std::string result = "";
  for (int i = 0; i < s.length(); i += 2)
    result += s[i];
  result += ' ';
  for (int i = 1; i < s.length(); i += 2)
    result += s[i];
  return result;
}
//////////////////////////
std::string sortMyString(const std::string &s) {
  std::string result = " ";
  result.reserve(s.size());
  
  int even_pos = 0;
  for(int i = 0; i < s.size(); i++) {
    bool is_even = i % 2 == 0;
    std::size_t index = is_even ?  even_pos : result.size();
    std::string::const_iterator itr = result.begin() + index;
    result.insert(itr, s[i]);
    
    if (is_even) even_pos++;
  }
  return result;
}
/////////////////////////
using namespace std;

string sortMyString(const string &s)
{
  string odd,even;
  for(int i=0; i<s.size(); i++){
    if(i%2==0) even.push_back(s[i]);
    else odd.push_back(s[i]);
  }
  return even + " " + odd;
}
///////////////////////
