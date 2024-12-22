#include <bitset>

typedef unsigned int ui;

ui rangeBitCount(ui a, ui b) {
  if(a==b) return std::bitset<16>(a).count();
  ui res=0;
  for(ui i=a;i<=b;++i){
    res+=std::bitset<16>(i).count();
  }
  return res;
}
//////////////////
unsigned rangeBitCount( unsigned a, unsigned b ) {
  unsigned c{};
  do c += __builtin_popcount( a );
  while ( ++a <= b );
  return c;
}
////////////
typedef unsigned int ui;

ui rangeBitCount(ui a, ui b) {
  
 int c=0;
while(a<=b){
    c+= (a & 1) !=0;
    c+= (a & 2) !=0;
    c+= (a & 4) !=0;
    c+= (a & 8) !=0;
    c+= (a & 16) !=0;
    c+= (a & 32) !=0;
    c+= (a &  64) !=0;
    a++;
}

return c; 
}
/////////////
