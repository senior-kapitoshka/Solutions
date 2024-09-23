#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::unordered_map<std::string, std::vector<std::string>> conjugate(std::string verb) {
  std::unordered_map<std::string,std::vector<std::string>>mp{{"ar",{"o","as","a","amos","áis","an"}},{"er",{"o","es","e","emos","éis","en"}},{"ir",{"o","es","e","imos","ís","en"}}};
  std::string s=verb.substr(verb.size()-2);
  std::unordered_map<std::string, std::vector<std::string>>res;
  res[verb].reserve(mp[s].size());
  std::for_each(mp[s].begin(),mp[s].end(),[w=verb.substr(0,verb.size()-2),&verb,&res](auto& suf){
    res[verb].emplace_back(w+suf);
  });
  return res;
}

/////////////////
std::unordered_map< std::string, std::vector<std::string>>
conjugate( std::string verb ) {
  std::vector< std::string > conjugations( 6 );
  const auto base{ verb.substr( 0, verb.size()-2 )};
  const std::vector< std::vector< std::string >> suffix{
    { "o", "as", "a", "amos", "áis", "an" },
    { "o", "es", "e", "emos", "éis", "en" },
    { "o", "es", "e", "imos",  "ís", "en" }};
  const char s{ verb[ verb.size()-2 ]};
  const int iform{ s == 'a' ? 0 : s == 'e' ? 1 : 2 };
  for ( int i{}; i < 6; ++i )
    conjugations[ i ] = base + suffix[ iform ][ i ];
  return {{ verb, conjugations }};
}