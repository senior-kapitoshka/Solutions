#include <sstream>
#include <numeric>
#include <chrono>
int timed_reading(int m, const std::string &tx)
{
  std::stringstream ss(tx);
  int res=0;
  for(std::string w;std::getline(ss,w,' ');){
    int a=std::accumulate(w.begin(),w.end(),0,[](auto sum, auto c){
      return sum+=isalpha(c)?1:0;
    });
    if(a<=m && a!=0) ++res;
  }
  return res;
}

//////////////////////
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/algorithm/count_if.hpp>
#include <iterator>
#include <sstream>
#include <string>
#include <cctype>
#include <chrono>

int timed_reading(int maxLength, const std::string &text)
{
  std::istringstream iss(text);
  return ranges::accumulate(std::istream_iterator<std::string>(iss),
                            std::istream_iterator<std::string>(),
                            0,
                            [maxLength] (int acc, const auto& word)
                            {
                              const int alphaChars = (int)ranges::count_if(word, ::isalpha);
                              return acc + (alphaChars && alphaChars <= maxLength);
                            });
}

//////////////////////
#include <chrono>
#define MW w += l && l <= maxLength
int timed_reading( int maxLength, const std::string& text ) {
  int w{}, l{};
  for ( char c : text )
    if ( !isalpha( c ) ) MW, l = 0;
    else ++l;
  return MW;
}

///////////////////
#include <chrono>

int timed_reading(size_t ml, std::string s)
{
	s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !(std::isalpha(c) || std::isspace(c)); }), s.end());
	std::stringstream ss(s);
	std::string t;
	int c{};
	while (ss >> t) if (t.size() <= ml) ++c;
	return c;
}

/////////////////
#include <regex>

int timed_reading(const int maxLength, const std::string& text) {
    static const std::regex word{ R"(\w+)" };
    return std::count_if(
        std::sregex_token_iterator{ text.cbegin(), text.cend(), word },
        std::sregex_token_iterator{},
        [&maxLength](const std::string& s) { return s.size() <= maxLength; }
    );
}

/////////////////
#include <chrono>

int timed_reading(size_t ml, std::string s)
{
	s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !(std::isalpha(c) || std::isspace(c)); }), s.end());
	std::stringstream ss(s);
	return std::count_if(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>(), [=](std::string x) { return x.size() <= ml; });
}

//////////

