 
std::string correct_it(std::string str) {
  std::string s;
  
  std::unique_copy(str.begin(),str.end(),std::back_inserter(s),
                   [](char c1, char c2) { return c1 == ' ' && c2 == ' '; });
  for(size_t i=0;i<s.size();++i){
    
    if(s[i]=='.'){
      if(s[i+1]!=' '){
        if(islower(s[i+1])){
          s[i+1]=toupper(s[i+1]);
          s.insert(i+1 ," ");
        }else {
            s.insert(i+1 ," ");
        }
      } else if(s[i+1]==' ' && islower(s[i+2])){
        s[i+2]=toupper(s[i+2]);
      }
    }
    
  }
  if(s.front()==' '||s.back()==' '){
    auto first=s.find_first_not_of(' ');
    auto last=s.find_last_not_of(' ');
    if(s.front()==' '&& s.back()==' '){
      s=s.substr(first,(last-first+1));
    }else if(s.front()!=' '&& s.back()==' '){
      s=s.substr(0,(last+1));
    }else if(s.front()==' '&& s.back()!=' '){
      s=s.substr(first);
    }
   
  }
   if(s.back()!='.') s.push_back('.');
    if(islower(s.front())) s[0]=toupper(s[0]);
  for(size_t i=1;i<s.size();++i){
    if(isupper(s[i])&& s[i-2]!='.'){
      s.insert(i-1,".");
    }
      
  }  
  
  return s;
    
  
} 
///////////////////////////////
#include <sstream>

std::string correct_it(std::string str) {
  std::string t;
  for (const char& c: str) c == '.' ? t += ". " : t += c;
  std::string r;
  std::stringstream ss(t);
  std::string p,c,n;
  ss >> p;
  ss >> c;
  p[0] = std::toupper(p[0]);
  r = p;
  while (ss) {
    ss >> n;
    if (p.back() == '.') c[0] = std::toupper(c[0]);
    if (isupper(n[0]) && c.back() != '.') c = c + '.';
    r += ' ' + c;
    p = c;
    c = n;
  }
  if (r.back() != '.') r += '.';
  return r;
}
/////////////////////////////
#include <regex>
std::string correct_it(std::string str) {
  str = std::regex_replace(std::regex_replace(std::regex_replace(str,std::regex("^ +| +$|( ) *"),"$1"),std::regex(" +([A-Z])|\\.([^ ])"),". $1$2"),std::regex("([^.])$|\\. *\\."),"$1.");
  for(int i=0; i<str.size(); i++) if((i==0||(i>=2&&str[i-2]=='.'))&&str[i]>='a'&&str[i]<='z') str[i]=std::toupper(str[i]);
  return str;
}
//////////////////////////
#include <cctype>
#include <regex>

// https://stackoverflow.com/a/37516316
template<class BidirIt, class Traits, class CharT, class UnaryFunction>
std::basic_string<CharT> regex_replace(BidirIt first, BidirIt last,
    const std::basic_regex<CharT,Traits>& re, UnaryFunction f)
{
    std::basic_string<CharT> s;
    typename std::match_results<BidirIt>::difference_type positionOfLastMatch = 0;
    auto endOfLastMatch = first;
    auto callback = [&](const std::match_results<BidirIt>& match)
    {
        auto positionOfThisMatch = match.position(0);
        auto diff = positionOfThisMatch - positionOfLastMatch;
        auto startOfThisMatch = endOfLastMatch;
        std::advance(startOfThisMatch, diff);
        s.append(endOfLastMatch, startOfThisMatch);
        s.append(f(match));
        auto lengthOfMatch = match.length(0);
        positionOfLastMatch = positionOfThisMatch + lengthOfMatch;
        endOfLastMatch = startOfThisMatch;
        std::advance(endOfLastMatch, lengthOfMatch);
    };
    std::regex_iterator<BidirIt> begin(first, last, re), end;
    std::for_each(begin, end, callback);
    s.append(endOfLastMatch, last);
    return s;
}

std::string correct_it(std::string str) {
    static const std::regex re_spaces{R"(  +)"},
        re_dot{R"( *\. *)"},
        re_begin_sentence{R"(\. ([a-z]))"},
        re_end_sentence{R"(\.? ([A-Z]))"},
        re_trim{R"(^[ .]*(.*?)\.? *$)"};
    str = std::regex_replace(str, re_spaces, " ");
    str = std::regex_replace(str, re_dot, ". ");
    str = regex_replace(begin(str), end(str), re_begin_sentence, [](const auto& match){
        return std::string(". ") + static_cast<char>(std::toupper(match[1].str()[0]));
    });
    str = std::regex_replace(str, re_end_sentence, ". $1");
    str = std::regex_replace(str, re_trim, "$1.");
    if (!str.empty()) str[0] = static_cast<char>(std::toupper(str[0]));
    return str;
}
/////////////////////////////////
