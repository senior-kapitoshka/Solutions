#include <string>
#include <regex>
using namespace std;

string alphabetWar(string f)
{
  std::regex r("[\\w]?\\*[\\w]?");
  f=std::regex_replace(f,r,"___");
  int res=0;
  std::for_each(f.begin(),f.end(),[&res](auto& c){
    res+=c=='w'?4:c=='m'?-4:c=='p'?3:c=='q'?-3:c=='b'?2:c=='d'?-2:c=='s'?1:c=='z'?-1:0;
    
  });
  
  return res==0?"Let's fight again!"s:res>0?"Left side wins!"s:"Right side wins!"s;
}