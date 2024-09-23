#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class MaxDiffLength
{
public:
    static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2){
      if(a1.empty() || a2.empty()) return -1;
      int x=std::abs((int)std::max_element(a1.begin(),a1.end(),[](auto lhs,auto rhs){
        return lhs.size()<rhs.size();
      })->size()-
        (int)std::min_element(a2.begin(),a2.end(),[](auto lhs,auto rhs){
        return lhs.size()<rhs.size();})->size());
      int y=std::abs((int)std::min_element(a1.begin(),a1.end(),[](auto lhs,auto rhs){
        return lhs.size()<rhs.size();
      })->size()-
        (int)std::max_element(a2.begin(),a2.end(),[](auto lhs,auto rhs){
        return lhs.size()<rhs.size();})->size());
      return x>y?x:y;
    }
};

//////////////////////
class MaxDiffLength
{
public:
    static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2){
        int max = -1;
        for(auto const & a : a1)
            for(auto const & b : a2)
                max = std::max(max, std::abs(int(a.size()) - int(b.size())));
        return max;
    }
};