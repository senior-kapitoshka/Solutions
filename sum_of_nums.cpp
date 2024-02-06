#include <numeric>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

int acc(int x,int y){
  std::vector<int>vc(x);
  std::iota(vc.begin(),vc.end(),y);
  std::copy(vc.begin(),vc.end(),std::ostream_iterator<int>(std::cout,","));
  std::cout<<"\n";
  return std::accumulate(vc.begin(),vc.end(),0);
}

int get_sum(int a, int b)
{
  if(a==b)return a;
  if(std::abs(a-b)==1) return a+b;
  if(a<b){
    return acc(b+1-a,a);
  }
  return acc(a+1-b,b);
}

////////////////////
int get_sum(int a, int b)
{
  int n = (a < b ? b - a : a - b) + 1;
  return n *(a + b)/ 2;
}