#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
using namespace std::literals;

std::unordered_map<std::string,int> mt={
  {"Jan"s,1},{"Feb"s,2},{"Mar"s,3},{"Apr"s,4},{"May"s,5},
  {"Jun"s,6},{"Jul"s,7},{"Aug"s,8},{"Sep"s,9} ,{"Oct"s,10},
{"Nov"s,11},{"Dec"s,12} 
};

string driver(const array<string, 5> &d)
{
  std::string s="9AA"s;
  if(d[2].size()>=5){
    s.insert(0,d[2].substr(0,5));
  }else{  
    s.insert(0,d[2] + std::string(5-d[2].size(),'9'));
  }
  s.insert(5,1,*(d[3].end()-2));
  d[4]=="M"s?(mt[d[3].substr(d[3].find_first_of('-')+1,3)]>=10?
    s.insert(6,std::to_string(mt[d[3].substr(d[3].find_first_of('-')+1,3)])):
    s.insert(6,"0"+std::to_string(mt[d[3].substr(d[3].find_first_of('-')+1,3)]))):
  (mt[d[3].substr(d[3].find_first_of('-')+1,3)]>=10?
    s.insert(6,std::to_string(mt[d[3].substr(d[3].find_first_of('-')+1,3)]+50)):
    s.insert(6,"5"+std::to_string(mt[d[3].substr(d[3].find_first_of('-')+1,3)])));
  s.insert(8,d[3].substr(0,2));
  s.insert(10,1,d[3].back());
  s.insert(11,1,d[0].front());
  d[1].empty()?s.insert(12,"9"s):s.insert(12,1,d[1].front());
  std::transform(s.begin(),s.end(),s.begin(),[](auto& c){
    return isalpha(c)?toupper(c):c;
  });
    return s; 
}