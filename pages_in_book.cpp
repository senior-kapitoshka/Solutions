#include <string>
uint32_t amount_of_pages(uint32_t s){
  std::string str;
  uint32_t ans=0;
    for(int i=1;(uint32_t)str.size()<s;++i){
      ans=i;
      str+=std::to_string(i);
    }

  return ans;
}
/////////////////////////
uint32_t amount_of_pages(uint32_t summary){
  uint32_t d=1, s=9, p=0;
  for(; summary > s*d; summary -= s*d, p += s, s *= 10, ++d);
  return p + summary/d;
}
///////////////////////
