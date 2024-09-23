#include <string>
using namespace std;

string tops(const string& msg)
{
  std::string res;
  for(size_t i=1,j=1;i<msg.size();i+=j){
    res+=msg[i];
    j+=4;
  }
    return std::string(res.rbegin(),res.rend());
}

///////////////////
#include <string>
#include <algorithm>
using namespace std;

string tops(const string& msg)
{
    std::string szTops;
    for (int x = 1; x < msg.size(); x += szTops.size() * 4 + 1)
      szTops += msg[x];
    
    std::reverse(szTops.begin(), szTops.end());
    return szTops;
}

//////////////////
#include <algorithm>
#include <string>

std::string tops(const std::string& msg) {
  std::string res;
  for (std::string::size_type i = 1, di = 5; i < msg.size(); i += di, di += 4)
    res.push_back(msg[i]);
  std::reverse(res.begin(), res.end());
  return res;
}