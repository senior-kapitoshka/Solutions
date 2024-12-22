#include <string>
#include <vector>

std::string h(std::string &s){
  s.push_back(*s.begin());
  auto it=s.begin();
  s.erase(it);
  return s;
}


std::vector<std::string> rotate(const std::string& s) {
  std::vector<std::string> vc;
  if(s.empty()) return {};
  else if(s==" ") return {" "};
  else{
    std::string t=s;
    h(t);
    vc.push_back(t);
    while(t!=s){
      vc.push_back(h(t));
    }
    
  }
  return vc;
}

/////////////////////////////////////////////////////////


#include <string>
#include <vector>

std::vector<std::string> rotate(const std::string& s) {
  std::vector<std::string> arr;
  for(int i = 0; i < s.size(); i++){
    arr.push_back(s.substr(i + 1, s.size()) + s.substr(0, i + 1));
  }
  return arr;
}
//////////////////////////////////////////////////////////
