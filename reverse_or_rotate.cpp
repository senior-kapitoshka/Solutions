#include <string>
#include <algorithm>
#include <vector>

class RevRot
{
public:
    static std::string revRot(const std::string &sg, unsigned int sz){
      std::vector<char>vc;
      std::string res;
      int sum=0;
      std::for_each(sg.begin(),sg.end(),[&res,&sum,&vc,sz,i=0](auto& c)mutable{
        if(i<sz){
          vc.push_back(c);
          sum+=c-'0';
        }else if(i==sz){
          if(sum%2==0){
            res+=std::string(vc.rbegin(),vc.rend());
          }else if(sum%2!=0){
            res+=std::string(vc.begin()+1,vc.end())+vc.front();
          }
          sum=0;
          i=0;
          vc.clear();
          vc.push_back(c);
          sum+=c-'0';
        }
        ++i;
      });
      return vc.size()!=sz?
        res:sum%2==0?res+std::string(vc.rbegin(),vc.rend())
          :res+std::string(vc.begin()+1,vc.end())+vc.front();
    }
};
////////////////////
#include <regex>
#include <numeric>
#include <cmath>

struct RevRot
{
    static std::string revRot(const std::string &str, unsigned int sz)
    {
        std::regex re{".{" + std::to_string(sz) + "}"};
        return std::accumulate(std::sregex_token_iterator{str.begin(), str.end(), re}, {}, std::string{}, [](auto &&sum, std::string chunk)
        {
            return std::move(sum) + (1 & std::accumulate(chunk.begin(), chunk.end(), 0, [](auto sum, char c)
            {
                return sum + std::pow(c - '0', 2);
            }) ? std::string(chunk.data() + 1) + chunk[0] : std::string(chunk.rbegin(), chunk.rend()));
        });
    }
};