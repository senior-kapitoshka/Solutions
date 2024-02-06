#include <string>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
float trans(std::string v){
  std::stringstream ss;
  ss.str(v);
  float res=0;
  float d=1;
  for(std::string w;std::getline(ss,w,'.');){
    float x=(std::stof(w));
    res+=(x/d);
    d*=100;
  }
  return res;
}


bool compareVersions (std::string v1, std::string v2) {
  if(v1==v2) return true;
  if(trans(v1)>trans(v2)) return true;
  if(trans(v1)==trans(v2)){
    int z=0;
    for(size_t i=0;i<std::min(v1.size(),v2.size());++i){
      if(v1[i]!=v2[i]) {
        z=i;
        break;
      }
    }
    v1.erase(0,z);
    v2.erase(0,z);
    return trans(v1)>=trans(v2);
  }
  return false;
}

///////////////////////////////////////////////
using namespace std;

bool compareVersions(string version1, string version2) {

    string tmp1, tmp2;
    stringstream s1(version1), s2(version2);
    while (getline(s1, tmp1, '.') && getline(s2, tmp2, '.'))
    {
        if (stoi(tmp1) != stoi(tmp2))
        {
            return stoi(tmp1) >= stoi(tmp2);
        }
        tmp1 = "-1";
        tmp2 = "-1";
    }
    if (stoi(tmp1) != stoi(tmp2))
    {
        return stoi(tmp1) >= stoi(tmp2);
    }
    return true;
}