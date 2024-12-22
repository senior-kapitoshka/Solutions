#include <cmath>
#include <algorithm>
#include <iostream>
class Crisis{
public:
static std::string helpZoom(std::vector<int> key){
  int x=std::sqrt((int)key.size());
  if(std::pow(x,2)!=(int)key.size())  return "No";
  if(key.size()%2==1){
    std::vector<int>t(key.begin()+((int)key.size()/2)+1,key.end());
    std::reverse(t.begin(),t.end());
    key.erase(key.begin()+((int)key.size()/2),key.end());
    return key==t?"Yes":"No";
  }
  std::vector<int>t(key.begin()+(int)key.size()/2,key.end());
  std::reverse(t.begin(),t.end());
  key.erase(key.begin()+(int)key.size()/2,key.end());
  return key==t?"Yes":"No";
}
};
/////////////////////////////
using namespace std;
class Crisis {                                               //^^
public:
static string helpZoom(vector<int> key){
  int n = key.size();
  int root = sqrt(n);
  if (root*root != n) return "No";  
  vector<int> v1(key.begin(), key.begin() + n/2 + n % 2), v2(key.begin() + n/2, key.end());
  reverse(v2.begin(), v2.end());
  return v1 == v2 ? "Yes" : "No";
}
};
/////////////////////////
class Crisis {
public:
  static std::string helpZoom( std::vector< int > key ) {
    return equal( key.cbegin(), key.cend() - key.size() / 2, key.crbegin() )
      && sqrt( key.size() ) == int( sqrt( key.size() ) ) ? "Yes" : "No";
  }
};
//////////////////////////
