#include <string>
#include <sstream>
#include <vector>
#include <numeric>

class Opstrings4
{
public:
    static std::string diag2Sym(const std::string &s){
      std::stringstream ss(s);
      std::vector<std::string>vs;
      for(std::string w;std::getline(ss,w,'\n');){
        if(vs.empty()){
            vs.resize(w.size());
            size_t i=w.size()-1;
            for(auto& s:vs){
                s+=w[i--];
            }
        }else{
            size_t i=w.size()-1;
            for(auto& s:vs){
                s+=w[i--];
            }
        }
      }
      std::for_each(vs.begin(),vs.end(),[](auto& s){
        std::reverse(s.begin(),s.end());
      });
      return std::accumulate(next(vs.begin()),vs.end(),vs.front(),[](auto& lhs, auto &rhs){
        return std::move(lhs)+"\n"+std::move(rhs);
      });
    }
    static std::string rot90Counter(const std::string &s){
      std::stringstream ss(s);
      std::vector<std::string>vs;
      for(std::string w;std::getline(ss,w,'\n');){
        if(vs.empty()){
            vs.resize(w.size());
            size_t i=w.size()-1;
            for(auto& s:vs){
                s+=w[i--];
            }
        }else{
            size_t i=w.size()-1;
            for(auto& s:vs){
                s+=w[i--];
            }
        }
      }
      return std::accumulate(next(vs.begin()),vs.end(),vs.front(),[](auto& lhs, auto &rhs){
        return std::move(lhs)+"\n"+std::move(rhs);
      });
    }
    static std::string selfieDiag2Counterclock(const std::string &s){
      std::string a=diag2Sym(s);
      std::string b=rot90Counter(s);
      std::stringstream res,ss(s),ss1(a),ss2(b);
      for(std::string w,w1,w2;std::getline(ss,w,'\n'),std::getline(ss1,w1,'\n'),std::getline(ss2,w2,'\n');){
        res<<w<<"|"<<w1<<"|"<<w2<<"\n";
      }
    std::string r=res.str();
    r.pop_back();
      return r;
    }
    // your function oper...
    template<typename F>
    static std::string oper(F f, const std::string &s){
       return f(s);
    }
};

//////////////////////////
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Opstrings4
{
private:
    static std::vector<std::string> split(const std::string &s);
    static std::string join(const std::vector<std::string>& vec);
    static std::string vertMirror(const std::string &strng);
    static std::string horMirror(const std::string &strng);
    static std::string diag1Sym(const std::string &strng);
public:
    static std::string diag2Sym(const std::string &strng);
    static std::string rot90Counter(const std::string &strng);
    static std::string selfieDiag2Counterclock(const std::string &strng);
    template<typename Func>
    static std::string oper(Func func, const std::string &s);
};

std::vector<std::string> Opstrings4::split(const std::string &s)
{
    std::vector<std::string> out;
    std::istringstream ss(s);
    std::string next;
    while (std::getline(ss, next, '\n'))
        out.push_back(next);
    return out;
}
std::string Opstrings4::join(const std::vector<std::string>& vec)
{
    std::string s = "";
    for (unsigned int i = 0; i < vec.size(); i++)
        if (i < vec.size() - 1) s += vec[i] + "\n";
        else s += vec[i];
    return s;
}
std::string Opstrings4::diag1Sym(const std::string &strng)
{
    std::vector<std::string> lines = split(strng);
    std::vector<std::string> newLines(lines.size());
    for (unsigned int i = 0; i < lines.size(); i++)
    {
        newLines[i] = "";
        for (unsigned int j = 0; j < lines.size(); j++)
            newLines[i] += lines[j][i];
    }
    return join(newLines);
}
std::string Opstrings4::vertMirror(const std::string &strng)
{
    std::vector<std::string> words = split(strng);
    std::string sb = "";
    for (unsigned int i = 0; i < words.size(); i++)
    {
        std::string word = words[i];
        for (int j = word.length() - 1; j >= 0; j--)
            sb += word[j];
        if (i < word.length() - 1) sb += "\n";
    }
    return sb;
}
std::string Opstrings4::horMirror(const std::string &strng)
{
    std::vector<std::string> words = split(strng);
    std::string sb = "";
    for (unsigned int i = words.size(); i >= 1; i--)
    {
        std::string word = words[i-1];
        sb += word;
        if (i > 1) sb += "\n";
    }
    return sb;
}

std::string Opstrings4::diag2Sym(const std::string &strng)
{
    return vertMirror(horMirror(diag1Sym(strng)));
}
std::string Opstrings4::rot90Counter(const std::string &strng)
{
    return horMirror(diag1Sym(strng));
}
std::string Opstrings4::selfieDiag2Counterclock(const std::string &strng)
{
    std::vector<std::string> org  = split(strng);
    std::vector<std::string> dia  = split(diag2Sym(strng));
    std::vector<std::string> cclk = split(rot90Counter(strng));
    std::string result = "";
    for (unsigned int i = 0; i < org.size(); i++)
    {
        if (i != org.size() - 1)
            result += org[i] + "|" + dia[i] + "|" + cclk[i] + "\n";
        else result += org[i] + "|" + dia[i] + "|" + cclk[i];
    }
    return result;
}
template<typename Func>
std::string Opstrings4::oper(Func func, const std::string &s)
{
    return func(s);
}

///////////////////////
#include <string>

class Opstrings4
{
public:
    static std::string diag2Sym(const std::string &strng);
    static std::string rot90Counter(const std::string &strng);
    static std::string selfieDiag2Counterclock(const std::string &strng);
    // your function oper...
    static std::string oper(std::string (*) (const std::string&), const std::string &s);
};

std::string 
Opstrings4::oper(std::string(*ptrf)(const std::string&),const std::string&str){
  return ptrf(str);
  }

std::string 
Opstrings4::diag2Sym(const std::string&str){
  std::string res;
  int num = str.find('\n');
  if(num < 0) num = str.length();
  for(int n = 0; n < num; ++n)
  {
    for(int j = str.length() - 1 - n; j > -1;j -= num + 1)
        res += str[j];
        res += '\n';
  }
  return {res.begin(), res.end() - 1};
}

std::string
Opstrings4::rot90Counter(const std::string& str){
  std::string res;
  int num = str.find('\n');
  if(num < 0) num = str.length();
  for(int n = num - 1; n > -1; --n){
      for(int j = n; j < str.length(); j += num + 1)
          res += str[j];
          res += '\n';
  }
  return {res.begin(),res.end() - 1};
}

std::string
Opstrings4::selfieDiag2Counterclock(const std::string& str){
std::string res;
int num = str.find('\n');
if(num < 0) num = str.length();
for(int n = 0; n < num; ++n){
  int to = n * (num + 1) + num;
  //if(to > str.length())break;
    for(int j = n * (num + 1); j < to; ++j)
    res += str[j];
    res += '|';
    for(int k = str.length() - 1 - n; k > -1; k -= num + 1)
      res += str[k];
    res += '|';
    for(int i = num - 1  - n; i < str.length(); i += num + 1)
      res += str[i];
    res += '\n';
  }
return {res.begin(), res.end() - 1};
}

