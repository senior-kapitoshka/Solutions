#include <map>
#include <algorithm>

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> arr)
    {
        std::map<size_t,int>mp;
      std::vector<int>st;
      for(size_t i=0;i<arr.size();++i){
        if(arr[i]%2==0)mp[i]=arr[i];
        else st.push_back(arr[i]);
      }
      std::sort(st.begin(),st.end());
      for(size_t i=0,j=0;i<arr.size();++i){
        mp.count(i)?arr[i]=mp[i]:arr[i]=st[j++];
      }
      return arr;
    }
};

////////////////
#include <algorithm>

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
        std::vector<int> odds;
        std::copy_if(array.begin(), array.end(), std::back_inserter(odds), [] (int x) {return x % 2;});
        std::sort(odds.begin(), odds.end());
        for (int i = 0, j = 0; i < array.size(); i++) if (array[i] % 2) array[i] = odds[j++];
        return array;
    }
};
//////////////////
class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
      for (int i=0; i<array.size(); i++) {
          if(array[i] &1){
            for (int j=i+1; j<array.size(); j++) {
                if(array[j] & 1 && array[j] < array[i]){
                    std::swap(array[i], array[j]);
                }
            }
          }
        }
        return array;
    }
};

/////////////////
