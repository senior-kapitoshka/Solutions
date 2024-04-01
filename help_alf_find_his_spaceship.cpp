#include <sstream>
#include <fmt/format.h>
using namespace std;
using namespace literals;

class EightiesKids2
{
public:
    static string findSpaceship(const string &map)
    {
        if(map.find('X')==map.npos) return "Spaceship lost forever.";
      size_t n=std::count(map.begin(),map.end(),'\n');
        stringstream ss(map);
      pair<size_t,size_t>x;
      size_t i=n;
      for(string s;getline(ss,s);){
        for(size_t j=0;j<s.size();++j){
          if(s[j]=='X'){
            x={j,i};
          }
        }
        --i;
      }
      return fmt::format("[{}, {}]",x.first,x.second);
    }
};

//////////////////
using namespace std;

class EightiesKids2
{
public:
    static string findSpaceship(const string &map)
    {
        auto ship = map.find('X');
        if (ship == string::npos) return "Spaceship lost forever.";
        return '[' + to_string(ship - map.rfind('\n', ship) - 1) + ", " + to_string(count(map.begin() + ship, map.end(), '\n')) + ']';
    }
};
/////////////
#include <fmt/format.h>
using namespace std;
struct EightiesKids2 {
  static string findSpaceship( const string& m ) {
    const auto p{ m.find( 'X' ) };
    return p == m.npos ? "Spaceship lost forever." : fmt::format( "[{}, {}]",
      p - 1 - m.rfind( '\n', p ), count( &m[ p ], &m[ m.size() ], '\n' ));
  }
};