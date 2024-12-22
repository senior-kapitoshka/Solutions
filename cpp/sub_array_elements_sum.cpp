#include<vector>
#include <numeric>

long elementsSum(const std::vector<std::vector<int>>& arr, int d = 0){
  return std::accumulate(arr.begin(),arr.end(),0l,
                         [d,i=(int)arr.size()-1](long sum,auto curr)
                         mutable{
                           if(curr.empty()){
                             sum+=d;
                           }else if((int)curr.size()<=i || i<0){
                             sum+=d;
                           }else if((int)curr.size()>i && i>=0){
                             sum+=curr[i];
                           }
                           --i;
                           return sum;
                           
                         });
}

/////////////////////

#include<vector>
#include <numeric>
using namespace std;
long elementsSum(const vector<vector<int>>& a, int d = 0){  
int i = -1,s = a.size()-1;
return accumulate(begin(a),end(a),0,[&i,d,s](int c , vector<int> b){ i++; return c + (s-i <= b.size()-1 && !b.empty() ? b[s-i] : d != 0 ? d : 0);});
}

///////////////
#include <vector>
#include <numeric>

long elementsSum(const std::vector<std::vector<int>>& arr, const int d = 0) {
    return std::accumulate(
        arr.cbegin(), arr.cend(), 0l,
        [i = arr.size(), &d](const long acc, const std::vector<int>& arr) mutable {
            if(arr.size() < i--) return acc + d;
            return acc + arr[i];
        }
    );
}