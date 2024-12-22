#include <ostream>
#include <vector>
#include <algorithm>
#include <string>

template <typename T>
void print_vector(std::ostream& os, const std::vector<T>& vec) {
  std::copy(vec.begin(),vec.end(),std::ostream_iterator<T>(os,""));
}

//////////////////////////
#include <ostream>
#include <vector>

template <typename T>
void print_vector(std::ostream& os, const std::vector<T>& vec, size_t i = 0) {
  if (i >= vec.size()) return;
  print_vector(os << vec[i], vec, i + 1);
}

/////////////////
#include <algorithm>
#include <iterator>
#include <ostream>

template <typename C>
void print_vector(std::ostream& os, const C& c) {
  using T = typename std::iterator_traits<decltype(std::cbegin(c))>::value_type;
  std::copy(std::cbegin(c), std::cend(c), std::ostream_iterator<T>(os));
}

///////////////
template <typename U>void print_vector(std::ostream& Q,std::vector<U> S){std::transform(S.begin(),S.end(),S.begin(),[&](U N){return Q<<N,N;});}

/////////////////////
#include <cstddef>
#include <ostream>
#include <vector>

template <typename T>
static void print_vector_helper(std::ostream& os, const std::vector<T>& vec, std::size_t i) {
    if (i < vec.size()) {
        os << vec[i];
        print_vector_helper(os, vec, i + 1);
    }     
}

template <typename T>
void print_vector(std::ostream& os, const std::vector<T>& vec) {
    print_vector_helper(os, vec, 0);
}

////////////////
