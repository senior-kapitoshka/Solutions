#define ALL(x) begin(x),end(x)
#include <array>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <utility>
#include <type_traits>
#include <limits>
#include <iostream>

using namespace std;
using namespace literals;

#if 0

template<typename T,typename ...Ts>
void i_c_out(const T& t,Ts&&...ts){
  if constexpr(std::is_same_v<T,std::vector<int>>) {
    std::copy(ALL(t),std::ostream_iterator<decltype(*t.begin())>(std::cout,","));
  }
  else if constexpr(std::is_same_v<T,std::unordered_map<std::string,std::array<int,3>>>){
    std::for_each(ALL(t),[](auto &p){
      std::cout<<p.first<<" - ";
      for_each(ALL(p.second),[](auto& i){
      std::cout<<i<<", ";
      });
      std::cout<<"\n";
    });
  }
   else if constexpr(std::is_same_v<T,std::array<std::string,3>>){
    std::copy(ALL(t),std::ostream_iterator<decltype(*t.begin())>(std::cout,","));
   }
  std::cout<<"\n---\n";
  if constexpr(sizeof...(ts)!=0){
    i_c_out(std::forward<Ts>(ts)...);
  }
}

template<typename ...Ts>
void c_out(Ts&&...ts){
  if constexpr(sizeof...(ts)!=0){
    i_c_out(std::forward<Ts>(ts)...);
  }
}

#endif

void prepare(std::unordered_map<std::string,std::array<int,3>>&mp){
  std::array<std::string,10>nm ={"Wild"s, "Star"s, "Bell"s, "Shell"s, "Seven"s, "Cherry"s, "Bar"s, "King"s, "Queen"s, "Jack"s};
   std::vector<int>ths(10),tws(10),tww(10,0);
  std::iota(ALL(ths),1);
  std::iota(ALL(tws),1);
  for_each(ALL(ths),[](auto& i){i*=10;});
  int c=2,i=0;
  for_each(ALL(tww),[&c](auto& i){i=c;c+=2;});
  tww.back()=std::numeric_limits<int>::min();
  for_each(rbegin(nm),rend(nm),[&mp,&ths,&tws,&tww,&i](auto& n){
    mp[n]={ths[i],tws[i],tww[i]};
    ++i;
  });
  #if 0
  c_out(ths,tws,tww,mp);
  #endif
}

unsigned fruit([[maybe_unused]]const array<vector<string>, 3> &reels, [[maybe_unused]]const array<unsigned, 3> &spins)
{
  std::unordered_map<std::string,std::array<int,3>> mp;
  prepare(mp);
  std::array<std::string,3> line ={reels[0][spins[0]],reels[1][spins[1]],reels[2][spins[2]] };
  #if 0
   c_out(line);
  #endif
  if(line[0]==line[1] && line[1]==line[2]) return mp[line.front()][0];
  else if((line.front()==line.back() && line[1]=="Wild"s) ||
     (line.front()==line[1] && line[2]=="Wild"s))return mp[line.front()][2];
  else if(line.back()==line[1] && line[0]=="Wild"s) return mp[line.back()][2];
  else if((line.front()==line.back())||
         (line.front()==line[1]))return mp[line.front()][1];
  else if(line.back()==line[1]) return mp[line.back()][1];
   return 0;
}