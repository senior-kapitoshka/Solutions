class ModSystem
{
public:
    static std::string fromNb2Str(int n, std::vector<int> &sys){
      int x=std::count_if(sys.begin(),sys.end(),[](auto& i){return i%2==0;});
      if(x>=2) return "Not applicable";
      int m=std::accumulate(sys.begin(),sys.end(),1, std::multiplies<int>());
      if(n>m){
        return "Not applicable";
      }
      std::vector<int> v;
      std::transform(sys.begin(),sys.end(),std::back_inserter(v),[&n](auto& i)
                     {return n%i;});
      
      std::string ans="-";
      for(auto i:v){
        ans+=std::to_string(i);
        ans+="--";
      }
      ans.erase(ans.end()-1);
      return ans;
    }
};
////////////////////
#include <sstream>

namespace ModSystem {

    int GCD(int a, int b) {
        if(b)
            while((a %= b) && (b %= a));
	      return a + b;
    }

    std::string fromNb2Str(int n, std::vector<int> &sys) {
        long product = 1;
        for(const auto& i : sys) {
            if(GCD(product, i) != 1)
                return "Not applicable";
            product *= i;
        }
        if(product<n)
            return "Not applicable";
        std::ostringstream oss;
        std::for_each(sys.begin(), sys.end(), [&](const int & i){
            oss << '-' << n%i <<'-';
        });
        return oss.str();
    }
};
///////////////////////
class ModSystem
{
public:
    static std::string fromNb2Str(int n, std::vector<int> &sys)
    {
      std::string s;
      int product = 1;
      for (auto &i : sys) product *= i; 
      if (product <= n) return "Not applicable";
      for (int i = 0, len = sys.size() - 1; i < len; ++i)
      {
        if (std::__gcd(sys[i], sys[i + 1]) != 1) return "Not applicable";
        else if (i == len - 1) s += "-" + std::to_string(n % sys[i]) + "--" + std::to_string(n % sys[i + 1]) + "-";
        else s += "-" + std::to_string(n % sys[i]) + "-";
      }
      return s;
    };
};
