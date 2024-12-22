#include <sstream>
#include <cmath>

std::string draw_spider(int l, int b, char m, char eye)
{
  std::stringstream ss;
  int e=std::pow(2,b)/2;
  ss<<std::string(b,'(')<<std::string(e,eye)<<m<<std::string(e,eye)<<std::string(b,')');
  std::string res;
  if(l==1){
    res="^"+ss.str()+"^"; 
  }else if(l==2){
    res="/\\"+ss.str()+"/\\"; 
  }else if(l==3){
    res="/╲"+ss.str()+"╱\\";
  }else if(l==4){
    res="╱╲"+ss.str()+"╱╲";
  }
    return res; 
}

////////////////////
#include <string>
#include <cmath>

std::string draw_spider(int a, int b, char c, char d) {
  std::string ll = a == 1 ? "^" : a == 2 ? "/\\" : a == 3 ? "/╲" : "╱╲",
              rl = a == 1 ? "^" : a == 2 ? "/\\" : a == 3 ? "╱\\" : "╱╲",
              lb = std::string(b, '('), rb = std::string(b, ')'),
              e = std::string(pow(2, b-1), d);
  return ll + lb + e + c + e + rb + rl;
}

////////////////////////
