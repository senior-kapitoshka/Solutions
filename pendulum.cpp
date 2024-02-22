/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
#include <vector>
#include <algorithm>

using namespace std; 

vector <int> Pendulum (vector <int> val)
{
  if(val.empty()) return {};
  sort(val.begin(),val.end());
  std::vector<int>ans(val.size());
  int m=0;
  if(static_cast<int>(val.size())%2!=0){
    m=static_cast<int>(val.size())/2;
  }else{
    m=(static_cast<int>(val.size())-1)/2;
  }
  int l=m-1,r=m+1;
  ans[m]=val[0];
  for(size_t i=1;i<val.size()-1;){
    
    ans[r++]=val[i++];
    ans[l--]=val[i++];
  
  }
  if(static_cast<int>(val.size())%2==0) ans.back()=val.back();
  return ans;
}

int main()
{   for(auto i:Pendulum({22,21,19,27,18,15,24,24}))
        cout<<i<<'-';

    return 0;
}
////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <algorithm>

bool is_even(int n) { return n % 2 == 0; }
bool is_odd(int n) { return not is_even(n); }

std::vector<int> Pendulum(std::vector<int> values)
{
	std::sort(values.begin(), values.end());
	std::vector<int> v(values.size());
	int it = values.size() / 2 - (1 - values.size() % 2);
	for (int i = 0; i < values.size(); ++i) {
		if (is_even(i))
			it -= i;
		else
			it += i;
		v[it] = values[i];
	}
	return v;
}
///////////////////////////////////////////////////////////////////

#include <deque>
std::vector <int> Pendulum (std::vector <int> v){                              // =)
std::deque<int> q;
std::sort(v.begin(), v.end());
for (int i = 0; i < v.size(); ++i)
   i % 2 != 0 ? q.push_back(v[i]) : q.push_front(v[i]);
return std::vector <int> (q.begin(), q.end()); 
}