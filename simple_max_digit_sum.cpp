#include <string>
#include <algorithm>
#include <numeric>

long long solve(long long n){
  if(n<10) return n;
	std::string s=std::to_string(n);
  std::string n_s=std::string(s.size()-2,'9');
  int x=std::stoi(s.substr(0,2));
  if(x>=10 && x<18) n_s.insert(0,1,'9');
  else{
    if(x%10!=9) n_s.insert(0,std::to_string(x-(x%10+1)));
    else 
      n_s.insert(0,std::to_string(x-1)); 
  } 
  long sum=std::accumulate(s.begin(),s.end(),0l,[](auto sum,auto curr){
    return sum+=std::stol(std::string(1,curr));
  });
  long n_sum= std::accumulate(n_s.begin(),n_s.end(),0l,[](auto sum,auto curr){
    return sum+=std::stol(std::string(1,curr));
  }); 
  return (sum==n_sum && std::stoll(s)>std::stoll(n_s))?std::stoll(s):(sum==n_sum && std::stoll(s)<std::stoll(n_s))?std::stoll(n_s):
  (sum>n_sum && std::stoll(s)>std::stoll(n_s))?std::stoll(s):std::stoll(n_s);
}

//////////////////////////////
template <class T>
T solve(T n) {
  T m = n, e = 1;
  while (m >= 10) {
    m /= 10;
    e *= 10;
  }
  T t = m * e + (e - 1);
  if (t == n)
    return t;
  for (T e = 1; ; e *= 10)
    if (T r = t - e; r <= n)
      return r;
}

///////////////
long long solve(long long n)
{
  auto digit_sum = [] (long long n) { long long m = 0; while (n) m+=n%10,n/=10; return m; };
  long long maxi = n, max_sum = digit_sum(n), pow10 = 1;
  while (n)
  {
    pow10 *= 10;
    n = n/pow10*pow10;
    long long sum = digit_sum(n-1);
    if (sum > max_sum)
      maxi = n-1, max_sum = sum;
  }
	return maxi;
}

///////////////////
