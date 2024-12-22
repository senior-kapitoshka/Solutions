# include <string>

bool is_vowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

std::string disemvowel(const std::string& str) {
  std::string ans;
  for(auto&& i:str){
    if(!is_vowel(tolower(i))){
      ans+=i;
    }else continue;
  }
  return ans;
}

///////////////////////////


# include <string>
# include <regex>
std::string disemvowel(std::string str)
{
  std::regex vowels("[aeiouAEIOU]");
  return std::regex_replace(str, vowels, "");
}

////////////////////////////
# include <string>

std::string disemvowel(std::string str)
{
    for ( auto letter : "AEIOUaeiou" ) {
      str.erase(std::remove(str.begin(), str.end(), letter), str.end());
    }
    
    return str;
}

/////////////////////////////////////////


# include <string>
# include <regex>

std::string disemvowel(std::string str)
{
    return std::regex_replace(str,static_cast<std::regex>("([AaEeIiOoUu])"),"");
}

///////////////////////

# include <string>
std::string disemvowel(std::string str) {
  str.erase(std::remove_if(str.begin(), str.end(), [] (char c) { 
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }), str.end()
  );
  return str;
}