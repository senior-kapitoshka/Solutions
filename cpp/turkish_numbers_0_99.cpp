#include <string>
#include <regex>
#include <map>
#include <fmt/format.h>

void helper(std::map<int,std::string>&mp){
  std::string s="0 = sıfır 1 = bir 2 = iki 3 = üç 4 = dört 5 = beş 6 = altı 7 = yedi 8 = sekiz 9 = dokuz 10 = on 20 = yirmi 30 = otuz 40 = kırk 50 = elli 60 = altmış 70 = yetmiş 80 = seksen 90 = doksan";
  std::regex r("([\\d]{1,2})[\\s]{1}[=]{1}[\\s]{1}([\\w|ö|ü|ç|ı|ş]+)");
  std::smatch m;
  auto rb=std::sregex_iterator(s.begin(),s.end(),r);
  auto re=std::sregex_iterator();
  for(auto it=rb;it!=re;++it){
    std::string t=it->str();
    std::regex_match(t,m,r);
    mp[std::stoi(m[1])]=m[2];
  }
}

std::string getTurkishNumber(unsigned int n) {
  std::map<int,std::string>mp;
  helper(mp);
  return (n<10||n%10==0)?mp[n]:fmt::format("{} {}",mp[(n/10)*10],mp[n%10]);
}

//////////////////