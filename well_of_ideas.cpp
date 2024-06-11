#include <string>
#include <vector>
#include <algorithm>

std::string well(const std::vector<std::vector<std::string>>& arr) {
  int cnt=0;
  std::for_each(arr.begin(),arr.end(),[&cnt](auto& v){
    cnt+=std::count_if(v.begin(),v.end(),[](auto& i){
      return i.front()=='g' || i.front()=='G';
    });
  });
  return (cnt==2||cnt==1)?"Publish!":cnt>=2?"I smell a series!":"Fail!";
}