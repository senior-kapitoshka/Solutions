using namespace std;

std::string doubles(std::string s){
  string res="";
  stack<char> eta;
  for (auto x: s) {
    if (eta.empty()) eta.push(x);
    else if (eta.top()==x) eta.pop();
    else eta.push(x);
  }
  char z;
  while (!eta.empty()) {
    res.push_back(eta.top());
    eta.pop();
    }
  reverse(res.begin(), res.end());
  return res;
}

/*#include <stack>
std::string doubles(std::string s){
  std::stack<char>vc;
  vc.push(s[0]);
  for(size_t i=1;i<s.size();++i){
    if(vc.empty())vc.push(s[i]);
    if(vc.top()==s[i]){
      vc.pop();
      vc.push(s[i]);
      

      
    }
    if(vc.top()!=s[i]){vc.push(s[i]);}
  }
  std::string ans;
  while(!vc.empty()){
    ans+=vc.top();
    vc.pop();
  }
  return  ans;
}*/
std::string doubles(std::string s){
 std::vector<char> cs;
  for (auto&&c: s) {
    if (cs.size() != 0 && cs[cs.size() - 1] == c)
      cs.pop_back();
    else
      cs.push_back(c);
  }
  std::string ans(cs.begin(),cs.end()); 
  return ans;
}

/////////////////////////////////////
std::string doubles(std::string s){
  std::string s1="";   
  int rep=0;
  for(int i=0;s[i]!='\0';i++){
      if(s[i]!=s[i+1])
        s1+=s[i];
      else{
        i++;
        rep++;
      }
    }
  if(rep==0)
    return s1;
  else
   return doubles(s1);
}
/////////////////////////////////

std::string doubles( std::string s ) {
  std::string r;
  for ( char c : s ) r.back() == c ?
    r.pop_back() : r.push_back( c );
  return r;
}
///////////////////////////////

#include <range/v3/numeric/accumulate.hpp>
#include <string>

std::string doubles(const std::string& s)
{
  return ranges::accumulate(s, std::string{}, [] (auto& acc, char c) -> auto&
                            {
                              if (acc.back() == c) { acc.pop_back();   }
                              else                 { acc.push_back(c); }
                              return acc;
                            });
}

///////////////////////////////////////////

#include <string>
#include <numeric>
using namespace std;

string doubles(string s)
{
    return accumulate(s.begin()+1, s.end(), string(1,s[0]), [](string &a, char &b)
    {
        if (b == a.back())
            a.pop_back();
        else
            a.push_back(b);
        return a;
    });
}
/////////////////////////////////////////

