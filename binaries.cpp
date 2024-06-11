#include <string>
#include <bitset>
#include <algorithm>

namespace coding
{
    std::string code(const std::string &sg)
    {
        std::string res;
      std::for_each(sg.begin(),sg.end(),[&res](auto& c){
        std::string t=std::bitset<4>(c-'0').to_string();
        t=c=='0'?"0":t.substr(t.find_first_of('1'));
        std::string d(t.size()-1,'0');
        res+=d+"1"+t;
      });
      return res;
    }
    std::string decode(const std::string &str)
    {
        std::string res;
      std::string t=str;
      while(!t.empty()){
        auto pos=t.find_first_of('1');
        size_t k=pos+1;
        std::string d=t.substr(pos+1,k);
        res+=std::to_string(std::bitset<4>(d).to_ulong());
        t=t.substr(pos+1+k);
      }
      return res;
    }
}
///////////////////////////////
#include <algorithm>
#include <iterator>
#include <map>
#include <regex>
#include <sstream>
#include <string>

namespace coding {
std::string code(const std::string& str) {
    std::ostringstream oss;

    std::transform(str.cbegin(), str.cend(),
                   std::ostream_iterator<std::string>{oss}, [](const char c) {
                       static const std::map<char, const char*> dict{
                           {'0', "10"},      {'1', "11"},     {'2', "0110"},
                           {'3', "0111"},    {'4', "001100"}, {'5', "001101"},
                           {'6', "001110"},  {'7', "001111"}, {'8', "00011000"},
                           {'9', "00011001"}};

                       return dict.at(c);
                   });

    return oss.str();
}

std::string decode(const std::string& str) {
    static const std::regex data{
        R"(1[01]{1}|01[01]{2}|001[01]{3}|0001[01]{4})"};

    std::ostringstream oss;

    std::transform(std::sregex_iterator{str.cbegin(), str.cend(), data},
                   std::sregex_iterator{}, std::ostream_iterator<char>{oss},
                   [](const std::smatch& s) {
                       static const std::map<std::string, char> dict{
                           {"10", '0'},      {"11", '1'},     {"0110", '2'},
                           {"0111", '3'},    {"001100", '4'}, {"001101", '5'},
                           {"001110", '6'},  {"001111", '7'}, {"00011000", '8'},
                           {"00011001", '9'}};

                       return dict.at(s.str());
                   });

    return oss.str();
}
}
///////////////////////////////
