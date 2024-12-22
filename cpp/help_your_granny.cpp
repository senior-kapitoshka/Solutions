#include <unordered_map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>


typedef std::unordered_map<std::string, double> stringdblmap;
class Tour
{
public:
    static int tour([[maybe_unused]]std::vector<std::string> &arr, std::vector<std::vector<std::string>> &tws, stringdblmap &h){
      return std::accumulate(h.begin(),prev(h.end()),0,[&tws,&h,i=1](int& sum,auto& curr)mutable{
        return sum+=std::pow(2,h[tws[i++][1]])-std::pow(2,curr.second);
      });
    }
};
////////////////
#include <unordered_map>
#include <vector>
#include <numeric>
#include <cmath>

using stringdblmap=std::unordered_map<std::string, double>;

class Tour {
   public:
       static int tour(std::vector<std::string>& arrFriends, std::vector<std::vector<std::string>>& ftwns, stringdblmap& h) {
     
            std::vector<double> dists;
            for (auto& fr : arrFriends) {
                for (auto& ft : ftwns)
                    if (ft[0] == fr) dists.push_back(h[ft[1]]);
            }
            return std::inner_product( std::next(dists.begin()), dists.end(), 
                                       dists.begin(), 
                                       dists[0] + dists.back(), 
                                       std::plus<>{}, 
                                       [](auto a, auto b) { return sqrt(a*a-b*b); });
    };
};
///////////////////
#include <cstddef>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <iterator>
#include <utility>

typedef std::unordered_map<std::string, double> stringdblmap;
class Tour
{
public:
    static int tour(const std::vector<std::string> &arrFriends,
        const std::vector<std::vector<std::string>> &ftwns,
        const stringdblmap &h)
    {
        std::unordered_map<std::string, std::string> friendTowns;
        std::transform(std::begin(ftwns), std::end(ftwns),
            std::inserter(friendTowns, std::end(friendTowns)),
            [](const auto &p){
                return std::make_pair(p[0], p[1]);
            });
        double dist = 0;
        double prevDist = 0;
        for(const auto &fr : arrFriends)
        {
            auto iter = friendTowns.find(fr);
            if(iter == std::end(friendTowns))
            {
                continue;
            }
            const auto curDist = h.at(iter->second);
            const auto m = std::minmax(curDist, prevDist);
            dist += std::sqrt(m.second*m.second - m.first*m.first);
            prevDist = curDist;
        }
        dist += prevDist;
        return std::floor(dist);
    }
};