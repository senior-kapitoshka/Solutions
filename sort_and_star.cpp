#include <vector>
#include <string>
#include <algorithm>

std::string twoSort(std::vector<std::string> s)
{
  auto it=std::min_element(s.begin(),s.end(),[](auto& lhs, auto& rhs){
    return std::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
  });
  std::string ns;
  std::for_each((*it).begin(),(*it).end(),[&ns,i=0,sz=(int)(*it).size()-1](auto& c)mutable{
    ns+=c;
    if(i++!=sz)ns+="***";
  });
    return ns;
}

/////////////////////
#include <regex>

std::string twoSort(std::vector<std::string> s)
{
    return std::regex_replace(*std::min_element(s.begin(), s.end()), std::regex{"(?!^)(.)"}, "***$1");
}

////////////////////
