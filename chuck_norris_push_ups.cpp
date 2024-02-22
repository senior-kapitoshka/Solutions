#include <algorithm>
#include <regex>
#include <string>
#include <iostream>
#include <cmath>
#include <vector>

int bin_to_decl(const std::string & a){
   std::regex al("[2,3,4,5,6,7,8,9]|[\\a-z \\A-Z ]+");
  std::string s=std::regex_replace(a,al,"");
  int res=0;
  int i=(int)s.size()-1;
  std::for_each(s.begin(),s.end(),[&res,&i](auto& c){
    res+=(c-'0')*std::pow(2,i);
    --i;
  });
  return res;
}

int chuckPushUps(const std::string & in) 
{
  if(!std::any_of(in.begin(),in.end(),[](auto &c){
    return isdigit(c);
  }) || in.empty()) return -1;
  std::regex dig("[01]+([^\\s01]*[01])*");
  auto db=std::sregex_iterator(in.begin(),in.end(),dig);
  auto de=std::sregex_iterator();
  int res = 0;
  for(auto i=db;i!=de;++i){
    std::smatch m=*i;
    res=std::max(res,bin_to_decl(m.str()));
  }
  return res;
}

////////////////////////////////////////////////

#include <string>
#include <regex>
#include <cmath>

using namespace std;
int chuckPushUps(const std::string & input) 
{
  regex r ("[^0-1 ]");
  string binary = std::regex_replace(input,r,"");
  r=regex("([\\s]+)(\\S|$)");
  binary = std::regex_replace(binary,r," $2");
  string bin1,bin2;
  cout<<"binary="<<binary<<endl;
  regex t("[01]+");
  smatch w;
  if (binary=="")return -1;
  int result=-1;
  int current = -1;
  int power=0;
  
  while(binary != ""){
    regex_search(binary, w, t);
    bin1=w.str();
    current=0;
    power=0;
    for(auto it = bin1.crbegin(); it != bin1.crend(); ++it){
      current += (*it-48)*pow(2,power++);
      result = current>result?current:result;
    }
    binary = w.suffix();
  }
  return result;
}

///////////////////////////////////////
#include <regex>
#include <string>

int chuckPushUps(const std::string & input) 
{
  int res = -1;
  std::string b = std::regex_replace(input, std::regex(R"([^ 0-1])"), "");
  b = std::regex_replace(b, std::regex("^ +| +$|( ) +"), "$1");
  
  std::stringstream streamData(b);
  std::string tmp;

  while (std::getline(streamData, tmp, ' ')) {
    int cur = std::stoi(tmp,nullptr,2);
    if (cur > res) res = cur;
  }
  return res; 
}