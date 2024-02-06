#include <regex>
class CamelCaseTranslator
{
  public: static std::string toUnderScore(std::string s)
  {
   std::regex re("([A-Z]|([0-9]+))");
   std::string x = std::regex_replace(s, re, "_$&");
    std::regex r("(__)");
   std::string y = std::regex_replace(x, r, "_");
    if(s.front()=='_') return y;
    else y.erase(0,1);
    return y;
  };
};

/////////////////////////////
#include <regex>
#include <string>

using namespace std;
class CamelCaseTranslator
{
  public: static std::string toUnderScore(std::string s)
  {
    return regex_replace(regex_replace(s,regex("\\B(\\d+|[A-Z])"), "_$1"), regex("__"), "_");
  };
};
////////////////////////
#include <bits/stdc++.h>
using namespace std;
class CamelCaseTranslator
{
  public: static std::string toUnderScore(std::string s)
  {
    regex re1(R"(^((.+?)[^_|\d])([0-9]+|[A-Z]+))");
    regex re2(R"(([\d])([A-Z]))");
    
    string ans=regex_replace(s,re1,"$1_$3");
    while(regex_search(ans,re1))ans=regex_replace(ans,re1,"$1_$3");
    ans=regex_replace(ans,re2,"$1_$2");
    
    return ans;
  };
};
////////////////////////
#include <algorithm>
#include <regex>

class CamelCaseTranslator {
public:
  static std::string toUnderScore(std::string s) {
    std::reverse(s.begin(), s.end());
    std::string r = std::regex_replace(s, std::regex("([A-Z](?!_|$)|\\d(?!_|\\d|$))"), "$&_");
    std::reverse(r.begin(), r.end());
    return r;
  }
};
////////////////
#include <string>
#include <regex>

class CamelCaseTranslator
{
public: 
    static std::string toUnderScore(std::string s)
    {
        std::regex first("([a-zA-Z])(?=[0-9A-Z])");
        std::regex second("([0-9])(?=[A-Z])");
        std::string out = std::regex_replace(s, first, "$1_");
        std::string result = std::regex_replace(out, second, "$1_");
        return result; 
    }
};
/////////////////////
/* ---------JAVA-----------
 
interface CamelCaseTranslator {
  static String toUnderScore(String name) {
    return name.replaceAll("(?<=[^_-])_?(?=[A-Z])|(?<=[^\\d_])_?(?=\\d)", "_");
  }
}*/

///  /////////////
///  /
template<typename T>
struct CamelCaseTranslatorSpec {
	static auto to_underscore(T const& s) {
		std::basic_string_view sv = s;
		using ChTraits = typename decltype(sv)::traits_type;
		constexpr auto SPLIT = ChTraits::to_char_type('_');
		enum class PrevKind {
			Split,
			Alpha,
			Digit,
		} prev_kind = PrevKind::Split;
		std::basic_string<typename ChTraits::char_type> res;
		res.reserve(sv.length());
		for (auto ch : sv) {
			auto chi = ChTraits::to_int_type(ch);
			if (ch == SPLIT) {
				prev_kind = PrevKind::Split;
			} else if (std::isdigit(chi)) {
				if (prev_kind != PrevKind::Split && prev_kind != PrevKind::Digit) {
					res.push_back(SPLIT);
				}
				prev_kind = PrevKind::Digit;
			} else {
				if (std::isupper(chi) && prev_kind != PrevKind::Split) {
					res.push_back(SPLIT);
				}
				prev_kind = PrevKind::Alpha;
			}
			res.push_back(ch);
		}
		return res;
	}
};

template<typename Ch>
struct CamelCaseTranslatorSpec<std::basic_string<Ch>> {
	static auto to_underscore(std::basic_string<Ch> const& s) {
		return CamelCaseTranslatorSpec<std::basic_string_view<Ch>>::to_underscore(static_cast<std::basic_string_view<Ch>>(s));
	}
};

struct CamelCaseTranslator {
	template<typename T>
	static auto toUnderScore(T const& s) {
		return CamelCaseTranslatorSpec<T>::to_underscore(s);
	}
};