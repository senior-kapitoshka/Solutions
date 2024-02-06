#include <string>
#include <algorithm>
#include <iostream>

bool ispal(unsigned int val){
  std::string s=std::to_string(val);
  if(s.size()%2==1){
    std::string c=s.substr(s.size()/2+1);
    std::reverse(c.begin(),c.end());
    s.substr(0,s.size()/2);
    return s.substr(0,s.size()/2)!=c;
  }
  std::string c=s.substr(s.size()/2);
  std::reverse(c.begin(),c.end());
  return s.substr(0,s.size()/2)!=c;
}

unsigned int nextPal(const unsigned int val) {
  unsigned int i = 0;
  for(i = val+1; ispal(i)==true;++i);
  return i;
}

////////////////////////////////////
unsigned nextPal(unsigned x) {
  while (true) {
    x++;
    unsigned y = 0;
    for (unsigned t = x; t != 0; t /= 10)
      y = y * 10 + t % 10;
    if (x == y)
      return x;
  }
}
////////////////////
unsigned int reverse(unsigned int val) {
    unsigned int res = 0;
    for (; val; val /= 10) res = res * 10 + val % 10;
    return res;
}

bool is_palindromic(const unsigned int val) { return val == reverse(val); }

unsigned int nextPal(unsigned int val) {
    while (!is_palindromic(++val));
    return val;
}
////////////////////
#include <iostream>
#include <algorithm>
#include <string>

bool isPalindromic(int num)
{
    std::string numString = std::to_string(num);
    return std::equal(numString.begin(), numString.begin() + numString.size() / 2, numString.rbegin());
}

unsigned int nextPal(const unsigned int val)
{
    for (int i = val + 1;; i++)
    {
        if (isPalindromic(i))
        {
            return i;
        }
    }
    return 0;
}
//////////////////////////
unsigned int nextPal(unsigned int val)
{
	while (true)
	{
		std::string s = std::to_string(++val);
		if (s == std::string(s.rbegin(), s.rend())) break;
	}
	return val;
}
///////////////////////////
unsigned int nextPal(const unsigned int val) {
  for (unsigned int i = val+1; ; i++)
  {
    std::string bufr = std::to_string(i);
    std::string buf = bufr;
    reverse(bufr.begin(), bufr.end());
    if(buf == bufr) return i;
  }
}
///////////////////////
