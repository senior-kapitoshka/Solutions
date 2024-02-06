#include <vector>
#include <variant>
#include <algorithm>

int divCon(const std::vector<std::variant<int, char>>& x) {
  int res=0;
  std::for_each(x.begin(),x.end(),[&res](auto& d){
    if(std::holds_alternative<int>(d)){
      res+=std::get<int>(d);
    }
    if(std::holds_alternative<char>(d)){
      res-=(std::get<char>(d)-'0');
    }
  });
  return res;
}

////////////////////////////////
#include <vector>
#include <variant>

int divCon(const std::vector<std::variant<int, char>>& arr)
{
  int result{0};
  
  for (const auto x : arr)
  {
    result += std::get_if<int>(&x) ? std::get<int>(x) : '0' - std::get<char>(x);
  }

  return result;
}

//////////////////////////////
#include <vector>
#include <variant>
#include <cstdlib>

struct CallForVariant {
    int operator()(const int var_int)   { return var_int; }    
    int operator()(const char var_char) { return -(std::atoi(&var_char)); }    
};

int divCon(const std::vector<std::variant<int, char>>& x) {
  int sum {};
  for (auto value : x) {
    sum += std::visit(CallForVariant{}, value);
  }
  return sum;
}

////////////////////////////////////
#include <vector>
#include <variant>
#include <numeric>

int divCon(const std::vector<std::variant<int, char>> &x) 
{
	int sum1 = std::accumulate(x.begin(), x.end(), 0, [](int s, auto v) { return !v.index() ? s + std::get<int>(v) : s; });
	int sum2 = std::accumulate(x.begin(), x.end(), 0, [](int s, auto v) { return v.index() ? s + std::get<char>(v) - '0' : s; });
	return sum1 - sum2;
}
//////////////////////////////
#include <vector>
#include <variant>
#include <numeric>

int divCon(const std::vector<std::variant<int, char>>& x) {
    return std::accumulate(x.cbegin(), x.cend(), 0,
                          [](const int acc, const auto& v) {
                              return acc + std::visit([](auto&& n) -> int {
                                  using T = std::decay_t<decltype(n)>;
                                  if constexpr(std::is_same_v<T, int>) {
                                      return n;
                                  }
                                  else if constexpr(std::is_same_v<T, char>) {
                                      return '0' - n;
                                  }
                                  return 0;
                              }, v);
                          });
}
/////////////////////////////
