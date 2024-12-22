#include <limits>
#include <numeric>
#include <algorithm>

class BestTravel
{
public:
  
  
  static void gen(int& sum,std::vector<int>&vp,int k,int t){
    std::vector<int>ids(vp.size());
    std::iota(ids.begin(),ids.end(),0);
      int p=k-1;
      while(p>=0){
        int x=0;
        for(int i=0;i<k;++i){
         x+=vp[ids[i]];
        }
        if(x<=t){
          sum=std::max(x,sum);
        }
        if(ids[k-1]==(int)vp.size()-1){
          --p;
        }else{
          p=k-1;
        }
        if(p>=0){
          for(int i=k-1;i>=p;--i){
            ids[i]=ids[p]+i-p+1;
          }
        }
      }
  }
  
    static int chooseBestSum([[maybe_unused]]int t, int k, std::vector<int>& ls){
      if(k>(int)ls.size()) return -1;
      if(k==(int)ls.size() && t>=std::accumulate(ls.begin(),ls.end(),0)) return std::accumulate(ls.begin(),ls.end(),0);
      int sum=std::numeric_limits<int>::min();
      gen(sum,ls,k,t);
      return sum==std::numeric_limits<int>::min()?-1:sum;
    }
};

///////////////////////////////

#include <vector>
#include <algorithm>

class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int>& ls);
};

int BestTravel::chooseBestSum(int t, int k, std::vector<int>& ls)
{
    unsigned int n = ls.size();
    if ((unsigned int)k > n) return -1;
    int mx = -1, sm;
    std::string bitmask(k, 1);
    bitmask.resize(n, 0);
    do {
        sm = 0;
        for (unsigned int i = 0; i < n; ++i)
            if (bitmask[i]) sm += ls[i];
        if ((sm >= mx) && (sm <= t)) mx = sm;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    return mx;
}
//////////////////////////


/////////////////////////////////
class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int>& ls, int start = 0);
};

int BestTravel::chooseBestSum(int t, int k, std::vector<int>& ls, int start)
{
  if (k == 0)
    return 0;
  
  int m = -1;
  for (int i = start; i < (int)ls.size() - k + 1; i++)
  {
    int n = chooseBestSum(t - ls[i], k - 1, ls, i + 1);
    if (n != -1 && t >= ls[i] + n) m = std::max(m, ls[i] + n);
  }
  return m;
}

////////////////////////
#include <functional>

class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int>& ls);
};


#define HAS_NO_SOLUTION -1u

int BestTravel::chooseBestSum(int t, int k, std::vector<int>& ls)
{
  if((int)ls.size() < k) return HAS_NO_SOLUTION;  // Не имеет решения
  
  /** Функция для организации рекурсии
   * @param value сумма с каждого погружкния рекурсии
   * @param diveDepth глубена текущего погружения( == 0 - Днище)
   * @param begin начало исследования массива запесей
   * @return возвращает сумму знаяений с каждого слоя
  */
  std::function<int(const int,const int,std::vector<int>::const_iterator)> sumOfDip 
    = [&ls, &t, &sumOfDip](const int value, const int diveDepth, std::vector<int>::const_iterator begin)
    {
        if(!diveDepth)  // Дно достигнуто
        {
            return value;
        }
    
        int result = HAS_NO_SOLUTION;
        for(auto it = begin, end = ls.cend(); it < end; ++it)
        {
            int temp = sumOfDip(*it + value, diveDepth - 1, it + 1);
            if((temp <= t) && (temp > result))
            {
              result = temp;
            }
        }
        return result;
    };
  
  return sumOfDip(0, k, ls.cbegin());
}