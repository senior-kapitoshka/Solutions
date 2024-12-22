#include <numeric>
std::vector<long> numbersWithDigitInside(long x, long d)
{
    std::vector<long> res;
    std::vector<long> vc;
  std::string f=std::to_string(d);
  for(long long i=1;i<=x;++i){
     std::string t=std::to_string(i);
    if(t.find(f)!=t.npos)
      vc.push_back(i);
  }
  res.push_back(vc.size());
  long sum=std::accumulate(vc.begin(),vc.end(),0);
  unsigned long prd=std::reduce(vc.begin(),vc.end(),(unsigned long)1, std::multiplies<unsigned long>());
  res.push_back(sum);
  if(vc.empty()) res.push_back(0);
  else res.push_back(prd);
    return res;
}
/////////////////////////////
#include <numeric>

std::vector<long> numbersWithDigitInside(long x, long d)
{
  std::vector<long> num(x), res;
  std::generate(num.begin(), num.end(), [i = 1l]() mutable { return i++; });
  std::copy_if(num.begin(), num.end(), std::back_inserter(res), [=](long n) { return std::to_string(n).find(d + '0') != std::string::npos; });
  return res.empty() ? std::vector<long>{ 0l, 0l, 0l } : std::vector<long>{ (long)res.size(), std::accumulate(res.begin(), res.end(), 0l), std::accumulate(res.begin(), res.end(), 1l, std::multiplies<long>()) };
}
/////////////////////////////
#include <numeric>

std::vector<long> numbersWithDigitInside(long x, long d)
{
    std::vector<long> numbers;
    for (long i = 1; i <= x; i++) {
        std::string number = std::to_string(i);
        if (number.find(std::to_string(d)) != std::string::npos) {
            numbers.push_back(i);
        }
    }
    if (numbers.empty()) { return { 0, 0, 0 }; }
    long count_numbers = numbers.size();
    return { count_numbers,
              std::accumulate(numbers.begin(), numbers.end(), 0),
              std::accumulate(numbers.begin(), numbers.end(), 1L, std::multiplies<long>())
    };
}
/////////////////////////////////
