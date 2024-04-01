#include <string>

int largest_five_digits(const std::string &dig)
{
    std::string s=dig.substr(0,5);
  int res=std::stoi(s);
    for(size_t i=0,j=i+5;i<dig.size()-4;++i){
      res=std::max(std::stoi(dig.substr(i,j)),res);
    }
  return res;
}