
std::vector<int> h(std::vector<int>& a){
    int i=0;
    int j=a.size()-1;
    std::vector<int>n;
    while(i!=j && i<j){
          n.push_back(a[i]+a[j]);
          ++i;--j;
    }
    if(a.size()%2!=0){
        n.push_back(a[std::floor(a.size()/2)]);
    }
    return n;
}

 std::vector<int> foldArray(std::vector<int> a, int r)
    {
      
        for(auto i=0;i<r;++i){
            a=h(a);
        }
      return a;
    }

///////////////////////////////////////////////////////////
#include <algorithm>
#include <functional>
#include <vector>

struct Kata
{
    std::vector<int> foldArray(std::vector<int> a, int runs)
    {
      for (; runs > 0; --runs) 
      {
        const auto half = a.size() / 2;
        std::transform(std::cbegin(a), std::cbegin(a) + half, std::crbegin(a), std::begin(a), std::plus<int>());
        a.resize((a.size() + 1) / 2);
      }
      return a;
    }
};
///////////////////////////////////////////////////////////////

class Kata
{
public:
    std::vector<int> foldArray(std::vector<int> array, int runs)
    {
        for (int r = 0; r < runs; r++) {     
          int length = array.size();
          for (int i = 0; i < length / 2; i++) {
              array[i] = array[i] + array.back();
              array.pop_back();  
          }
        }
        return array;
    }
};
/////////////////////////////////////////////////////
class Kata
{
public:
    std::vector<int> foldArray(std::vector<int> array, int runs)
    {
        while(runs --> 0) {
          std::transform(array.begin(), array.begin() + array.size()/2,
                         array.rbegin(), array.begin(), std::plus<>{});
          array.resize((1+array.size())/2);
        }
        return array;
    }
};