
#include <vector>
#include <algorithm>
int get_in_line(std::vector<int>& arr){
  int res=0;
  std::stable_sort(arr.begin(),arr.end(),[](auto& lhs,auto& rhs)
                   {
                     return lhs==1 || (lhs==2 && rhs!=1); 
                   });
  size_t i,j;
  while(arr.front()==1){
    i=1;
    j=arr.size()-1;
    while(i<=j){
      if(arr[i]!=3 && arr[j]!=3 && arr[i]!=1){
        std::swap(arr[i],arr[j]);
      }
      ++i;
      --j;
    }
    arr.erase(arr.begin());
    ++res;
  }
  res+=std::distance(arr.begin(),std::find(arr.begin(),arr.end(),0))+1;
  return res;
}


//////////////////////
int get_in_line(std::vector<int>& arr){
  int n(arr.size()), c(0);
  stable_sort(arr.begin(), arr.end(), [](const int& a, const int& b) {return a==1 || (b!=1 && a==2);});
  while (arr[c] == 1){c++;
    for (int i(0); i < (n-c) / 2; i++){
      if (arr[i+c]!=1 && arr[n-i-1]!=1 && arr[i+c]!=3 && arr[n-i-1]!=3){
        std::swap(arr[i+c], arr[n-i-1]);}}}
  return find(arr.begin(), arr.end(), 0) - arr.begin() + 1;}

#include <vector>
#include <algorithm>

int get_priority(const int g) {
    switch(g) {
        case 1: return 1;
        case 2: return 2;
        default: return 3;
    }
}

int get_in_line(std::vector<int> arr) {
    std::stable_sort(arr.begin(), arr.end(), [](const int l, const int r) {
       return get_priority(l) < get_priority(r);
    });
  
    int minutes = 1;
    while(arr.front() != 0) {
        const auto g = arr.front();
        arr.erase(arr.begin());
        ++minutes;
      
        if(g == 1 && arr.size() > 1) {
            for(std::size_t i = 0, j = arr.size() - 1; i < j; ++i, --j) {
                if(arr[i] == 1 || arr[j] == 1) continue;
                if(arr[i] == 3 || arr[j] == 3) continue;
                std::swap(arr[i], arr[j]);
            }
        }
    }

    return minutes;
}

///////////////////


#include <vector>
int get_in_line(std::vector<int>& arr){
  std::vector<int> res;
  int i, j, temp, steps;
  for(i=0; i<arr.size(); i++){
    if(arr[i] == 1){
      res.push_back(arr[i]);
    }
  }
  for(i=0; i<arr.size(); i++){
    if(arr[i] == 2){
      res.push_back(arr[i]);
    }
  }
  for(i=0; i<arr.size(); i++){
    if(arr[i] != 1 && arr[i] != 2){
      res.push_back(arr[i]);
    }
  }
  for(i=0; i<res.size(); i++){
    std::cout << res[i] << " ";
  }
  std::cout << "\n";
  steps = 0;
  while(res[0] == 1){
    i = 1;
    j = res.size()-1;
    while(i<=j){
      if(res[i] != 3 && res[j] != 3 && res[i] != 1){
        temp = res[i];
        res[i] = res[j];
        res[j] = temp;
      }
      i++;
      j--;
    }
    res.erase(res.begin()+0);
    steps++;
  }
  while(res[0] != 0){
    res.erase(res.begin()+0);
    steps++;
  }
  steps++;
  return steps;
}