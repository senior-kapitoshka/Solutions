#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
std::vector<std::string> ps(const std::string s){
  std::stringstream ss(s);
  std::vector<std::string>vs;
  for(std::string w;ss>>w;){
    vs.push_back(move(w));
  }
  return vs;
}

std::string sortTheInnerContent (const std::string wds,[[maybe_unused]] int length) {
  if(wds.empty()) return std::string("");
  std::cout<<wds<<"\n";
  std::vector<std::string> vs=ps(wds);
  for_each(vs.begin(),vs.end(),[](auto& s){
    if(s.size()>2) std::sort(next(s.begin()),prev(s.end()), std::greater<char>());});
  std::string res;
  int j=0;
   bool fl=false;
  if(wds[0]==' '){
    int i=0;
    while(wds[i]==' '){
      res+=' ';
      ++i;
    }
  }
  for(int i=0;i<length;++i){
     
      if(wds[i]!=' ' && fl==false){
        fl=true;
        res+=vs[j];
        j++;
      }
      else if(wds[i]==' '&& wds[i+1]!=' ' && fl==true) {
        res+=' ';
        fl=false;
      }else if(wds[i]==' '&& wds[i+1]==' ' && fl==true){
        res+=' ';
      }
  }
  std::cout<<res<<"\n";
  return res;

}
////////////////////////////////////////////
#include <cstdlib>
#include <cstring>

int cmp (const void *a, const void *b) { return *(unsigned char*)b - *(unsigned char*)a; }

char* sortTheInnerContent (const char* words, int length) {
  char *sorted = strdup (words), *word = sorted;
  
  for (char *end; *word && ((end = strchr (word, ' ')) || (end = strchr (word, 0))); word = end+!!*end)
    if (end-word > 3) qsort (word+1, end-2-word, 1, cmp);
  
  return sorted;
}
//////////////////////////////////
#include <string>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <functional>


std::string sortTheInnerContent(std::string words, [[maybe_unused]] int length)
{
  static auto isalnum = [] (char c) -> bool { return std::isalnum(c); };
  static auto isspace = [] (char c) -> bool { return std::isspace(c); };

  for (
    auto start = std::find_if(words.begin(), words.end(), isalnum),
       end = std::find_if(start, words.end(), isspace);
    start != words.end();
    start = std::find_if(end, words.end(), isalnum),
       end = std::find_if(start, words.end(), isspace)
  ) {
    if (std::distance(start, end) > 3) {
      std::sort(std::next(start), std::prev(end), std::greater<char>());
    }
  }

  return words;
}
//////////////////////////////

#include <iostream>
#include <regex>
#include <algorithm>

std::string sortTheInnerContent(std::string words, int x)
{
    using si = std::string::iterator;
    std::regex rgx ("(\\s)|(\\w+)");
    std::string res;
    std::regex_token_iterator<si> rend;
    std::regex_token_iterator<si> it (words.begin(), words.end(), rgx);
    auto func = [](char a, char b) ->bool { return a > b; };

    for (; it != rend; ++it)
    {
        std::string buffer = *it;
        if (buffer.length() > 3)
        {
            auto init = ++buffer.begin();
            auto end = (si) &buffer[buffer.length() - 1];
            std::sort (init, end, func);
        }
        res += buffer;
    }
    return res;
}
//////////////////////
std::string sortTheInnerContent (const std::string words, int l) {
    std::string s, r = words;
  
    auto start = words.find_first_not_of(" ");
    auto pos = words.find (" ", start+1);
    while (start != std::string::npos && l) {
        s = pos == std::string::npos ? r.substr (start) : r.substr (start, pos-start);
        if (s.length() >= 4)
            sort(s.begin ()+1, s.begin () + (s.length () - 1), std::greater ());
        r.replace(start, s.length (), s);
        start = words.find_first_not_of(" ", pos);
        pos = words.find (" ", start+1);        
    }    
    return r;
}
////////////////////////////////
