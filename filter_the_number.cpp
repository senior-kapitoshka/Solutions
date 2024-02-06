#include <string>


long long filter_string(const std::string &val)
{
  std::cout<<val<<"\n";
    string a;
    
    for_each(val.begin(),val.end(),[&a](auto& c){
      if(isdigit(c)) a+=c;
    });

  char* end;
  return strtol(a.data(),&end,10);
  
}

//////////////////////////

#include <string>
#include <regex>
long long filter_string(const std::string &value)
{
  std::regex r("[^0-9]+");
  
  std::string ans = std::regex_replace(value,r,"");
  
  return std::stoll(ans); // complete this function :)
}
/////////////////////////////
#include <string>

long long filter_string(const std::string& value) {
    long long res = 0;
    for(const char c : value) {
        if(!std::isdigit(c)) continue;
        res = res * 10 + c - '0';
    }
    return res;
}
///////////////////////////////
#include <string>

long long filter_string(const std::string &v)
{
  std::string res;
  std::copy_if(v.begin(), v.end(), std::back_inserter(res), ::isdigit);
  return std::stoll(res);
}
/////////////////////////////
