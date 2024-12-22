#include <string>
#include <vector>
#include <utility>
#include <regex>
#include <fmt/format.h>
#include <limits>

struct TknSq{
  char c='_';
  long long val=1;
  void set(const std::string& str){
    std::string s=str.substr(1);
    if(!std::any_of(s.begin(),s.end(),[](auto& c){return isalpha(c);}))return;
    if(c=='_'){
      if(s.front()=='-'){
        c=s.back();
        if(isdigit(s[1])){
          val=std::stoll(s.substr(0,s.find(c)));
        }else{
          val=-1;
        }
      }else{
        c=s.back();
        if(isdigit(s[0])){
          val=std::stoll(s.substr(0,s.find(c)));
        }else{
          val=1;
        }
      }
    }else{
      if(s.front()=='-'){
        if(isdigit(s[1])){
          val*=std::stoll(s.substr(0,s.find(c)));
        }else{
          val*=-1;
        }
      }else{
        if(isdigit(s[0])){
          val*=std::stoll(s.substr(0,s.find(c)));
        }
      }
    }
  }
  std::string get()const{
    return val==0?"":(val!=-1 && val!=1)?fmt::format("{}{}^2",val,c):(val==-1)?
      fmt::format("-{}^2",c):fmt::format("{}^2",c);
  }
};

struct TknX{
  char c='_';
  long long x1=1;
  long long n1=std::numeric_limits<long long>::max();
  long long x2=1;
  long long n2=1;
  void setx(const std::string& str){
    std::string s=str.substr(1);
    if(!std::any_of(s.begin(),s.end(),[](auto& c){return isalpha(c);}))return;
    if(c=='_'){
      if(s.front()=='-'){
        c=s.back();
        if(isdigit(s[1])){
          x1=std::stoll(s.substr(0,s.find(c)));
        }else{
          x1=-1;
        }
      }else{
        c=s.back();
        if(isdigit(s[0])){
          x1=std::stoll(s.substr(0,s.find(c)));
        }else{
          x1=1;
        }
      }
    }else{
      if(s.front()=='-'){
        c=s.back();
        if(isdigit(s[1])){
          x2=std::stoll(s.substr(0,s.find(c)));
        }else{
          x2=-1;
        }
      }else{
        c=s.back();
        if(isdigit(s[0])){
          x2=std::stoll(s.substr(0,s.find(c)));
        }else{
          x2=1;
        }
      }
    } 
  }
  void setn(const std::string& str){
    std::string s=str;
    s.pop_back();
    if(std::any_of(s.begin(),s.end(),[](auto& c){return isalpha(c);}))return;
    else{
      if(n1==std::numeric_limits<long long>::max()){
        n1=std::stoll(s);
      }else{
        n2=std::stoll(s);
      }
    }
  }
  std::string get(){
    std::cout<<x1<<"-"<<x2<<"-"<<n1<<"-"<<n2<<"\n";
    return (x1*n2+x2*n1)==0?"":(x1*n2+x2*n1)==1?fmt::format("+{}",c):(x1*n2+x2*n1)==-1?fmt::format("-{}",c):(x1*n2+x2*n1)>0?fmt::format("+{}{}",(x1*n2+x2*n1),c):fmt::format("{}{}",(x1*n2+x2*n1),c);
  }
};

struct TknInt{
  long long val=1;
  void set(const std::string& str){
    std::string s=str;
    s.pop_back();
   if(std::any_of(s.begin(),s.end(),[](auto& c){return isalpha(c);}))return;
    else val*=std::stoll(s);
  }
  std::string get()const{
    return val==0?"":val<0?std::to_string(val):fmt::format("+{}",val);
  }
  
};

std::string quadratic_builder(const std::string& ex)
{
  std::regex r1("\\([-]{0,1}[\\d]{0,}[\\a-z]+");
  std::regex r2("-?[\\d]+?\\)");
  
  TknSq x_sq;
  TknX x_x;
  auto rb1= std::sregex_iterator(ex.begin(),ex.end(),r1);
  auto re1=std::sregex_iterator();
  for(auto it=rb1;it!=re1;++it){
    x_sq.set((*it).str());
    x_x.setx((*it).str());
  }
  auto rb2= std::sregex_iterator(ex.begin(),ex.end(),r2);
  auto re2=std::sregex_iterator();
  TknInt x_int;
  for(auto it=rb2;it!=re2;++it){
    x_x.setn((*it).str());
    x_int.set((*it).str());
  }
  
  return fmt::format("{}{}{}",x_sq.get(),x_x.get(),x_int.get());
}


