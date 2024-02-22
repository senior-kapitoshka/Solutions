#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>
#include <utility>


std::string biggest(const std::vector<int> &nums){
  if(nums.empty()) return "";
  if(all_of(nums.begin(),nums.end(),[](auto& i){return i==0;})) return "0";
  std::vector<std::string>vs;
  std::transform(nums.begin(),nums.end(),std::back_inserter(vs),
                [](auto& i){
                  
                  return std::to_string(i);
                });
  
  std::sort(vs.begin(),vs.end(),[](const auto& lhs,const auto& rhs){
      int ab =std::stoi(lhs+rhs);
      int ba =std::stoi(rhs+lhs);
      return ab>ba;
    
    });

  auto w = [](std::string& a,std::string& b){
    return std::move(a)+std::move(b);
  };
  std::string res= std::accumulate(std::next(vs.begin()),vs.end(),vs.front(),w);

  return res;
}
////////////////////////

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
std::string biggest(const std::vector<int>& nums) {
	std::vector<std::string> numsString;
	for (const int& element : nums)  numsString.push_back(std::to_string(element));
	std::sort(numsString.begin(), numsString.end(), [](const std::string& firstNumber, const std::string secondNumber) {
		return stoi(firstNumber + secondNumber) > stoi(secondNumber + firstNumber);
	});
	return numsString[0] == "0" ? "0" : std::accumulate(numsString.begin(), numsString.end(), std::string());
}
///////////////////////
#include <algorithm>
#include <string>
#include <vector>

std::string biggest(const std::vector<int>& numbers)
{
    std::vector<std::string> strings(numbers.size());
    std::transform(begin(numbers), end(numbers), begin(strings),
        [](int n) { return std::to_string(n); });
    std::sort(begin(strings), end(strings), [](auto& a, auto& b) {
        return a + b > b + a;
    });
    std::string result;
    for (auto& s: strings)
        result += s;
    if (result.front() == '0')
        result.erase(1);
    return result;
}