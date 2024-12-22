#include <sstream>
#include <numeric>
#include <limits>
#include <algorithm>
namespace Closest
{
  struct Node{
    Node(int s,unsigned int i,long long v):
    sum(s),id(i),val(v){}
    int sum;
    unsigned int id;
    long long val;
  };
    std::vector<std::tuple<int, unsigned int, long long>> closest(const std::string &s)
    {
      std::vector<Node>vn;
        std::stringstream ss(s);
      size_t i=0;
        for(std::string d;std::getline(ss,d,' ');){
          int sum=std::accumulate(d.begin(),d.end(),0,[](int sum,auto c)->int{
            return sum+=c-'0';
          });
          vn.emplace_back(sum,i++,std::stoll(d));
        }
      int mn=std::numeric_limits<int>::max();
      std::sort(vn.begin(),vn.end(),[&mn](auto lhs,auto rhs){
        mn=std::min(mn,std::abs(lhs.sum-rhs.sum));
        return  lhs.sum<rhs.sum || (lhs.sum==rhs.sum && lhs.id<rhs.id);
      });
      std::vector<std::tuple<int, unsigned int, long long>>res={{0,0,0},{0,0,0}};
      for(size_t i=1;i<vn.size();++i){
        if(std::abs(vn[i-1].sum-vn[i].sum)==mn){
          res={{vn[i-1].sum,vn[i-1].id,vn[i-1].val},{vn[i].sum,vn[i].id,vn[i].val}};
          break;
        }
      }
      return res;
    }
}

/////////////////////////////
#include <vector>
#include <tuple>
#include <string>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iterator>

namespace Closest
{
    std::vector<std::tuple<int, unsigned int, long long>> closest(std::string const& strng)
    {
        auto get_weight = [](std::string const& s)
        {
            return std::reduce(s.cbegin(), s.cend(), 0, [](int r, char c) { return r + c - '0'; });
        };
        auto split = [](std::string const& s, char delim = ' ')
        {
            std::vector<std::string> res;
            std::stringstream ss(s);
            std::string sub;
            while (std::getline(ss, sub, delim)) res.push_back(sub);
            return res;
        };
        std::vector<std::tuple<int, unsigned int, long long>> res;
        unsigned int idx = 0;
        for (auto const& s : split(strng))
            res.push_back(std::make_tuple(get_weight(s), idx++, std::stoll(s)));
        
        if (res.size() < 2) return {{0, 0, 0}, {0, 0, 0}};
      
        std::sort(res.begin(), res.end(), [](auto& t1, auto& t2) { return std::get<0>(t1) == std::get<0>(t2) ? std::get<1>(t1) < std::get<1>(t2) : std::get<0>(t1) < std::get<0>(t2); });

        std::vector<int> distance(res.size());
        std::transform(res.cbegin(), res.cend(), distance.begin(), [](auto const& t) { return std::get<0>(t); });
        std::adjacent_difference(distance.begin(), distance.end(), distance.begin());
        distance.erase(distance.begin());

        auto min_idx = std::distance(distance.cbegin(), std::min_element(distance.cbegin(), distance.cend()));
        return { res[min_idx], res[min_idx + 1] };
    }
}

/////////////////////
#include <algorithm>
#include <sstream>
#include <numeric>

using namespace std;

namespace Closest
{
    vector<tuple<int, unsigned int, long long>> closest(const string &strng)
    {
      istringstream in_s(strng);
      vector<tuple<int, unsigned int, long long>> n_list;
      string nb_str;
      
      while (in_s >> nb_str)
      {
        long long n = stoll(nb_str);
        int weight = accumulate(nb_str.begin(),nb_str.end(),0,[](int acc, char c) { return acc+c-'0'; });
        unsigned int i = n_list.size();
        n_list.push_back({weight, i, n});
      }
      if (!n_list.size())
        return {{0,0,0},{0,0,0}};
      
      sort(n_list.begin(), n_list.end());
      
      int i_min = 0, diff_min = get<0>(n_list[1])-get<0>(n_list[0]);
      for (int i = 1 ; i+1 < n_list.size() ; i++)
      {
        int diff = get<0>(n_list[i+1])-get<0>(n_list[i]);
        if (diff < diff_min)
        {
          i_min = i;
          diff_min = diff;
        }
      }
      return {n_list[i_min], n_list[i_min+1]};
    }
}

/////////////////