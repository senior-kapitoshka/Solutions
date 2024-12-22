#include <string>
#include <vector>
#include <iostream>
#include <string_view>

std::string check(std::string_view x,std::string_view y){
    size_t n=x.size()>=y.size()?y.size():x.size();
    std::string s;
    for(size_t i=0;i<n;++i){
        if(x[i]==y[i]){
            s+=x[i];
        }else break;
    }
    return s;
}

std::string CommonPrefix(const std::vector<std::string>& ws){
  if(ws.empty())return "";
   std::string res=ws[0];
    for(size_t i=1;i<ws.size() && !res.empty();++i){
        res=check(res,ws[i]);
    }
    return res;
}