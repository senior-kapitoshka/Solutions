#include <vector>
#include <algorithm>

std::vector<int> cleaned_counts(const std::vector<int>& d) {
  std::vector<int>res;
  std::transform(d.begin(),d.end(),std::back_inserter(res),[mx=d.front()](auto& c)mutable{
    if(c>mx){
      mx=c;
    }else if(c<mx){
      return mx;
    }
    return c;
  });
  return res;
}

/////////////////////////
std::vector<int> cleaned_counts( const std::vector< int >& data ) {
  std::vector< int > correct;
  correct.reserve( data.size() );
  for ( const int sample : data )
    correct.push_back( std::max( sample, correct.back() ));
  return correct;
}

///////////////
#include <range/v3/action/transform.hpp>
#include <vector>

std::vector<int> cleaned_counts(std::vector<int> data) 
{ 
  return data |= ranges::actions::transform([max = -1] (int n) mutable
                                           {
                                             return max = std::max(max, n);
                                           });
}

//////////////////////
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>

std::vector<int> cleaned_counts(const std::vector<int>& data) {
  std::vector<int> res;
  std::partial_sum(data.begin(), data.end(), std::back_insert_iterator(res), [](int a, int b) { return std::max(a, b); });
  return res;
}

///////////////////
#include <vector>
using namespace std;
vector<int> cleaned_counts( vector<int>& data) {
  for(int i = 0;i < data.size()-1;i++){
    if(data[i] > data[i+1]){
      data[i+1] = data[i];
    }
  }
  return data;
}

//////////////////
