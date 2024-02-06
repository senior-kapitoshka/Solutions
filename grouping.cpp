#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isConsecutive(string s){
  vector<char>vc;
  for(auto&&c:s){
    if(vc.empty())vc.push_back(c);
    if(c==vc.back())continue;
    if(c!=vc.back()){
      if(count(vc.begin(),vc.end(),c)!=0) return false;
      else vc.push_back(c);
    }
  }
  return true;
}

////////////////////////////

#include <unordered_set>
bool isConsecutive( std::string s ) {
  std::unordered_set< char > us;
  for ( size_t i{}, n{ s.size()-1 }; i < n; ++i )
    if ( us.find( s[ i ] ) != us.cend() ) return false;
    else if ( s[ i ] != s[ i+1 ] ) us.insert( s[ i ] );
  return true;
}

////////////////////////////////////


#include <string>
#include <set>
#include <regex>

bool isConsecutive(std::string s){
    s = std::regex_replace(s, std::regex("(.)\\1+"), "$1");
    std::set<char> ss(s.cbegin(), s.cend());
    return s.size() == ss.size();
}

//////////////////////////////
#include <string>
#include <map>
using namespace std;

bool isConsecutive(string s)
{
    map <char, bool> grp;
    char g = '\0';
    for (char c : s)
        if (g != c)
            if (grp.count(c))
                return false;
            else
                grp[c] = true, g = c;
    return true;
}

////////////////////////////
