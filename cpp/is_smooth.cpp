#include<vector>
#include <iostream>

bool isSmooth(const std::vector<int>& arr){
  if(arr.size()==2) return arr.front()==arr.back();
  if(arr.size()==3) return arr.front()==arr.back() && arr[arr.size()/2]==arr.back();
  else if(arr.size()>2 && arr.size()%2==1){
    return (arr.front()==arr.back() && (arr[arr.size()/2]==arr.back()));
  }
  return (arr.front()==arr.back() && (arr[arr.size()/2-1]+arr[arr.size()/2])==arr.back());
}

/////////////////
#include<vector>

bool isSmooth(const std::vector<int>& arr)
{
   int midVal = arr.size() / 2, ex = 1 - arr.size() % 2;
    return  arr.front() == arr.back() &&   arr.front() ==  arr[midVal] + ex *  arr[midVal- ex];
}

/////////////////
bool isSmooth( const std::vector< int >& a ) {
  const auto m{ a.size() / 2 };
  const auto mid{ a.size() & 1 ? a[ m ] : a[ m ] + a[ m-1 ] };
  return a.front() == mid && mid == a.back();
}

/////////////////
