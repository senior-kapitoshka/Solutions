//не проходит бльшие тесты
#define ALL(x) begin(x), end(x)
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>

long bin_to_decl(const std::string& s){
  int i=s.size()-1;
  long res=0;
  std::for_each(ALL(s),[&res,&i](auto &c){
    res+=std::pow(2,i)*(c-'0');
    --i;
    });
  return res;
}

unsigned long long eliminate_unset_bits(const std::string& num){
  std::string s;
  std::for_each(ALL(num),[&s](auto& i){
    s+=i=='1'?"1":"";
  });
  if(s.empty())return 0;
  long res=bin_to_decl(s);
  return (unsigned long long)res>ULLONG_MAX?(res-(unsigned long long)1):res;
}

/// ///////////////////////////////////////

long eliminate_unset_bits(std::string number) {
	long res = 1;
	for (char c : number) if (c == '1') res <<= 1;
	return res - 1;
}

/////
#include <algorithm>
#include <string>

long eliminate_unset_bits(const std::string& number) {
  return (1l << std::count(number.cbegin(), number.cend(), '1')) - 1;
}