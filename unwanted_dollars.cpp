#include <algorithm>
using namespace std;

double money_value(const string &s)
{
  std::string t;
  std::copy_if(s.begin(),s.end(),std::back_inserter(t),[](auto& c){
    return isdigit(c) || c=='.' || c=='-';
  });
  if(t.empty() || std::none_of(t.begin(),t.end(),[](auto& c){return isdigit(c);})|| t=="0") return 0.0;
  t=t.substr(t.find_first_not_of('0'));
 return std::stod(t);
}
///////////
#include <regex>
#include <stdexcept>
#include <string>

double money_value(const std::string &s) {
    std::smatch match_result{};
    static const std::regex extract_number{ R"#(^ *-? *\$? *-? *([\d ]*\.?[\d ]*)$)#" };
    std::regex_match(s, match_result, extract_number);
    if (match_result.size() != 2) {
        return 0.0;
    }
    else {
        try {
            auto abs_money = std::stod(match_result.str(1));
            if (s.find('-') != std::string::npos) {
                return -1 * abs_money;
            }
            else {
                return abs_money;
            }
        }
        catch (const std::invalid_argument&) {
            return 0.0;
        }
    }
}
////////////
using namespace std;
#include <string>

double money_value(const string &s)
{
string buffer(s);
buffer.erase(std::remove(buffer.begin(), buffer.end(), '$'), buffer.end()); 
buffer.erase(std::remove(buffer.begin(), buffer.end(), ' '), buffer.end()); 

return atof(buffer.c_str()); 
}

//////////////
using namespace std;
double money_value(const string &s)
{
     string temp = s;
		 temp.erase(remove_if(temp.begin(), temp.end(), [](unsigned char c) -> bool {return !isdigit(c) && c!='.' && c!='-';}), temp.end());
		 return (none_of(temp.begin(), temp.end(), [](unsigned char c){ return isdigit(c); } )) ? 0.0 : stod(temp);
}
////////////
#include <string>

double money_value(const std::string &s) {
std::cout << s << std::endl;
  std::string xs;
  std::copy_if(
    s.begin(), s.end(), std::back_inserter(xs),
    [](char c){ return c != '$' && !isspace(c); }
  );
  try {
     return std::stod(xs);
   } catch (...) {
     return 0;
   }
}
/////////////
