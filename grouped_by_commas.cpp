#include <string>
#include <algorithm>

std::string group_by_commas(int n)
{
  std::string s=std::to_string(n);
  std::reverse(s.begin(),s.end());
  int i=0;
  std::string res;
  std::for_each(s.begin(),s.end(),[&i,&res](auto& c){
    if(i==3){
      i=0;
      res+=',';
    }
    res+=c;
    ++i;
  });
  std::reverse(res.begin(),res.end());
  return res;
}

//////////////////////////
#include <string>

std::string group_by_commas(int n)
{
  std::string result = std::to_string(n);

	for (int i = result.size(); i > 3;)
	{
		i -= 3;
		result.insert(i, ",");
	}

	return result;
}
///////
#include <string>
#include <locale>
using namespace std;

struct rep : std::numpunct<char>
{
  rep() {}
  string do_thousand_sep() const { return "\03";}
  string do_grouping() const { return "\03";}
};
string group_by_commas(int n)
{
  stringstream ss;
  ss.imbue(std::locale(ss.getloc(), new rep()));
  
  ss  << n;
  return ss.str(); 
}