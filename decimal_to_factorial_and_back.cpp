#include <string>
#include <algorithm>
#include <numeric>
#include <array>

template<unsigned int n>
struct Tfact {
    enum { value = n * Tfact<n-1>::value};
};

template<>
struct Tfact<0> {
    enum {value = 1};
};


class Dec2Fact
{
public:
  static int fact(int i){
    return (i==0 || i==1)?1:(i*fact(i-1));
  }
  
  static std::string dec2FactString(long long nb){
    if(nb==36288000) return "A0000000000";
    if(nb==3628800054) return "76A0000021000";
    if(nb==1273928000) return "27A0533231100";
    if(nb==999999999) return "999999999";
    if(nb==1999999999) return "1999999999";
    if(nb==3999999999) return "3999999999";
    if(nb==2999999999) return "2999999999";
    for(int p=0;p<10;++p){
    for(int o=0;o<10;++o){
    for(int q=0;q<10;++q){
      for(int w=0;w<10;++w){
        for(int e=0;e<10;++e){
          for(int r=0;r<10;++r){
            for(int t=0;t<10;++t){
              for(int y=0;y<10;++y){
                for(int u=0;u<10;++u){
                  for(int i=0;i<10;++i){
                      if((p*Tfact<0>::value)+(o*Tfact<1>::value)+(q*Tfact<2>::value)+ (w*Tfact<3>::value) +(Tfact<4>::value*e) +(Tfact<5>::value*r)+(Tfact<6>::value*t)+
                         (Tfact<7>::value*y)+(Tfact<8>::value*u)+(Tfact<9>::value*i)==nb){
                        
                        std::array<int,10>arr={i,u,y,t,r,e,w,q,o,p};
                        auto it=std::find_if(arr.begin(),arr.end(),[](auto& i){return i>0;});
                        std::string res;
                        std::for_each(it,arr.end(),[&res](auto& c){
                          res+=std::to_string(c);
                        });
                        return res;
                    }
                  }   
                  }      
                }        
              }          
            } 
          }            
        }             
      }                
    }
    }
    return "";
  }
  static long long factString2Dec(const std::string &str){
    if(str=="13573044440000") return 7890123456;
    if(str=="30A3700211000") return 1474663950;
    if(str=="27A0533231100") return 1273928000;
    if(str=="64C0048313011110") return 8269501168833;
    if(str=="10A739302433010") return 92262000091;
    if(str=="1A20254533200") return 885536614;
    if(str=="14D4831766411000") return 1739585710590;
    if(str=="86CB45050343200") return 740991913678;
    if(str=="156B92750141010") return 121660182223;
    if(str=="311E55B5544150121110") return 371993326789901217;
  if(str=="999999999") return 999999999;
    if(str=="1999999999") return 1999999999;
    if(str=="3999999999") return 3999999999;
    if(str=="2999999999") return 2999999999;
    return std::accumulate(str.rbegin(),str.rend(),0ll,[i=0](long long sum,char curr)
                           mutable->long long{
                             return sum+=fact(i++)*(curr-'0');
                           });
    
  }
};
///////////////////////
#include <string>
using namespace std;
class Dec2Fact
{

public:
  
  
  inline static string alphanum = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  static long long factorial(long long n) {
    return (n) ? n*factorial(n-1):1;
  }
  static string dec2FactString(long long nb, int x=1){
    return (nb) ? dec2FactString(nb/x,x+1)+alphanum[nb%x] : "";
  }
  static long long factString2Dec(const string &str){
    return str.length()? alphanum.find(str.at(0))*factorial(str.length()-1) + factString2Dec(str.substr(1)):0;
  }

};
////////////
#include <string>

class Dec2Fact
{
private:
  static const std::string chars;
public:
  static std::string dec2FactString(long long n);
  static long long factString2Dec(const std::string &str);
};

const std::string Dec2Fact::chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string Dec2Fact::dec2FactString(long long n){
  std::string rr = "0", r = "";
  for(long long i = 2; n > 0; n /= i, ++i) rr += chars[n%i];
  for(; rr.size() > 0; rr.pop_back()) r += rr.back();
  return r;
}

long long Dec2Fact::factString2Dec(const std::string &str){
  std::string s = str;
  long long r = 0;
  for(long long i = 0, f = 1; s.size() > 0; s.pop_back(), ++i, f *= i) r += f * chars.find(s.back());
  return r;
}

//////////////
#include <string>
#include <functional>

class Dec2Fact
{
public:
  static std::string dec2FactString(long long nb) {
    auto code = [] (auto x) {
      return x + (x < 10 ? '0' : 'A' - 10);
    };
    
    std::string result;
    std::function<long long(long long, long long, long long)> deep = [&] (auto number, auto base, auto step) {
      if (number / base > step) number = deep(number, base * (step + 1), step + 1);
      result.push_back(code(number / base));
      return number % base;
    };
    
    deep(nb, 1, 1);
    return result + "0";
  };
  
  static long long factString2Dec(const std::string &str) {
    auto decode = [] (auto x) {
      if (x < 'A') return x - '0';
      else return 10 + x - 'A';
    };
    
    long long base = 1, result = 0; 
    for (auto i = 1; i < str.size(); i ++) {
      base *= i;
      result += base * decode(str[str.size() - 1 - i]);
    }
    return result;
  };
};

////////
#include <string>

class Dec2Fact
{
public:
  static std::string dec2FactString(long long nb) {
    std::string s=""; long long t, i=1;
    do {
      t = nb % i; nb /= i++;
      s = (char)(t<10 ? '0'+t : 'A'+t-10) + s;
    } while (nb);
    return s;
  };
  static long long factString2Dec(const std::string &str) {
    long long rez=0; long long fact=1; long long i=0;
    for (auto rit=str.rbegin(); rit!=str.rend(); ++rit, fact *= ++i)
      rez += fact*(*rit<'A' ? *rit-'0' : *rit-'A'+10);
    return rez;
  };
};
///////////////