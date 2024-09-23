#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Arith{
public:
  Arith(std::string s):s_(s){
    x=mp[s];
  }
  std::string add(std::string str){
    return std::find_if(mp.begin(),mp.end(),[f=(mp[str]+x)](auto& p){
      return p.second==f;
    })->first;
  }
private:
  std::string s_;
  char x;
  std::map<std::string,char>mp={
    {"one",1},{"two",2},{"three",3},{"four",4},{"five",5}, {"six",6},{"seven",7},{"eight",8}, {"nine",9}, {"ten",10},
  {"eleven",11},	{"twelve",12},
{"thirteen",13},	{"fourteen",14},
{"fifteen",15},	{"sixteen",16},
{"seventeen",17},	{"eighteen",18},
{"nineteen",19},	{"twenty",20}};
  
};