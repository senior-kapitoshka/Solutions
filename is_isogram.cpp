#include <map>
#include <istream>
bool is_isogram(std::string str) {
  std::cout<<str<<"\n";
  std::map<char,int>mp;
  for(auto&& i:str){
    ++mp[tolower(i)];
  }
  for(auto&& i:mp){
    if(i.second>1) return false;
  }
  return true;

}

////////////////////////////////
bool is_isogram(std::string str) {
  for (int i = 0; i < str.length(); i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (tolower(str[i]) == tolower(str[j]))
			{
				return false;
			}
		}
	}
	return true;
}

/////////////////////////////////////////
#include <set>

bool is_isogram(const std::string& str) {
    std::set<char> chars;
    std::transform(cbegin(str), cend(str), std::inserter(chars, end(chars)),
        [](const unsigned char c){ return std::tolower(c); });
    return str.size() == chars.size();
}
/////////////////////////////////////////
