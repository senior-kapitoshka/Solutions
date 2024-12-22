#include <string>
#include <sstream>
#include <regex> 
//MORSE_CODE['.--']

std::string decodeMorse(const std::string& mC) {
  std::string mc;
  if(!mC.empty() && (mC.front()==' ' ||mC.back()==' ')){
    mc=mC.substr(mC.find_first_not_of(' '),mC.find_last_not_of(' ')-mC.find_first_not_of(' ')+1);
  }else{
    mc=mC;
  } 
  std::string res;
  if(mc.find(' ')!=mc.npos){
    std::vector<int>vc;
    int l=0;
    for(size_t i=1;i<mc.size();++i){
       if(mc[i-1]!=' ' && mc[i]==' ' && mc[i+1]!=' ') ++l;
      else if((mc[i-1]==' ' && mc[i]==' ' && mc[i+1]==' ') 
             ||(i==mc.size()-1)){
        ++l;
        vc.push_back(l);   
        l=0;
      }
     }
      std::regex r("[-|.]+");
    auto rb=std::sregex_iterator(mc.begin(),mc.end(),r);
    auto re=std::sregex_iterator();

    int i=0;
    for(auto it=rb;it!=re;){
      if(vc[i]!=0){
        res+=MORSE_CODE[it->str()];
        --vc[i];
        ++it;
      }
      else{
        res+=' ';
        ++i;
      }
    }
  }else{
    res=MORSE_CODE[mc];
  }
    return res;
}

/////////////////
#include <regex>

const std::regex morse("([^\\s]+|\\s{3})");

std::string decodeMorse(std::string morseCode) {
  std::string decoded;
  
  auto begin = morseCode.begin() + morseCode.find_first_not_of(' ');
  auto end = morseCode.begin() + morseCode.find_last_not_of(' ') + 1;
  
  for (auto it = std::sregex_iterator(begin, end, morse); it != std::sregex_iterator(); ++it) {
    std::string str = it->str();
    decoded += str == "   " ? " " : MORSE_CODE[str];
  }
  
  return decoded;
}
///////////////
std::string decodeMorse(std::string morseCode) {
  std::string decoded;
  const char* current = morseCode.data(), *end = current + morseCode.size();
  
  // Strip off all leading and trailing space first
  while (*current == ' ') current++;
  while (end[-1] == ' ') end--;
  
  while (current < end) {
    if (*current == ' ') {
      decoded += ' ';
      current += 2;
    } else {
      const char* start = current;
      while (current < end && *current == '.' || *current == '-') ++current;
      decoded += MORSE_CODE[std::string(start, current)];
      current++;
    }
  }
  return decoded;
}