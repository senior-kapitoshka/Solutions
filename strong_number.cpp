
#include <string>
#include <numeric>
using namespace std; 

int fact(int n){
  if(n==0 || n==1) return 1;
  return n*fact(n-1);
}

string strong_num (int n )
{
  std::string s=std::to_string(n);
    return std::accumulate(s.begin(),s.end(),0,[](int sum,auto c){
      return sum+=fact(c-'0');
      })==n?"STRONG!!!!":"Not Strong !!" ; 
}
/////////////////////////////
std::string strong_num( int number ) {
  switch ( number ) {
    case 1: case 2: case 145: case 40585: return "STRONG!!!!";
    default: return "Not Strong !!";
  }
}
///////////////////////////////
#include <map>
#include <string>

std::string strong_num(int number)
{
  std::map<int, int> factorials;
  factorials[0] = 1;
  factorials[1] = 1;
  factorials[2] = 2;
  factorials[3] = 6;
  factorials[4] = 24;
  factorials[5] = 120;
  factorials[6] = 720;
  factorials[7] = 5040;
  factorials[8] = 40320;
  factorials[9] = 362880;
  
  int sum = 0;
  
  int n = number;
  while (n != 0)
  {
    sum += factorials[n % 10];
    n /= 10;
  }
  
  return sum == number ? "STRONG!!!!" : "Not Strong !!"; 
}