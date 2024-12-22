#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<std::pair<int, int>> twos_difference(const std::vector<int> &vec) {
  
  std::vector<std::pair<int, int>> res;
  std::for_each(vec.begin(),vec.end(),[&res,&vec](auto& i){
    std::for_each(vec.begin(),vec.end(),[&res,i](auto& j){
      
      if(std::abs(i-j)==2){
        std::pair<int,int>p;
        p.first=i>j?j:i;
        p.second=i>j?i:j;
        res.push_back(p);
      }
      
    });
  });
  std::sort(res.begin(),res.end());
  res.erase(std::unique(res.begin(),res.end()),res.end());
  return res;
}
////////////////////////
#include <utility>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> twos_difference(std::vector<int> vec)
{
    std::vector<std::pair<int, int>> res; res.reserve(vec.size());
    std::sort(vec.begin(), vec.end());
    for (auto it = vec.cbegin(); it != vec.cend(); it++)
        if (auto it1 = std::find(it, vec.cend(), *it + 2); it1 != vec.cend())
            res.emplace_back(std::make_pair(*it, *it1));
    return res;
}
////////////////
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> twos_difference(std::vector<int> vec) {
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

    std::vector<std::pair<int, int>> res;
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        for (std::size_t i = 1; it + i < vec.cend(); ++i) {
            const auto a = *it;
            const auto b = *(it + i);
            if (std::abs(a - b) == 2) res.emplace_back(a, b);
        }
    }

    return res;
}
////////////////
//Author Gavin Cobb
//total time: 3388 ms
//using quicksort and then vector comparison
#include <utility>
#include <vector>
std::vector<int> quicksort(const std::vector<int> &vec, int L, int R);
std::vector<int> quicksort(const std::vector<int> &vec, int L, int R) {
    int i, j, mid, piv;
    int temp;
    std::vector<int> tempVec = vec;
    i = L;
    j = R;
    mid = L + (R - L) / 2;
    piv = tempVec[mid];

    while (i<R || j>L) {
        while (tempVec[i] < piv)
            i++;
        while (tempVec[j] > piv)
            j--;

        if (i <= j) {
            temp = tempVec[i];
            tempVec[i] = tempVec[j];
            tempVec[j] = temp; //error=swap function doesnt take 3 arguments
            i++;
            j--;
        }
        else {
            if (i < R)
                tempVec = quicksort(tempVec, i, R);
            if (j > L)
                tempVec = quicksort(tempVec, L, j);
            return tempVec;
        }
    }
    return tempVec;
}
std::vector<std::pair<int, int>> twos_difference(const std::vector<int> &vec) {
  std::vector<std::pair<int, int> > twos;
  int tempNum = 0;
  
  std::vector<int> newVec;
  newVec = quicksort(vec, 0, (int)vec.size()-1);
  for(std::size_t i = 0; i < newVec.size(); i++){
    tempNum = newVec[i] + 2;
    for(std::size_t j = 0; j < newVec.size(); j++){
       if(newVec[j] == tempNum){
         auto p1 = std::make_pair(newVec[i], tempNum);
         twos.push_back(p1);
         //std::make_pair<vec[i], tempnum>;
       }
    }
  }
  return twos;
}
////////////
#include <utility>
#include <vector>
using namespace std;

std::vector<std::pair<int, int>> twos_difference(const std::vector<int>& vec) {
    vector<std::pair<int, int>> arr;
    vector<int> lol = vec;
    std::sort(lol.begin(), lol.end());
    int left = 0;
    int right = 1;
    while (right < lol.size()) {
        int diff = lol[right] - lol[left];
        if (diff == 2) {
            arr.emplace_back(lol[left], lol[right]);
            left++;
            right++;
        } 
        else if (diff < 2) {
            right++;
        } 
        else {
            left++;
        }
    }
    return arr;
}