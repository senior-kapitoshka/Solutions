#include <algorithm>
#include <sstream>

class ComposeSqStrings
{
public:
    static std::string compose(const std::string &s1, const std::string &s2){
      std::stringstream ss1(s1);
      std::vector<std::string>vs1;
      for(std::string s;std::getline(ss1,s);){
        vs1.push_back(std::move(s));
      }
      std::stringstream ss2(s2);
      std::vector<std::string>vs2;
      for(std::string s;std::getline(ss2,s);){
        vs2.push_back(std::move(s));
      }
      std::stringstream sss;
      std::for_each(vs1.begin(),vs1.end(),[i=1,&vs2,&sss](auto& s)mutable{
        sss<<s.substr(0,i)<<vs2[vs2.size()-i].substr(0,vs2.size()-(i++)+1);
        i!=vs2.size()+1?sss<<"\n":sss<<"";
      });
      return sss.str();
    }
};

/////////////////////////////////////
#include <cmath>
class ComposeSqStrings
{
public:
    static std::string compose(const std::string &s1, const std::string &s2){
        int n = (int(sqrt(4*s1.length()+5))-1)/2;
        std::ostringstream ans;
        for(int i=1;i<=n;++i)
            ans << '\n' << s1.substr((i-1)*(n+1),i) << s2.substr((n-i)*(n+1),n-i+1);
        return ans.str().substr(1);
    }
};

////////////////////////////
struct ComposeSqStrings {
    static std::string compose(const std::string &s1, const std::string &s2) {
        std::string s;
        for (int i = 0, n = s1.find('\n'); i < n; s += (n - ++i) ? "\n" : "")
            s += s1.substr(i * (n + 1), i + 1) + s2.substr(n * (n - i) - i - 1, n - i);
        return s;
    }
};
/////////////////
struct ComposeSqStrings {
  static std::string compose( const std::string& s1,
                              const std::string& s2 ) {
    size_t len1{ 1 }, len2{ s1.find( '\n' )},
           pos1{ 0 }, pos2{ s2.size() - len2 };
    const size_t shift{ len2 + 1 };
    std::string s;
    s.reserve( len2 * shift );
    while ( len2 )
      s += s1.substr( pos1, len1++ ) +
           s2.substr( pos2, len2-- ) + '\n',
      pos1 += shift, pos2 -= shift;
    return s.pop_back(), s;
  }
};

////////////
