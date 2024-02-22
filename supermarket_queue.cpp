#include <algorithm>

long queueTime(std::vector<int> cs,int n){
 std::vector<int>vc(n,0);
	for (auto& c : cs){
		*std::min_element(vc.begin(), vc.begin() + n) += c;
	}
	return *std::max_element(vc.begin(), vc.begin() + n);
}
/////////////////////////
#include <queue>
#include <functional>
long queueTime(std::vector<int> customers,int n){
  std::priority_queue<int, std::vector<int>, std::greater<int>> time;
  for (auto &customer: customers) {
    if (time.size() < n) {
      time.push(customer);
    } else {
      auto top = time.top();
      time.pop();
      time.push(top + customer);
    }
  }
  int res;
  while (!time.empty()) {
    res = time.top();
    time.pop();
  }
  return res;
}

/*
3
83,21,17,8,86,32,67,42,1,1,20,80,90,
customer-83
customer-21
customer-17
top-17
top-21
top-25
top-57
top-83
top-107
top-108
top-109
top-124
top-125

time.top()-129
time.top()-204
time.top()-215
res-215
*/
/////////////////////////
long queueTime(std::vector<int> customers,int n)
{
std::vector <long> tills (n);
for(unsigned int i =0; i <customers.size(); i++ )
{
    tills[0]+=customers[i];
    std::sort(tills.begin(),tills.end());
}
return tills[n-1];
}