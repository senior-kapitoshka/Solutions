#define ALL(x) cbegin(x),cend(x)
#include <string>
#include <algorithm>
using namespace std;

string encode (string str, string key)
{
  std::transform(ALL(str),str.begin(),[&key](auto& c){
    return key.find(tolower(c))==std::string::npos?c
      :key.find(tolower(c))%2==0?
        (isupper(c)?toupper(key[key.find(tolower(c))+1]):key[key.find(tolower(c))+1]):
        (isupper(c)?toupper(key[key.find(tolower(c))-1]):key[key.find(tolower(c))-1]);
  });
    return str;
}

string decode (string str, string key)
{
    return encode(str,key);
}