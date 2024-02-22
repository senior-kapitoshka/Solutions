#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>

void trans(std::string& x,std::vector<std::string>& vs){
  std::stringstream ss;
  ss.str(x);
  for(std::string w;std::getline(ss,w,' ');){
    vs.push_back(std::move(w));
  }
}

void insout(std::vector<std::string>& vs){
  std::transform(vs.begin(),vs.end(),vs.begin(),[](auto& s){
    if(s.size()%2!=0 && s.size()>3){
      std::string t=s.substr(0,(s.size()/2));
      std::reverse(t.begin(),t.end());
      char x=s[s.size()/2];
      std::string m=s.substr((s.size()/2)+1);
      std::reverse(m.begin(),m.end());   
      std::string r=t+x+m;
      return r;
      
    }else if(s.size()%2==0 && s.size()>3){
      std::string t=s.substr(0,(s.size()/2));
      std::reverse(t.begin(),t.end());
      std::string m=s.substr(s.size()/2);
      std::reverse(m.begin(),m.end());  
      std::string r=t+m;
      return r;
    }
    return s;                      
  });
}

std::string insideOut(const std::string& s)
{
  if(s.empty()) return s;
  std::string x=s;
   std::vector<std::string> vs;
    trans(x,vs);
    insout(vs);
  auto ws=[](std::string& a,std::string& b){
    return std::move(a)+" "+std::move(b);
  };
  return std::accumulate(std::next(vs.begin()),vs.end(),vs.front(),ws);
}

///////////////////////////////
#include <sstream>
#include <algorithm>
std::string insideOut(std::string x)
{
  std::stringstream ss(x);
  std::string temp,ans;
  while (ss >> temp){
    int midP = temp.size() / 2;
    std::reverse(temp.begin(),temp.begin() + midP);
    std::reverse(temp.begin() + midP + (temp.size() % 2),temp.end());
    ans.append(temp);
    ans.push_back(' ');
  }
  if (!ans.empty()) ans.pop_back();
  return ans;
}
//////////////////////////
#include <iostream>

std::string insideOut(std::string x) {
  if (!x.size()) return "";
  std::istringstream ssi(x);
  std::ostringstream sso;
  std::string s;
  while (ssi >> s) {
    if (s.size() > 3) {
      size_t l = s.size() / 2;
      reverse(s.begin(),s.begin() + l);
      reverse(s.end() - l,s.end());
    }
    sso << s << " ";
  }
  s = sso.str();
  s.pop_back();
  return s;
}