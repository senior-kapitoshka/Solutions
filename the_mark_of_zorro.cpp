#include <vector> 
#include <algorithm>

template <typename T> std::vector<T> zorro(const std::vector<std::vector<T>> mx) {
  if(mx.empty())return {};
  std::vector<T> res;
  res.reserve(mx.size());
  std::copy(mx.front().begin(),mx.front().end()-1, std::back_inserter(res));
  for(size_t i=0;i<mx.size();++i){
    res.push_back(mx[i][mx.size()-i-1]);
  }
  std::copy(mx.back().begin()+1,mx.back().end(), std::back_inserter(res));
  return res;;
}
////////////////////
template< typename T >
std::vector<T> zorro( const std::vector< std::vector< T >> matrix ) {
  const size_t size{ matrix.size() }, s{ size - 1 };
  std::vector< T > z;
  z.reserve( size ? size * 3 - 2 : 0 );
  for ( size_t row{}; row < size; ++row )
    for ( size_t col{}; col < size; ++col )
      if ( !row || row == s || row + col == s )
        z.push_back( matrix[ row ][ col ]);
  return z;
}