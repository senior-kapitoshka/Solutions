
#include <regex>

std::string solve(std::string eq){
	static std::regex reg("[\\w]+|[\\-*+/]");
  auto rb = std::sregex_iterator(eq.begin(),eq.end(),reg);
  auto re = std::sregex_iterator();
  std::string res;
  for(auto it=rb;it!=re;++it){
    std::smatch m = *it;
    res.insert(0,m.str());
  }
  return res;
}
///////////////////////
#include <regex>
#include <numeric>

std::string solve(const std::string& eq){
    static const std::regex term{ R"(\*|\/|-|\+|\d+|\w+)" };
    return std::accumulate(
        std::sregex_token_iterator{ eq.cbegin(), eq.cend(), term },
        std::sregex_token_iterator{},
        std::string{},
        [](const std::string& acc, const std::string& match) {
            return match + acc;
        }
    );
}
/////////////////////
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/view/reverse.hpp>
#include <range/v3/view/istream.hpp>
#include <range/v3/view/iota.hpp>
#include <sstream>
#include <string_view>
#include <string>
#include <vector>

inline constexpr std::string_view gk_operators = "*+-/";
inline const char gk_delimiter = ' ';

void accumulateWith(std::string source, std::vector<std::string>& outArgs, std::vector<char>& outOpers)
{
  outOpers = ranges::accumulate(source, std::vector<char>{}, 
                                [] (auto& acc, char& c) -> auto& 
                                { 
                                  const auto seekPos = gk_operators.find(c);
                                  if (seekPos != std::string::npos)
                                  {
                                    acc.push_back(gk_operators[seekPos]);
                                    c = gk_delimiter;
                                  }
                                  return acc;
                                });
  
  std::istringstream iss(source);
  outArgs = ranges::accumulate(ranges::_istream_::istream<std::string>(iss), 
                               std::vector<std::string>{}, [] (auto& acc, auto word) 
                               {
                                 acc.emplace_back(word);
                                 return acc;
                               });
}

std::string reverse(const std::vector<std::string>& arguments, const std::vector<char>& operators)
{
  using namespace ranges;
  return accumulate(views::iota(0, static_cast<int>(operators.size())) | views::reverse,
                    std::string(arguments.back()), [&] (auto& acc, int i) -> auto&
                    {
                      return (acc += operators[i]) += arguments[i];
                    });
}

std::string solve(std::string eq)
{
  std::vector<std::string> arguments; std::vector<char> operators;
  accumulateWith(eq, arguments, operators);
  return reverse(arguments, operators);
}
/////////////////////
using namespace std; 
#include <regex>
#include <vector>
#include <numeric>

string solve(string eq)
{
    static const regex re(R"(\w+|\+|-|\*|/)");
    vector<string> tokens;
    for(sregex_iterator it(eq.begin(), eq.end(), re), end; it != end; ++it) tokens.push_back(it->str());
    return accumulate(tokens.rbegin(), tokens.rend(), string(""));
}
/////////////////
