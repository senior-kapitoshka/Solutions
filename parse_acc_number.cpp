#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <sstream>


void tr(const std::string &acc,std::vector<std::string>& vs){
  std::stringstream ss;
  ss.str(acc);
  for(std::string w;std::getline(ss,w,'\n');){
    vs.push_back(w);
  }
}

template<typename V,typename D>
void from_arr_to_dict(V& digs, D& mp){
  int j=0;
  size_t m=0;
  while(m!=digs.size()){
    for(size_t i=0;i<digs[0].size();i+=3){
      if(j>((int)digs[0].size()/3-1)) j=0;
      mp[j]+=digs[m][i];
      mp[j]+=digs[m][i+1];
      mp[j]+=digs[m][i+2];
      ++j;
    }
    ++m;
  }
}

long parse_bank_account(const std::string &acc)
{
  std::vector<std::string>digs={
" _     _  _     _  _  _  _  _ ",
"| |  | _| _||_||_ |_   ||_||_|",
"|_|  ||_  _|  | _||_|  ||_| _|"
};
    std::map<int,std::string>mp;
   from_arr_to_dict(digs,mp);
  std::vector<std::string> vs;
  tr(acc,vs);
  std::unordered_map<int,std::string>check;
  from_arr_to_dict(vs,check);
  std::string res;
  for_each(check.begin(),check.end(),[&mp,&res](const auto& p){
    auto it=find_if(mp.begin(),mp.end(),[&p](const auto& s){
      return p.second==s.second;
    });
    res+=std::to_string((*it).first);
  });
  std::reverse(res.begin(),res.end());
  long result=std::stol(res);
  return result;
}

//////////////////////////////////
#define c(n, m) acctNbr[i * 3 + m + acctNbr.size() / 3 * n]

long parse_bank_account(const std::string &acctNbr)
{
    long res = 0;
    for (int i = 0; acctNbr[i * 3] != '\n'; ++i) res = res * 10 + std::map<std::string, long>{{" _ | ||_|", 0}, {"     |  |", 1}, {" _  _||_ ", 2}, {" _  _| _|", 3}, {"   |_|  |", 4}, {" _ |_  _|", 5}, {" _ |_ |_|", 6}, {" _   |  |", 7}, {" _ |_||_|", 8}, {" _ |_| _|", 9}}[(char[]){c(0, 0), c(0, 1), c(0, 2), c(1, 0), c(1, 1), c(1, 2), c(2, 0), c(2, 1), c(2, 2), '\0'}];
    return res;
}
/////////////////////////////
#include <string>
#include <map>

std::map<int,int> seg7map {
  {0b0111111,0},{0b0000110,1},{0b1011011,2},{0b1001111,3},{0b1100110,4},
  {0b1101101,5},{0b1111101,6},{0b0000111,7},{0b1111111,8},{0b1101111,9}
};

long parse_bank_account(const std::string &acctNbr) {
    const auto line   = acctNbr.find_first_of('\n');
    const auto stride = line + 1;
    auto get7segindex = [&](int start) {
        return    (acctNbr[start + 1]         =='_')
               + ((acctNbr[stride  +start + 2]=='|')<<1)
               + ((acctNbr[2*stride+start + 2]=='|')<<2)
               + ((acctNbr[2*stride+start + 1]=='_')<<3)
               + ((acctNbr[2*stride+start]    =='|')<<4)
               + ((acctNbr[  stride+start    ]=='|')<<5)
               + ((acctNbr[  stride+start + 1]=='_')<<6);
    };
    int ret=0;
    for (auto s = 0u; s < line; s += 3)
        ret=ret*10+seg7map[get7segindex(s)];
    return ret;  // your code here
}
//////////////////////////////////
