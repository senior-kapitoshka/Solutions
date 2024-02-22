std::string pattern(int n)
{
    std::string p;
    if(n==0) return p;
    int c=1;
    while(c<=n){
      for(int i=c;i<=n;++i){
        p+=std::to_string(i);
      }
      if(c!=n)p+="\n";
      ++c;
    }
  return p;
  
}
//////////////////////////
