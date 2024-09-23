#include <cmath>
#include <algorithm>
#include <map>
#include <limits>

int minRemove(std::vector<int> arr) {
  if(!is_sorted(arr.begin(),arr.end())) std::sort(arr.begin(),arr.end());
  size_t rp=1,lp=0;
  for(;rp<arr.size();){
    if(arr[lp]*arr[lp]>=arr[rp]) ++rp;
    else{
      ++rp;
      ++lp;
    }
  }
  return lp;
}    
    
#if 0
// fail big_random_tests

int minRemove(std::vector<int> arr) {
  if(arr.empty())return 0;
    if(!is_sorted(arr.begin(),arr.end())) std::sort(arr.begin(),arr.end());
  std::map<int,int>mp;
  int cnt=std::numeric_limits<int>::max();
    std::for_each(arr.begin(),arr.end(),[i=0,&mp,&arr,&cnt](auto& c)mutable{
    for(int j=(int)arr.size()-1;j>=i;--j){
      if(c>=std::sqrt(arr[j])){
        if(mp.count(j))
          break;
        else{
          mp[j]=i; 
          cnt=std::min(cnt,((int)arr.size()-((j-i)+1)));
        }
        break;
      }
    }
    ++i;
  });
  return cnt;
}

#endif

//////////////////////////////
#include <algorithm>
using namespace std;

#define bsearch(a,n) (upper_bound(begin(a),end(a),n)-begin(a))
int minRemove(vector<int> arr) {
	sort(begin(arr), end(arr));
	int i=0, s=(int)arr.size(), m=s, bi;
	while (i < s){
		if (i >= m) break;
		bi = bsearch(arr, arr[i]*arr[i]);
		m = min(m, i+s-bi);
		i+=1;
	}
	return m;
}

//////////////////////
