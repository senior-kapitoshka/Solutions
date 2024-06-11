#include <fmt/format.h>
#include <algorithm>
#include <set>

class Printer
{
public:
    static std::string printerError(const std::string &s){
      return fmt::format("{}/{}",std::count_if(s.begin(),s.end(),[](auto& c){
        return c>109;
      }),s.size());
    }
};