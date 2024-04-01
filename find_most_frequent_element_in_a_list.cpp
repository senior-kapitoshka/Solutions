#include <forward_list>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
struct Node{
  size_t id;
  int d;
};

bool operator==(const Node& lhs,const Node& rhs){
  return lhs.id==rhs.id &&lhs.d==rhs.d; 
}

std::pair<int,int> findMostFrequent(std::forward_list<int> l)
{
  std::vector<std::pair<Node,int>>mp;
  std::for_each(l.begin(),l.end(),[i=0,&mp](auto& j)mutable{
    auto it= std::find_if(mp.begin(),mp.end(),[j](auto& n){return n.first.d==j;});
    if(it==mp.end()){
      mp.push_back({{(size_t)i++,j},1});
    }else{
      (*it).second++;
    }
  });
  std::sort(mp.begin(),mp.end(),[](auto& lhs,auto& rhs){
    return lhs.second>rhs.second || (lhs.second==rhs.second && lhs.first.id<rhs.first.id);
  });

  return {mp.front().first.d,mp.front().second};
  }

////////////////////////////////
#include <forward_list>
#include <unordered_map>
#include <utility>
#include <algorithm>
struct Node{
  size_t id;
  int d;
};

bool operator==(const Node& lhs,const Node& rhs){
  return lhs.id==rhs.id &&lhs.d==rhs.d; 
}
struct mp_hash{
  //const required!!!
  size_t operator()(const Node& n)const{
    std::hash<size_t> sz_h;
    std::hash<int> i_h;
    auto h1=sz_h(n.id);
    auto h2=i_h(n.d);
    return h1^(h2<<1);
  }
};

std::pair<int,int> findMostFrequent(std::forward_list<int> l)
{
  std::unordered_map<Node,int,mp_hash>mp;
  std::for_each(l.begin(),l.end(),[i=0,&mp](auto& j)mutable{
    auto it= std::find_if(mp.begin(),mp.end(),[j](auto& n){return n.first.d==j;});
    if(it==mp.end()){
      mp[{(size_t)i++,j}]=1;
    }else{
      (*it).second++;
    }
  });
  auto it=std::max_element(mp.begin(),mp.end(),[](auto& lhs,auto& rhs){
    return lhs.second<rhs.second || (lhs.second==rhs.second && lhs.first.id>rhs.first.id);
  });
  return {(*it).first.d,(*it).second};
  }


  //////////////////////
  #include <cstddef>
#include <algorithm>
#include <forward_list>
#include <unordered_map>
#include <utility>

std::pair<int, int> findMostFrequent(const std::forward_list<int>& xs) {
  std::unordered_map<int, std::size_t> frequencies, firstIndices;
  std::size_t i = 0;
  for (auto ix = xs.cbegin(); ix != xs.cend(); ++ix, ++i) {
    frequencies[*ix]++;
    if (firstIndices.find(*ix) == firstIndices.end())
      firstIndices[*ix] = i;
  }
  return *std::max_element(frequencies.cbegin(), frequencies.cend(), [&firstIndices](const auto& a, const auto& b) {
    return a.second < b.second || a.second == b.second && firstIndices[a.first] > firstIndices[b.first];
  });
}

//////////////////////
#include <algorithm>
#include <forward_list>
#include <unordered_map>

std::pair<int, int> findMostFrequent(const std::forward_list<int> &l)
{
    typedef std::unordered_map<int, int>::value_type pair_t;
    std::pair<int, int> result;

    std::unordered_map<int, int> counter;
    for (auto n: l)
        ++counter[n];

    result.second = std::max_element(counter.begin(), counter.end(),
        [](const pair_t &a, const pair_t &b) { return a.second < b.second; })->second;
    result.first = *std::find_if(l.begin(), l.end(),
        [&](int n){ return counter[n] == result.second; });

    return result;
}

/////////////////////
#include <forward_list>
#include <utility>
#include <unordered_map>
std::pair<int,int> findMostFrequent(std::forward_list<int> l)
{
  std::unordered_map<int,int> count{},first{};
  int max{0},num{*l.begin()},i{0};
  for(const auto& e : l) ++count[e],i+=first.try_emplace(e,i).second;
  for(const auto& [n,m] : count)
    if(m > max || (m == max && first[n] < first[num])) max=m,num=n;
  return {num,max};
}
/////////////////
#include <forward_list>
#include <utility>
#include <unordered_map>
std::pair<int,int> findMostFrequent(std::forward_list<int> l)
{
  std::unordered_map<int,int> count{};
  int max{0},num{0};
  for(const auto& e : l) ++count[e];
  for(const auto& [n,m] : count) if(m >= max) max=m,num=n;
  return {num,max};
}
//////////////
