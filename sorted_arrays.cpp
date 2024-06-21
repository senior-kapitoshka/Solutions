#include <algorithm>

int nthSmallest(std::vector<std::vector<int>> arr, int n)
{
  int ans=0;
    for(int i=0;i<n;++i){
      auto it=std::min_element(arr.begin(),arr.end(),
                           [](auto lhs,auto rhs){
                             return lhs.front()<rhs.front();
                           });
      ans=it->front();
      it->erase(it->begin());
      if(it->empty())arr.erase(it);
    }
  return ans;
                
}

//////////////////////
#include<algorithm>
using namespace std;

int nthSmallest(vector<vector<int>> arr, int n)
{
	 vector<int> v;
   for(size_t i = 0; i<arr.size(); i++)
  	   for(size_t j=0; j<arr[i].size(); j++)
  		     v.push_back(arr[i][j]);
   sort(v.begin(), v.end());
   return v[n-1];
}

/////////////////
int nthSmallest(std::vector<std::vector<int>> arr, int n)
{
    std::vector<int> v;
    for(auto a : arr)
    {
        std::vector<int> aux;
        std::merge(a.begin(), a.end(), v.begin(), v.end(), std::back_inserter(aux));
        v = aux;
    }
    
    return v[n-1];
}

/////////////////
