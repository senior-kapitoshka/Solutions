#include <map>
#include <vector>
#include <numeric>

std::string f(const char& c,int i){
  std::string r(i,'*');
  if(i>=10)r.insert(0,4,' ');
  else r.insert(0,5,' ');
  r.insert(0,std::to_string(i));
  r.insert(0,2,' ');
  r.insert(0,1,c);
  return r;
}

auto w=[](std::string& a,std::string& b){
  return std::move(a)+"\\r"+std::move(b);
};

std::string hist(const std::string &s)
{
    std::map<const char,int>mp;
  for(const char& c:s){
    if(c=='u'||c=='z'||c=='w'||c=='x'){
      mp[c]++;
    }
  }
  if(mp.empty()) return "";
  std::vector<std::string>vs;
  for(auto p:mp){
    vs.push_back(f(p.first,p.second));
  }
  return std::accumulate(std::next(vs.begin()),vs.end(),vs.front(),w);
}
/////////////////////////////
#include <sstream>

using namespace std;

string hist(const string &s)
{
    map<char, int> count;
    for (auto c : s) count[c]++;
    stringstream ss;
    for (auto c : "uwxz")
        if ( count[c] )
            ss << c << "  "
               << (to_string(count[c]) + "      ").substr(0, 6)
               << string(count[c], '*') << "\\r";
    return ss.str().substr(0, ss.str().size()-2);
}
//////////////////////////////
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;
string hist(const std::string &s)
{
       
  ostringstream out;
  bool first = true;
for (const char x : "uwxz") {
    int errors = count(s.begin(), s.end(), x);
        if(errors > 0){
          if(!first) out << "\\r" ;
            out << left << x <<"  "<< setw(6)<<errors;
            out << string(errors, '*');
          first = false;
        }

    }
  return out.str();
}