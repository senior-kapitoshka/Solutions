
#include <cstdint>
#include <string>
#include <bitset>
#include <sstream>

uint32_t ip_to_int32(const std::string& ip) {
    std::string res;
  std::stringstream ss;
  ss.str(ip);
  for(std::string w;std::getline(ss,w,'.');){
   res+=std::bitset<8>(std::stoll(w)).to_string();
  }

  return static_cast<uint32_t>(std::bitset<32>(res).to_ullong());
} 
////////////////////////
#include <cstdint>
#include <string>
#include <sstream>

uint32_t ip_to_int32(const std::string& ip) {
    
  std::istringstream iss(ip);
  uint32_t res = 0, part;
  for(int i=0; i<4; ++i) {
    iss >> part;
    iss.ignore(1, '.');
    res = res << 8 | part;
  }
  return res;
} 