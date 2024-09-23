#include <iostream>
#include <string>
#include <map>

using namespace std;

int solution(string rn) {
  std::map<char,int>mp={{'I',1},
{'V',5},
{'X',10},
{'L',50},
{'C',100},
{'D',500},
{'M',1000}};
  int res=mp[rn.front()];
  for(size_t i=1;i<rn.size();++i){
    if(mp[rn[i-1]]>=mp[rn[i]])
      res+=mp[rn[i]];
    else{
      res=mp[rn[i]]-mp[rn[i-1]]>res?mp[rn[i]]-mp[rn[i-1]]:
      res+(mp[rn[i]]-mp[rn[i-1]]*2);
    }
  }
  return res;
}

//////////////////////////
#include <iostream>
#include <string>

using namespace std;

int decode(char letter)
{
  switch (letter)
  {
    case 'M':
      return 1000;
    case 'D':
      return 500;
    case 'C':
      return 100;
    case 'L':
      return 50;
    case 'X':
      return 10;
    case 'V':
      return 5;
    case 'I':
      return 1;
  }
}

int solution(string roman) {
  
  int result = 0;
  
  for (size_t i = 0; i < roman.size(); ++i)
    if (i < roman.size() - 1 && decode(roman[i]) < decode(roman[i + 1]))
      result -= decode(roman[i]);
    else result += decode(roman[i]);
    
  return result;
}

///////////////////////
#include <iostream>
#include <string>

using namespace std;

int solution(string roman) {
    int roman_number = 0;
    for(int i = 0; i < roman.length(); i++) {
        switch(roman[i]) {
          case 'I': roman_number += 1; break;
          case 'V': (roman[i - 1] == 'I') ? roman_number += 3: roman_number += 5; break;
          case 'X': (roman[i - 1] == 'I') ? roman_number += 8: roman_number += 10; break;
          case 'L': (roman[i - 1] == 'X') ? roman_number += 30: roman_number += 50; break;
          case 'C': (roman[i - 1] == 'X') ? roman_number += 80: roman_number += 100; break;
          case 'D': (roman[i - 1] == 'C') ? roman_number += 300: roman_number += 500; break;
          case 'M': (roman[i - 1] == 'C') ? roman_number += 800: roman_number += 1000; break;
        }
    }
  return roman_number;
}

////////////////////////
