#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

#if 0
static int& getReg(std::unordered_map<std::string, int>& regs, std::string name)
{
  
}
#endif


std::unordered_map<std::string, int> assembler(const std::vector<std::string>& pm)
{
  
  std::unordered_map<std::string, int>res;
  for(size_t i=0;i<pm.size();){
    if(pm[i].substr(0,3)=="mov"){
      std::string x=pm[i].substr(pm[i].find_last_of(' ')+1);
      if(isdigit(x[0])|| x[0]=='-'){
        res[pm[i].substr(pm[i].find_first_of(' ')+1,1)]=std::stoi(x);
      }else if(isalpha(x[0])){
        res[pm[i].substr(pm[i].find_first_of(' ')+1,1)]=res[x];
      }
      ++i;
    }else if(pm[i].substr(0,3)=="inc"){
      ++res[pm[i].substr(pm[i].find_first_of(' ')+1)];
      ++i;
    }else if(pm[i].substr(0,3)=="dec"){
      --res[pm[i].substr(pm[i].find_first_of(' ')+1)];
      ++i;
    }else if(pm[i].substr(0,3)=="jnz"){
      std::string x=pm[i].substr(pm[i].find_last_of(' ')+1);
      std::string y=pm[i].substr(pm[i].find_first_of(' ')+1,1);
      if(isdigit(y[0])|| y[0]=='-'){
        if(std::stoi(y)!=0){
          i+=std::stoi(x);
        }else{
            ++i;
        }
      }else if(isalpha(y[0])){
        if(res[y]!=0){
          i+=std::stoi(x);
        }else{
            ++i;
        }
      }
    }
  }
  return res;
}

////////////////////////
#include <unordered_map>
#include <functional>
#include <sstream>
#include <vector>
#include <string>

inline std::string inpo(std::istringstream &s, std::string &o) { return (s >> o, o); }
inline int extro(std::unordered_map<std::string, int> &m, const std::string &o) { return (m.count(o) ? m[o] : std::stoi(o)); }

std::unordered_map<std::string, int> assembler(const std::vector<std::string> &a)
{
    unsigned p = 0;
    std::unordered_map <std::string, int> m;
    std::unordered_map <std::string, std::function<void(std::istringstream &)>> l ({
        { "mov", [&](std::istringstream &s) { std::string r, o; s >> r; m[r] = extro(m, inpo(s, o)); }},
        { "inc", [&](std::istringstream &s) { std::string r; ++m[inpo(s, r)]; }},
        { "dec", [&](std::istringstream &s) { std::string r; --m[inpo(s, r)]; }},
        { "jnz", [&](std::istringstream &s) { std::string o; if (extro(m, inpo(s, o))) p += extro(m, inpo(s, o)) - 1; }}
    });
    do {
        std::istringstream s { a[p++] };
        std::string i;
        if (!l.count(inpo(s, i)))
            continue;
        l[i](s);
    }
    while (!p || p < a.size());
    return m;
}
///////////////////
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;

static int& getReg(unordered_map<string, int>& regs, string name) {
  return regs[name];
}

// res[1] = code, res[2] = reg1, res[3] = reg2 || const

unordered_map<string, int> assembler(const vector<string>& program) {
    for (auto& it : program)
        cout << it << endl;

    unordered_map<string, int> regs;
    regex matcher("^([a-z]{3}) (\\w+) ?(-?\\w?.*)$");
    smatch res;

    for (int i = 0; i < program.size(); i++) {
        regex_search(program[i], res, matcher);
        if (res[1] == "mov") {
            regs[res[2]] = res[3].str()[0] >= 'a' ? regs[res[3]] : stoi(res[3].str(), nullptr, 10);
            continue;
        }
        if (res[1] == "inc") {
            regs[res[2].str()]++;
            continue;
        }
        if (res[1] == "dec") {
            regs[res[2].str()]--;
            continue;
        }
        if (res[1] == "jnz") {
            if ((res[2].str()[0] >= 'a' && regs[res[2].str()]) || (res[2].str()[0] < 'a' && stoi(res[2].str(), nullptr, 10)))
                i += stoi(res[3].str(), nullptr, 10) - 1;
        }
    }

    return regs;
}
///////////
#include <string>
#include <unordered_map>

static int getValue(std::unordered_map<std::string, int>& regs, std::string val)
{
  if(isalpha(val[0])) return regs[val.substr(0, 1)];
  return std::stoi(val);
}
std::unordered_map<std::string, int> assembler(const std::vector<std::string>& program)
{
  std::unordered_map<std::string, int> reg_map = {};
  for(ssize_t i = 0; i < program.size(); i++){
    std::string inst = program[i].substr(0,3), params = program[i].substr(4);
    if(inst == "mov") reg_map[params.substr(0,1)] = getValue(reg_map, params.substr(2));
    else if (inst == "inc") reg_map[params.substr(0,1)] ++;
    else if (inst == "dec") reg_map[params.substr(0,1)] --;
    else if (inst == "jnz" && getValue(reg_map, params)) i += (stoi(params.substr(params.find(" ") + 1)) - 1) ;
    
  }
  return reg_map;
}
///////////////
