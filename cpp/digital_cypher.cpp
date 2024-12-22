class Kata
{
public:
    static std::vector<int> Encode(std::string str, int n){
      std::vector<int> res(str.size());
      std::string nm=std::to_string(n);
      std::transform(res.begin(),res.end(),res.begin(),[i=0,&nm,&str](auto& j)mutable{
         return j+=(nm[i%nm.size()]-'0')+(str[i++]-96);
      });
      return res;
    }
};