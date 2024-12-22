#include <string>

#if 0
//pass basic tests,\
fail random
bool check(const std::string& str, size_t i){
  if(i*2>str.size() ) return false;
  for(size_t j=(i-1)+i,x=0;j<str.size();j+=i,x+=i){
    if(((str[j]-'0')-(str[j-i]-'0')!=1) && ((str[j]-'0')!=0 && (str[j-i]-'0')!=9))
      return false;
    if((str[j-i]-'0')==9){
      ++i;
      ++j;
    }
  }
  return true;
}


int find(const std::string& str)
{
  if(str.size()==1) return std::stoi(str);
  if(str.front()=='9'){
    if(str[1]=='1'){
      for(size_t x=2;x<str.size();++x){
          if(check(str.substr(1),x)) return std::stoi(str.substr(0,1));
      }
    }else{
      for(size_t x=2;x<str.size();++x){
          if(check(str,x)) return std::stoi(str.substr(0,x));
      }
    }
  }else{
    if((str[1]-'0')-(str[0]-'0')==1){
      if(check(str,1)) return str[0]-'0';
      else{
        for(size_t x=2;x<str.size();++x){
          if(check(str,x)) return std::stoi(str.substr(0,x));
        }
      }
    }else{
      for(size_t x=2;x<str.size();++x){
          if(check(str,x)) return std::stoi(str.substr(0,x));
      }
    }
  }
  return std::stoi(str);
}
#endif
int find(const std::string& s)
{
  for (size_t i = 1; i <= s.size(); i++) {
    int n = std::stoi(s.substr(0, i));  
    std::string strNums;               

    while (strNums.size() < s.size()) {
      strNums += std::to_string(n);  
      n += 1;                 
    } 

    if (strNums == s) return std::stoi(s.substr(0, i));
  } 
  return std::stoi(s);
} 

////////////////////////////

int find( const std::string& str ) {
  for ( size_t dig{ 1 }; dig < str.size(); ++dig ) {
    std::string tmp;
    int num{ stoi( str.substr( 0, dig )) }, n{ num };
    do tmp += std::to_string( n++ );
    while ( tmp.size() < str.size() );
    if ( tmp == str ) return num;
  }
  return stoi( str );
}

//////////////////
