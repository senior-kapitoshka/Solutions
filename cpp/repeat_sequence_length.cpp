#include <map>
#include <numeric>
#include <string>
int repeat_sequence_len(int a0)
{
    std::map<int,int>mp;
  mp[a0]=1;
  int res=0;
  while(true){
    std::string a=std::to_string(a0);
    int n=std::accumulate(a.begin(),a.end(),0,[](int sum,auto c){
      return sum+=(c-'0')*(c-'0');
    });
    if(mp.count(n)){
      res=mp[n];
      break;
    }else{
      std::for_each(mp.begin(),mp.end(),[](auto& p){
        ++p.second;
      });
      mp[n]=1;
      std::swap(n,a0);
    }
  }
  return res;
}

/////////////////////
#include <cmath>
int repeat_sequence_len( int a ) {
  do { int sum{};
    do sum += pow( a % 10, 2 );
    while ( a /= 10 );
    if ( sum == 1 ) return 1;
    a = sum;
  } while ( a > 9 );
  return 8;
}

/////////////////
#include <vector>
int repeat_sequence_len(int a0)
{
	int res = 0;
	std::vector<int> digits;
	std::vector<int> results;

	while (res >= 0)
	{
		//split number into digits
		for (a0 = a0; a0 > 0; a0 /= 10) digits.push_back(a0 % 10);

		//sum up the square of digits
		a0 = 0;
		for (size_t i = 0; i < digits.size(); i++)
		{
			a0 += digits[i] * digits[i];
		}
		digits.clear();

		//check if the result already existed
		for (size_t i = 0; i < results.size(); i++)
		{
			if (a0 == results[i]) return results.size() - i;
		}
		results.push_back(a0);
	}
	return res;
}

////////////////////
#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;
int repeat_sequence_len(int a0)
{
  string num = to_string(a0); // 123
  vector<string> memory;
  int el = 0;
  while (true)
  {
    for (int i = 0; i < memory.size(); i++)  // Loop On The Memory
      if (memory.at(i) == num)               // Check if there is no the same number in the memory
        return memory.size() - i;            // Return The Number Of The Duplicte Numbers
    memory.push_back(num);                   // Put The Number In The Memory If There In No The Same One Into
    for (int i = 0; i < num.length(); i++)   // Get The New Number Using F(N)
      el += (num[i] - '0') * (num[i] - '0'); // Convert The String Number To Integer Number
    num = to_string(el);                     // Reset The Old Number To The New Number
    el = 0;                                  // Set The Integer Number To Zero
  }
  return -1;
}

/////////////////
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <array>
#include <cmath>
#include <algorithm>
#include <iterator>
#include<numeric>
#include <cstdint>
#include<bitset>
#include <vector>
#include <unordered_set>
#include <utility>
#include<variant>
#include<map>
#include<functional>
using namespace std;
//7.11
/* */
int F(int n) {
	//123 →  14 (1 x 1 + 2 x 2 + 3 x 3)
	int sum = 0;
	while (n > 0)
	{
		int p = n % 10;
		sum += p * p;
		n = n / 10;
	}
	return sum;
}
int repeat_sequence_len(int a0)
{
	//unordered_set<int> seen; //存储已经出现过的数及位置
	unordered_map<int, int> seen;//存储每个序列及其首次出现的位置
	int a = a0;
	int index = 0;
	while (true)
	{
		if (seen.find(a) != seen.end())
		{
			//找到重复数字
			return index - seen[a];//返回首次出现的位置与当前位置的差值
		}
		//若不重复，继续迭代查找
		seen[a] = index;
		a = F(a);
		index++;

	}
}