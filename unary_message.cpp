#include <string>
#include <string_view>
#include <algorithm>
#include <regex>
#include <numeric>
#include <cassert>
#include <cmath>


namespace util{
  void trans(std::string& res,const std::string& src){
    std::regex r("[^0]+|[^1]+");
    auto rb=std::sregex_iterator(src.begin(),src.end(),r);
    auto re=std::sregex_iterator();
    for(auto it=rb;it!=re;++it){
      std::string t=(*it).str();
     res+=t.front()=='1'?"0 "+std::string(t.size(),'0')+" ":"00 "+std::string(t.size(),'0')+" ";
    }
    res.pop_back();
  }
  
  void from_dec_to_bin(std::string& res,int d){
    int x=d;
    std::string s;
    while(d!=1){
      s+=d%2+'0';
      d/=2;
    }
    s+='1';
    if(x<=63){
      s+='0';
    }
    std::reverse(s.begin(),s.end());
    res+=s;
  }
  void from_bin_to_dec(std::vector<int>&txt,std::string_view s){
    std::string str=(std::string)s;
    while(!str.empty()){
      std::string t=str.substr(0,7);
      str.erase(0,7);
      int res=0;
      int i=6;
      std::for_each(t.begin(),t.end(),[&i,&res](auto& c){
        res+=(c-'0')*std::pow(2,i);
        --i;
      });
      txt.push_back(res);
    }
  }
  std::string to_txt(const std::vector<int>&txt){
    std::string res;
    std::transform(txt.begin(),txt.end(),std::back_inserter(res),
                   [](auto& i){return static_cast<char>(i);});
    return res;
  }
}

namespace UnaryMessage
{
  std::string send(const std::string& tt)
  {
    std::string s;
    std::for_each(tt.begin(),tt.end(),[&s](auto& c){
      if((c-0)>=31 && (c-0)<=128)util::from_dec_to_bin(s,c-0);
    });
    std::string res;
    util::trans(res,s);
    return res;
  }

  std::string receive(const std::string& txt)
  {
    std::regex r("[0]{1,2}[\\s][0]*");
    auto rb=std::sregex_iterator(txt.begin(),txt.end(),r);
    auto re=std::sregex_iterator();
    std::string s;
    for(auto it=rb;it!=re;++it){
      s+=(*it).str().substr(0,(*it).str().find_first_of(" ")).size()==2?
        std::string((*it).str().substr((*it).str().find_first_of(" ")+1).size(),'0'):
      std::string((*it).str().substr((*it).str().find_first_of(" ")+1).size(),'1'); 
    }
    std::vector<int>vc;
    util::from_bin_to_dec(vc,s);
    return util::to_txt(vc);
  }
}

///////////////////////////////
#include <string>
#include <iostream>
#include <bitset>
#include <sstream>

namespace UnaryMessage
{
  std::string send(const std::string& text)
  {
    std::string mes;
    char cur='2';
    for(auto c:text)
    {
      std::string binstr=std::bitset<7>(c).to_string();
      for (auto b:binstr)
      {
        if (b==cur)mes+='0';
        else
        {
          mes += b == '0' ? " 00 0" : " 0 0";
          cur=b;
        }
      }
    }
    mes.erase(0,1);
    return mes;
  }

  std::string receive(const std::string& text)
  {
    
    std::string mes;
    int cur = text.substr(0,2) == "00" ? 0 : 1;
    int i = cur == 0 ? 3 : 2,b=6;
    std::bitset<7> bits;
    
    while (i<text.size())
    {
      if (text[i++]=='0')
      {
        bits[b--]=cur;
        if (b<0)
        {
          mes+= char(bits.to_ulong());
          b=6;
        }
      }
      else
      {
        cur = text.substr(i,2) == "00" ? 0 : 1;
        i+= cur == 0 ? 3 : 2;
      }
    }

    return mes;
  }
}
//////////////////////////
