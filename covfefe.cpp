#include <string>
#include <vector>
#include <sstream>

std::string covfefe(std::string s){
 /* auto i=adjacent_find(s.begin(),s.end());
  size_t d=distance(s.begin(),i);*/
  std::stringstream ss(s);
  std::vector<std::string>vs;
  for(std::string w;ss>>w;){
    vs.push_back(std::move(w));
  }
  std::string ans;
  bool flag=false;
  
  for(size_t w=0;w<vs.size();++w){
    if(vs[w]=="coverage"){
      ans+="covfefe";
      if(w!=vs.size()-1)ans+=' ';
      flag=true;
      }
    else{
      ans+=vs[w];
      if(w!=vs.size()-1) ans+=' ';
    }
  }
  if(flag==false){
    if(s[s.size()-1]!=' '){
      ans+=" covfefe";}else{
      ans+="  covfefe";
    }
  }
  //if(d!=s.size()) ans.insert(d," ");
  if((s[s.size()-1]==' ') && flag==true) ans+=' ';
  return ans;
}

//////////////////////////
using namespace std;
string covfefe(string s){
  if (s.find("coverage") == -1) return s + " covfefe";
  while (s.find("coverage") != -1) 
    s.replace(s.find("coverage"), 8,"covfefe");
  return s;
}

////////////////////////////
#include <regex>

std::string covfefe(const std::string &s)
{
    return std::regex_match(s, std::regex(".*coverage.*")) ?
        std::regex_replace(s, std::regex("coverage"), "covfefe") :
        s + " covfefe";
}
////////////////////////////
#include <string>

std::string covfefe(std::string s)
{
	bool flag = false;
	while (s.find("coverage") != std::string::npos)
	{
		s.replace(s.find("coverage"), 8, "covfefe");
		flag = true;
	}
	return flag ? s : s + " covfefe";
}
///////////////////////////
