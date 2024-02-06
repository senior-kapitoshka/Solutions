#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <numeric>
#include <iostream>

using UMP = std::unordered_map<size_t,std::pair<char,std::string>>;

void pars(UMP& mp,const std::string& eq){
  char f='+';
  for(size_t i=0;i<eq.size();++i){
    if(eq[i]=='-') {f=eq[i];++i;}
    if(eq[i]=='+') {f=eq[i];++i;}
    if(eq[i]=='x' || eq[i]=='='){
      if(eq[i-2]=='-') {f='-';}
      else f='+';
      std::string t;
      t+=eq[i];
      mp[i]={f,t};
      ++i;
    }
    if(isdigit(eq[i])){
      if(!isdigit(eq[i+1])){
        std::string t;
        t+=eq[i];
        mp[i]={f,t};
      }else{
        std::string t;
        size_t z=i;
        while(isdigit(eq[i])){
            t+=eq[i];++i;
        }
        mp[z]={f,t};
      }
    }
  }
}

std::vector<int> dig(UMP& mp){
  size_t x=0;
  size_t e=0;
  bool p=false;
  for(auto&[k,v]:mp){
    if(v.second=="x") {
        x=k;
        if(v.first=='-')p=true;
    }
    if(v.second=="=") e=k;
  }
  bool fl=false;
  if((x>e&& p==false)  || (x<e && p==true)) fl=true;
  std::vector<int> res;
  for(auto&[k,v]:mp){
    if(v.second!="x" && v.second!="="){
      if(k<e){
        if(v.first=='-'){
          
          res.push_back(std::stoi(v.second));
        }else if(v.first=='+'){
          
          res.push_back(std::stoi(v.second)*(-1));
        }
      }else if(k>e){
        if(v.first=='-'){
         
          res.push_back(std::stoi(v.second)*(-1));
        }else if(v.first=='+'){
          
          res.push_back(std::stoi(v.second));
        }
      }
    }
  }

  if(fl){
    for_each(res.begin(),res.end(),[](auto&i){
        i*=(-1);
      return i;
    });
  }
  return res;
}

int solve(const std::string& eq)
{
  
    UMP mp;
    pars(mp,eq);
    
    std::vector<int> vc=dig(mp);
    return std::accumulate(vc.begin(),vc.end(),0);
}

////////////////////////////
#include <string>
#include <regex>

int solve(const std::string& eq)
{
  int v = 0, sign = 1, lhs = 1, xsign = 1;
  std::regex re("\\S+");
  for (auto it = std::sregex_token_iterator(eq.begin(), eq.end(), re); it != std::sregex_token_iterator(); ++it) {
    if (*it == "=") sign = lhs = -1;
    else if (*it == "+") sign = lhs;
    else if (*it == "-") sign = -lhs;
    else if (*it == "x") xsign = -sign;
    else v += std::stoi(*it) * sign;
  }
  return v * xsign;
}