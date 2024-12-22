#include <string>

std::string repeat_str(size_t r, const std::string& str) {
  std::string res;
  while(r){
    res.insert(0,str);
    --r;
  }
  return res;
}

///////////////
#include <string>

std::string repeat_str(const size_t repeat, const std::string& str) {
    std::ostringstream oss;
    std::generate_n(std::ostream_iterator<std::string>{ oss }, repeat, [&str]{ return str; });
    return oss.str();
}