std::string find_routes (const std::vector<std::pair<std::string, std::string>> &rs) {
  std::list<std::pair<std::string, std::string>>ls;
  ls.push_back(rs[0]);
  while(ls.size()!=rs.size()){
    auto b=find_if(rs.begin(),rs.end(),[&ls](auto p){return ls.back().second==p.first;});
    auto f=find_if(rs.begin(),rs.end(),[&ls](auto p){return ls.front().first==p.second;});
    if(b!=rs.end()) ls.push_back(*b);
    if(f!=rs.end()) ls.push_front(*f);
  }
  std::string ans;
  for(auto i=ls.begin();i!=ls.end();++i){
    auto p=*i;
    ans+=p.first;
    if(i!=ls.end()) ans+=", ";
    if(i==prev(ls.end())) ans+=p.second;
  }
  return ans;
  
}
///////////////////////////////////////
#include <vector>
#include <unordered_map>
#include <string>

std::string find_routes(const std::vector<std::pair<std::string, std::string>>& routes)
{
	std::vector<std::pair<std::string, std::string>> copy;
	std::string out;	
	std::unordered_map<std::string, int> counter;

	for (const auto& [one, two] : routes)
	{
		counter[two]++;
	}
	for (const auto& pair : routes)
	{
		if (counter[pair.first] != 1)
			copy.push_back(pair);
	}

	while (copy.size() < routes.size())
	{
		for (const auto& p : routes)
		{
			if (p.first == copy.back().second)
				copy.push_back(p);
		}
	}

	for (const auto& p : copy)
	{
		out += p.first + ", ";
		if (p == copy.back())
			out += p.second;
	}
	return out;
}
/////////////////////////////////////////
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <algorithm>
#include <sstream>

std::string find_routes (std::vector<std::pair<std::string, std::string>> const &routes)
{
    std::map<std::string, std::string> m(routes.cbegin(), routes.cend());
    std::string start{}, end{};
    for (auto const& [k, v] : routes)
    {
        if (std::find_if(routes.cbegin(), routes.cend(), [&k = k](auto const& p) { return k == p.second; }) == routes.cend())
            start = k;
        if (m.find(v) == m.end())
            end = v;
        if (!start.empty() && !end.empty())
            break;
    }
    std::stringstream ss;
    while (start != end)
    {
        ss << start << ", ";
        start = m[start];
    }
    ss << end;
    return ss.str();
}