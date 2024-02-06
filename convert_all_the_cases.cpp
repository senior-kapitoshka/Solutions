using namespace std;
#include <algorithm>
#include <sstream>
#include <vector>
#include <numeric>
#include <iostream>

char what(const std::string& id){
  std::cout<<id<<"\n";
  auto it = std::find_if(id.begin(),id.end(),[](auto& i){return std::isupper(i);});
  std::cout<<std::distance(id.begin(),it)<<"\n";
  auto it1 = std::find(id.begin(),id.end(),'-');
  std::cout<<std::distance(id.begin(),it1)<<"\n";
  auto it2 = std::find(id.begin(),id.end(),'_');
  std::cout<<std::distance(id.begin(),it2)<<"\n";
  if(it!=id.end() && it1!=id.end() && it2!=id.end()) return 'x';
  if((it!=id.end() && it1!=id.end()) || (it1!=id.end() && it2!=id.end()) ||
     (it!=id.end() && it2!=id.end())) return 'x';
  if(it!=id.end() && it1==id.end() && it2==id.end()) return 'U';
  if(it1!=id.end() && it==id.end() && it2==id.end()) return '-';
  if(it2!=id.end() && it==id.end() && it1==id.end()) return '_';
  return 'a';
}

void h(std::vector<std::string>& vc,const std::string& s,char c){
  std::stringstream ss;
  ss.str(s);
  for(std::string w;getline(ss,w,c);){
    //std::cout<<w<<"\n";
    vc.push_back(std::move(w));
  }
}
void h2(std::vector<std::string>& vc,const std::string& str){
  std::string s=str;
  while(true){
    auto it=std::find_if(s.begin()+1,s.end(),[](auto& c){return std::isupper(c);});
    if(it==s.end()) break;
    size_t d=std::distance(s.begin(),it);
    std::string t=s.substr(0,d);
    t[0]=tolower(t[0]);
    cout<<t[0]<<"\n";
    vc.push_back(t);
    s.erase(0,d);
  }
  s[0]=tolower(s[0]);
  vc.push_back(s);
}


std::vector<std::string> pars(const std::string& id){
  std::vector<std::string> vc;
  char x=what(id);
  std::cout<<"x="<<x<<"\n";
  switch(x){
    case '_':
      h(vc,id,'_');
      return vc;
    case '-':
      h(vc,id,'-');
      return vc;
    case 'U':
      h2(vc,id);
      return vc;
    case 'x':
      return vc;
    default:
      vc.push_back(id);
      return vc;
  }
  
  return vc;
}


auto k=[](std::string&a, std::string&b){
  return std::move(a)+"-"+std::move(b);
};
auto s=[](std::string&a, std::string&b){
  return std::move(a)+"_"+std::move(b);
};

template <typename BinOp>
std::string acc(std::vector<std::string>& s, BinOp b){
  return std::accumulate(std::next(s.begin()),s.end(),s.front(),b);

}

std::string trans(std::vector<std::string>& s){
  std::string res;
  std::for_each(std::next(s.begin()),s.end(),[&res](auto& i)
    {
        i[0]=toupper(i[0]);
        res+=i;
    });
    return s.front()+res;
}

string changeCase(const string &tar, const string &id)
{
  if(id.empty() || tar.empty()) return "";
  std::cout<<id<<"-"<<tar<<"\n";
  std::vector<std::string> vc=pars(tar);
  std::cout<<"["<<"\n";
  for(auto& i:vc) std::cout<<i<<"\n";
  std::cout<<"]"<<"\n";
  if(vc.empty()) return "";
  std::string res;
  
  if(id=="kebab"){
        res=acc(vc,k);
        
  }
  else if(id=="snake"){
        
        res=acc(vc,s);
  }
  else if(id=="camel"){
        
        res=trans(vc);
  }
  else
    {
        
        res="";
  }
   return res; 
}

///////////////////////
using namespace std;
string changeCase(const string& identifier, const string& targetCase)
{
	string str; int a = 0, b = 2, c = 3;
	for (int i = 0; i < identifier.size(); i++) {
		if (isupper(identifier[i])) { str.push_back(' '); str.push_back(tolower(identifier[i])); a = 1; }
		else if (identifier[i] == '-') { str.push_back(' '); b = 1; }
		else if (identifier[i] == '_') { str.push_back(' '); c = 1; }
		else { str.push_back(identifier[i]); }
	}
	if (a == b || b == c || a == c) { return ""; }
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			if (targetCase == "snake") { str[i] = '_'; }
			else if (targetCase == "camel") { str.erase(str.begin() + i); str[i] = toupper(str[i]); }
			else if (targetCase == "kebab") { str[i] = '-'; }
			else { return ""; }
		}
	}
	return str;
}
////////////////////////////////
