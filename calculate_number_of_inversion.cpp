#include <vector>

class Kata {
  public:
    int countInversions(const std::vector<int>& vec) {
      if(vec.empty())return 0;
      std::vector c=vec;
      int cnt=0;
      for(size_t i=0;i<c.size();++i){
        int cur=c[i];
        for(size_t j=i;j<c.size();++j){
          if(cur>c[j]){
            ++cnt;
          }
        }
      }
      return cnt;
    }
};