#include <vector>
#include <numeric>
char add_letters(std::vector<char> ls) {
  return  ls.empty()?'z':static_cast<char>('a'+(std::accumulate(ls.begin(),ls.end(),0,[](int& sum, auto& curr){
                                 return sum+=(curr-96);
                                 })-1)%26);
}

/////////////////////
#include <vector>
#include <numeric>
char add_letters(std::vector<char> s) {
 return  (accumulate(s.begin(), s.end(), 0) - 96 * s.size()) % 26 != 0 ? (accumulate(s.begin(), s.end(), 0) - 96 * s.size()) % 26+96 : 'z';
}
///////////////////
#include <vector>
#include <numeric>

char add_letters(std::vector<char> l) 
{
  return l.empty() ? 'z' : (std::accumulate(l.begin(), l.end(), 0, [](int s, int c) { return s + c - 'a' + 1; }) - 1) % 26 + 'a';
}