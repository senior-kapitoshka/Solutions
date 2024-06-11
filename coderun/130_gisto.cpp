#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <utility>

int main() 
{
    std::map<char,int>mp;
    for(std::string s;std::getline(std::cin,s);){
        std::stringstream ss(s);
        for(std::string w;std::getline(ss,w,' ');){
            for(size_t i=0;i<w.size();++i){
                ++mp[w[i]];
            }
        }
    }
    int n=mp.size();
    int m=std::max_element(mp.begin(),mp.end(),
    [](auto& lhs,auto& rhs){
        return lhs.second<rhs.second;
    })->second;
    std::vector<std::string>vs;
    vs.reserve(n);
    std::for_each(mp.begin(),mp.end(),
        [m,&vs](auto& p){
            std::string t(m+1,' ');
            t[0]=std::forward<std::pair<char,int>>(p).first;
            for(int i=1;
                i<std::forward<std::pair<char,int>>(p).second+1;++i){
                    t[i]='#';
                }
            std::reverse(t.begin(),t.end());
            vs.push_back(t);
        });
    
    for(size_t i=0;i<vs[0].size();++i){
        for(size_t j=0;j<vs.size();++j){
            std::cout<<vs[j][i];
        }
        std::cout<<"\n";
    }

	return 0;
}