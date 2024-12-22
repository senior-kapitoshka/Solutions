using namespace std;
#include <unordered_map>

char solve(string s){
  std::unordered_map<char,std::pair<int,int>>mp;
	for(int i=0;i<(int)s.size();++i){
    if(!mp.count(s[i])){
      mp[s[i]]={i,0};
    }else{
      mp[s[i]]={mp[s[i]].first,i-mp[s[i]].first};
    }
  }
  return std::max_element(mp.begin(),mp.end(),[](auto& lhs, auto& rhs){
    return lhs.second.second<rhs.second.second || (lhs.second.second==rhs.second.second && lhs.first>rhs.first);
  })->first;
}

/////////////////
char solve( std::string s ) {
  std::vector< int > v( 26 + 'a' );
  for ( const char c : s ) if ( !v[ c - 'a' ] )
    v[ c - 'a' ] = 1, v[ c ] = s.find_last_of( c ) - s.find_first_of( c );
  return std::max( max_element( v.cbegin() + 'a', v.cend() ) - v.cbegin(),
    max_element( v.cbegin(), v.cbegin() + 26 ) - v.cbegin() + 'a' );
}

/////////////
using namespace std;

char solve(string s){
	unsigned max = 0;
  char letter = s[0];
  for(unsigned i = 0 ; i < s.size() ; ++i)
  {
      int dis = i - s.find(s[i]);
      if(max < dis)
      {
         max = dis;
         letter = s[i];  
      }
    if(max == dis && s[i] < letter)
         letter = s[i];  
  }  
  return letter;
}

/////////////////
