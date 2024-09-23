#include <algorithm>

using namespace std;

int findDeletedNumber(list<int> st, list<int> mt)
{
    std::vector<int>res;
    mt.sort();
    std::set_difference(st.begin(),st.end(),mt.begin(),mt.end(),std::back_inserter(res));
  return res.empty()?0:res.front();
}
//////////////////
#include <numeric>

using namespace std;


int findDeletedNumber(list<int> startingList, list<int> mixedList)
{
    int sumStarting = std::accumulate(startingList.begin(), startingList.end(), 0);
    
    int sumMixed = std::accumulate(mixedList.begin(), mixedList.end(), 0);
    
    return sumStarting - sumMixed;
}

///////////////////
#include <numeric>
int findDeletedNumber( std::list< int > s, std::list< int > m ) {
  s.splice( s.cend(), m );
  return accumulate( s.cbegin(), s.cend(), 0, std::bit_xor() );
}
///////////////////
