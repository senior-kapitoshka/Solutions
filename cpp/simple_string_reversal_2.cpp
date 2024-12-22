std::string solve(std::string s, int a, int b){
  b=b>=(int)s.size()?s.size():b+1;
    std::reverse(s.begin()+a,s.begin()+b);
  return s;
}

/////////////////
std::string solve(std::string s, int a, int b)
{
  std::reverse(s.begin() + a, s.begin() + (b >= s.size() ? s.size() : b + 1));
  return s;
}
/////////////
std::string solve( std::string s, int a, int b ) {
  return reverse( s.begin() + a,
    s.begin() + std::min( ++b, int( s.size() ))), s;
}