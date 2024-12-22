#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <algorithm>

int prs(std::string& s){
  int res=0;
  for_each(s.begin(),s.end(),[&res](char& c){
    res+=c-96;
  });
  return res;
}

std::vector<std::string>ps(const std::string &s){
  std::stringstream ss(s);
  std::vector<std::string>vs;
  for(std::string w;ss>>w;){
    vs.push_back(move(w));
  }
  return vs;
}

std::vector<std::pair<int,std::string>>topr(std::vector<std::string>& vc){
  std::vector<std::pair<int,std::string>> vp;
  std::transform(vc.begin(),vc.end(),std::back_inserter(vp),[](auto& s)->std::pair<int,std::string>{
    return make_pair(prs(s),s);
  });
  return vp;
}

std::string highestScoringWord(const std::string &str)
{
  std::vector<std::string> vs=ps(str);
  std::vector<std::pair<int,std::string>>vp=topr(vs);
  std::sort(vp.begin(),vp.end(),[](auto& a,auto& b){
    if(a.first==b.first)return a.second.size()>b.second.size();
    return a.first>b.first;});
  return vp.front().second;
  
}
////////////////////////////////
using namespace std;
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
string highestScoringWord(const string &str)
{
    stringstream s; s << str;
    vector<string> sent((istream_iterator<string>(s)), istream_iterator<std::string>());
    return *max_element(sent.begin(), sent.end(), [](string a, string b)
        {return accumulate(a.begin(), a.end(), 0) - a.size() * 96 
              < accumulate(b.begin(), b.end(), 0) - b.size() * 96;});
}
////////////////////////////