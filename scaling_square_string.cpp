class ScalingSqStrings
{
public:
  static std::string mul(const std::string &str, int k){
    if(k==1) return str;
    std::string res;
    for(size_t i=0;i<str.size();++i){
      res.insert(res.end(),k,str[i]);
    }
    return res;
  }
  static std::vector<std::string> mul2(const std::string &str, int n){
    std::vector<std::string> res(n);
    std::fill(res.begin(),res.end(), str);
    return res;
  }
    static std::string scale(const std::string &str, int k, int n){
      if(str.empty()) return "";
      std::string ans;
      std::vector<std::string> vs;
      std::string tmp;
      std::stringstream ss;
      ss.str(str);
      for(std::string w;getline(ss,w,'\n');){
         std::vector<std::string>t= mul2(mul(w,k),n);
        vs.insert(vs.end(),t.begin(),t.end());
      }
      ans+=vs[0];
      for(size_t i=1;i<vs.size();++i){
          ans+="\n";
          ans+=vs[i];
      }
      return ans;
      
    }
};
/////////////////////////////////////
using namespace std;                                                                   // <3
class ScalingSqStrings
{
public:
    static string scale(const string &s, int k, int n){
      string line, in;
      stringstream ss(s);
      while (getline(ss, in)) 
        for (int i = 0; i < n; i++) {
          for (auto ch : in) 
            line += string(k, ch);
          line.push_back('\n');
        }
      return line.substr(0, line.size() - 1);
    }
};
////////////////////////////////
class ScalingSqStrings
{
public:
    static std::string scale(const std::string &strng, int k, int n);
};

std::string ScalingSqStrings::scale(const std::string &strng, int k, int n)
{
	if (strng == "")
  	return "";
	std::string line;
  std::stringstream res;
  std::stringstream ss(strng);
  while (getline(ss, line, '\n')) {
  	std::string newLine = "\n";
  	for (auto c : line) {
    	newLine += std::string(k, c);
    }
    for (int i = 0; i < n; i++) {
    	res << newLine;
    }
  }
  return res.str().substr(1);
}
///////////////////////////////////


#include<bits/stdc++.h>

using std::string, std::stringstream;

struct ScalingSqStrings {
    static string scale(const string &s, int k, int v) {
        if(s.empty()) {
            return "";
        }
      
        stringstream ss(s);
        string res, buf;
        while (ss.good()) {
            ss >> buf;
            for(int i = 0; i < v; ++i) {
                for_each(buf.begin(), buf.end(), [&](auto ch){ res.append(k, ch); });
                res.push_back('\n');
            }
        }
        res.pop_back(); //remove last '/n'
      
        return res;
    }
};
/////////////////////////////
