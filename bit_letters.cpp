#include <bitset>
#include <algorithm>
std::string bitLetter(const std::vector<unsigned char> n){
  std::string res;
  res.reserve(n.size());
  std::for_each(n.begin(),n.end(),
                [&res](auto& c){
                  std::string t=std::bitset<8>(c).to_string();
                  res+=t.substr(0,2)=="01"?" ":"";
                  res+=t[2]=='0'?tolower((char)(97+std::bitset<5>(t.substr(3)).to_ulong())):
                  toupper((char)(97+std::bitset<5>(t.substr(3)).to_ulong()));
                  res+=t.substr(0,2)=="10"?",":
                  t.substr(0,2)=="11"?".":"";
      
                });
  return res;
}

////////////////////
std::string bitLetter(const std::vector<unsigned char>& bytes) {
    std::string result;
    for (auto c : bytes) {
        if ((c >> 6) == 1) result.push_back(' ');
        result.push_back('A' + (c & 0x3F ^ 0x20));
        if ((c >> 6) == 2) result.push_back(',');
        if ((c >> 6) == 3) result.push_back('.');        
    }
    return result;
}

/////////////////////
#include <string>
#include <vector>
std::string bitLetter(const std::vector<unsigned char> &v) {
	std::string res,
		        M[] = {""," ",",","."};
	for (unsigned char c : v)
		res += (c>>6 == 1 ? M[1] : "")
		       +std::string(1,(c & 0x1f) + (c & 0x20 ? 'A' : 'a'))
		       +(c>>6 > 1 ? M[c>>6]: "");

	return res;
}

////////////////////
#include <numeric>

using namespace std;

string bitLetter(const vector<unsigned char> n)
{
  return accumulate(n.begin(), n.end(), string(""), [] (const string &acc, unsigned char c) {
    string res = ((c>>6) == 1) ? " " : "";
    res.push_back((c&31)+((c&32) ? 'A' : 'a'));
    return acc + res + (((c>>6) == 2) ? "," : ((c>>6) == 3) ? "." : "");
  });
}
/////////////////
