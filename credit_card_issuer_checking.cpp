#include <regex>
   
using namespace std::literals;
std::string getIssuer(const std::string &n)
{
    std::regex a("^3(4|7)[\\d]{13}$");
    std::regex d("^6011[\\d]{12}$");
    std::regex m("^5(1|2|3|4|5)[\\d]{14}$");
    std::regex v1("^4[\\d]{15}$");
  std::regex v2("^4[\\d]{12}$");
    return std::regex_match(n,a)?"AMEX"s:
    std::regex_match(n,v1)?"VISA"s:
  std::regex_match(n,v2)?"VISA"s:
  std::regex_match(n,d)?"Discover"s:
  std::regex_match(n,m)?"Mastercard"s:
  "Unknown";
  ;
}
////////////////////
#include <regex>

std::string getIssuer(const std::string& number) {
    static const std::regex amex      { R"(^3(4|7)\d{13}$)" };
    static const std::regex discover  { R"(^6011\d{12}$)" };
    static const std::regex mastercard{ R"(^5[12345]\d{14}$)" };
    static const std::regex visa      { R"(^4(\d{12}|\d{15})$)" };
  
    if(std::regex_match(number, amex)) return "AMEX";
    if(std::regex_match(number, discover)) return "Discover";
    if(std::regex_match(number, mastercard)) return "Mastercard";
    if(std::regex_match(number, visa)) return "VISA";
  
    return "Unknown";
}