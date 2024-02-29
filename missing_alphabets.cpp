#include <string>
#include <map>
#include <algorithm>

void prepare(std::map<char,int>&mp){
  using namespace std::literals;
  std::string_view s="abcdefghijklmnopqrstuvwxyz"sv;
  std::for_each(s.begin(),s.end(),[&mp](auto& c){
    return mp[c]=0;
  });
}

std::string missing_alphabets(const std::string &s) {
  std::string res;
  std::map<char,int> d;
  prepare(d);
  std::for_each(s.begin(),s.end(),[&d](auto& c){
    ++d[c]; 
  });
  int max=(*std::max_element(d.begin(),d.end(),[]
                            (auto& lhs,auto &rhs)
                            {return lhs.second<rhs.second;})).second;
  std::for_each(d.begin(),d.end(),[max,&res](auto& p){
    res+=p.second==max?"":std::string(max-p.second,p.first);
  });
  return res;
}

////////////////////////
#include <algorithm>
#include <iterator>
#include <map>
#include <string>

std::string missing_alphabets(const std::string& s) {
    std::map<char, std::size_t> counter;
    for (const char c : s) ++counter[c];

    const std::size_t max =
        s.empty() ? 0
                  : std::max_element(counter.cbegin(), counter.cend(),
                                     [](const auto& l, const auto& r) {
                                         return l.second < r.second;
                                     })
                        ->second;

    std::ostringstream res;
    for (const char c : "abcdefghijklmnopqrstuvwxyz") {
        if(!c) continue;
        const std::size_t count =
            counter.find(c) == counter.cend() ? 0 : counter.at(c);
        std::fill_n(std::ostream_iterator<char>{res}, max - count, c);
    }

    return res.str();
}