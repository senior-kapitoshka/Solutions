std::string workNeeded(int proM, std::vector<std::pair<int, int>> fr)
{
  int fs=0;
  int ans=0;
  int h=0;
  int m=0;
  for_each(fr.begin(),fr.end(),[&fs](auto& p){
    fs+=p.first*60+p.second;
  });
  if(proM==fs) return "Easy Money!";
  else{
    if(fs<proM){
      ans=proM-fs;
      h=ans/60;
      m=ans%60;
    }else return "Easy Money!";
  }
  return "I need to work "+std::to_string(h)+" hour(s) and "+std::to_string(m)+" minute(s)";
}
///////////////////////////////

#include <numeric>
using namespace std;
string workNeeded(int time, vector<pair<int, int>> f)
{
  time -= accumulate(f.begin(), f.end(), 0, [](const int i, const auto p){return i+60*p.first+p.second;});
  return (time <= 0)? "Easy Money!" : "I need to work "+ to_string(time/60) +" hour(s) and "+ to_string(time%60) +" minute(s)";
}
//////////////////////////////
