#include <array>
#include <algorithm>
#include <set>

unsigned int mem_alloc(const std::array<unsigned int, 16>& b) {
  std::set<std::array<unsigned int, 16>>st;
  std::array<unsigned int, 16>arr=b;
  int cnt=0;
  while(true){
    auto p=st.insert(arr);
    if(p.second==false){
      break;
    }
    auto mx=std::max_element(arr.begin(),arr.end());
    int x=*mx;
    size_t dist=std::distance(arr.begin(),mx);
    arr[dist]=0;
    ++dist;
    for(int i=0;i<x;++i){
          ++arr[dist++%16];
    }
    ++cnt;
  }
  return cnt;
}

/////////////////////////////
#include <algorithm> 
#include <array>
#include <set>

unsigned int mem_alloc(std::array<unsigned int, 16> banks) {
  std::set<std::array<unsigned int, 16>> states;
  unsigned int r = 0;
  while (1) {
    if (states.find(banks) != states.end()) return r;
    states.insert(banks);
    int max = *std::max_element(banks.begin(), banks.end());
    int index = std::distance(banks.begin(), std::find(banks.begin(), banks.end(), max));
    int a = max / 16, b = max % 16;
    banks[index] = a;
    for (int i = 1; i < 16; i++)
      banks[(index + i) % 16] += a + (b-- > 0);
    r++;
  }
}

///////////////////////////
#include <array>
#include <unordered_set>
#include <vector>

unsigned int mem_alloc(const std::array<unsigned int, 16>& banks) {
  using State = std::array<unsigned int, 16>;
  std::unordered_set<State, size_t(*)(const State&)> seen(0, [](const State& s) {
    size_t hash = 0;
    for (auto val : s) {
      hash = hash * 31 + val;  // Simple polynomial hash
    }
    return hash;
  });

  State current = banks;
  unsigned int cycles = 0;

  while (seen.insert(current).second) {  // Check for duplicates while inserting
    cycles++;

    // Find bank with most blocks
    unsigned int max_blocks = 0;
    size_t max_index = 0;
    for (size_t i = 0; i < 16; ++i) {
      if (current[i] > max_blocks) {
        max_blocks = current[i];
        max_index = i;
      }
    }

    // Redistribute blocks
    current[max_index] = 0;
    size_t current_index = (max_index + 1) % 16;
    while (max_blocks > 0) {
      current[current_index]++;
      max_blocks--;
      current_index = (current_index + 1) % 16;
    }
  }

  return cycles;
}

//////////////////////
#include <array>
#include <unordered_set>

std::string genKey(const std::array<unsigned int, 16>& banks) {
    std::string key;
    for (const auto& val : banks) {
        key += std::to_string(val) + ",";
    }
    return key;
}

unsigned int mem_alloc(const std::array<unsigned int, 16>& banks) {
    std::array<unsigned int, 16> mutableBanks = banks;
    std::unordered_set<std::string> seen;
    unsigned int counter = 0;

    while (seen.insert(genKey(mutableBanks)).second) {
        auto maxIt = std::max_element(mutableBanks.begin(), mutableBanks.end());
        unsigned int maxIndex = std::distance(mutableBanks.begin(), maxIt);
        unsigned int blocks = *maxIt;
        mutableBanks[maxIndex] = 0;
      
        while (blocks > 0) {
            maxIndex = (maxIndex + 1) % mutableBanks.size();
            mutableBanks[maxIndex]++;
            blocks--;
        }  
        counter++;
    }

    return counter;
}

////////////////////
#include <array>
#include <unordered_set>

using namespace std;

constexpr int SIZE = 16;
//constexpr int SIZE = 4;

/*
- general principle -
stores hashes of the array of each step
(in order to be more efficient, both memory-wise [less space needed than saving the whole array],
as well as computational [simple custom hash function for the array])
in an hash set (unordered list, uses hash values directly for finding a new hash value [in order to cycle check]).

also uses an enhanced distribution method, that does not work by distributing one element at a time to the next slot,
but rather calculates for each slot, how many memory-elements it receives.
*/

long gen_hash(array<unsigned int, SIZE>& arr) {
  long hash = 0;
  for (unsigned int n : arr) hash = hash * 31 + n;
  return hash;
}

unsigned int mem_alloc(const array<unsigned int, 16>& banks) {
  array<unsigned int, SIZE> state;
  for (int i = 0; i < SIZE; i++) state[i] = banks[i]; // copy
  
  unordered_set<long> state_hashes;
  state_hashes.insert(gen_hash(state));
  
  unsigned int largest_val;
  int largest_pos;
  int add;
  int rest;
  bool overflow;
  long curr_hash;
  
  for (unsigned int turns = 1;; turns++) {
    // finding largest block
    largest_val = state[0];
    largest_pos = 0;
    for (int i = 1; i < SIZE; i++) if (state[i] > largest_val) {
      largest_val = state[i];
      largest_pos = i;
    }

    // re-distribution

    // optimization of above code
    add = largest_val / SIZE;
    rest = largest_val % SIZE;
    overflow = largest_pos + rest >= SIZE;
    for (int i = 0; i < SIZE; i++) {
      if (i == largest_pos) state[i] = add;
      else if ((i > largest_pos and i <= largest_pos + rest) or (overflow and i <= (largest_pos + rest) % SIZE)) state[i] += add + 1;
      else state[i] += add;
    }
    
    // loop check
    curr_hash = gen_hash(state);

    if (state_hashes.find(curr_hash) != state_hashes.end()) return turns;
    state_hashes.insert(curr_hash);
  }
}

/////////////////////////
#include <array>
#include <unordered_set>

struct arr {
    size_t operator()(const std::array<unsigned int, 16>& arr) const {
        unsigned int h = 0;
        for (const auto& elem : arr) h ^= std::hash<unsigned int>{}(elem)+0x9e3779b9 + (h << 6) + (h >> 2);
        return h;
    }
};

unsigned int mem_alloc(const std::array<unsigned int, 16>& banks) {
    std::array<unsigned int, 16> bs = banks;
    std::unordered_set<std::array<unsigned int, 16>, arr> con;
    con.insert(bs);
    unsigned int res = 0;

    while (true) {
        int max_bl = 0;
        int max_ix = 0;
        for (int i = 0; i < bs.size(); ++i) {
            if (bs[i] > max_bl) {
                max_bl = bs[i];
                max_ix = i;
            }
        }
        bs[max_ix] = 0;
        while (max_bl > 0) {
            max_ix = (max_ix + 1) % bs.size();
            ++bs[max_ix];
            --max_bl;
        }
        if (con.count(bs) > 0) break;
        con.insert(bs);
        ++res;
    }

    return ++res;
}