//fail random tests
#include <vector>
#include <utility>
#include <algorithm>
#include <execution>


static int cnt=0;

struct Node{
  Node()
  {
    id=cnt;
    ++cnt;
  }
  int l=1;
  size_t id;
  int e_=std::numeric_limits<int>::min();
};

std::pair<int, int> longest_mountain_pass(const std::vector<int>& ms,const int e) {
  if(ms.empty()) return {0,0};
  cnt=0;
  std::vector<Node>vn(ms.size());
  for(size_t i=1;i<ms.size();++i){
    std::for_each(std::execution::par,vn.begin(),vn.end(),[i,x=ms[i],y=ms[i-1],&e](auto& n){
      if(n.id==i-1 && n.e_==std::numeric_limits<int>::min()){
        n.e_=e;
      }
      if(x<=y && n.id<=i &&  n.e_>=0){
        ++n.l;
      }else if(x>y){
        int r=x-y;
        if(n.e_-r>=0 && n.id<=i ){
           ++n.l;
            n.e_-=r;
        }else if(n.e_-r<0){
          n.e_-=r;
        }
      }
    });
  }
  auto it=std::max_element(vn.begin(),vn.end(),[](auto& lhs, auto& rhs){
    return lhs.l<rhs.l || (lhs.l==rhs.l && lhs.id>rhs.id);
  });
    return {it->l, it->id};
}

//////////////////////////////////////////

using std::vector, std::pair;

pair<int, int> longest_mountain_pass(const vector<int>& mountains, int e) {
  const auto n = mountains.size();
  if (n==0) return {0,0};
  vector<int> costs;  costs.reserve(n-1);
  for (int i=1; i<n; ++i) costs.push_back(std::max(mountains[i] - mountains[i-1], 0));
  struct Pass {
    int size() const { return to - from; }
    int cost_sum, from, to;
  };
  Pass curr{0, 0, 1};
  auto best = curr;
  for (int i=0; i<n-1; ++i) {
    auto x = curr.cost_sum + costs[i];
    if (x <= e) { curr.cost_sum = x; ++curr.to; continue; }   // extend pass; continue
    if (curr.size() > best.size()) best = curr;               // best yet?
    while (x > e) { x -= costs[curr.from]; ++curr.from; }     // move pass forward
    curr.cost_sum = x;
    ++curr.to;
  }
  if (curr.size() > best.size()) best = curr;                 // best yet?
  return {best.size(), best.from};
}
/////////////////////////////////////
#include <vector>
#include <utility>

std::pair<int, int> longest_mountain_pass(const std::vector<int>& mountains, int e) {
  if (mountains.size() == 0) return {0, 0};
  int max_length = 1, start_index = 0, j = 0, x = 0;
  for (int i = 1; i < (int)mountains.size(); i++) {
    x += std::max(0, mountains[i] - mountains[i - 1]);
    for (; x > e; j++) {
      x -= std::max(0, mountains[j + 1] - mountains[j]);
    }
    if (i - j + 1 > max_length) {
      max_length = i - j + 1;
      start_index = j;
    }
  }
  return {max_length, start_index};
}

using namespace std;
//////////////////////////////////////////
#include <vector>
#include <utility>
using namespace std;

std::pair<int, int> longest_mountain_pass(const std::vector<int>& a, int e) {
  int pos=0,lmx=0,length=a.size();
  vector<long long> v(length+1);
  v[0]=0;
  for(int i=1;i<length;++i){
    v[i]=v[i-1];
    if(a[i]>a[i-1])
      v[i]+=a[i]-a[i-1];
  }
  for(int i=0;i<length;++i){
    int l=0,r=length-1;
    while(l<r){
      int mid=(l+r+1)>>1;
      if(v[mid]-v[i]>e) r=mid-1;
      else l=mid;
    }
    if(lmx<l-i+1) lmx=l-i+1,pos=i;
  }
  return {lmx,pos};
}

///////////////////////////
#include <vector>
#include <utility>
std::pair<int, int> longest_mountain_pass(const std::vector<int>& mountains, int limit) {
    if(!mountains.size()) return {0,0};
    // Your code goes here
    int l = 0, e =0;
    int energy = 0;
    int start_index = l;
    int max_length = 0;
    while(e < mountains.size()){
        if(e-l > max_length){
            max_length = e-l;
            start_index = l;
        }
        if(e == mountains.size()-1) break;
        int next = mountains[e+1];
        int current = mountains[e];
        if(current >= next){
            e++;
            continue;
        }
        else {
            if(next - current + energy <= limit){
                e++;
                energy += next - current;
            }
            else{
                l++;
                if(mountains[l-1] < mountains[l])
                    energy -= mountains[l] - mountains[l-1];
            }
        }
    }
    return {max_length+1, start_index};
}


/////////////////
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>

std::pair<int, int> longest_mountain_pass(const std::vector<int>& mountains, int e)
{
    if (mountains.empty()) return {0, 0};
    int start_index = 0, max_length = 1, current_start = 0, current_end = 1;
    std::deque<int> des;
    while (current_end < static_cast<int>(mountains.size()))
    {
        auto de = std::max(mountains[current_end] - mountains[current_end - 1], 0);
        e -= de;
        des.push_back(de);
        current_end++;
        if (e >= 0)
        {
            if (auto length = current_end - current_start; length > max_length)
            {
                max_length = length;
                start_index = current_start;
            }
        }
        else
        {
            current_start++;
            if (!des.empty())
            {
                e += des.front();
                des.pop_front();
            }
        }
    }
    return {max_length, start_index};
}

//////////////////
#include <vector>
#include <utility>

using namespace std;

pair<int, int> longest_mountain_pass(const vector<int>& mountains, int e)
{
  int i = mountains.size()-1, j = mountains.size()-1;
  int i_lmax = 0, lmax = 0, used_energy = 0;
  
  while (i > 0)
  {
    while (i > 0 && used_energy+std::max(0,mountains[i]-mountains[i-1]) <= e)
    {
      used_energy += std::max(0,mountains[i]-mountains[i-1]);
      i--;
    }
    if (lmax <= j-i+1)
    {
      i_lmax = i;
      lmax = j-i+1;
    }
    if (j > 0)
      used_energy -= std::max(0, mountains[j]-mountains[j-1]);
    j--;
  }
  return {lmax, i_lmax};
}

////////////////////////
