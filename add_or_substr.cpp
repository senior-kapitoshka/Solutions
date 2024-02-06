#include <vector>
#include <iostream>
std::string calculate(std::string s)
{
  std::vector<std::string>vs;
  for(size_t i=0;i<s.size();){
    std::string t;
    if(isdigit(s[i])){
      while(isdigit(s[i])){
        t+=s[i];
        ++i;
      }
    }else if(isalpha(s[i])){
      if(s[i]=='p'){
        vs.push_back("+");
        i+=4;
      }else if(s[i]=='m'){
        vs.push_back("-");
        i+=5;
      }
    }
    if(!t.empty())vs.push_back(t);
    t.clear();
    
  }
  int r=std::stoi(vs.front());
  for(size_t i=1;i<vs.size()-1;i++){
    if(vs[i]=="+"){
      r+=std::stoi(vs[i+1]);
    }else if(vs[i]=="-"){
      r-=std::stoi(vs[i+1]);
    }
  }
  return std::to_string(r);
}

///////////////////
std::string calculate( std::string s ) {
  int n{ stoi( s )};
  for ( size_t i{ s.find_first_of( "pm" )}, j; i != s.npos; i = s.find_first_of( "pm", j ))
    n += ( s[ i ] == 'p' ? 1 : -1 ) * stoi( s.substr( j = s.find_first_of( "0123456789", i )));
  return std::to_string( n );
}
///////////////////
#include <string>
#include <sstream>
#include <numeric>
#include <iterator>

std::string calculate(std::string str)
{
  auto pos{0};
  while ( (pos = str.find("minus")) != std::string::npos) str.replace(pos, 5, " -");
  while ( (pos = str.find("plus"))  != std::string::npos) str.replace(pos, 4, " ");
  std::istringstream ss{str};
  return std::to_string(std::accumulate(std::istream_iterator<int>(ss), std::istream_iterator<int>(), 0));
}
///////////////
#include <regex>
#include <numeric>
std::regex r{".*?([a-z]+)(\\d+)"};

std::string calculate(std::string str) {
  return std::to_string(std::accumulate(std::regex_iterator{str.begin(), str.end(), r}, {}, stoll(str), [](auto sum, auto m) {
    return sum + stoll((m[1] == "plus" ? "" : "-") + m.str(2));
  }));
}
//////////////////
