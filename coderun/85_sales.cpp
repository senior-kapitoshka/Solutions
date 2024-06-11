#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <execution>

#if 0

using table= std::map<std::string,std::vector<std::pair<std::string,long long>>>;

int main() 
{
    table t;
    for(std::string s;std::getline(std::cin,s);){
         std::stringstream ss(s);
        std::vector<std::string>vs;
        for(std::string w;getline(ss,w,' ');){
            vs.emplace_back(w);
        }
        if(!t.count(vs[0])){
            t[vs[0]].push_back({vs[1],std::stoi(vs[2])});
        }else if(t.count(vs[0])){
            auto it=std::find_if(t[vs[0]].begin(),t[vs[0]].end(),
            [&vs](auto& p){
                return vs[1]==p.first;
            });
            if(it==t[vs[0]].end()){
                t[vs[0]].push_back({vs[1],std::stoll(vs[2])});
            }else{
                it->second+=std::stoll(vs[2]);
            }
        }
    }
    std::for_each(t.begin(),t.end(),[](auto& p){
        std::cout<<p.first<<":\n";
        std::sort(std::execution::par,p.second.begin(),p.second.end(),[](auto& lhs, auto& rhs){
            return lhs.first<rhs.first;
        });
        std::for_each(p.second.begin(),p.second.end(),[](auto& k){
            std::cout<<k.first<<" "<<k.second<<"\n";
        });
    });
    

	return 0;
}

#endif


using table= std::map<std::string,std::map<std::string,long long>>;

int main() 
{
    table t;
    for(std::string s;std::getline(std::cin,s);){
         std::stringstream ss(s);
        std::vector<std::string>vs;
        for(std::string w;getline(ss,w,' ');){
            vs.emplace_back(w);
        }
        if(!t.count(vs[0])){
            t[vs[0]].emplace(vs[1],std::stoll(vs[2]));
        }else if(t.count(vs[0])){
            
            if(!t[vs[0]].count(vs[1])){
                t[vs[0]].emplace(vs[1],std::stoll(vs[2]));
            }else{
                t[vs[0]][vs[1]]+=std::stoll(vs[2]);
            }
        }
    }
    std::for_each(t.begin(),t.end(),[](auto& p){
        std::cout<<p.first<<":\n";
        for(auto& m:p.second){
            std::cout<<m.first<<" "<<m.second<<"\n";
        }
    });
    

	return 0;
}
