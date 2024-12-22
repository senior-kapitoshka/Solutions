#include <cmath>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <limits>

bool helper(const std::pair<std::string, int>& p){
  std::vector<int>vc;
  int mx=std::numeric_limits<int>::min();
  std::transform(p.first.begin(),p.first.end(),std::back_inserter(vc),
                 [i=p.second,&mx](auto& c){
                   mx=std::max(mx,((int)c+i));
                   return ((int)c+i);
                 });
  std::vector<bool>vb(mx+1,true);
  vb[0]=vb[1]=false;
  for(int i=2;i*i<=mx+1;++i){
    if(vb[i]){
      for(int j=i*i;j<=mx+1;j+=i){
        vb[j]=false;
      }
    }
  }
  for(auto i:vc){
    if(vb[i]) return true;
  }
  return false;
}

std::vector<int> prime_word(const std::vector<std::pair<std::string, int>> &list){
  std::vector<int>res;
  std::transform(list.begin(),list.end(),std::back_inserter(res),
                [](auto& p){
                  return (int)helper(p);});
  return res;
}

///////////////////////////
#include <algorithm>
#include <cmath>
#include <iterator>

bool is_prime(int i) {
    if(i < 2)
        return false;
    else if(i == 2)
        return true;
    else if(i%2 == 0)
        return false;
    else
        for(int j=3; j<=std::sqrt(i); j+=2)
            if(i%j == 0)
                return false;
    return true;
}


std::vector<int> prime_word(const std::vector<std::pair<std::string, int>> &list){
    std::vector<int> result;
    result.reserve(list.size());
    std::transform(list.begin(), list.end(), std::back_inserter(result), [](const std::pair<std::string, int>& i){
        return std::any_of(i.first.begin(), i.first.end(), [&](const char& j){ return is_prime(j+i.second); });
    });
    return result;
}

/////////////////////////
#include <cmath>
#include <string>
#include <vector>
#include <utility>

bool is_prime(int num) {
  if(num<2) return false;
  
  for(int i=2; i*i<=num; i++)
    if(num%i==0) return false;
  
  return true;
}

bool is_match(std::string str, int n) {
  for(auto c : str)
    if(is_prime((int) c + n))
      return true;
  
  return false;
}

std::vector<int> prime_word(const std::vector<std::pair<std::string, int>> &list){
  std::vector<int> matches;
  
  for(auto entry : list) {
    matches.push_back(is_match(entry.first, 
                               entry.second));
  }
  
  return matches;
}

/////////////////
#include <cmath>
#include <string>
#include <vector>
#include <utility>

std::vector<int> prime_word(const std::vector<std::pair<std::string, int>> &list) {
    auto isPrime = [](int n) {
        for (int i = n - 1; i > 1; i--) {
            if (n % i == 0) return false;
        }
        return true;
        };
    std::vector<int> vec{};
    for (std::pair p : list) {
        bool chb = false;
        for (auto c : p.first) {
            if (isPrime(static_cast<int>(c) + p.second)) chb = true;
        }
        chb ? vec.push_back(1) : vec.push_back(0);
    }
    return vec;
}

///////////////////
