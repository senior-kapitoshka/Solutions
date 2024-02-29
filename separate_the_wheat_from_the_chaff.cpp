#include <vector>
#include <algorithm>

using namespace std ; 

vector <long long int> wheatFromChaff (vector <long long int> v)
{
  vector <long long int>val=v;
  size_t i=0;
  size_t j=val.size()-1;
  while(i<j){
    if(val[i]>0 && val[j]<0){
      std::swap(val[i],val[j]);
      ++i;
      --j;
    }
    if(val[j]>0) --j;
    if(val[i]<0) ++i;
  }
  return val;
}
//////
#include <vector>

using namespace std;

vector<long long int> wheatFromChaff (vector <long long int> values)
{
    partition(begin(values), end(values), [](long long int value) -> bool { return value < 0; });
    return values;
}