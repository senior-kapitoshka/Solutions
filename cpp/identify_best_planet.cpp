#include <string>
#include <vector>
#include <limits>
static const std::vector<std::string> RE { "H", "C", "N", "O", "P", "Ca" };
std::string bestPlanet(const std::vector<std::string>& sls, int mx)
{
  std::string res;
  int m=std::numeric_limits<int>::min();
  std::for_each(sls.begin(),sls.end(),[&m,&res,mx](auto& s){
    std::string el=s.substr(0,s.find_first_of('_')+1);
    int d=std::stoi(s.substr(s.find_first_of('_')+1));
 
    int cnt=0;
    for(size_t i=0;i<el.size()-1;++i){
      if(((el[i]=='H' || el[i]=='N' || el[i]=='C'
         || el[i]=='O' || el[i]=='P')
         && (isupper(el[i+1]) || el[i+1]=='_')) 
         || (el[i]=='C' && el[i+1]=='a')){
        ++cnt;
      }
    }
    if(cnt==6){
      if(d<=mx){
        if(d>m){
          res=s;
          m=d;
        }
      }
    }
      
  });
  return res;
}

#if 0
#include <regex>
std::string bestPlanet(const std::vector<std::string>& sls, int mx)
{
  std::vector<std::string>re(RE.begin(),RE.end());
  std::string res;
  std::regex r("([\\A-z]+_)([\\d]*)");
  int m=std::numeric_limits<int>::min();
  std::for_each(sls.begin(),sls.end(),[&r,&re,&m,&res,mx](auto& s){
      std::smatch sm;
      if(std::regex_match(s,sm,r)){
        if(std::all_of(re.begin(),re.end(),[&sm](auto& e){
          return sm[1].str().find(e)!=sm[1].str().npos;
        })){
          int cnt=0;
          for(size_t i=0;i<sm[1].str().size()-1;++i){
            if(((sm[1].str()[i]=='H' || sm[1].str()[i]=='N' || sm[1].str()[i]=='C'
               || sm[1].str()[i]=='O' || sm[1].str()[i]=='P')
               && (isupper(sm[1].str()[i+1]) || sm[1].str()[i+1]=='_')) 
               || (sm[1].str()[i]=='C' && sm[1].str()[i+1]=='a')){
              ++cnt;
            }
          }
          if(cnt==6){
            if(std::stoi(sm[2])<=mx){
              if(std::stoi(sm[2])>m){
                res=s;
                m=std::stoi(sm[2]);
              }
            }
          }
        }
      }
  });
  return res;
}
#endif

//////////////////////////
#include <iostream>
#include <vector>

std::string bestPlanet(std::vector<std::string>& solarSystem, int maxSize)
{
  int v=-1; std::string r="";
  for (auto& s : solarSystem) {
    int z = 0;
    bool H = false, C = false, N = false, O = false, P = false, Ca = false;
    while (s.at(z) != '_') {
      if (s.at(z) == 'C' && s.at(z+1) == 'a') { Ca = true; z+=2; }
      else if (s.at(z+1) < 'a' || s.at(z+1) > 'z') {
        if (s.at(z) == 'H') { H = true; ++z; }
        else if (s.at(z) == 'C') { C = true; ++z; }
        else if (s.at(z) == 'N') { N = true; ++z; }
        else if (s.at(z) == 'O') { O = true; ++z; }
        else if (s.at(z) == 'P') { P = true; ++z; }
        else { ++z; }
      } else { ++z; }
    }
    if (!H || !C || !N || !O || !P || !Ca) continue;
    int t=std::stoi(s.substr(z + 1));
    if (t > maxSize) continue;
    if (t > v) { r = s; v = t; }
  }
  return r;
}

/////////////////////////
