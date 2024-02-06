#include <vector>
#include <array>
#include <set>
#include <algorithm>
#include <iostream>

void sw(std::array<int, 4>& a){
    std::swap(a[0],a[1]);
    std::swap(a[0],a[2]);
    std::swap(a[2],a[3]);
}

bool muts(std::array<int, 4>& lhs, std::array<int, 4> rhs){
    if(lhs==rhs) return true;
    sw(lhs);
    if(lhs==rhs) return true;
    sw(lhs);
    if(lhs==rhs) return true;
    sw(lhs);
    return lhs==rhs?true:false;   
}


int count_different_matrices(const std::vector<std::array<int, 4>> &mtrx) {
  std::vector<std::array<int, 4>>st;
  st.push_back(mtrx.front());
  std::for_each(mtrx.begin()+1,mtrx.end(),[&st](const auto& a){
    if(std::find_if(st.begin(),st.end(),[&a](auto& m){return muts(m,a);})==st.end())
      st.push_back(a);
  });
  return st.size();
}

//////////////
#include <vector>
#include <array>
#include <set>

std::array<int, 4> rotate(const std::array<int, 4>& in)
{
  return { in[2], in[0], in[3], in[1] };
}

int makeHash(const std::array<int, 4>& m)
{
  int hash{ 0 };
  
  hash |= (m[0] << 0);
  hash |= (m[1] << 4);
  hash |= (m[2] << 8);
  hash |= (m[3] << 12);
  
  return hash;
}

int count_different_matrices(const std::vector<std::array<int, 4>> &matrices) {
    std::set<int> processed;
    int count { 0 };
  
    for (const auto& m : matrices)
    {
      auto hash = makeHash(m);
      
      if (processed.find(hash) == processed.end())
      {
        processed.insert(hash);
        auto temp = m;
        
        for (int i = 0; i < 3; ++i)
        {
          temp = rotate(temp);
          hash = makeHash(temp);
          processed.insert(hash);
        }
        
        ++count;
      }
    }
  
    return count;
}

///////////////////
#include <vector>
#include <array>
#include <set>

using matrix_t = std::array<int, 4>;
using hash_t = unsigned int;

matrix_t rotate(const matrix_t& a)
{
  matrix_t result;
  result[0] = a[2];
  result[1] = a[0];
  result[2] = a[3];
  result[3] = a[1];
  return result;
}

hash_t matrix_hash(const matrix_t& a, size_t rotationLeft = 4)
{
  if (rotationLeft == 0)
  {
    return 0;  
  }
  
  hash_t result = a[0];
  for (int i=1; i <4; ++i)
  {
      result *= 10;
      result += a[i];
  }  
  return std::max(result, matrix_hash(rotate(a), --rotationLeft));
}

int different_hashes(const std::vector<hash_t>& hashes)
{
  std::set<hash_t> diff_hashes(hashes.begin(), hashes.end());
  return diff_hashes.size();
}

int count_different_matrices(const std::vector<std::array<int, 4>> &matrices) {
  std::vector<hash_t> hashes;
  for (const auto& m : matrices)
  {
    hashes.push_back(matrix_hash(m));
  }
  return different_hashes(hashes);
}

/////////////////////////
#include <vector>
#include <array>
#include<unordered_set>
using namespace std;
template<>
struct std::hash< array<int, 4>> {
	std::size_t operator()(array<int, 4> const& arr)const noexcept {
		size_t h1= std::hash<int>{}(arr[0]);
			size_t h2 = std::hash<int>{}(arr[1]);
			size_t h3 = std::hash<int>{}(arr[2]);
			size_t h4 = std::hash<int>{}(arr[3]);
		return h1 + h2 + h3 + h4;
	}
};
template<>
struct std::equal_to< array<int, 4>> {
	bool operator()(array<int, 4> const& arr_left, array<int, 4> const& arr_right)const  {
		if (arr_left[0] == arr_right[1] && arr_left[1] == arr_right[3] && arr_left[2] == arr_right[0] && arr_left[3] == arr_right[2]) {
			return true;
		}

		if (arr_left[0] == arr_right[3] && arr_left[1] == arr_right[2] && arr_left[2] == arr_right[1] && arr_left[3] == arr_right[0]) {
			return true;
		}
		if (arr_left[0] == arr_right[2] && arr_left[1] == arr_right[0] && arr_left[2] == arr_right[3] && arr_left[3] == arr_right[1]) {
			return true;
		}
if (arr_left[0] == arr_right[0] && arr_left[1] == arr_right[1] && arr_left[2] == arr_right[2] && arr_left[3] == arr_right[3]) {
			return true;
		}
	
		return false;
	}
};
int count_different_matrices(const std::vector<std::array<int, 4>> &matrices) {
    unordered_set<array<int, 4>> obj;
	for (auto& arr : matrices) {
		obj.insert(arr);
	}
	return obj.size();
}