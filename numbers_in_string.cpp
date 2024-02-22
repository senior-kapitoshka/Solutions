#include <sstream>

int solve(std::string s){
  for(size_t i=0;i<s.size();++i){
    if(isalpha(s[i])) s[i]=' ';
    else if(isdigit(s[i])) continue;
  }
  std::stringstream ss;
  ss.str(s);
  int m=0;
   int t=0;
  for(std::string w;std::getline(ss,w,' ');){
    if(!w.empty()) t=std::stoi(w);
    m=std::max(t,m);
  }
  return m;
}

/////////////////////////


#include <string>
#include <regex>

int solve(std::string s)
{
  int number = -1;
  std::regex reg("[[:digit:]]+");
  for(auto it = std::sregex_iterator(s.begin(), s.end(), reg); it != std::sregex_iterator(); ++it)
  {
    int n = std::stoi((*it).str());
    number = n > number ? n : number;
  }
  return number;
}

////////////////////
int solve(std::string s){
    int max = 0;
    std::string tmp("");
    for(int i = 0; i < s.length() + 1; ++i){
        if(isdigit(s[i]))
        {
            tmp += s[i];
            continue;
        }
        if(!tmp.empty()){
            if(std::stoi(tmp) > max){
                max = std::stoi(tmp);
            } 
            tmp = "";
        }
    }
    
    return max;
}
//////////////////
int solve( std::string s ) {
  for ( char& c : s ) if ( !isdigit( c )) c = 32;
  int n{}, i{}; std::istringstream ss{ s };
  while ( ss >> i ) n = std::max( n, i );
  return n;
}

/////////////////
int solve( std::string s ) {
  int n{};
  const std::string d{ "0123456789" };
  size_t i{}, j;
  while (( i = s.find_first_of( d, i )) != std::string::npos )
    j = s.find_first_not_of( d, i ),
    n = std::max( n, stoi( s.substr( i, j - i ))), i = j;
  return n;
}