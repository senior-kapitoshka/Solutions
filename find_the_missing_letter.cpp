#include <vector>
#include <algorithm>

char findMissingLetter(const std::vector<char>& ch)
{
  std::vector<char>vc;
  vc.push_back(ch.front());
  std::transform(ch.begin(),prev(ch.end()),next(ch.begin()),std::back_inserter(vc),
                [](auto& prev, auto& next){
                  return prev+1==next?prev:prev+1;
                });
  vc.push_back(ch.back());
  vc.erase(std::unique(vc.begin(),vc.end()),vc.end());
  auto r=std::find_if(vc.begin(),vc.end(),[&ch](auto& c)
                      {return find(ch.begin(),ch.end(),c)==ch.end();});
  return *r;
}
///////////////////////////////////
#include <vector>

char findMissingLetter(const std::vector<char>& chars)
{
  for (int i {0}; i < chars.size() ; i++){
    if ( i > 0 ){
        if ( chars[i-1] +1 != chars[i] )
            return chars[i-1] +1;
    }
  }
}
/////////////////////////////
#include <vector>
#include <range/v3/algorithm/mismatch.hpp>
#include <range/v3/view/iota.hpp>

char findMissingLetter(const std::vector<char>& chars)
{
  return *ranges::mismatch(chars, ranges::views::iota(chars.front())).in2;
}
////////////////////////
#include <vector>
#include <algorithm>
#include <numeric>

char findMissingLetter(const std::vector<char>& chars) {
  std::vector<int> diffs;
  std::adjacent_difference(chars.begin(), chars.end(), std::back_inserter(diffs));
  return chars[std::find(diffs.begin(), diffs.end(), 2) - 1 - diffs.begin()] + 1;
}
//////////////////
