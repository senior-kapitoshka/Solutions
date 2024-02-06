#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> uniq(const std::vector<std::string> &v) {
  std::vector<std::string>res(v.begin(),v.end());
  while(true){
    auto it=adjacent_find(res.begin(),res.end());
    if(it==res.end())break;
    else res.erase(it);
  }
  return res;
}
/////////////////////////////////////////
#include <string>
#include <vector>
#include <algorithm>


std::vector<std::string> uniq(const std::vector<std::string> &v)
{
	std::vector<std::string> res;
	std::unique_copy(v.begin(), v.end(), std::back_inserter(res));
	return res;
}
/////////////////////////////
#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> uniq(std::vector<std::string> v) {
  v.erase(std::unique(v.begin(), v.end()), v.end());
  return v;
}
////////////////