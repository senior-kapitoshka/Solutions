#include <cmath>
#include <sstream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>


void get_line(const std::string& s, int& sum){
  std::stringstream ss;
  ss.str(s);
  std::vector<long long>vl;
  for(std::string w;std::getline(ss,w,';');){
    std::string t;
    bool flag=w.front()=='-'?true:false;
    int tmp = 0;
 
    if(!w.empty()){
      if(std::all_of(w.begin(),w.end(),[](auto& c){return isdigit(c)||c=='-';})){ 
        
          if(flag && w.size()!=1){
            tmp = std::stoi(w.substr(1));
          }
          else if(!flag){ 
            tmp = std::stoi(w);
          }
      }
      if(flag) tmp*=(-1);
    }
      if(tmp!=0)vl.push_back(std::move(tmp));
  }

  double ssm = std::accumulate(vl.begin(),vl.end(),0.0)/vl.size();
  sum=ssm;
  std::string str = std::to_string(ssm);
  auto it =  str.find_first_of('.'); 
  std::cout<<str[it+1]<<"\n";
  std::cout<<str<<"\n";
  if(str[it+1]>='5') sum = std::stoi(str)+1;
  else sum = std::stoi(str);
  std::cout<<sum<<"\n";
}

void sum_dig(const double& sum, int& sd){
  std::string s=std::to_string((int)sum);
  std::for_each(s.begin(),s.end(),[&sd](auto& c){
    sd+=c-'0';
  });
}

std::string calculateArray(std::string stringArray) 
{
    std::string result;
    int sum=0;
    get_line(stringArray, sum);
    result+=std::to_string((int)sum)+",";
    int sd =0; 
    sum_dig(sum,sd);
    std::string s = std::to_string(sd);
    result+=s+",";
    result+=(s.back()=='5'||s.back()=='0')?"TRUE":"FALSE";
    return result;
}   

/////////////////////////////////
#include <cmath>
#include <numeric>
#include <regex>

std::string calculateArray(const std::string& str)
{
    auto regex = std::regex{R"((?:^|;)([+-]?\d+)(?=;|$))"};
    auto begin = std::sregex_iterator(str.begin(), str.end(), regex);
    auto end = std::sregex_iterator();
    int mean = std::round(1.0 *
        std::accumulate(begin, end, 0, [](auto a, auto b) {return a + std::stoi(b[1]);}) /
        std::distance(begin, end));
    auto sumOfDigits = 0;
    for (auto n = mean; n; n /= 10)
        sumOfDigits += n % 10;
    auto divisibleBy5 = (sumOfDigits % 5 == 0);
    std::ostringstream out;
    out << mean << ',' << sumOfDigits << ',' << (divisibleBy5? "TRUE": "FALSE");
    return out.str();
}   
////////////////////////
#include <math.h>
using namespace std;
string calculateArray(string stringArray) 
{
    string temp;
    stringstream ss(stringArray);
    int n = 0;
    int sum = 0;
    int count = 0;
    int digits = 0;
    while(getline(ss, temp,';')) 
    {
        if(stringstream(temp)>>n && to_string(n).size()==temp.size())
        {
            sum += n;
            count++;
        }
    }
    if (count>0) sum = round(double(sum)/count);
    for (char i : to_string(sum)) digits += i - '0';
    
    ss.clear();
    ss.str("");
    ss << sum << "," << digits << "," << ((digits%5 == 0)?"TRUE":"FALSE");
    return ss.str();
}   
//////////////////////
std::string calculateArray( std::string s ) {
  std::istringstream ss( s );
  int avg{}, cnt{}, num{}, sum{};
  while ( getline( ss, s, ';' ) ) {
    for ( const char c : s ) if ( isalpha( c ) ) s.clear();
    if ( std::istringstream( s ) >> num ) avg += num, ++cnt;
  }
  avg = double( avg ) / cnt + 0.5;
  for ( const char c : std::to_string( avg ) ) sum += c - 48;
  return { std::to_string( avg ) + ','
         + std::to_string( sum ) + ','
         + ( sum % 5 ? "FALSE" : "TRUE" ) };
}
///////////////////
