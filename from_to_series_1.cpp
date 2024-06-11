#include <regex>
#include <algorithm>
#include <map>
#include <limits>
#include <cmath>

using namespace std;

vector<string> find_max_range(const vector<string> &rs)
{
  std::map<double,std::vector<std::string>>mp;
  std::for_each(rs.begin(),rs.end(),[&mp](auto& s){
    std::regex d("-?[\\d|.]+");
    auto rb=std::sregex_iterator(s.begin(),s.end(),d);
    auto re=std::sregex_iterator();
    double a=std::numeric_limits<int>::min(),b=std::numeric_limits<int>::min();
    for(auto it=rb;it!=re;++it){
      a==std::numeric_limits<int>::min()?a=std::stod((*it).str()):b=std::stod((*it).str());
    }
    mp[std::abs(a-b)].push_back(s);
  });
    return rs.empty()?std::vector<std::string>{}:(*prev(mp.end())).second; 
}
/////////////////////
#include <regex>
#include <string>
#include <vector>

std::vector<std::string> find_max_range(
    const std::vector<std::string>& ranges) {
    static const std::regex reg_range{
        R"(^from (-?\d+(?:\.\d+)?) to (-?\d+(?:\.\d+)?)$)"};

    std::vector<std::string> res;
    double max = -std::numeric_limits<double>::infinity();
    for (const auto& range : ranges) {
        std::smatch match;
        if (!std::regex_match(range, match, reg_range)) continue;

        const double from = std::stod(match[1].str());
        const double to = std::stod(match[2].str());
        const double dist = std::abs(from - to);

        if (dist > max) {
            res.clear();
            max = dist;
        }

        if (dist == max) {
            res.push_back(range);
        }
    }

    return res;
}
///////////
#include <algorithm>
#include <iterator>
#include <chrono>
#include <tuple>
#include <string_view>
#include <string>
#include <vector>
#include <cmath>

inline const std::string_view gk_patternFrom("from ");
inline const std::string_view gk_patternTo(" to ");

using tsd = std::tuple<const std::string&, const double>;

double calculateRangeDistance(const std::string& textRange)
{
  const size_t fromPos  = textRange.find(gk_patternFrom);
  const size_t toPos    = textRange.find(gk_patternTo);
  if ((fromPos != std::string::npos) && (fromPos != std::string::npos))
  {
    const std::string begin(textRange.begin() + fromPos + gk_patternFrom.size(), textRange.begin() + toPos);
    const std::string end  (textRange.begin() + toPos + gk_patternTo.size(), textRange.end());
    return std::abs(std::stod(end) - std::stod(begin));    
  }
  return 0.0;
}

std::vector<std::string> find_max_range(const std::vector<std::string>& ranges)
{
  if (ranges.empty()) { return {}; }
  
  std::vector<tsd> data;
  std::transform(ranges.begin(), ranges.end(), std::back_inserter(data),
    [] (const std::string& s) { return std::make_tuple(std::ref(s), calculateRangeDistance(s)); });
  
  const double maxIntervalDistance = std::get<const double>(*std::max_element(data.begin(), data.end(),
             [] (const auto& lhs, const auto& rhs) 
             {
                return std::get<const double>(lhs) < std::get<const double>(rhs);
             }));
  
  std::vector<std::string> result;
  std::for_each(data.begin(), data.end(), [maxIntervalDistance, &result] (const auto& t) 
    {
      const auto &[text, value] = t;
      if (value == maxIntervalDistance) { result.push_back(text); }
    });
  return result;
}
//////////////
#include <numeric>
#include <chrono>

std::vector<std::string> find_max_range(const std::vector<std::string> &ranges)
{
    auto range([](auto s) {
        auto i = s.find(' ') + 1;
        auto j = s.find(' ', i);
        auto x = std::stod(s.substr(i, j - i));
        
        i = s.rfind(' ') + 1;
        auto y = std::stod(s.substr(i));
        
        return std::abs(y - x) + 1;
    });
    
    auto max_range = std::accumulate(
        ranges.begin(),
        ranges.end(),
        0.0,
        [&](double acc, auto s) {
            return std::max(acc, range(s));
        });
    
    std::vector<std::string> result;
    std::copy_if(
        ranges.begin(),
        ranges.end(),
        std::back_inserter(result),
        [&, max_range](auto s) {
            return range(s) == max_range;
        });
    
    return result;
}
////////////
