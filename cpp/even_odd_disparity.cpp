int solve(std::vector<std::string>v){
    return std::count_if(v.begin(),v.end(),[](auto& curr)
                           {
                             return std::all_of(curr.begin(),curr.end(),[](auto& c){
                               return isdigit(c);
                             }) && std::stoi(curr)%2==0;                  
                           })-std::count_if(v.begin(),v.end(),[](auto& curr)
                           {
                             return std::all_of(curr.begin(),curr.end(),[](auto& c){
                               return isdigit(c);
                             }) && std::stoi(curr)%2!=0;                  
                           });
}
////////////////////////
#include <numeric>
int solve(std::vector<std::string>v){
  return std::accumulate(begin(v),
                         end(v),
                         0,
                         [](auto s, auto e) {return s + (isdigit(e[0]) ? (stoi(e)%2 ? -1 : 1) : 0);});
}
///////////////////
#include <numeric>
#include <cmath>

int solve(std::vector<std::string>v, int even = 0)
{
  v.erase(remove_if(v.begin(), v.end(), [](std::string a) -> bool { return !std::isdigit(a[0]); }), v.end());
  return ((even = std::accumulate(v.cbegin(), v.cend(), 0, [](int a, std::string b) -> int { return (a += !(stoi(b) % 2)); })) - (v.size() - even));
}
///////////////////
