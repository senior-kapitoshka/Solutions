#include <string>
#include <bitset>
#include <algorithm>

std::string whitespace_number(int n)
{
  if(n==0) return " \n";
  bool flag=false;
  std::string s;
  if(n<0){
    flag=true;
    s=std::bitset<64>(n*(-1)).to_string();
  }else{
    s=std::bitset<64>(n).to_string();
  }
  s=s.substr(s.find_first_of('1'));
  std::string res;
  std::transform(s.begin(),s.end(),
                 std::back_inserter(res),[](auto& c){
                   return c=='0'?' ':'\t';
                 });
  if(flag){
    res.insert(0,"\t");
  }else{
    res.insert(0," ");
  }
  return res+'\n';
}

///////////////////////
#include <string>
#include <bitset>
#include <cmath>

std::string whitespace_number(int n)
{
  std::string s = std::bitset<32>(abs(n)).to_string(), ret = "";
  s.erase(0, s.find('1'));
  ret += (n < 0) ? '\t' : ' ';
  for (auto e : s)
    ret += std::string(1, e == '0' ? ' ' : '\t');
  ret += '\n';
  return ret;
}

///////////////////
#include <string>
#include <algorithm>

std::string whitespace_number(int n) {
  std::string result = "\n";
  bool isPlus = n >= 0;
  for (; n != 0; n /= 2)  result.push_back((n % 2 == 0) ? ' ' : '\t');
  result.push_back(isPlus ? ' ' : '\t');
  
  std::reverse(result.begin(), result.end());
  
  return result;
}

/////////////////////