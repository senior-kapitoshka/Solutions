#include <cstdint>
#include <string>
#include <bitset>

std::string add_binary(uint64_t a, uint64_t b) {
  if(a==0 && b==0) return "0";
  std::string s=std::bitset<64>(a+b).to_string();  
  return s.substr(s.find_first_of('1'));
}
////////////////////
#include <cstdint>
#include <string>
#include <fmt/core.h>

std::string add_binary(std::uint64_t a, std::uint64_t b) {
  return fmt::format("{:b}", a + b);
}