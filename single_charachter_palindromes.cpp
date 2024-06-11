std::string solve(std::string s){
  size_t i=0,j=s.size()-1;
  bool f=true;
  while(i<j){
    if(s[i]==s[j]){
      ++i;--j;
    }else if(s[i]!=s[j] && f){
      if(s[i]==s[j-1]){
        --j;
        f=false;
      }else if(s[i+1]==s[j]){
        ++i;
        f=false;
      }else{
        return "not possible";
      }
    }else return "not possible";
  }
  return f?"OK":"remove one";
}
//////////////////
bool is_palindrome(const std::string& str) {
  return str == std::string(str.crbegin(), str.crend());
}

std::string solve(std::string s) {
  if (is_palindrome(s)) {
    return "OK";
  }

  for (std::size_t i{0}; i < s.size(); ++i) {
    std::string foo{s};

    if (is_palindrome(foo.erase(i, 1))) {
      return "remove one";
    }
  }

  return "not possible";
}
//////////
#include <functional>
std::string solve(std::string s) {
  std::function<unsigned(unsigned, unsigned, unsigned)> comparison = [&] (unsigned i, unsigned j, unsigned remove) {
    while(i < j) {
      if (s[i] == s[j]) i++, j--;
      else return std::min(comparison(i + 1, j, remove + 1), comparison(i, j - 1, remove + 1));
    };
    return remove;
  };
  
  unsigned result = comparison(0, s.size() - 1, 0);
  if      (result == 0) return "OK";
  else if (result == 1) return "remove one";
  else                  return "not possible";
    
}