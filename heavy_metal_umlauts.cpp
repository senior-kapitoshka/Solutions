#include <algorithm>
#include <regex>
#include <unordered_map>
#include <fmt/format.h>

void replac(std::string& s,std::string& rx,std::string& um){
  std::regex r(rx);
  s=std::regex_replace(s,r,um);
}

std::string heavyMetalUmlauts(std::string bT)
{
  std::unordered_map<char,std::string>dict={{'A',"\u00c4"},{'E', "\u00cb"},
                                           {'I' ,"\u00cf"},{'O',"\u00d6"},
                                           {'U', "\u00dc"},{'Y',"\u0178"},
                                           {'a',"\u00e4"},{'e',"\u00eb"},
                                           {'i',"\u00ef"},{'o',"\u00f6"},
                                           {'u',"\u00fc"},{'y',"\u00ff"}};
  std::string res=bT;
  std::for_each(bT.begin(),bT.end(),[&res,&dict](auto& c){
    if(dict.count(c)){
      std::string rx=fmt::format("[{}]",c);
      replac(res,rx,dict[c]);
    }
  });
    return res;
}
/////////////////////////////
std::string meAtalize(const char c) {
    switch(c) {
        case 'A': return "Ä";
        case 'O': return "Ö";
        case 'a': return "ä";
        case 'o': return "ö";
        case 'E': return "Ë";
        case 'U': return "Ü";
        case 'e': return "ë";
        case 'u': return "ü";
        case 'I': return "Ï";
        case 'Y': return "Ÿ";
        case 'i': return "ï";
        case 'y': return "ÿ";
    }
    return std::string(1, c);
}

// \m/
std::string heavyMetalUmlauts(const std::string& boringText) {
    std::ostringstream oss;
    std::transform(
        boringText.cbegin(), boringText.cend(),
        std::ostream_iterator<std::string>{ oss },
        meAtalize
    );
    return oss.str();
}
////////////////////////
std::string heavyMetalUmlauts(std::string boringText)
{
  std::string n = "AEIOUYaeiouy";
  std::string m = "ÄËÏÖÜŸäëïöüÿ";
  std::string r = "";
  size_t p;
  for (const char& c: boringText) {
    p = n.find(c);
    p == std::string::npos ? r += c : r+= m.substr(p*2,2);
  }
  return r;
}
//////////////////////
std::string heavyMetalUmlauts(std::string boring) {
  std::stringstream ss;
  std::map<char, std::string> m = {
    { 'A', "Ä" }, { 'E', "Ë" }, { 'I', "Ï" },
    { 'O', "Ö" }, { 'U', "Ü" }, { 'Y', "Ÿ" },
    { 'a', "ä" }, { 'e', "ë" }, { 'i', "ï" },
    { 'o', "ö" }, { 'u', "ü" }, { 'y', "ÿ" }
  };
  for (auto &c : boring) {
    if (m.find(c) != m.end())
      ss << m[c];
    else
      ss << c;
  }
  return ss.str();
}
//////////////////
#include <range/v3/numeric/accumulate.hpp>
#include <unordered_map>
#include <string_view>
#include <string>

std::unordered_map<char, std::string_view> unrocked = {
  { 'A', "\u00c4" }, { 'E', "\u00cb" }, { 'I', "\u00cf" }, 
  { 'O', "\u00d6" }, { 'U', "\u00dc" }, { 'Y', "\u0178" },
  { 'a', "\u00e4" }, { 'e', "\u00eb" }, { 'i', "\u00ef" },
  { 'o', "\u00f6" }, { 'u', "\u00fc" }, { 'y', "\u00ff" }
};

std::string heavyMetalUmlauts(const std::string& boringText)
{
  return ranges::accumulate(boringText, std::string{}, [] (std::string& acc, char c) 
                            {
                              const auto seekIter = unrocked.find(c);
                              if (seekIter != unrocked.end()) { return acc += (seekIter->second).data(); }
                              else { return acc += c; }
                            });
}
