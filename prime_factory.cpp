#include<vector>
#include <algorithm>
#include <iostream>
#include <cmath>
std::vector<int> prime_factors(long n){
 /* std::vector<int>ans;
  std::cout<<n<<"\n";
  while(n!=1){
    if(n%2==0){
      n/=2;
      ans.push_back(2);
    } else if(n%3==0){
      n/=3;
      ans.push_back(3);
    }
    else if(n%5==0){
      n/=5;
      ans.push_back(5);
    }else if(n%7==0){
      n/=7;
      ans.push_back(7);
    }
  }

  for(auto i:ans)std::cout<<i<<",";
  std::cout<<"\n";
  return ans;*/

std::vector<int>vc;

	while (n % 2 == 0)
	{
		vc.push_back(2);
		n = n/2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		
		while (n % i == 0)
		{
			vc.push_back(i);
			n = n/i;
		}
	}

	if (n > 2)
		vc.push_back(n);

  return vc;

}

////////////////////////////////////////////////////////////

#include<vector>
std::vector<int> prime_factors(long n) {
  std::vector<int> res;
  for (auto i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n > 1) res.push_back(n);
  return res;
}
/////////////////////////////////////////////

#include<vector>
std::vector<int> prime_factors(long n){
  std::vector<int> obj;
  int p = 2;
  while(p*p <= n) {
    while(n%p == 0) {
      n /= p;
      obj.push_back(p);
    }
    p += 1 + p % 2;
  }
  if(n > 1) obj.push_back(n);
  return obj;
}
///////////////////////////////////////
