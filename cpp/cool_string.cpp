#include <string>
#include <algorithm>

bool cool_string(const std::string& s) {
  if(std::any_of(s.begin(),s.end(),[](auto& c){return isdigit(c)||c==' '||!isalpha(c);}))return false;
  return std::adjacent_find(s.begin(),s.end(),[](auto& lhs,auto& rhs)
                            {return (isupper(lhs)&&isupper(rhs))||(islower(lhs)&&islower(rhs));})==s.end();
}
////////////////////
#include <regex>
#include <string>
bool cool_string(const std::string& s) {
  return !(regex_search(s, std::regex("[^A-Za-z]|[A-Z]{2,}|[a-z]{2,}"))); 
}
///////////////
#include <range/v3/algorithm/all_of.hpp>
#include <range/v3/view/subrange.hpp>
#include <range/v3/view/sliding.hpp>
#include <string>
#include <cctype>

bool cool_string(const std::string& s) 
{
  auto iter = s.begin();
  if (!std::isalpha(*iter++)) { return false; }
  return ranges::all_of(ranges::subrange(iter, s.end()) | ranges::views::sliding(2), 
                        [] (const auto& p) { return std::isupper(p[0]) != std::isupper(p[1]); });
}
//////////////
#include <string>
#include <algorithm>
#include <numeric>

bool cool_string(const std::string& s) {

  // it is formed only by Latin letters 
  if (std::any_of(s.begin(),s.end(),[](auto c){return !::isalpha(c);}))
    return false;
  
  // no two lowercase and no two uppercase letters are in adjacent positions
  std::string out;
  std::adjacent_difference(s.begin(),s.end(),std::back_inserter(out),
                 [](auto a,auto b){return ::isupper(a)==::isupper(b)?'+':'-';});

//  return out.find_first_of('+',1)==std::string::npos;
  return std::none_of(std::next(out.begin()),out.end(),[](auto c){return c=='+';});
}
////////////
#include <string>
#include <algorithm>
#include <cctype>

bool cool_string(const std::string& s) {
  return std::all_of(s.begin(), s.end(), isalpha) && 
    std::adjacent_find(s.begin(), s.end(), 
                       [](char i, char j)
                       {return (isupper(i) && isupper(j)) || 
                               (islower(i) && islower(j));}) == s.end();
}