#include <string>
#include <sstream>
#include <vector>
int find_short(std::string str)
{
  std::stringstream ss(str);
  std::vector<std::string>vs;
  for(std::string w;ss>>w;){
    vs.push_back(std::move(w));
  }
  sort(vs.begin(),vs.end(),[](auto& a,auto& b){
    return a.size()<b.size();
  });
  return (int)vs[0].size();
}

////////////////////////
int find_short(const std::string &str)
{
    std::istringstream inp(str);
    std::string s;
    int len = -1;
    while (std::getline(inp, s, ' '))
        if (s.length() < len)
            len = s.length();
    return len;
}

///////////////////////
int find_short(std::string str)
{
    std::istringstream iss(str);
    std::vector<std::string> vec{ std::istream_iterator<std::string>(iss), {} };
    return std::min_element(vec.begin(), vec.end(), [](const std::string& s1, const std::string& s2)
     { return s1.length() < s2.length(); })->length();
}
///////////////////////////
#include <sstream>

int find_short(std::string str) {
  std::stringstream ss(str);
  auto buff = std::string();
  auto shorter = std::numeric_limits<size_t>::max();
  while (ss >> buff)
    shorter = min(shorter, buff.size());
  return shorter;
}

////////////////////////
