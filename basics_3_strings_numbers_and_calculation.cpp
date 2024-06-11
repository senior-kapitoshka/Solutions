#include <cmath>
std::string calculateString(std::string ct) 
{
  std::cout<<ct<<'\n';
    std::string a,b;
  size_t j=0;
  char x;
  for(size_t i=0;i<ct.size();++i){
    if(isdigit(ct[i])|| ct[i]=='.'){
      a+=ct[i];
    }else if(ct[i]=='+'||ct[i]=='/'||ct[i]=='*'||ct[i]=='-'){
      x=ct[i];
      j=i;
      break;
    }
  }
  for(size_t i=j;i<ct.size();++i){
    if(isdigit(ct[i])|| ct[i]=='.'){
      b+=ct[i];
    }
  }
  std::string res;
  if(x=='-'){
    res=std::to_string((int)std::round(std::stod(a)-std::stod(b)));
  }else if(x=='+'){
    res=std::to_string((int)std::round(std::stod(a)+std::stod(b)));
  }else if(x=='*'){
    res=std::to_string((int)std::round(std::stod(a)*std::stod(b)));
  }else if(x=='/'){
    res=std::to_string((int)std::round(std::stod(a)/std::stod(b)));
  }
    
    return res;
}   

////////////
#include <regex>
#include <cmath>
#include <string>
std::string calculateString(std::string calcIt) 
{
    std::regex e("[^-|.|0-9|+|*|/]");     
    calcIt = std::regex_replace (calcIt,e,"");
    double a,b;
    char op;
    for(int i = 0; i < calcIt.length(); i++){
    if(calcIt[i]=='+'||calcIt[i]=='-'||calcIt[i]=='/'||calcIt[i]=='*'){
    op = calcIt[i];
    a = std::stod(calcIt.substr(0,i));
    b = std::stod(calcIt.substr(i+1));
    break;
    }
    }
    double ans;
    if(op == '+') ans = a+b;
    if(op == '*') ans = a*b;
    if(op == '-') ans = a-b;
    if(op == '/') ans = a/b;
    return std::to_string((long)round(ans));
}
/////////////
