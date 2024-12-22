#include <string>
#include <algorithm>
std::string encrypt(std::string text, int rule) {

  
  for(size_t i=0;i<text.size();++i){
    text[i]=text[i]+rule;
  }
  
  return text;
};
///////////////////////////
#include <algorithm>
#include <iterator>
#include <string>

std::string encrypt(const std::string& text, const int rule)
	{
	std::string result;
  result.reserve(text.size());
	std::transform(text.begin(),
	               text.end(),
	               std::back_inserter(result),
	               [&rule](unsigned int character) { return static_cast<unsigned char>((character + rule) % 256); });
	return result;
	}
/////////////////////////////
#include <string>
#include <algorithm>

using namespace std;

string encrypt(string text, int rule) {
    for_each(text.begin(), text.end(), [rule](char &c){ c = (rule + c)%256; });
    return text;
};
////////////////////////
#include <string>
std::string encrypt(std::string text, int rule) {
  for (uint pos = 0; pos < text.length(); pos++) {
    text.at(pos) = (char)(((int)text.at(pos) + rule) % 256);
  }
  return text;
};
////////////////////////////