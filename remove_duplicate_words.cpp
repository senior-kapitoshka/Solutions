#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>


 std::vector<std::string> proc(const std::string& s){
  std::stringstream ss;
  ss.str(s);
  std::vector<std::string> vs;
  for(std::string w;std::getline(ss,w,' ');){
    if(auto it=find(vs.begin(),vs.end(),w);it==vs.end()){
      vs.push_back(std::move(w));
    }
  }
  return vs;
}

auto w=[](const std::string& lhs, const std::string& rhs){
  return  std::move(lhs)+" "+std::move(rhs); 
                                                          };

std::string removeDuplicateWords(const std::string& str)
{
  if(str.empty()) return "";
    std::vector<std::string> vs= proc(str);
     std::string ans;
  ans=std::accumulate(next(vs.begin()),vs.end(),vs.front(),w);
  return ans;
}
///////////////////////
#include <string>
#include <sstream>
#include <unordered_set>

std::string removeDuplicateWords(const std::string& str)
{
	std::string result;
	std::unordered_set<std::string> cached;
	std::stringstream ss{ str };
	
	for (std::string word; ss >> word;)
	{
		if (cached.find(word) == cached.end())
		{
			if (cached.size() > 0)
				result.append(" ");
			result.append(word);
			cached.insert(std::move(word));
		}
	}
	return result;
}
//////////////////
