#include <algorithm>
#include <numeric>
int SJF(std::vector <int> js, int id){
  std::vector<std::pair<int,int>>vp;
  std::transform(js.begin(),js.end(),std::back_inserter(vp),
                [i=0](auto& c)mutable{
                  return std::make_pair(c,i++);
                });
  std::sort(vp.begin(),vp.end(),[](auto& lhs,auto& rhs)
            {return lhs.first<rhs.first;});
  return std::accumulate(vp.begin(),
                         std::find_if(vp.begin(),vp.end(),
                                      [&id](auto& p){
                                        return p.second==id;
                                      })+1,0,
                         [](int sum, auto curr){
                           return sum+=curr.first;
                         });
}
//////////////////
int SJF(std::vector <int> jobs, int index) {
  long long int sum = 0;
  for (int i = 0; i < jobs.size(); ++i) {
    if (jobs[i] < jobs[index]) sum += jobs[i];
    if (jobs[i] == jobs[index] && i <= index) sum += jobs[i];
  }
  return sum;
}
/////////////
