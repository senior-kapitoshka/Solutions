#include <string>

int secondSymbol(const std::string& str, char s) {
  if(str.find(s)==std::string::npos) return -1;
  int c=0;
  int i=0;
  int n=static_cast<int>(str.size());
  while(c<=1){
    if(str[i]==s) ++c;
    ++i;
    if(i==n && c<=1) return -1;
  }
  return i-1;
}

#include <string_view>

int secondSymbol(std::string_view s, char c) {
  auto i = s.find(c);
  return i == s.npos ? -1 : s.find(c, i + 1);
}

#include <string>

int secondSymbol(const std::string& str, char symbol) {
  return str.find(symbol, str.find(symbol) + 1);
}