#include <string>
#include <array>

using namespace std::literals;
//..."scissors">"paper">"rock">"scissors"...;


std::string rps(const std::string& p1, const std::string& p2)
{
  std::array<std::string,3>arr{"paper","rock","scissors"};
  auto i1=std::distance(arr.begin(),std::find(arr.begin(),arr.end(),p1));
  auto i2=std::distance(arr.begin(),std::find(arr.begin(),arr.end(),p2));
  
    return  i1==i2?"Draw!"s:((i1<i2 && i1-i2==-1)|| i1-i2==2)?"Player 1 won!"s:"Player 2 won!"s;
}

/////////////////
#include <string>

std::string rps(const std::string& p1, const std::string& p2)
{
    if(p1 == p2)
      return "Draw!";
    if( ( p1[0] == 's' && p2[0] == 'p' )||
        ( p1[0] == 'p' && p2[0] == 'r' )||
        ( p1[0] == 'r' && p2[0] == 's' ) )
        return "Player 1 won!";
    return "Player 2 won!";
}
//////////
#include <string>
#include <unordered_map>

namespace {
  std::unordered_map<std::string,std::string> win_map = {{"rock", "scissors"}, {"scissors", "paper"}, {"paper", "rock"}};
}

std::string rps(const std::string& p1, const std::string& p2)
{
  if (p1 == p2) {
    return "Draw!";
  }

  if (win_map[p1] == p2) {
    return "Player 1 won!";
  } else {
    return "Player 2 won!";
  }
}