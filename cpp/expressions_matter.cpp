unsigned short int expressionsMatter (unsigned short int a , unsigned short int b , unsigned short int c)
{
    if(a==1 || b==1 || c==1){
      if((a==1 && b==1 && c==1) || (a==c && c==1)){
        return a+b+c;
      }else if(a<=b && b<=c){
        return (a+b)*c;
      }else if(a>=b && b>=c){
        return a*(b+c);
      }else if(a<=b && b>=c){
        if(a>c){
          return a*(b+c);
        }else if(a<c){
          return (a+b)*c;
        }else if(a==c && c!=1){
          return (a+b)*c;
        }
      }else if(a>=b && b<=c){
        if(a>c){
          return a*(b+c);
        }else if(a<c){
          return (a+b)*c;
        }else if(a==c && c!=1){
          return (a+b)*c;
        }
      }
    }
  return a*b*c;
}

/////////////////////////
#include <algorithm>

unsigned short expressionsMatter(unsigned short a, unsigned short b, unsigned short c) {
  return std::max({a + b + c, a * (b + c), (a + b) * c, a * b * c});
}

////////////