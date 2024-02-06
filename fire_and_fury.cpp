#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

 using namespace std::string_literals;
 using namespace std::string_view_literals;


std::string fire_and_fury(const std::string& tweet) {
  if(!all_of(tweet.begin(),tweet.end(),[](const auto& c){
    return c=='E' || c== 'F' || c=='I'|| c== 'R'|| c=='U'|| c=='Y';
  })) return "Fake tweet.";
  std::string res;
  std::string fired="You are fired!"s;
  std::string furious="I am furious."s;
  std::string really=" really "s;
  std::string and_you=" and you "s;
  std::string t = tweet;
  
  size_t p_fire=0,p_fury=0;
  std::vector<std::string> vb;
  while(true){
    if(p_fire==t.npos && p_fury==t.npos) break;
    p_fire=t.find("FIRE"s);
    p_fury=t.find("FURY"s);
    if((p_fire<p_fury) || (p_fury==t.npos && p_fire!=t.npos)){
      
      if(vb.empty()){
        vb.push_back(fired);
      }else if(!vb.empty() && vb.back().back()=='.'){
        vb.push_back(fired);
      }else if(!vb.empty() && vb.back().back()=='!'){
        vb.back().insert(3,and_you);
      }
      
      t.erase(0,p_fire+4);
    }else if((p_fire>p_fury) || (p_fire==t.npos && p_fury!=t.npos)){
      if(vb.empty()){
        vb.push_back(furious);
      }else if(!vb.empty() && vb.back().back()=='!'){
        vb.push_back(furious);
      }else if(!vb.empty() && vb.back().back()=='.'){
        vb.back().insert(4,really);
      }
      
      t.erase(0,p_fury+4);
    }
  }
  if(vb.empty())return "Fake tweet.";
  
  std::for_each(vb.begin(),vb.end(),[&res](auto& s){
    s.erase(std::unique(s.begin(),s.end(),[](auto& lhs, auto& rhs){return lhs==rhs && lhs==' ';}),s.end());
    if(!res.empty())res+=' ';
    res+=s;
  });
    return res;
}

/////////////////////////
#include <string>
#include <regex>
#include <algorithm>

std::string fire_and_fury(const std::string& tweet) 
{
  std::regex reg (R"(FIRE|FURY)"); std::string letters ("EFIRUY");
  std::sregex_iterator it = std::sregex_iterator(tweet.begin(), tweet.end(), reg), end;
  if (it == end || std::any_of(tweet.begin(), tweet.end(), [&](const char& c){
      return letters.find(c) == std::string::npos;
    })) return "Fake tweet.";
  std::string ret;
  while (it != end) {
    std::string word = (*it).str(0); int count = 1; ++it;
    while ((*it).str(0) == word) ++it, ++count;
    if (word == "FIRE") {
      std::string s = " You";
      for (int i = 1; i < count; ++i) s += " and you";
      ret += s + " are fired!";
    } else {
      std::string s = " I am";
      for (int i = 1; i < count; ++i) s += " really";
      ret += s + " furious.";
    }
  }
  return ret.substr(1);
}
///////////////////////
