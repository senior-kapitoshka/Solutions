#include<string>
#include <vector>
#include <iostream>

void tr(std::vector<long long>&vc,long long n){
  long long i=n%10;
  if(i<0) i*=-1;
  vc.push_back(i);
  long long t=n/10;
  if(t==0) return;
  tr(vc,t);
}

std::string numberFormat(long long n){
  if(n==0) return "";
  std::vector<long long> vc;
  tr(vc,n);
  std::string ans;
  
  for(size_t i=vc.size()-1;i>0;i--){
    if((i+1)%3==0) ans+=",";
    ans+=std::to_string(vc[i]);
  }
  ans+=std::to_string(vc.front());
  if(ans.front()==',') ans.erase(0,1);
  if(n<0) ans.insert(0,"-");
  std::cout<<ans<<"\n";
  return ans;
}
////////////////////////
#include<string>

std::string numberFormat(long long n) {
	std::string str = std::to_string(n);
	for (int i = str.size() - 3; i > 0; i-=3)
	{
		if (str.at(i-1) == '-') break;
		str.insert(str.begin() + i, ',');
	}
	return str;
}
///////////////////////
#include <string>
#include <regex>

std::string numberFormat(long long n) {
	std::string res=std::regex_replace(std::to_string(n),
					                   std::regex(R"(([+-]?\d{1,3})(?=(\d{3})*$))"),
					                   R"($1,)");
	res.pop_back();
	return res;
}
//////////////////
#include<string>

std::string numberFormat(long long n){
  std::string num = std::to_string(n);
  
  for(int i = num.size()-3; i > (num[0] == '-'); i-=3)
    num.insert(i, 1, ',');
    
  return num;
}
//////////////////////
