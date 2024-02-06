#include <string>
#include <algorithm>

using namespace std;

int getCount(const string& is){
  int num_vowels = 0;
  string v="aeiou";
  for(auto&& i:is){
    if(find(v.begin(),v.end(),i)!=v.end()) {++num_vowels;}
  }
  return num_vowels;
}

/////////////////////////////////

#include <string>

using namespace std;

bool is_vowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int getCount(const string& inputStr) {
  return count_if(inputStr.begin(), inputStr.end(), is_vowel);
}

//////////////////////////

#include <string>

using namespace std;

int getCount(const string& inputStr){
  return count_if(inputStr.begin(), inputStr.end(), [](const char ch) {
      switch(ch) {
          case 'a':
          case'e':
          case'i':
          case'o':
          case'u':
              return true;
          default:
              return false;} 
     });
}