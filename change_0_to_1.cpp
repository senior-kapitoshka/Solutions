#include <string>
#include <algorithm>

std::string broken(const std::string& inp) {
  std::string res;
  std::transform(inp.begin(),inp.end(),std::back_inserter(res),[](auto& c){
    return c=='0'?'1':'0';
  });
  return res;
}

//////////////////////////
#include <string>
#include <string_view>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/transform.hpp>

std::string broken(std::string_view s) {
  return s
    | ranges::views::transform([](char c) { return c ^ 1; })
    | ranges::to<std::string>;
}
///////////////////////
#include <string>
#include <algorithm>

std::string broken(const std::string& inp) {
  std::string res;
  std::transform(inp.begin(),inp.end(),std::back_inserter(res),[](auto c){return c^1;});
  return res;
}