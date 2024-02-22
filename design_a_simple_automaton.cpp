#include <array>

class Automaton
{
private:
  std::array<bool,3>q{true,false,false};
public:
  Automaton()=default;
  bool read_commands(const std::vector<char>& com){
    std::for_each(com.begin(),com.end(),[this](auto& c){
      if(q[0]==true && c=='1'){
        q[0]=false;
        q[1]=true;
      }else if(q[1]==true && c=='0'){
        q[1]=false;
        q[2]=true;
      }else if(q[2]==true){
        q[2]=false;
        q[1]=true;
      }
    });
    return q[1];
  }
  
};
////////////////////////////
#include<regex>
using namespace std;
class Automaton
{
public:
  bool read_commands(const std::vector<char>& commands){
    return regex_match(string(commands.begin(), commands.end()), regex("^0*1((1)|(00)|(01))*$"));
  }
};

//////////////////////////
#include <array>
#include <functional>
#include <vector>

class Automaton
{
public:
  Automaton() {}
  
  [[nodiscard]]
  bool read_commands(const std::vector<char>& commands) const;
};

[[nodiscard]]
bool Automaton::read_commands(const std::vector<char>& commands) const
{
  using F = std::function<int(char)>;
  const std::array machine {
    F([]([[maybe_unused]] char c) { return c == '1' ? 1 : 0; }),
    F([]([[maybe_unused]] char c) { return c == '1' ? 1 : 2; }),
    F([]([[maybe_unused]] char c) { return 1; })};

    auto state = 0;
    for (auto c : commands) {
      state = machine[state](c);
    }
    
    return state == 1;
}
////////////////
