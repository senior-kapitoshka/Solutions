

#include <algorithm>
#include <iostream>
std::string triangle(std::string row_str) {
  while(row_str.size()!=1){
    std::string t; 
    std::transform(row_str.begin(),prev(row_str.end()),next(row_str.begin()),
                  std::back_inserter(t),[](auto& p, auto& n){
                    if(p!=n){
                      if((p=='B'&& n=='G')||(p=='G'&& n=='B')) return 'R';
                      if((p=='R'&& n=='G')||(p=='G'&& n=='R')) return 'B';
                      if((p=='B'&& n=='R')||(p=='R'&& n=='B')) return 'G';
                    }
                    return n;
                  });
    row_str=t;
  }
  return row_str;
}
////////////////////////////////////////////

std::string triangle(std::string str)
{
  while (str.size() != 1)
  {
    std::string s;
    std::transform(str.begin(), str.end() - 1, str.begin() + 1, std::back_inserter(s), [](char c1, char c2) { return c1 == c2 ? c1 : c1 == 'B' && c2 == 'G' || c1 == 'G' && c2 == 'B' ? 'R' : c1 == 'R' && c2 == 'G' || c1 == 'G' && c2 == 'R' ? 'B' : 'G'; });
    str = s;
  }
  return str;
}