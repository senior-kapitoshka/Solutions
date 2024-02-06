#include <vector>
#include <algorithm>
#include <sstream>

std::vector<std::string> ps(const std::string &s){
  std::stringstream ss(s);
  std::vector<std::string>vs;
  for(std::string w;ss>>w;){
    if(w.size()>4) reverse(w.begin(),w.end());
    vs.push_back(move(w));
  }
  return vs;
}

std::string spinWords(const std::string &str)
{
  std::vector<std::string>vs=ps(str);
  std::string ans;
  for(size_t i=0;i<vs.size();++i){
    ans+=vs[i];
    if(i!=vs.size()-1) ans+=' ';
  }
  return ans;
}
////////////////////////
#include <string>
#include <algorithm>
#include <sstream>
std::string spinWords(const std::string &str)
{
    std::stringstream ss(str);
    std::string result;
    std::string buff;
    while (ss >> buff) {
        if (buff.size() >= 5) {
            std::reverse(buff.begin(), buff.end());
        }
        result += buff + ' ';
    }
    result.pop_back();
    return result;
}
//////////////////////
using namespace std;                                                        //
string spinWords(const string &s){
  stringstream ss(s);
  string a, res;
  while (getline(ss, a, ' ')) {
    if (a.size() >= 5) {
        reverse(a.begin(), a.end());
        res += a + " ";}
    else res += a + " "; 
    }
  return res.substr(0,  res.size() - 1);
}
/////////////////////
