#include <string>
#include <bitset>

std::string uint32_to_ip(uint32_t ip)
{
  std::string res;
  std::string s=std::bitset<32>(ip).to_string();
  for(size_t i=0;i<s.size();i+=8){
    std::string t=s.substr(i,i+8);
    res+=std::to_string(std::bitset<8>(t).to_ulong());
    res+='.';
  }
  res.pop_back();
  return res;
}
///////////
#include <sstream>

std::string uint32_to_ip(uint32_t ip)
{
  std::stringstream result{};
  result << (ip >> 24) << '.' << (ip >> 16 & 0xFF) << '.' 
      << (ip >> 8 & 0xFF ) << '.' << (ip & 0xFF);
  return result.str();
}
/////////////
#include <arpa/inet.h>

std::string uint32_to_ip(uint32_t ip)
{
    in_addr addr;
    addr.s_addr = htonl(ip);
    return {inet_ntoa(addr)};  
}
///////////
std::string uint32_to_ip(uint32_t ip)
{
  return 
    std::to_string(ip>>24 & 255) + "." + 
    std::to_string(ip>>16 & 255) + "." +
    std::to_string(ip>>8 & 255) + "." +
    std::to_string(ip & 255);
}
////////////////
std::string uint32_to_ip(uint32_t ip) {
  std::string result;
  
  uint32_t mask4 = (0xff);        // 00000000 00000000 00000000 11111111
  uint32_t mask3 = (0xff00);      // 00000000 00000000 11111111 00000000
  uint32_t mask2 = (0xff0000);    // 00000000 11111111 00000000 00000000
  uint32_t mask1 = (0xff000000);  // 11111111 00000000 00000000 00000000
    
  result += std::to_string((ip & mask1) >> 24);
  result += '.';
  result += std::to_string((ip & mask2) >> 16);
  result += '.';
  result += std::to_string((ip & mask3) >> 8);
  result += '.';
  result += std::to_string(ip & mask4);
  
  return result;
}