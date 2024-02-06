std::string replaceAll(std::string str) {
  auto i=find(str.begin(),str.end(),'#');
  if(i==str.end())return str;
  std::string ans(str.begin(),i);
    return ans;
}
///////////////////////////////////////////

std::string replaceAll(std::string str) {
  return str.substr(0, str.find('#'));
}
\////////////////////////////

std::string replaceAll(std::string str) 
{
  size_t found = str.find_first_of('#', 0);
  return found != std::string::npos ? str.substr(0, found) : str;
}

//////////////////////////////////

#include <algorithm>

std::string replaceAll(std::string str) 
{
	auto it = std::find(str.begin(), str.end(), '#');
	str.erase(it, str.end());
	return str;
}

///////////////////////////////////


std::string replaceAll(std::string_view str)
{
  return {std::begin(str), std::find(std::begin(str), std::end(str), '#')};
}