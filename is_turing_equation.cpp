#include <regex>
#include <algorithm>
#include <vector>
using namespace std;
bool is_turing_equation(std::string s){
  std::regex r("[\\d]+");
  auto rb=std::sregex_iterator(s.begin(),s.end(),r);
  auto re=std::sregex_iterator();
  std::vector<int>vc;
  vc.reserve(3);
  for(auto it=rb;it!=re;++it){
    std::string t=(*it).str();
    std::reverse(t.begin(),t.end());
    vc.push_back(std::stoi(t));
  }
  return vc[0]+vc[1]==vc[2];
}
//////////////////////////
using namespace std;
bool is_turing_equation( string s ) {
#define INIT( x ) while ( isdigit( s[ --S ] ) ) x += s[ S ]
  string a, b, c; size_t S{ s.size() };
  INIT( c ); INIT( b ); INIT( a );
  return stoi( a ) + stoi( b ) == stoi( c );
}
////////////////////
#include <regex>

using namespace std;

string reverse(string s) {    
    reverse(s.begin(), s.end());
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](const char c) { return c != '0'; }));
    if(s.empty()) return "0";
    return s;
}

bool is_turing_equation(const string& s) {
    static const regex expr{ R"(^(\d+)([-+\/*])(\d+)=(\d+)$)" };
    smatch match;
    if(!regex_match(s, match, expr)) throw invalid_argument{ "It is indeed invalid" };
      
    const auto a = stoll(reverse(match[1].str()));
    const auto b = stoll(reverse(match[3].str()));
          auto c = stoll(reverse(match[4].str()));
    const char o = match[2].str().front();
  
    switch(o) {
        case '+': c -= a + b; break;
        case '-': c -= a - b; break;
        case '/': c -= a / b; break;
        case '*': c -= a * b; break;
    }
  
    return !c;
}

///////////////////////
using namespace std;

bool is_turing_equation(std::string s){
  std::string reversed {s.rbegin(), s.rend()};
  int res {}, a {}, b {};
  char symbol;
  std::stringstream ss {reversed};
  ss >> res >> symbol >> a >> symbol >> b;
  return res == a + b;
}
///////////////////