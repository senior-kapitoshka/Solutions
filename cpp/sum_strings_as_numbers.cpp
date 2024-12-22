#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>

std::string sum_strings(const std::string& a, const std::string& b) {
  std::string x=a.size()==b.size()?a:a.size()>=b.size()?a:b;
  std::string y=a.size()==b.size()?b:a.size()<=b.size()?a:b;
  int sz1=x.size();
  int sz2=y.size();
  int sz=sz1>sz2?sz1-sz2:sz2-sz1;
  if(sz!=0){
    std::string pl(sz,'0');
    y.insert(0,pl);
  }
  int n=(int)y.size()-1;
  bool flag=false;
  std::string res;
  std::transform(x.rbegin(),x.rend(),std::back_inserter(res),[&n,&y,&flag](auto& c){
      int i=(c-'0')+(y[n]-'0');
      i+=flag?1:0;
      if(i>=10){
        flag=true;
        c=(i%10)+'0';
      }else{
        c=i+'0';
        flag=false;
      } 
      --n;
    return c;
  });
  if(flag)res+='1';
  std::reverse(res.begin(),res.end());
  return res;
}
////////////////////////////
#include <string>

using namespace std;

string sum_strings(const string &a, const string &b)
{
  string result;
  int carry = 0, n = max(a.size(),b.size());
  for (int i = 0 ; i < n ; i++)
  {
    if (i < a.size()) carry += a[a.size()-1-i]-'0';
    if (i < b.size()) carry += b[b.size()-1-i]-'0';
    result.push_back('0'+carry%10);
    carry /= 10;
  }
  result.push_back(carry+'0');
  while (result.size() > 1 && result.back() == '0')
    result.pop_back();
  reverse(result.begin(), result.end());
  return result;
}
////////////////

#include <string>
#include <algorithm>

std::string sum_strings(std::string a, std::string b) {
  auto getN = [](std::string s, int j) {return j < 0 ? '0' : s[j];};
  auto max_len = std::max(a.size(), b.size());
  
  int c = 0;
  int sum = 0;
  
  std::string result(max_len+1, '0');
  
  for (size_t i = 0; i < max_len+1; i++) {
    sum = getN(a, a.size() - i - 1) + getN(b, b.size() - i - 1) - 2*'0' + c;
    c = sum / 10;
    result[result.size() - i - 1] = sum % 10 + '0';
  }
  
  auto k = result.find_first_not_of('0');
  
  return k != std::string::npos ? result.substr(k) : std::string(1, '0');
}

////////////////////
#include <string>

std::string sum_strings(const std::string& a, const std::string& b) {
    std::string out;
  int n = a.size();
  int m = b.size();
  int k = std::max(n,m);
  int carry = 0;
  for(int i=0;i<k;++i) {
    int ca = 0, cb = 0;
    if(i<n) ca = a[n-i-1]-'0';
    if(i<m) cb = b[m-i-1]-'0';
    auto s = ca+cb+carry;
    carry = s / 10;
    out.push_back('0'+s%10);
  }
  if(carry) out.push_back('0'+carry);
  std::reverse(out.begin(), out.end());
  return out;
}