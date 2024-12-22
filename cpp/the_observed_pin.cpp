#include <string>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

/*
#if 0
template<typename T,typename ...Ts>
void add_strings(std::set<std::string>& res,const T& v,const Ts& ...vs){
  if(res.empty()){
    std::for_each(v.begin(),v.end(),[&res](auto& c){
        std::string s;
        s+=c;
        res.insert(s);
    });
  }else{
    std::set<std::string>new_st;
    std::for_each(res.begin(),res.end(),[&v,&new_st](auto& s){
      std::for_each(v.begin(),v.end(),[&new_st,&s](auto&c){
          std::string t=s;
          t+=c;
          new_st.insert(t);
        });
      });
      std::swap(res,new_st);
    }
  if constexpr(sizeof...(vs)!=0){
    add_strings(res, vs...);
  }
}




template<typename ...Ts>
void make_string(std::set<std::string>& res, const Ts& ...vs){
  if constexpr(sizeof...(vs)!=0){
    add_strings(res,vs...);
  }
}
#endif
*/


std::vector<char> add_neighbor(char c){
    std::vector<char> res;                               

    if(c=='1') res = {'1','2','4'};
    else if(c=='2') res = {'1','2','3','5'};
    else if(c=='3') res ={'2','3','6'};
    else if(c=='4') res={'1','4','5','7'};
    else if(c=='5') res={'5','6','4','2','8'};
    else if(c=='6') res={'6','9','3','5'};
    else if(c=='7') res={'7','8','4'};
    else if(c=='8') res={'8','0','9','5','7'};
    else if(c=='9') res={'9','6','8'};
    else if(c=='0') res={'0','8'};
    return res;
}

void add_char(std::set<std::string>& res,char c){
  std::vector<char> v=add_neighbor(c);
  if(res.empty()){
    std::for_each(v.begin(),v.end(),[&res](auto& c){
        std::string s;
        s+=c;
        res.insert(s);
    });
  }else{
    std::set<std::string>new_st;
    std::for_each(res.begin(),res.end(),[&v,&new_st](auto& s){
      std::for_each(v.begin(),v.end(),[&new_st,&s](auto&c){
          std::string t=s;
          t+=c;
          new_st.insert(t);
        });
      });
      std::swap(res,new_st);
    }
}

std::vector<std::string> get_pins(std::string obs) {
  std::set<std::string> st;
  std::for_each(obs.begin(),obs.end(),[&st](auto& c){
      add_char(st,c);
  });
  std::vector<std::string> res(st.begin(),st.end());
  return res;
}


///////////////////
using namespace std;

vector<string> get_pins(const string &observed, const string &prefix = "")
{
    static const map<char, string> neighbors =
    {
        {'1', "124"},  {'2', "1235"},  {'3', "236"},
        {'4', "1457"}, {'5', "24568"}, {'6', "3569"},
        {'7', "478"},  {'8', "05789"}, {'9', "689"},
                       {'0', "08"}
    };
    if ( !observed.size() ) return {prefix};
    vector<string> pins;
    for (auto c : neighbors.at(observed[0]))
        for (auto pin : get_pins(observed.substr(1), prefix + c))
            pins.push_back(pin);
    return pins;
}

////////////////////

#include <string>
#include <vector>
#include <array>
#include <numeric>

const static std::array<std::string, 10> possibilities = {
  "08", "124", "1235", "236", "1457", "24568", "3569", "478", "57890", "689"
};

std::vector<std::string> generate_next_sequence(const std::vector<std::string>& strings, char c) {
  const int value = c - '0';
  std::vector<std::string> results;
  results.reserve(std::size(strings) * std::size(possibilities[value]));
  
  for (const auto& str : strings) {
    for (char c : possibilities[value]) {
      results.push_back(str + c);
    }
  }
  
  return results;
}


std::vector<std::string> get_pins(std::string observed) {
  return std::accumulate(std::begin(observed), std::end(observed), std::vector<std::string>{{""}}, generate_next_sequence);
}

////////////////////
