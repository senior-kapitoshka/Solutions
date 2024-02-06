class Rotations
{
public:
    
   static std::vector<std::string> rot(const std::string&str){
     std::string s=str;
     std::vector<std::string> vs;
      size_t i=0;
      while(i<s.size()){
          vs.push_back(s);
          s.insert(0,1,s.back());
          s.erase(s.size()-1);
          ++i;
      }
      return vs;
  }
  
    static bool containAllRots(const std::string &s, std::vector<std::string> &arr){
      std::vector<std::string> vs=rot(s);

      for(auto i:vs){
        if(find(arr.begin(),arr.end(),i)==arr.end()) return false;
      }
      return true;
    }
};

/////////////////////////////////

class Rotations
{
public:
  static bool containAllRots(std::string& str, const std::vector<std::string>& arr)
  {
      for (int i = 0; i < str.length(); ++i)
      {
          if(find(arr.begin(), arr.end(), str) == arr.end())
              return false;
          rotate(str.begin(), str.begin()+1, str.end());
      }
      return true;
  }
};

////////////////////////////
#include <string>
#include <vector>
#include <algorithm>

class Rotations
{

public:
    static bool containAllRots(const std::string &strng, std::vector<std::string> &arr);
};

std::string rot(const std::string &s, int i)
{
    return s.substr(i, s.length()) + s.substr(0,i);
}
bool Rotations::containAllRots(const std::string &strng, std::vector<std::string> &arr)
{
    for (unsigned int i = 0; i < strng.length(); i++)
    {
        std::string r = rot(strng, i);
        std::vector<std::string>::iterator it;
        it = std::find(arr.begin(), arr.end(), r);
        if (it == arr.end())
            return false;
    }
    return true;
}
///////////////////////////
class Rotations
{
public:
    static bool containAllRots(const std::string &strng, std::vector<std::string> &arr) {
      if (strng.empty())
        return true;
      std::string rot = strng;
      do {
        std::rotate(rot.begin(), rot.begin()+1, rot.end());
        if (std::find(arr.cbegin(), arr.cend(), rot) == arr.cend())
          return false;          
      } while(rot != strng);
      return true;
    }
};