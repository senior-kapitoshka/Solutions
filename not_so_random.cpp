#include <string>

#if 0
std::string not_so_random(unsigned b, unsigned w) {
  while(true){
    if((b==1 && w==0) || (w==1 && b==0))break;
    if(b!=0 && w!=0){
      --w;
    }else if(b==0 && w!=0){
      --w;
    }else if(b!=0 && w==0){
      b-=2;
      ++w;
    }
  }
  return (b==1 && w==0)?"Black":"White";
}
#endif

std::string not_so_random(unsigned b, unsigned w) {
  return ((b==w && b%2!=0 && w%2!=0) || (b%2!=0 && w%2==0) || (b%2!=0 && w%2!=0))?"Black":
  ((b==w && b%2==0 && w%2==0) || (b%2==0 && w%2!=0) || (b%2==0 && w%2==0))?"White":
  "Unsure";
}

///////////////////
#include <string>

std::string not_so_random(unsigned b, unsigned w) {
  return b % 2 != 0 ? "Black" : "White";
}

/////////////////
#include <string>

std::string not_so_random(unsigned b, unsigned w) {
  while(b != 0 and w != 0){
    b--;
    w--;
    b++;
  }
  
  return (b %2 ==0 and b > 1)? "White" : "Black";
}

////////////////
