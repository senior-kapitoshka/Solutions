#include <string>
#include <algorithm>
#include <cmath>
int square_digits(int num) {
  std::string s=std::to_string(num);
  std::vector<int>vs;
  std::transform(s.begin(),s.end(),std::back_inserter(vs),[](auto& c){
    return std::pow(c-'0',2);
  });
  std::string res;
  std::for_each(vs.begin(),vs.end(),[&res](auto& i){
    return res+=std::to_string(i);
  });
 return std::stoi(res);
}
/////////////////
int square_digits(int n) {
  int a = 1;
  int m = 0;
  while (n > 0) {
    int d = n % 10;
    m += a * d * d;
    a *= d <= 3 ? 10 : 100;
    n /= 10;
  }
  return m;
}
////////////
