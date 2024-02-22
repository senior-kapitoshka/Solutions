#include <string>

std::string operator+(std::string& a,std::string& b)noexcept{
    long long x=0;
    try{
      x=std::stoll(a)+ std::stoll(b);
    }catch(std::invalid_argument){
      return std::to_string(x);
    }catch(std::out_of_range){
      return std::to_string(x);
    }
    return std::to_string(x);
    
}

std::string add(const std::string& a, const std::string& b) {
  std::string x;
  std::string y;
  if(a.empty()){
    x="0";
  }else{
    x=a;
  }
  if(b.empty()){
    y="0";
  }else{
    y=b;
  }
  return x+y;
}


////////////////////////////////////////////////////////////////
string add(string a, string b)
{
    a = string(max(a.size(), b.size()) + 1 - a.size(), '0') + a;
    b = string(a.size() - b.size(), '0') + b;
    for (int i = a.size()-1, carry = 0; i >= 0; i--)
    {
        int sum = a[i] + b[i] - 96 + carry;
        carry   = sum / 10;
        a[i]    = sum % 10 + '0';
    }
    int i = a.find_first_not_of('0');
    return 0 <= i ? a.substr(i) : a.substr(0, 1);
}