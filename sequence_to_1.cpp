#define ALL(x) begin(x),end(x)
#include <numeric>
std::vector<int> seqToOne(int n) {
  std::vector<int>vc;
  if(n>0){
    vc.resize(n);
    std::iota(ALL(vc),1);
    std::reverse(ALL(vc));
  }else{
    int i=2;
    vc.resize(i+std::abs(n));
    std::iota(ALL(vc),n);
  }
  return vc;
}
/////////////////////////
std::vector<int> seqToOne(int n) {
  std::vector<int> s;
  while (n != 1) {
  s.push_back(n);
  n > 1 ? n-- : n++;
  }
  s.push_back(n);
  return s;
}
/////////////////
std::vector<int> seqToOne(int n) {
  std::vector<int> result;
  
  while(n != 1){
    result.push_back(n);
    
    n += n > 1 ? -1 : +1;
  }
  
  result.push_back(1);
  return result;
}