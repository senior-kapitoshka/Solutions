#include <execution>
std::vector<int> solve(std::string s){
    std::vector<int>vc(4);
  for_each(std::execution::unseq,s.begin(),s.end(),[&vc](auto &c){
    if(isdigit(c)){
      ++vc[2];
    }else if(isalpha(c)){
      if(isupper(c)){
        ++vc[0];
      }else{
        ++vc[1];
      }
    }else{
      ++vc[3];
    }
  });
  return vc;
}

/////////////////////////////////////
std::vector<int> solve(std::string s){
    std::vector <int> v = {0,0,0,0};
    for(char& ch : s) {
        if (isupper(ch)) v[0]++;
        else if (islower(ch)) v[1]++;
        else if (isdigit(ch)) v[2]++;
        else v[3]++;
    }
    return v;
}
//////////////////////
std::vector<int> solve(std::string s){
    return std::vector<int>({ (int)std::count_if(s.begin(), s.end(), isupper), (int)std::count_if(s.begin(), s.end(), islower),
        (int)std::count_if(s.begin(), s.end(), isdigit), (int)std::count_if(s.begin(), s.end(), [&](char c) {return !islower(c) && !isupper(c) && !isdigit(c); }) });
}
//////////////////////////////
#include <regex>
#include <vector>
using namespace std;

vector<int> solve(string s){
  int up = regex_replace(s, regex("[^A-Z]"), "").size();
  int low = regex_replace(s, regex("[^a-z]"), "").size();
  int no = regex_replace(s, regex("[^0-9]"), "").size();
  return vector<int>{up, low, no, (int)(s.size()) - up - low - no};
}
/////////////////////////
