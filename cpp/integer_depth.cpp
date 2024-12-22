bool check(int&& dig,std::vector<int>&vc){
  while(dig){
    if(!vc[dig%10]) vc[dig%10]=1;
    dig/=10;
  }
  std::vector<int>ch(10,1);
  return vc==ch;
}

unsigned integer_depth(unsigned n) {
  int cnt=1;
  std::vector<int> vc(10,0);
  for(;cnt<=100;++cnt){
    if(check(n*cnt,vc)) return cnt;
  }
  return -1;
}

//////////////////
unsigned integer_depth(unsigned n) {
  unsigned r = 0;
  for (unsigned s = 0; s != 1023;) {
    for (unsigned x = ++r * n; x > 0; x /= 10) {
      s |= 1 << x % 10;
    }
  }
	return r;
}

/////////////////////
#include <string>
#include <numeric>

unsigned integer_depth(unsigned n) {
  int nums[10] = {0};
  int i = 0;
  while (std::accumulate(std::begin(nums), std::end(nums), 0) < 10){
    i++;
    for (char digit : std::to_string(i*n)){
      int d = digit - '0';
      nums[d] = 1;
    } 
  }
  return i;
}
////////////////
#include <unordered_set>
#include <string>
unsigned integer_depth(unsigned n) {
 std::unordered_set<char> digits;
    int i = 1;
    while (digits.size() < 10) {
        int multiple = n * i;
        std::string str = std::to_string(multiple);
        for (char c : str) {
            digits.insert(c);
        }
        i++;
    }
    return i - 1;
}

//////////////
unsigned integer_depth(unsigned n) {
    std::vector<int> vec{};
    int i = 0;
    while (vec.size() < 10) {
        int num = n * ++i;
        while (num > 0) {
            if (find(vec.begin(), vec.end(), num % 10) == vec.end()) {
                vec.push_back(num % 10);
            }
            num /= 10;
        }
    }
    return i;
}

/////////////
