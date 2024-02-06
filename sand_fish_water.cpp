#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

int sum_of_a_beach(std::string s)
{
  std::cout<<s<<"\n";
  transform(s.cbegin(),s.cend(),s.begin(),[](auto& c)
            {return tolower(c);});
  std::vector<std::string> vs={"sand", "water", "fish", "sun"};
  int sum=0;
  for(auto&& i:vs){
    if(s.find(i)!=s.npos){
    for(size_t j=0;j<=s.size()-i.size();++j){
      if(s.substr(j,i.size())==i) 
        ++sum;
    }
    }
  }
  return sum;
  
}
////////////////////////
int sum_of_a_beach(std::string s)
{
  std::transform(s.cbegin(), s.cend(), s.begin(), tolower);
  int i = 0, sum = 0;
  for (auto e : {"sand", "sun", "fish", "water"})
    for (auto pos = 0; (i = s.find(e, pos)) != std::string::npos; pos = i + 1, ++sum);

  return sum;
}
///////////////////////////
int sum_of_a_beach( std::string s ) {
  for ( char& c : s ) c = tolower( c );
  int c{};
  for ( const auto& e : { "sand", "water", "fish", "sun" }) {
    size_t i{};
    while (( i = s.find( e, i )) != s.npos ) ++c, ++i;
  }
  return c;
}
/////////////////////
#include <string>
#include <regex>

int sum_of_a_beach(std::string s)
{
  std::regex re("sand|water|fish|sun", std::regex_constants::icase);
  return std::distance(std::sregex_iterator(s.begin(), s.end(), re), {});
}