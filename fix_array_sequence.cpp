
//fail ramdom tests
std::vector<int> solve(std::vector<int> v){
  std::deque<int> res;
  std::vector<std::pair<int,bool>>vc;
  vc.reserve(v.size());
  std::transform(v.begin(),v.end(),std::back_inserter(vc),[](auto i){return std::pair<int,bool>{i,false};});
  res.push_back(v.front());
  vc.front().second=true;
  while(res.size()<v.size()){
    for(auto& [val,flag]:vc){
      if((res.back()/3==val || res.back()*2==val)&& !flag) {
        res.push_back(val);
        flag=true;
      }
      if((res.front()/2==val || res.front()*3==val)&& !flag) {
        res.push_front(val);
        flag=true;
      }
    }
  }
  return std::vector<int>(res.begin(),res.end());
}

////////////////////////////////////
std::vector<int> solve( std::vector< int > v ) {
  sort( v.begin(), v.end() );
  std::deque d{ v.front() };
  auto check( []( int a, int b ){ return a == b * 2 || a == b / 3; } );
  for ( size_t i{ 1 }; i < v.size(); ++i )
    if ( check( d.front(), v[ i ] )) d.push_front( v[ i ] );
    else if ( check( v[ i ], d.back() )) d.push_back( v[ i ] );
    else v.push_back( v[ i ] );
  return { d.cbegin(), d.cend() };
}

////////////////////////
std::vector<int> solve(std::vector<int> v){
  std::deque<int> d;
  std::vector<int>::iterator it = v.begin();
  d.push_back(*it);
  *it = 0;
  while (d.size() != v.size()) {
    if (++it == v.end()) it = v.begin();
    if (*it) 
      if (*it == d.back() * 2 || *it * 3 == d.back()) {
        d.push_back(*it);
        *it = 0;
      } else
        if (*it == d.front() * 3 || *it * 2 == d.front()) {
          d.push_front(*it);
          *it = 0;
        }
  }
  std::vector<int> r;
  std::copy(d.begin(),d.end(),std::back_inserter(r));
  return r;
}

////////////////////
#include <algorithm>
std::vector<int> solve(std::vector<int> v){
    struct Number {
      int number = 0, deuces = 0, triplets = 0;
      Number(int x) {
        number = x;
        for (;x % 2 == 0; x /= 2) deuces ++;
        for (;x % 3 == 0; x /= 3) triplets ++;
      };
    };
    std::vector<Number> numbers (v.cbegin(), v.cend());
  
    std::sort(numbers.begin(), numbers.end(), [](auto x, auto y) {
      return (x.triplets != y.triplets) ? x.triplets > y.triplets : x.deuces < y.deuces;
    });
  
    std::vector<int> result;
    for (auto n : numbers) result.push_back(n.number);
  
    return result;
}

//////////////////////////
#include <vector>
#include <algorithm>

bool cmparator(int i,int j) {
  int i2 = 0;
  while (i % 2 == 0) {
    i2 ++;
    i /= 2;
  }
  
  int i3 = 0;
  while (i % 3 == 0) {
    i3 ++;
    i /= 3;
  }
  
  int j2 = 0;
  while (j % 2 == 0) {
    j2 ++;
    j /= 2;
  }
  
  int j3 = 0;
  while (j % 3 == 0) {
    j3 ++;
    j /= 3;
  }
  
  if (i3 != j3) {
    return i3 > j3;
  } else {
    return i2 < j2;
  }
}

std::vector<int> solve(std::vector<int> v) {
    sort(v.begin(), v.end(), cmparator);
    return v;
}

////////////////////

