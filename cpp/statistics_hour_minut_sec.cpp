#include <tuple>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <array>
#include <iostream>
#include <utility>

class Stat
{
public:
  struct HMS{
    int h;
    int m;
    int s;
    int sm;
    bool operator<(const HMS& other){
      return sm<other.sm;
    }
    bool operator>(const HMS& other){
      return sm>other.sm;
    }
    bool operator==(const HMS& other){
      return sm==other.sm;
    }
    bool operator!=(const HMS& other){
      return sm!=other.sm;
    }
  };

  template<typename S>
  static std::vector<HMS> process(S &&s){
    std::vector<HMS> res;
    std::vector<std::string> rws;
    std::stringstream ss;
    ss.str(std::forward<S>(s));
    for(std::string hms;std::getline(ss,hms,' ');){
      rws.push_back(std::move(hms));
    }
    for_each(rws.begin(),rws.end(),[&res](auto& hms){
      std::stringstream ss;
      ss.str(hms);
      std::array<int,3> t;
      int i=0;
      for(std::string s;std::getline(ss,s,'|');++i){
        t[i]=std::stoi(std::move(s));
      }
      res.push_back({t[0],t[1],t[2],((60*t[0]+t[1])*60+t[2])});
    });
    sort(res.begin(),res.end());
    //res.erase(std::unique(res.begin(),res.end()),res.end());
    return res;
  }
  static void test([[maybe_unused]]const std::vector<HMS>& vh){
    for_each(vh.begin(),vh.end(),[](auto& hms){
      std::cout<<"h:"<<hms.h<<",m:"<<hms.m<<",s:"<<hms.s<<",sm:"<<hms.sm<<"\n";
    });
  }
  static HMS result(const int in){
    int i=in/3600;
    int t=in%3600;
    int d=t/60;
    int s=t%60;
    return {i,d,s,in};
  }
  

  static std::string range(const std::vector<HMS>& vh){
    int res=vh.back().sm-vh.front().sm;
    HMS r=result(res);
    std::string sr = "Range: "+(r.h>=10?std::to_string(r.h):"0"+std::to_string(r.h))
      +"|"+(r.m>=10?std::to_string(r.m):"0"+std::to_string(r.m))
      +"|"+(r.s>=10?std::to_string(r.s):"0"+std::to_string(r.s))+" ";
    return sr;
  }
  
  static std::string average(const std::vector<HMS>& vh){
    int res=std::accumulate(vh.begin(),vh.end(),0,[](int sum,const HMS& curr){return sum+curr.sm;})/static_cast<int>(vh.size());
    HMS r=result(res);
    std::string sr = "Average: "+(r.h>=10?std::to_string(r.h):"0"+std::to_string(r.h))
      +"|"+(r.m>=10?std::to_string(r.m):"0"+std::to_string(r.m))
      +"|"+(r.s>=10?std::to_string(r.s):"0"+std::to_string(r.s))+" ";
    return sr;
  }
  
  static std::string median(const std::vector<HMS>& vh){
    std::string sr;
    if(vh.size()%2!=0){ 
      size_t i=vh.size()/2;
      HMS r=vh[i];
      sr = "Median: "+(r.h>=10?std::to_string(r.h):"0"+std::to_string(r.h))
      +"|"+(r.m>=10?std::to_string(r.m):"0"+std::to_string(r.m))
      +"|"+(r.s>=10?std::to_string(r.s):"0"+std::to_string(r.s));
    }else{
      size_t i=vh.size()/2;
      HMS c=vh[i-1];
      HMS d=vh[i];
      int res=(d.sm+c.sm)/2;
      HMS r=result(res);
      sr = "Median: "+(r.h>=10?std::to_string(r.h):"0"+std::to_string(r.h))
      +"|"+(r.m>=10?std::to_string(r.m):"0"+std::to_string(r.m))
      +"|"+(r.s>=10?std::to_string(r.s):"0"+std::to_string(r.s));
    }
    return sr;
  }

  static std::string stat(const std::string &strg){
    std::vector<HMS> vh = process(strg);
    #if 1
    test(vh);
    #endif
    #if 1
    std::cout<<"---\n";
    std::cout<<range(vh)<<"\n";
    std::cout<<average(vh)<<"\n";
    std::cout<<median(vh)<<"\n";
    std::cout<<"---\n";
    #endif
    return range(vh)+average(vh)+median(vh) ;
  }
  
};