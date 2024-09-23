#include <sstream>
#include <algorithm>
class Opstrings
{
public:
    static std::string vertMirror(const std::string &str){
      std::string s(str.begin(),str.end());
      std::string res;
      while(!s.empty()){
        std::string x=s.substr(0,s.find_first_of('\n'));
        std::copy(x.rbegin(),x.rend(),std::back_inserter(res));
        s=s.find_first_of('\n')!=s.npos?s.substr(s.find_first_of('\n')+1):"";
        res+=s==""?"":"\n";
      }
      return res;
    }
	  static std::string horMirror(const std::string &str){
      std::string s(str.begin(),str.end());
      std::string res;
      while(!s.empty()){
        std::string x=s.substr(0,s.find_first_of('\n'))+"\n";
        res.insert(0,x);
        s=s.find_first_of('\n')!=s.npos?s.substr(s.find_first_of('\n')+1):"";
      }
      res.pop_back();
      return res;
    }
    // your high order function oper
    //... oper(...);
  template<typename F>
    static std::string oper(F f, const std::string &s){
      return f(s);
    }

};

//////////////////////////
class Opstrings
{
public:
    static std::string vertMirror(const std::string& s) {
        auto strings = split(s);
        for (auto& str : strings) std::reverse(str.begin(), str.end());
        return merge(strings);
    }
    
	  static std::string horMirror(const std::string& s) {
        auto strings = split(s);
        std::reverse(strings.begin(), strings.end());
        return merge(strings);
    }

    static std::string oper(std::string(*f)(const std::string&), const std::string& s) {
        return f(s);
    }
    
private:
    static std::vector<std::string> split(const std::string& s, const char d = delim) {
        std::vector<std::string> result;
        std::istringstream ss(s);
        std::string token;    
        
        while (std::getline(ss, token, d)) {
            result.push_back(token);
        }
        return result;
    }
    
    static std::string merge(const std::vector<std::string>& strings) {
        std::string result;
        for (auto& str : strings) {
            result += str;
            result += delim;
        }
        return result.erase(result.size() - 1);
    }
    
private:
    static const char delim = '\n';
};


//////////////////////
struct Opstrings {
  static std::string vertMirror( const std::string& str ) {
    std::string mirror, line;
    std::istringstream iss( str );
    while ( iss >> line )
      mirror += std::string( line.crbegin(), line.crend() ) + '\n';
    return mirror.pop_back(), mirror;
  }
  static std::string horMirror( const std::string& str ) {
    return vertMirror( std::string( str.crbegin(), str.crend() ));
  }
  template< typename Func >
  static std::string oper( const Func fname, const std::string& str ) {
    return fname( str );
  }
};

///////////////////////
