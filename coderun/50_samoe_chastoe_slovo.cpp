#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

int main() 
{
    std::map<std::string,int>mp;
    std::vector<std::string>vs;
    int mx=0;
    for(std::string w;std::getline(std::cin,w,'\n');){
        vs.push_back(w);
    }

    for(auto& s:vs){
        std::stringstream ss(s);
        for(std::string w;std::getline(ss,w,' ');){
            if(mp.count(w)){
                mx=std::max(mp[w]+1,mx);
                ++mp[w];
            }else{
                ++mp[w];
            }
        }
    }
    
    
    std::cout<<std::find_if(mp.begin(),mp.end(),[mx]
        (auto& p){
            return mx!=0?p.second==mx:p.second==1 ;
        })->first;

	return 0;
}