int snail(int col, int d, int n) {
  int cnt=0;
  for(int i=0;i<=col;){
    ++cnt;
    i+=d;
    if(i>=col) break;
    i-=n;
  }
  return cnt;
}
//////////////
#include <cmath>
int snail(int h, int d, int n) {
  return std::ceil(double(h-d)/(d-n))+1;
}
//////////
constexpr int snail(const int column, const int day, const int night) {
  return (column + day - 2 * night - 1) / (day - night);
}
//////////
