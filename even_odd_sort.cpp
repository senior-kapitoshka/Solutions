#include <vector>
#include <set>
#include <deque>

using namespace std ; 

vector <int> menFromBoys (vector <int> val)
{
  std::set<int>st(val.begin(),val.end());
  vector <int> ans(st.size());
  size_t i=0,j=st.size()-1;
  for_each(st.begin(),st.end(),[&ans,&i,&j](auto& c)
           {
             if(c%2==0){
               ans[i]=c;
               ++i;
             }else{
               ans[j]=c;
               --j;
             }
           });
  return ans;
  
}
///////////////////////////
//EXECUTION EXPML MUTEX
//////////////////////////
#include <vector>
#include <set>
#include <deque>
#include <execution>
#include <mutex>

using namespace std ; 

vector <int> menFromBoys (vector <int> val)
{
  std::set<int>st(val.begin(),val.end());
  vector <std::mutex> l(st.size());
  vector <int> ans(st.size());
  size_t i=0,j=st.size()-1;
  for_each(std::execution::par,st.begin(),st.end(),[&l,&ans,&i,&j](auto& c)
           {
             if(c%2==0){
               std::lock_guard<std::mutex>lg (l[i]);
               ans[i]=c;
               ++i;
             }else{
                std::lock_guard<std::mutex>lg (l[i]);
               ans[j]=c;
               --j;
             }
           });
  return ans;
  
}

////////////////////////////
//EXECUTION EXPML ATOMIC
//////////////////////////

#include <vector>
#include <set>
#include <deque>
#include <execution>
#include <atomic>

using namespace std ; 

vector <int> menFromBoys (vector <int> val)
{
  std::set<int>st(val.begin(),val.end());
  
  vector <atomic_int> ans(st.size());
  size_t i=0,j=st.size()-1;
  for_each(std::execution::par,st.begin(),st.end(),[&ans,&i,&j](auto& c)
           {
             if(c%2==0){
               
               ans[i]=c;
               ++i;
             }else{
               
               ans[j]=c;
               --j;
             }
           });
  return {ans.begin(),ans.end()};
  
}
////////////////////////////
//EXECUTION EXPML PARTITION ASYNC
//////////////////////////
#include <vector>
#include <execution>
#include <future>

using namespace std ; 

std::vector<int> menFromBoys(std::vector<int> values)
{
    auto it = std::partition(std::execution::par,begin(values), end(values), [](auto n) {return n % 2 == 0;});
    std::future<void>ls=std::async(std::launch::async,[&values,&it]
                                   {std::sort(begin(values), it);});
    std::future<void>rs=std::async(std::launch::async,[&values,&it]
                                   {std::sort(it, end(values), std::greater<>());});
    ls.get();
    rs.get();
    values.erase(std::unique(begin(values), end(values)), end(values));
    return values;
}

////////////////////////////////



std::vector<int> menFromBoys(std::vector<int> values)
{
    auto it = std::partition(begin(values), end(values), [](auto n) {return n % 2 == 0;});
    std::sort(begin(values), it);
    std::sort(it, end(values), std::greater<>());
    values.erase(std::unique(begin(values), end(values)), end(values));
    return values;
}
////////////////////////
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std ; 

vector <int> menFromBoys (vector <int> values){
  std::sort(begin(values), end(values), [](int a, int b){return std::abs(a % 2) != std::abs(b % 2) ? (b % 2) : (b % 2 ? b < a : a < b);});
  values.erase(std::unique(begin(values), end(values)), end(values));
  return values;
}
///////////////////////////

#include <vector>
#include <algorithm>

auto menFromBoys (std::vector<int> v)
{
  std::sort(v.begin(), v.end(), [](auto a, auto b){
    if(a % 2 == 0 && b % 2 == 0) return a < b;
    if(a % 2 == 0) return true;
    if(b % 2 == 0) return false;
    return a > b; 
  });
  v.erase(std::unique(v.begin(), v.end()), v.end());
  return v;
}/////////////////////////
#include <vector>

std::vector<int> menFromBoys(std::vector<int> v)
{
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  auto it = std::partition(v.begin(), v.end(), [](int i) { return i % 2 == 0; });
  std::sort(v.begin(), it);
  std::sort(it, v.end(), std::greater<int>());
  return v;
}