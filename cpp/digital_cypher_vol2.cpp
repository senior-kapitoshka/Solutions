#include <algorithm>

using namespace std;
class Kata
{
public:
	static string Decode(vector<int> code, int n)
	{
		std::string res;
    std::string k=std::to_string(n);
    std::transform(code.begin(),code.end(),std::back_inserter(res),[i=0,k](auto& c)mutable{
      return char('a'+((c-(k[(i++)%k.size()]-'0'))-1));
    });
    return res;
	}
};

