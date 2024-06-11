#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using Pairs=std::vector<std::pair<std::string,std::string>>;

int main() 
{
    size_t n=0;
    std::cin>>n;
    Pairs vp;
    vp.reserve(n);
    for(size_t i=0;i<n;++i){
        std::string a,b;
        std::cin>>a>>b;
        vp.push_back({a,b});
    }
    std::string s;
    std::cin>>s;
    auto it=std::find_if(vp.begin(),vp.end(),
    [&s](auto& p){
       return p.first==s || p.second==s; 
    });
    if(it->first==s)
        std::cout<<it->second<<"\n";
    else std::cout<<it->first<<"\n";
	return 0;
}