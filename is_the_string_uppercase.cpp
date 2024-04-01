#include <string>
#include <algorithm>

bool is_uppercase(const std::string &s) {
  std::cout<<s<<"\n";
  return std::all_of(s.begin(),s.end(),[](auto& c){return(!isalpha(c)||isupper(c))||(c==' ');});
}
///////////////
#include <string>
#include <algorithm>

bool is_uppercase(const std::string &s) {
  return std::none_of(s.begin(), s.end(), islower);
}