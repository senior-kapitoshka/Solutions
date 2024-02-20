#include <math.h>
#if 0
#include <algorithm>
#include <vector>
#include <numeric>

int predictAge(int age1, int age2, int age3, int age4, int age5, int age6, int age7, int age8)
{
  std::vector<int>vc{age1,age2, age3,age4,age5,age6, age7, age8};
  std::transform(vc.begin(),vc.end(),vc.begin(),[](auto& i){return i*i;});
  int sum=accumulate(vc.begin(),vc.end(),0);
  return std::sqrt(sum)/2;
}
#endif

template<typename T,typename ...Ts>
void pow_sum(T& sum,T& i,Ts&...ts){
  if constexpr(sizeof...(ts)!=0){
    sum+=i*i;
    pow_sum(sum,ts...);
  }
  else if constexpr(sizeof...(ts)==0){
    sum+=i*i;
  }
}

template<typename ...Ts>
int predict(Ts& ...ts){
  int sum=0;
  if constexpr(sizeof...(ts)!=0){
    pow_sum(sum,ts...);
  }
  return std::sqrt(sum)/2;
}

int predictAge(int age1, int age2, int age3, int age4, int age5, int age6, int age7, int age8)
{
  return predict(age1,age2,age3,age4,age5,age6,age7,age8);
}

//////////////////////////////////
#include <numeric>
#include <cmath>
#include <array>

template <typename ... T>
int predictAge(const T ...ages)
{
  const std::array<std::common_type_t<T...>, sizeof...(T)> all_ages = { (ages*ages)... };
  
  const int sum = { std::accumulate(all_ages.begin(), all_ages.end(), 0) };
  
  const auto squared = std::sqrt(sum) / 2;
  
  return squared;
}
//////////////////////
#include <cmath>

int predictAge_aux(int sum, int n)
{
    return std::sqrt(sum + n * n) / 2;
}

template <typename... Args>
int predictAge_aux(int sum, int n, Args... args)
{
    return predictAge_aux(sum + n * n, args...);
}

template <typename... Args>
int predictAge(Args... args)
{
    return predictAge_aux(0, args...);
}
//////////////////////
#include <cmath>

template <typename... Ages>
int predictAge(Ages... ages)
{
  int sum{ 0 };
  int _[]{ sum += (ages * ages)... };
  return std::sqrt(sum) / 2;
}
////////////