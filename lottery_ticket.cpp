#include <algorithm>
#include <string_view>
#include <set>

std::string bingo(std::vector<std::pair<std::string, int>> tt, int win)
{
  using namespace std::literals;
  std::array<std::string_view,2>ans={"Winner!"sv,"Loser!"sv};
  int cnt=0;
  std::for_each(tt.begin(),tt.end(),[&cnt](auto& p){
    std::vector<int>st;
      std::transform(p.first.begin(),p.first.end(),std::back_inserter(st),[](auto& c)
                     {return c-0;});
    std::cout<<"\n";
    cnt+=std::find(st.begin(),st.end(),p.second)!=st.end()?1:0;
  });
  return (std::string)(cnt>=win?ans.front():ans.back());
}
//////////////////////
#include <algorithm>
std::string bingo(std::vector<std::pair<std::string, int>> ticket, int win)
{
    return std::count_if(ticket.begin(), ticket.end(), [](const auto& i){
        return std::any_of(i.first.begin(), i.first.end(), [&](const char& j) { return j == i.second; });
    }) >= win ? "Winner!" : "Loser!" ;
}
/////////////////////