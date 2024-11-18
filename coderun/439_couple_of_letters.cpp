#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

int main() 
{
    std::unordered_map<std::string,unsigned>mp;
    std::string s;
    std::getline(std::cin,s);
    std::stringstream ss(s);
    for(std::string w;std::getline(ss,w,' ');){
        for(size_t i=0;i<w.size()-1;++i){
            ++mp[w.substr(i,2)];
        }
    }
    auto it=std::max_element(mp.begin(),mp.end(),[]
    (auto& lhs,auto& rhs){
        return lhs.second<rhs.second ||(lhs.second==rhs.second && lhs.first<rhs.first); 
    });
    std::cout<<it->first<<"\n";
	return 0;
}