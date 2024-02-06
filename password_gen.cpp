#define ALL(x) begin(x), end(x)
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>
#include <random>
#include <iostream>
#include <string_view>

using namespace std::literals;

std::string rot13(const std::string& str) {
  using namespace std::literals;
    std::string s ="ABCDEFGHIJKLMabcdefghijklm"s;
    std::string c = "NOPQRSTUVWXYZnopqrstuvwxyz"s;
    std::unordered_map<char,char> mp;
    int i=0;
    std::for_each(s.begin(),s.end(),[&i,&c,&mp](auto z){
        mp[z]=c[i];
        mp[c[i]]=z;
        ++i;
    });

  std::string res;
  std::transform(str.begin(),str.end(),std::back_inserter(res),[&mp](auto& c){
    if(mp.count(c)) return mp[c];
    return c;
  });
  return res;
}

std::string password_gen() {
  std::string_view alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"sv;
    std::srand(std::time(nullptr));
  int digs = std::rand();
   int alow = std::rand();
  int aup = std::rand();
  int x = std::rand()%2 + std::rand() / ((std::numeric_limits<int>::max() + 1u) / 3);

  std::string dg = std::to_string(digs);
  std::random_device rd1;
    std::mt19937 g1(rd1());
  std::shuffle(dg.begin(), dg.end(), g1);
  
  std::string al = std::to_string(alow);
  std::random_device rd2;
    std::mt19937 g2(rd2());
 
  std::shuffle(al.begin(), al.end(), g2);
  std::string au = std::to_string(aup);
  std::random_device rd3;
    std::mt19937 g3(rd3());
 
  std::shuffle(au.begin(), au.end(), g3);
  dg.erase(x);
  al.erase(x);
  au.erase(x);
  std::string alpl;
  std::string alpu;
  std::transform(ALL(al),std::back_inserter(alpl),[&alpha](auto& c){
    int h=rand()%2;
      if(h==1 && isalpha(c+=rand()%2)) c+=rand()%2;
      else if(h==0 && isalpha(c-=rand()%2)) c-=rand()%2;
    int t=c;
    //t+=1 + (std::rand() / ((std::numeric_limits<int>::max() + 1u) / t)>>(std::rand()));
    //t=t>>1;
    char r = alpha[t%alpha.size()-std::rand()%2];
    return r;
  });
  std::transform(ALL(au),std::back_inserter(alpu),[&alpha](auto& c){
    int h=rand()%2;
      if(h==1 && isalpha(c+=rand()%2)) c+=rand()%2;
      else if(h==0 && isalpha(c-=rand()%2)) c-=rand()%2;
    int t=c;
   // t+=1 + (std::rand() / ((std::numeric_limits<int>::max() + 1u) / t)>>(std::rand()));
    //t=t<<1;
    char r = std::toupper(alpha[t%alpha.size()-std::rand()%2]);
    return r;
  });
  
  std::string res = dg+alpl+alpu;
   std::random_device rd;
    std::mt19937 g(rd());
 
  std::shuffle(res.begin(), res.end(), g);
  int y=rand()%2;
  if(y==1){
    rot13(res);
  }else{
    std::transform(ALL(res),res.begin(),[](auto& c){
      int t=rand()%2;
      if(t==1 &&  isalpha(c+=rand()%2)) c+=rand()%2;
      else if(t==0 && isalpha(c-=rand()%2)) c-=rand()%2;
      return c;
    });
  }
  std::cout<<res<<"\n";
  return res;
}///////////////////regex
#include <string>
#include <bits/stdc++.h>
using namespace std;

std::string password_gen() {
  char alphanum[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    regex re1("[0-9]");
    regex re2("[a-z]");
    regex re3("[A-Z]");
    while(true){
      int len =  rand() % 15+6;
      tmp_s="";
      tmp_s.reserve(len);
      for (int i = 0; i < len; ++i) tmp_s += alphanum[rand() % (sizeof(alphanum)-1)];
      if(regex_search(tmp_s,re1) && regex_search(tmp_s,re2) && regex_search(tmp_s,re3) ) break;
    }
    return tmp_s;
}
///////////////regex
#include <string>
#include <regex>
#include <random>

using namespace std;
// Required password regex
regex re("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[A-Za-z\\d]{6,20}$");
smatch m;

// RNG
default_random_engine generator;
uniform_int_distribution<int> pwlen(8,20);
uniform_int_distribution<int> randchar(48,122);

std::string password_gen() {
  int l = pwlen(generator);
  string s {};
  while(s.size() != l){
    int r = randchar(generator);
    if((r >= 65 && r <= 90) || (r >= 48 && r <= 57) || (r >= 97 && r <= 122))
      s.push_back(char(r));
  }
  // If we failed to include any of the character groups, just rerun lols
  return regex_match(s,m,re) ? s : password_gen();
}
//////////////////////////////
#include <string>
#include <algorithm>
#include <iostream>
using namespace std::literals;

std::string password_gen() {
    const std::string l = "abcdefghijklmnopqrstuvwxyz"s;
    const std::string u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"s;
    const std::string num = "0123456789"s;

    const std::string chars = l + u + num;

    std::string pass;

    unsigned int len = std::rand() % 15 + 6;

    pass += l[std::rand() % l.size()];
    pass += u[std::rand() % u.size()];
    pass += num[std::rand() % num.size()];

    while (pass.size() < len) {
        char c = chars[std::rand() % chars.size()];
        if (std::count(pass.begin(), pass.end(), c) < 1) {
            pass += c;
        }
    }
    std::random_shuffle(pass.begin(), pass.end());
  std::random_shuffle(pass.begin(), pass.end());

  std::cout<<pass<<"\n";
    return pass;
}//////////////////////////////////
std::string password_gen()
{
    srand(std::time(0));
    std::size_t len = rand() % 15 + 6;
    char arr[] = {'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    do
        std::random_shuffle(arr, std::end(arr));
    while (std::none_of(arr, arr + len, ::islower) || std::none_of(arr, arr + len, ::isupper) || std::none_of(arr, arr + len, ::isdigit));
    return {arr, arr + len};
}
//////////////////////////////
#include <random>
#include <string>
#include <vector>

int generate(int from, int to)
{
    std::mt19937 engine{std::random_device{}()};    
    std::uniform_int_distribution<> distribution(from,to);
    return distribution(engine);
}

std::string password_gen()
{
   const std::string set{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
   const auto maxIndex = set.length()-1;
   const auto length   = generate(6,20);
   
   std::string password{""};
   do
   {
     bool hasLower {false}; bool hasUpper {false}; bool hasNumber{false};
     while(password.length() < length)
     {
         const auto ch = set[generate( 0, maxIndex )];
         hasLower  |= ::islower(ch); hasUpper  |= ::isupper(ch); hasNumber |= ::isdigit(ch);
         password.push_back( ch );
     }
     if(!hasLower || !hasUpper || !hasNumber)
     {
         password.clear();
     }
   }
   while(password.empty());
   return password;
}
//////////////////////