/////////////////////////
#include <string>
#include <sstream>
#include <regex>

using namespace std;

string quadratic_builder(const string& expression)
{
  static regex re("\\((-|-?\\d+)?([a-z])(\\+|-)(\\d+)\\)\\((-|-?\\d+)?[a-z](\\+|-)(\\d+)\\)");
  
  smatch m;
  regex_match(expression, m, re);
  
  int a = m.str(1).empty() ? 1 : m.str(1) == "-" ? -1 : stoi(m.str(1));
  char x = m.str(2)[0];
  int b = (m.str(3) == "+" ? 1 : -1) * stoi(m.str(4));
  int c = m.str(5).empty() ? 1 : m.str(5) == "-" ? -1 : stoi(m.str(5));
  int d = (m.str(6) == "+" ? 1 : -1) * stoi(m.str(7));
  
  int a2 = a*c, a1 = b*c+a*d, a0 = b*d;
  ostringstream out_s;
  out_s << (a2 == 1 ? "" : a2 == -1 ? "-" : to_string(a2)) << x << "^2";
  if (a1) out_s << (a1 == -1 ? "-" : a1 == 1 ? "+" : (a1 < 0 ? "" : "+") + to_string(a1)) << x;
  if (a0) out_s << (a0 < 0 ? "" : "+") << a0;
  return out_s.str();
}
///////////////
#include <string>
#include <regex>

std::string quadratic_builder(const std::string& expression)
{
  std::smatch match;
  std::regex_match(expression, match, std::regex{"\\((-?\\d*)(.)([-+]\\d*)\\)\\((-?\\d*).([-+]\\d*)\\)"});
  auto coef = [&match](int i) { return match[i] == "-" ? -1 : match[i] == "" ? 1 : std::stoi(match[i]); };
  int m = coef(1), n = coef(3), p = coef(4), q = coef(5);
  int a = m * p, b = m * q + n * p, c = n * q;
  std::string x = match[2];
  std::string ra, rb, rc;
  if (!a && !b) return std::to_string(c);
  if (a != 0) ra = (a == 1 ? "" : a == -1 ? "-" : std::to_string(a)) + x + "^2";
  if (b != 0) rb = (b == 1 ? (a ? "+" : "") : b == -1 ? "-" : (a && b > 0 ? "+" : "") + std::to_string(b)) + x;
  if (c != 0) rc = (c > 0 ? "+" : "") + std::to_string(c);
  return ra + rb + rc;
}
///////////
#include <regex>
#include <string>
#include <vector>

using namespace std;

// This function is to deal with the fact that the coefficient
// cannot be -1 or 1 or 0,

string fSign(long int a, string x, string op) {
  string str;
  if (a == -1 and x != "") {
    str = "-";
  } else {
    str = (a == 1 and x != "") ? "" : to_string(a);
  }
  return (a == 0) ? "" : op + str + x;
}

// Using regex extract the necesary elements and then
// convert that to long int to do the expansion.
// After that make a string with the format required.

string quadratic_builder(const string &s) {
  vector<long int> v{0, 0, 0, 0, 0};
  int i{};
  long int a0{}, a1{}, a2{};
  string x, str_a0, str_a1, str_a2, op0, op1;
  regex e(R"(\((-?\d?+)([a-z])([+-]\d+)\)\((-?\d?+)[a-z]([+-]\d+)\))");
  smatch m;
  regex_match(s, m, e);

  for (smatch::iterator it = m.begin() + 1; it != m.end(); ++it) {
    if (i == 1) {
      x = *it;
    } else {
      if (*it == "") {
        v[i] = 1;
      } else {
        v[i] = (*it == "-") ? -1 : stoll(*it);
      }
    }
    i++;
  }

  a2 = v[0] * v[3];
  a1 = v[0] * v[4] + v[2] * v[3];
  a0 = v[2] * v[4];

  op1 = (a1 <= 0) ? "" : "+";
  op0 = (a0 <= 0) ? "" : "+";

  str_a0 = (a0 == 0) ? "" : to_string(a0);

  string ans = fSign(a2, x + "^2", "") + fSign(a1, x, op1) + fSign(a0, "", op0);

  return ans;
}