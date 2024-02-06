#include <vector>
#include <string>
#include <sstream>

std::vector<std::string>filter(const std::string& s, int n){
  std::stringstream ss;
  ss.str(s);
  std::vector<std::string>res;
  for(std::string w;std::getline(ss,w,' ');){
    if((int)w.size()>n)res.push_back(std::move(w));
  }
  return res;
}

std::vector<std::string> filter_long_words(const std::string& sentence, int n) {
  return filter(sentence,n);
}

/////////////////////////
#include <vector>
#include <string>
#include <istream>

std::vector<std::string> filter_long_words(const std::string& sentence, int n) {
  std::vector<std::string> r;
  std::istringstream ss(sentence);
  std::string s;
  while (ss >> s) if (s.size() > n) r.push_back(s);
  return r;
}
////////////////////////
#include <vector>
#include <string>
#include <regex>

std::vector<std::string> filter_long_words(const std::string& sentence, int n) {
  const std::regex r(std::string("\\w{") + std::to_string(n + 1) + ",}+");
  return std::vector<std::string>(
      std::sregex_token_iterator(sentence.cbegin(), sentence.cend(), r, 0),
      std::sregex_token_iterator()
    );
}
/////////////////////////
#include <vector>
#include <string>

std::vector<std::string> filter_long_words(const std::string& sentence, const int n) {
    std::vector<std::string> res;
  
    std::istringstream iss{ sentence };
    std::copy_if(
        std::istream_iterator<std::string>{ iss },
        std::istream_iterator<std::string>{},
        std::back_inserter(res),
        [n](const std::string& s) { return s.size() > n; }
    );

    return res;
}