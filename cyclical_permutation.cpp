

std::string pattern(int n)
{
    std::string res;
  if (n < 1) return res;
    if (n == 1) return "1";
  for(size_t j=1;j<=(size_t)n;++j){
    for(size_t k=0,i=j;k<(size_t)n;++k,++i){
      res+=i==(size_t)n?std::to_string(n):std::to_string(i%n);
    }
    if(j!=(size_t)n)res+="\n";
  }
  return res;
}
////////////////////
std::string pattern(int n)
{
    std::string s;
    for (int i = 0; i < n; i++, s += "\n")
        for (int j = 0; j < n; j++)
            s += std::to_string((i + j) % n + 1);
    return s.substr(0, s.size()-1);
}
///////////////
std::string pattern( int n ) {
  if ( n < 1 ) return {};
  std::string s;
  for   ( int r{ 1 }; r <= n; ++r,  s += '\n' ) {
    for ( int c{ r }; c <= n; ++c ) s += std::to_string( c );
    for ( int c{ 1 }; c <  r; ++c ) s += std::to_string( c ); }
  return s.pop_back(), s;
}