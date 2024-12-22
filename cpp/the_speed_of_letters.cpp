#include <string>

std::string speedify(const std::string &in)
{
  if(in.empty())return in;
  size_t n=static_cast<size_t>(tolower(*std::max_element(in.begin(),in.end()))-97);
  size_t x=in.size()+n;
  std::string res(x,' ');
  for(size_t i=0;i<in.size();++i){
      res[i+((tolower(in[i]))-97)]=in[i];
  }
    return res.substr(0,res.find_last_not_of(' ')+1);
}